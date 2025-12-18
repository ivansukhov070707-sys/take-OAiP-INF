#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <filesystem>
#include <pqxx/pqxx>

using namespace std;
using namespace pqxx;

struct Sale {
    int sale_id;
    string sale_date;
    int product_id;
    int customer_id;
    int quantity;
    double amount;
};

struct Product {
    int product_id;
    string product_name;
    string category;
    double price;
};

struct Customer {
    int customer_id;
    string customer_name;
    string region;
};

// Функция для проверки существования файла
bool fileExists(const string& filename) {
    return filesystem::exists(filename);
}

// Функция для вывода информации о файле
void printFileInfo(const string& filename) {
    if (fileExists(filename)) {
        cout << "Файл " << filename << " найден. ";

        // Проверяем размер файла
        uintmax_t size = filesystem::file_size(filename);
        if (size > 0) {
            cout << "Размер: " << size << " байт" << endl;
        }
        else {
            cout << "Файл пуст!" << endl;
        }
    }
    else {
        cout << "Файл " << filename << " НЕ НАЙДЕН!" << endl;
    }
}

// Загрузка CSV с улучшенной обработкой ошибок
vector<Sale> loadSalesData(const string& filename) {
    vector<Sale> sales;

    // Проверяем существование файла
    if (!fileExists(filename)) {
        cerr << "ОШИБКА: Файл " << filename << " не существует!" << endl;
        cerr << "Текущая директория: " << filesystem::current_path().string() << endl;
        return sales;
    }

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Не удалось открыть файл: " << filename << endl;
        return sales;
    }

    string line;

    // Проверяем, не пустой ли файл
    if (file.peek() == ifstream::traits_type::eof()) {
        cerr << "Файл " << filename << " пустой!" << endl;
        file.close();
        return sales;
    }

    getline(file, line); // Пропустить заголовок

    int line_num = 2; // Начинаем с 2 строки (после заголовка)
    int loaded_count = 0;

    while (getline(file, line)) {
        if (line.empty()) continue;

        try {
            stringstream ss(line);
            Sale s;
            string temp;

            getline(ss, temp, ','); s.sale_id = stoi(temp);
            getline(ss, s.sale_date, ',');
            getline(ss, temp, ','); s.product_id = stoi(temp);
            getline(ss, temp, ','); s.customer_id = stoi(temp);
            getline(ss, temp, ','); s.quantity = stoi(temp);
            getline(ss, temp, ','); s.amount = stod(temp);

            sales.push_back(s);
            loaded_count++;
        }
        catch (const exception& e) {
            cerr << "Ошибка при обработке строки " << line_num
                << " в файле " << filename << ": " << e.what() << endl;
            cerr << "Строка: " << line << endl;
        }

        line_num++;
    }

    file.close();

    if (loaded_count > 0) {
        cout << "✓ Загружено " << loaded_count << " продаж из " << filename << endl;
    }
    else {
        cout << "✗ Не загружено ни одной продажи из " << filename << endl;
    }

    return sales;
}

vector<Product> loadProductsData(const string& filename) {
    vector<Product> products;

    if (!fileExists(filename)) {
        cerr << "ОШИБКА: Файл " << filename << " не существует!" << endl;
        cerr << "Текущая директория: " << filesystem::current_path().string() << endl;
        return products;
    }

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Не удалось открыть файл: " << filename << endl;
        return products;
    }

    string line;

    if (file.peek() == ifstream::traits_type::eof()) {
        cerr << "Файл " << filename << " пустой!" << endl;
        file.close();
        return products;
    }

    getline(file, line); // Пропустить заголовок

    int line_num = 2;
    int loaded_count = 0;

    while (getline(file, line)) {
        if (line.empty()) continue;

        try {
            stringstream ss(line);
            Product p;
            string temp;

            getline(ss, temp, ','); p.product_id = stoi(temp);
            getline(ss, p.product_name, ',');
            getline(ss, p.category, ',');
            getline(ss, temp, ','); p.price = stod(temp);

            products.push_back(p);
            loaded_count++;
        }
        catch (const exception& e) {
            cerr << "Ошибка при обработке строки " << line_num
                << " в файле " << filename << ": " << e.what() << endl;
            cerr << "Строка: " << line << endl;
        }

        line_num++;
    }

    file.close();

    if (loaded_count > 0) {
        cout << "✓ Загружено " << loaded_count << " продуктов из " << filename << endl;
    }
    else {
        cout << "✗ Не загружено ни одного продукта из " << filename << endl;
    }

    return products;
}

vector<Customer> loadCustomersData(const string& filename) {
    vector<Customer> customers;

    if (!fileExists(filename)) {
        cerr << "ОШИБКА: Файл " << filename << " не существует!" << endl;
        cerr << "Текущая директория: " << filesystem::current_path().string() << endl;
        return customers;
    }

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Не удалось открыть файл: " << filename << endl;
        return customers;
    }

    string line;

    if (file.peek() == ifstream::traits_type::eof()) {
        cerr << "Файл " << filename << " пустой!" << endl;
        file.close();
        return customers;
    }

    getline(file, line); // Пропустить заголовок

    int line_num = 2;
    int loaded_count = 0;

    while (getline(file, line)) {
        if (line.empty()) continue;

        try {
            stringstream ss(line);
            Customer c;
            string temp;

            getline(ss, temp, ','); c.customer_id = stoi(temp);
            getline(ss, c.customer_name, ',');
            getline(ss, c.region, ',');

            customers.push_back(c);
            loaded_count++;
        }
        catch (const exception& e) {
            cerr << "Ошибка при обработке строки " << line_num
                << " в файле " << filename << ": " << e.what() << endl;
            cerr << "Строка: " << line << endl;
        }

        line_num++;
    }

    file.close();

    if (loaded_count > 0) {
        cout << "✓ Загружено " << loaded_count << " клиентов из " << filename << endl;
    }
    else {
        cout << "✗ Не загружено ни одного клиента из " << filename << endl;
    }

    return customers;
}

int main() {
    setlocale(LC_ALL, "RU");

    cout << "=== ПРОВЕРКА CSV ФАЙЛОВ ===" << endl;
    printFileInfo("products.csv");
    printFileInfo("customers.csv");
    printFileInfo("sales.csv");
    cout << "===========================\n" << endl;

    try {
        // Подключение
        connection conn("host=localhost dbname=dz user=postgres password=12345");
        cout << "✓ Подключение к БД успешно!" << endl;

        // Проверяем существование таблиц
        {
            work txn(conn);
            // Создаем таблицы если их нет
            txn.exec("CREATE TABLE IF NOT EXISTS products_dim ("
                "product_id INTEGER PRIMARY KEY, "
                "product_name VARCHAR(100), "
                "category VARCHAR(50), "
                "price DECIMAL(10,2))");

            txn.exec("CREATE TABLE IF NOT EXISTS customers_dim ("
                "customer_id INTEGER PRIMARY KEY, "
                "customer_name VARCHAR(100), "
                "region VARCHAR(50))");

            txn.exec("CREATE TABLE IF NOT EXISTS sales_fact ("
                "sale_id INTEGER PRIMARY KEY, "
                "sale_date DATE, "
                "product_id INTEGER REFERENCES products_dim(product_id), "
                "customer_id INTEGER REFERENCES customers_dim(customer_id), "
                "quantity INTEGER, "
                "amount DECIMAL(10,2))");
            txn.commit();
            cout << "✓ Таблицы проверены/созданы" << endl;
        }

        // Загрузка данных
        cout << "\n=== ЗАГРУЗКА ДАННЫХ ИЗ CSV ===" << endl;
        vector<Product> products = loadProductsData("products.csv");
        vector<Customer> customers = loadCustomersData("customers.csv");
        vector<Sale> sales = loadSalesData("sales.csv");

        cout << "\n=== ПРОВЕРКА ЗАГРУЖЕННЫХ ДАННЫХ ===" << endl;
        cout << "Продуктов загружено: " << products.size() << endl;
        cout << "Клиентов загружено: " << customers.size() << endl;
        cout << "Продаж загружено: " << sales.size() << endl;

        // Проверяем, все ли данные загружены
        if (products.empty() && customers.empty() && sales.empty()) {
            cerr << "\n✗ ВСЕ файлы CSV не загружены или пустые!" << endl;
            cerr << "Создайте файлы или проверьте их расположение." << endl;
            cerr << "\nСоздайте следующие CSV файлы:" << endl;
            cerr << "1. products.csv (обязательный)" << endl;
            cerr << "2. customers.csv (обязательный)" << endl;
            cerr << "3. sales.csv (обязательный)" << endl;
            return 1;
        }

        // Проверяем минимальные требования для работы
        bool can_continue = true;

        if (products.empty()) {
            cerr << "✗ ОШИБКА: Нет данных о продуктах!" << endl;
            can_continue = false;
        }

        if (customers.empty()) {
            cerr << "✗ ОШИБКА: Нет данных о клиентах!" << endl;
            can_continue = false;
        }

        if (sales.empty()) {
            cerr << "✗ ОШИБКА: Нет данных о продажах!" << endl;
            can_continue = false;
        }

        if (!can_continue) {
            cerr << "\nПродолжение невозможно. Проверьте CSV файлы." << endl;
            return 1;
        }

        // Вставка продуктов (с проверкой дубликатов)
        if (!products.empty()) {
            work txn(conn);
            int inserted_count = 0;
            for (auto& p : products) {
                result res = txn.exec("INSERT INTO products_dim VALUES (" +
                    to_string(p.product_id) + ", " +
                    txn.quote(p.product_name) + ", " +
                    txn.quote(p.category) + ", " +
                    to_string(p.price) + ") ON CONFLICT (product_id) DO NOTHING");

                if (res.affected_rows() > 0) {
                    inserted_count++;
                }
            }
            txn.commit();
            cout << "✓ Продукты добавлены: " << inserted_count << " новых записей" << endl;
        }

        // Вставка клиентов (с проверкой дубликатов)
        if (!customers.empty()) {
            work txn(conn);
            int inserted_count = 0;
            for (auto& c : customers) {
                result res = txn.exec("INSERT INTO customers_dim VALUES (" +
                    to_string(c.customer_id) + ", " +
                    txn.quote(c.customer_name) + ", " +
                    txn.quote(c.region) + ") ON CONFLICT (customer_id) DO NOTHING");

                if (res.affected_rows() > 0) {
                    inserted_count++;
                }
            }
            txn.commit();
            cout << "✓ Клиенты добавлены: " << inserted_count << " новых записей" << endl;
        }

        // Вставка продаж (с проверкой дубликатов)
        if (!sales.empty()) {
            work txn(conn);
            int inserted_count = 0;
            for (auto& s : sales) {
                result res = txn.exec("INSERT INTO sales_fact VALUES (" +
                    to_string(s.sale_id) + ", " +
                    txn.quote(s.sale_date) + ", " +
                    to_string(s.product_id) + ", " +
                    to_string(s.customer_id) + ", " +
                    to_string(s.quantity) + ", " +
                    to_string(s.amount) + ") ON CONFLICT (sale_id) DO NOTHING");

                if (res.affected_rows() > 0) {
                    inserted_count++;
                }
            }
            txn.commit();
            cout << "✓ Продажи добавлены: " << inserted_count << " новых записей" << endl;
        }

        // Создание индексов (если их нет)
        {
            work txn(conn);
            txn.exec("CREATE INDEX IF NOT EXISTS idx_sales_fact_product ON sales_fact(product_id)");
            txn.exec("CREATE INDEX IF NOT EXISTS idx_sales_fact_customer ON sales_fact(customer_id)");
            txn.exec("CREATE INDEX IF NOT EXISTS idx_sales_fact_date ON sales_fact(sale_date)");
            txn.exec("CREATE INDEX IF NOT EXISTS idx_products_dim_category ON products_dim(category)");
            txn.exec("CREATE INDEX IF NOT EXISTS idx_customers_dim_region ON customers_dim(region)");
            txn.commit();
            cout << "✓ Индексы созданы" << endl;
        }

        // Аналитические запросы
        {
            nontransaction ntxn(conn);

            cout << "\n=== АНАЛИТИЧЕСКИЕ ЗАПРОСЫ ===" << endl;

            // Проверяем, есть ли данные для анализа
            result check = ntxn.exec("SELECT COUNT(*) FROM sales_fact");
            int sales_count = check[0][0].as<int>();

            if (sales_count == 0) {
                cout << "\n⚠ Внимание: В таблице sales_fact нет данных для анализа!" << endl;
                cout << "Загрузите данные о продажах в файле sales.csv" << endl;
            }
            else {
                // 1. Объем продаж по категориям
                cout << "\n1. Объем продаж по категориям:" << endl;
                result res1 = ntxn.exec(
                    "SELECT p.category, SUM(s.amount) as total_sales "
                    "FROM sales_fact s "
                    "JOIN products_dim p ON s.product_id = p.product_id "
                    "GROUP BY p.category ORDER BY total_sales DESC"
                );

                if (res1.empty()) {
                    cout << "   Нет данных" << endl;
                }
                else {
                    for (auto row : res1) {
                        cout << "   " << row[0].as<string>() << ": " << row[1].as<string>() << " руб." << endl;
                    }
                }

                // 2. Покупки по регионам
                cout << "\n2. Покупки по регионам:" << endl;
                result res2 = ntxn.exec(
                    "SELECT c.region, COUNT(s.sale_id) as number_of_sales "
                    "FROM sales_fact s "
                    "JOIN customers_dim c ON s.customer_id = c.customer_id "
                    "GROUP BY c.region ORDER BY number_of_sales DESC"
                );

                if (res2.empty()) {
                    cout << "   Нет данных" << endl;
                }
                else {
                    for (auto row : res2) {
                        cout << "   " << row[0].as<string>() << ": " << row[1].as<int>() << " продаж" << endl;
                    }
                }

                // 3. Средний чек по месяцам
                cout << "\n3. Средний чек по месяцам:" << endl;
                result res3 = ntxn.exec(
                    "SELECT EXTRACT(YEAR FROM sale_date) as year, "
                    "EXTRACT(MONTH FROM sale_date) as month, "
                    "AVG(amount) as average_ticket "
                    "FROM sales_fact "
                    "GROUP BY year, month "
                    "ORDER BY year, month"
                );

                if (res3.empty()) {
                    cout << "   Нет данных" << endl;
                }
                else {
                    for (auto row : res3) {
                        cout << "   " << row[0].as<int>() << "-"
                            << (row[1].as<int>() < 10 ? "0" : "") << row[1].as<int>()
                            << ": " << row[2].as<string>() << " руб." << endl;
                    }
                }
            }
        }

        cout << "\n=== ПРОГРАММА УСПЕШНО ЗАВЕРШЕНА! ===" << endl;

    }
    catch (const exception& e) {
        cerr << "\n✗ КРИТИЧЕСКАЯ ОШИБКА: " << e.what() << endl;
        return 1;
    }

    return 0;
}