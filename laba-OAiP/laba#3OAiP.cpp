#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Book {
    string title;
    string author;
    int year;
};

void addBooks() {
    ofstream file("books.txt", ios::app);
    if (!file.is_open()) {
        cout << "File opening error!" << endl;
        return;
    }

    cout << "Adding books (an empty line to complete):" << endl;

    while (true) {
        Book book;
        cout << "Name: ";
        getline(cin, book.title);

        if (book.title.empty()) break;

        cout << "Autor: ";
        getline(cin, book.author);

        cout << "Год: ";
        cin >> book.year;
        cin.ignore();

        file << book.title << "|" << book.author << "|" << book.year << endl;
        cout << "The book has been added!" << endl;
    }

    file.close();
}

void searchBook() {
    string searchTitle;
    cout << "Enter a name for the search: ";
    getline(cin, searchTitle);

    ifstream file("books.txt");
    if (!file.is_open()) {
        cout << "File not found!" << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(file, line)) {
        size_t pos1 = line.find('|');
        string title = line.substr(0, pos1);

        if (title.find(searchTitle) != string::npos) {
            size_t pos2 = line.find('|', pos1 + 1);
            string author = line.substr(pos1 + 1, pos2 - pos1 - 1);
            string year = line.substr(pos2 + 1);

            cout << "Found: " << title << " | " << author << " | " << year << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Book not found!" << endl;
    }

    file.close();
}

void sortBooks() {
    ifstream file("books.txt");
    if (!file.is_open()) {
        cout << "File not found!" << endl;
        return;
    }

    vector<Book> books;
    string line;

    while (getline(file, line)) {
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);

        Book book;
        book.title = line.substr(0, pos1);
        book.author = line.substr(pos1 + 1, pos2 - pos1 - 1);
        book.year = stoi(line.substr(pos2 + 1));

        books.push_back(book);
    }
    file.close();
    cout << "Sorting (autor(1), year(2)): ";
    int choice;
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
            return a.author < b.author;
            });
    }
    else if (choice == 2) {
        sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
            return a.year < b.year;
            });
    }

    ofstream outFile("books.txt");
    for (const auto& book : books) {
        outFile << book.title << "|" << book.author << "|" << book.year << endl;
    }
    outFile.close();

    cout << "Books are sorted!" << endl;
}

void addSingleBook() {
    ofstream file("books.txt", ios::app);
    if (!file.is_open()) {
        cout << "File opening error!" << endl;
        return;
    }

    Book book;
    cout << "Adding a new book:" << endl;
    cout << "Name: ";
    getline(cin, book.title);
    cout << "Autor: ";
    getline(cin, book.author);
    cout << "Year: ";
    cin >> book.year;
    cin.ignore();

    file << book.title << "|" << book.author << "|" << book.year << endl;
    file.close();

    cout << "The book has been added!" << endl;
}

void findBooksByYear() {
    int Year;
    cout << "Enter the year: ";
    cin >> Year;
    cin.ignore();

    ifstream file("books.txt");
    if (!file.is_open()) {
        cout << "File not found!" << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(file, line)) {
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);
        int year = stoi(line.substr(pos2 + 1));

        if (year <= maxYear) {
            string title = line.substr(0, pos1);
            string author = line.substr(pos1 + 1, pos2 - pos1 - 1);
            cout << title << " | " << author << " | " << year << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Books not found!" << endl;
    }

    file.close();
}

void logToOutput(const string& message) {
    ofstream file("output.txt", ios::app);
    file << message << endl;
    file.close();
}

void showMenu() {
    cout << "\nLibrary" << endl;
    cout << "1. Add books" << endl;
    cout << "2. Name search" << endl;
    cout << "3. Sorting" << endl;
    cout << "4. Add one book" << endl;
    cout << "5. Search by year" << endl;
    cout << "0. Exit" << endl;
    cout << "Choice: ";
}

int main() {
    // Очистка output.txt при запуске
    ofstream clearFile("output.txt");
    clearFile.close();

    int choice;

    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            addBooks();
            logToOutput("The user added books");
            break;
        case 2:
            searchBook();
            logToOutput("The user was looking for a book");
            break;
        case 3:
            sortBooks();
            logToOutput("The user was sorting books");
            break;
        case 4:
            addSingleBook();
            logToOutput("The user added one book");
            break;
        case 5:
            findBooksByYear();
            logToOutput("The user searched for books by year");
            break;
        case 0:
            cout << "Exit!" << endl;
            logToOutput("The user has logged out of the program");
            break;
        default:
            cout << "Wrong choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}