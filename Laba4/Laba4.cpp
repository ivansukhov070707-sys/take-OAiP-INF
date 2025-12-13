#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <pqxx/pqxx>

using namespace std;
using namespace pqxx;

class Database {
private:
    unique_ptr<connection> conn;
public:
    Database(const string& connStr) : conn(make_unique<connection>(connStr)) {
        if (!conn->is_open()) throw runtime_error("Нет подключения");
    }
    connection* getConnection() { return conn.get(); }
};

class Author {
private:
    Database* db;
public:
    Author(Database* db) : db(db) {}

    int add(const string& name, int year) {
        try {
            work txn(*db->getConnection());
            result res = txn.exec(
                "INSERT INTO authors (name, birth_year) VALUES (" +
                txn.quote(name) + ", " + to_string(year) +
                ") RETURNING id"
            );
            int id = res[0][0].as<int>();
            txn.commit();
            cout << "Автор добавлен! ID: " << id << endl;
            return id;
        }
        catch (const exception& e) {
            cerr << "Ошибка: " << e.what() << endl;
            return 0;
        }
    }
};

class Book {
private:
    Database* db;
public:
    Book(Database* db) : db(db) {}

    int add(const string& title, int author_id, int year, const string& genre) {
        try {
            work txn(*db->getConnection());
            result res = txn.exec(
                "INSERT INTO books (title, author_id, publication_year, genre) VALUES (" +
                txn.quote(title) + ", " + to_string(author_id) + ", " +
                to_string(year) + ", " + txn.quote(genre) +
                ") RETURNING id"
            );
            int id = res[0][0].as<int>();
            txn.commit();
            cout << "Книга добавлена! ID: " << id << endl;
            return id;
        }
        catch (const exception& e) {
            cerr << "Ошибка: " << e.what() << endl;
            return 0;
        }
    }
};

class User {
private:
    Database* db;
public:
    User(Database* db) : db(db) {}

    int add(const string& name, const string& date) {
        try {
            work txn(*db->getConnection());
            result res = txn.exec(
                "INSERT INTO users (name, registration_date) VALUES (" +
                txn.quote(name) + ", " + txn.quote(date) +
                ") RETURNING id"
            );
            int id = res[0][0].as<int>();
            txn.commit();
            cout << "Пользователь добавлен! ID: " << id << endl;
            return id;
        }
        catch (const exception& e) {
            cerr << "Ошибка: " << e.what() << endl;
            return 0;
        }
    }
};

class BorrowedBook {
private:
    Database* db;
public:
    BorrowedBook(Database* db) : db(db) {}

    void add(int user_id, int book_id, const string& borrow_date, const string& return_date) {
        try {
            work txn(*db->getConnection());
            txn.exec(
                "INSERT INTO borrowed_books (user_id, book_id, borrow_date, return_date) VALUES (" +
                to_string(user_id) + ", " + to_string(book_id) + ", " +
                txn.quote(borrow_date) + ", " + txn.quote(return_date) + ")"
            );
            txn.commit();
            cout << "Заем зарегистрирован!" << endl;
        }
        catch (const exception& e) {
            cerr << "Ошибка: " << e.what() << endl;
        }
    }
};

class LibrarySystem {
private:
    Database db;

    vector<vector<string>> query(const string& sql) {
        vector<vector<string>> results;
        try {
            work txn(*db.getConnection());
            result res = txn.exec(sql);
            for (const auto& row : res) {
                vector<string> rowData;
                for (size_t i = 0; i < res.columns(); i++) {
                    rowData.push_back(row[i].as<string>());
                }
                results.push_back(rowData);
            }
        }
        catch (const exception& e) {
            cerr << "Ошибка запроса: " << e.what() << endl;
        }
        return results;
    }

    void showMenu() {
        cout << "\n=== БИБЛИОТЕКА ===" << endl;
        cout << "1. Добавить автора\n2. Добавить книгу\n3. Добавить пользователя\n";
        cout << "4. Зарегистрировать заем\n5. Все записи\n0. Выход\nВыберите: ";
    }

    void showAll() {
        cout << "\n=== ВСЕ ЗАПИСИ ===" << endl;

        auto authors = query("SELECT id, name, birth_year FROM authors ORDER BY name");
        cout << "\nАвторы (" << authors.size() << "):" << endl;
        for (auto& a : authors) cout << "ID: " << a[0] << " | " << a[1] << " | " << a[2] << endl;

        auto books = query("SELECT b.id, b.title, a.name, b.publication_year, b.genre FROM books b JOIN authors a ON b.author_id = a.id ORDER BY b.title");
        cout << "\nКниги (" << books.size() << "):" << endl;
        for (auto& b : books) cout << "ID: " << b[0] << " | " << b[1] << " | Автор: " << b[2] << " | " << b[3] << " | " << b[4] << endl;

        auto users = query("SELECT id, name, registration_date FROM users ORDER BY name");
        cout << "\nПользователи (" << users.size() << "):" << endl;
        for (auto& u : users) cout << "ID: " << u[0] << " | " << u[1] << " | " << u[2] << endl;

        auto borrowed = query("SELECT u.name, b.title, bb.borrow_date, bb.return_date FROM borrowed_books bb JOIN users u ON bb.user_id = u.id JOIN books b ON bb.book_id = b.id ORDER BY bb.borrow_date DESC");
        cout << "\nЗаймы (" << borrowed.size() << "):" << endl;
        for (auto& br : borrowed) cout << br[0] << " | " << br[1] << " | " << br[2] << " | " << br[3] << endl;
    }

public:
    LibrarySystem(const string& connStr) : db(connStr) {
        initDatabase();
    }

    void initDatabase() {
        try {
            work txn(*db.getConnection());
            txn.exec("CREATE TABLE IF NOT EXISTS authors (id SERIAL PRIMARY KEY, name VARCHAR(100), birth_year INT)");
            txn.exec("CREATE TABLE IF NOT EXISTS books (id SERIAL PRIMARY KEY, title VARCHAR(200), author_id INT REFERENCES authors(id), publication_year INT, genre VARCHAR(50))");
            txn.exec("CREATE TABLE IF NOT EXISTS users (id SERIAL PRIMARY KEY, name VARCHAR(100), registration_date DATE)");
            txn.exec("CREATE TABLE IF NOT EXISTS borrowed_books (user_id INT REFERENCES users(id), book_id INT REFERENCES books(id), borrow_date DATE, return_date DATE)");
            txn.commit();
        }
        catch (const exception& e) {
            cerr << "Ошибка инициализации: " << e.what() << endl;
        }
    }

    void run() {
        int choice;
        do {
            showMenu();
            cin >> choice;

            switch (choice) {
            case 1: {
                Author author(&db);
                string name; int year;
                cout << "Имя автора: "; cin.ignore(); getline(cin, name);
                cout << "Год рождения: "; cin >> year;
                author.add(name, year);
                break;
            }
            case 2: {
                Book book(&db);
                string title, genre; int author_id, year;
                cout << "Название: "; cin.ignore(); getline(cin, title);
                cout << "ID автора: "; cin >> author_id;
                cout << "Год издания: "; cin >> year;
                cout << "Жанр: "; cin.ignore(); getline(cin, genre);
                book.add(title, author_id, year, genre);
                break;
            }
            case 3: {
                User user(&db);
                string name, date;
                cout << "Имя: "; cin.ignore(); getline(cin, name);
                cout << "Дата (YYYY-MM-DD): "; cin >> date;
                user.add(name, date);
                break;
            }
            case 4: {
                BorrowedBook borrowed(&db);
                int user_id, book_id; string borrow_date, return_date;
                cout << "ID пользователя: "; cin >> user_id;
                cout << "ID книги: "; cin >> book_id;
                cout << "Дата взятия (YYYY-MM-DD): "; cin >> borrow_date;
                cout << "Дата возврата (YYYY-MM-DD): "; cin >> return_date;
                borrowed.add(user_id, book_id, borrow_date, return_date);
                break;
            }
            case 5:
                showAll();
                break;
            case 0:
                cout << "Выход" << endl;
                break;
            default:
                cout << "Неверный выбор" << endl;
            }
        } while (choice != 0);
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    try {
        LibrarySystem system("dbname=library user=postgres password=12345 host=localhost");
        system.run();
    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }
    return 0;
}