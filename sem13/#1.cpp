#include <iostream>
#include <string>

using namespace std;

// Базовый класс Publication
class Publication {
protected:
    string title;  // Название публикации

public:
    Publication(const string& t) : title(t) {}
};

// Производный класс Book
class Book : public Publication {
private:
    string author;  // Автор книги
    int year;       // Год выпуска

public:
    // Конструктор с параметрами
    Book(const string& t, const string& a, int y)
        : Publication(t), author(a), year(y) {
    }

    // Метод для вывода информации о книге
    void displayInfo() {
        cout << "Название: " << title
            << ", Автор: " << author
            << ", Год выпуска: " << year << endl;
    }
};

int main() {
    // Создаем объект книги
    Book book("Война и мир", "Лев Толстой", 1869);

    // Выводим информацию о книге
    book.displayInfo();

    return 0;
}