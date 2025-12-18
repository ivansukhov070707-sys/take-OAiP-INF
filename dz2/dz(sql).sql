-- Создаем таблицы только если они не существуют
CREATE TABLE IF NOT EXISTS products_dim (
    product_id INTEGER PRIMARY KEY,
    product_name VARCHAR(100) NOT NULL,
    category VARCHAR(50),
    price DECIMAL(10,2) CHECK (price >= 0)
);

CREATE TABLE IF NOT EXISTS customers_dim (
    customer_id INTEGER PRIMARY KEY,
    customer_name VARCHAR(100) NOT NULL,
    region VARCHAR(50)
);

CREATE TABLE IF NOT EXISTS sales_fact (
    sale_id INTEGER PRIMARY KEY,
    sale_date DATE NOT NULL,
    product_id INTEGER NOT NULL REFERENCES products_dim(product_id) ON DELETE RESTRICT,
    customer_id INTEGER NOT NULL REFERENCES customers_dim(customer_id) ON DELETE RESTRICT,
    quantity INTEGER NOT NULL CHECK (quantity > 0),
    amount DECIMAL(10,2) NOT NULL CHECK (amount >= 0)
);

-- Улучшенный код для создания индексов с проверкой существования
DO $$
BEGIN
    -- Индексы для таблицы sales_fact
    IF NOT EXISTS (SELECT 1 FROM pg_indexes WHERE indexname = 'idx_sales_fact_product') THEN
        CREATE INDEX idx_sales_fact_product ON sales_fact(product_id);
    END IF;
    
    IF NOT EXISTS (SELECT 1 FROM pg_indexes WHERE indexname = 'idx_sales_fact_customer') THEN
        CREATE INDEX idx_sales_fact_customer ON sales_fact(customer_id);
    END IF;
    
    IF NOT EXISTS (SELECT 1 FROM pg_indexes WHERE indexname = 'idx_sales_fact_date') THEN
        CREATE INDEX idx_sales_fact_date ON sales_fact(sale_date);
    END IF;
    
    IF NOT EXISTS (SELECT 1 FROM pg_indexes WHERE indexname = 'idx_sales_fact_date_product') THEN
        CREATE INDEX idx_sales_fact_date_product ON sales_fact(sale_date, product_id);
    END IF;
    
    -- Индексы для таблицы products_dim
    IF NOT EXISTS (SELECT 1 FROM pg_indexes WHERE indexname = 'idx_products_dim_category') THEN
        CREATE INDEX idx_products_dim_category ON products_dim(category);
    END IF;
    
    -- Индексы для таблицы customers_dim
    IF NOT EXISTS (SELECT 1 FROM pg_indexes WHERE indexname = 'idx_customers_dim_region') THEN
        CREATE INDEX idx_customers_dim_region ON customers_dim(region);
    END IF;
END $$;

-- Опционально: создание представлений для аналитики
CREATE OR REPLACE VIEW sales_summary AS
SELECT 
    s.sale_id,
    s.sale_date,
    p.product_name,
    p.category,
    c.customer_name,
    c.region,
    s.quantity,
    s.amount,
    ROUND(s.amount / s.quantity, 2) as avg_price_per_unit
FROM sales_fact s
JOIN products_dim p ON s.product_id = p.product_id
JOIN customers_dim c ON s.customer_id = c.customer_id;

CREATE OR REPLACE VIEW monthly_sales_report AS
SELECT 
    EXTRACT(YEAR FROM s.sale_date) as year,
    EXTRACT(MONTH FROM s.sale_date) as month,
    COUNT(*) as total_sales,
    SUM(s.amount) as total_amount,
    AVG(s.amount) as avg_sale_amount,
    SUM(s.quantity) as total_quantity
FROM sales_fact s
GROUP BY EXTRACT(YEAR FROM s.sale_date), EXTRACT(MONTH FROM s.sale_date)
ORDER BY year DESC, month DESC;

CREATE OR REPLACE VIEW top_products AS
SELECT 
    p.product_id,
    p.product_name,
    p.category,
    COUNT(s.sale_id) as sales_count,
    SUM(s.quantity) as total_quantity,
    SUM(s.amount) as total_revenue
FROM products_dim p
LEFT JOIN sales_fact s ON p.product_id = s.product_id
GROUP BY p.product_id, p.product_name, p.category
ORDER BY total_revenue DESC NULLS LAST;

CREATE OR REPLACE VIEW top_customers AS
SELECT 
    c.customer_id,
    c.customer_name,
    c.region,
    COUNT(s.sale_id) as purchase_count,
    SUM(s.amount) as total_spent
FROM customers_dim c
LEFT JOIN sales_fact s ON c.customer_id = s.customer_id
GROUP BY c.customer_id, c.customer_name, c.region
ORDER BY total_spent DESC NULLS LAST;

-- Функция для очистки всех данных
CREATE OR REPLACE FUNCTION clear_all_data() 
RETURNS void AS $$
BEGIN
    DELETE FROM sales_fact;
    DELETE FROM products_dim;
    DELETE FROM customers_dim;
    RAISE NOTICE 'Все данные удалены';
END;
$$ LANGUAGE plpgsql;

-- Функция для получения статистики
CREATE OR REPLACE FUNCTION get_database_stats() 
RETURNS TABLE (
    table_name VARCHAR,
    row_count BIGINT,
    last_update TIMESTAMP
) AS $$
BEGIN
    RETURN QUERY
    SELECT 
        'products_dim'::VARCHAR as table_name,
        COUNT(*)::BIGINT as row_count,
        MAX(NULL)::TIMESTAMP as last_update
    FROM products_dim
    UNION ALL
    SELECT 
        'customers_dim'::VARCHAR,
        COUNT(*)::BIGINT,
        MAX(NULL)::TIMESTAMP
    FROM customers_dim
    UNION ALL
    SELECT 
        'sales_fact'::VARCHAR,
        COUNT(*)::BIGINT,
        MAX(sale_date)::TIMESTAMP
    FROM sales_fact;
END;
$$ LANGUAGE plpgsql;
