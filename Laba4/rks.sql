-- Выполнить этот скрипт после подключения к базе данных library
-- Подключитесь к базе через: psql -d library -U postgres

-- Создание таблицы authors
CREATE TABLE IF NOT EXISTS authors (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    birth_year INT
);

-- Создание таблицы books
CREATE TABLE IF NOT EXISTS books (
    id SERIAL PRIMARY KEY,
    title VARCHAR(200) NOT NULL,
    author_id INT REFERENCES authors(id),
    publication_year INT,
    genre VARCHAR(50)
);

-- Создание таблицы users
CREATE TABLE IF NOT EXISTS users (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    registration_date DATE
);

-- Создание таблицы borrowed_books
CREATE TABLE IF NOT EXISTS borrowed_books (
    user_id INT REFERENCES users(id),
    book_id INT REFERENCES books(id),
    borrow_date DATE,
    return_date DATE
);

-- Создание индексов
CREATE INDEX IF NOT EXISTS idx_authors_name ON authors(name);
CREATE INDEX IF NOT EXISTS idx_books_title ON books(title);
CREATE INDEX IF NOT EXISTS idx_borrowed_books_date ON borrowed_books(borrow_date);