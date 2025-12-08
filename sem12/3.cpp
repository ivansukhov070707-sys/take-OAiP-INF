#include <iostream>
#include <string>
using namespace std;

int main() {
    string titles[100], authors[100], genres[100];
    int years[100];
    int count = 0;
    int choice;

    do {
        cout << "\n1. Добавить\n2. Удалить\n3. Найти\n4. Все\n5. Выйти\nВыбор: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {  // Добавить
            if (count >= 100) {
                cout << "Библиотека полна!" << endl;
                break;
            }
            cout << "Название: "; getline(cin, titles[count]);
            cout << "Автор: "; getline(cin, authors[count]);
            cout << "Год: "; cin >> years[count]; cin.ignore();
            cout << "Жанр: "; getline(cin, genres[count]);
            count++;
            cout << "Добавлено!" << endl;
            break;
        }

        case 2: {  // Удалить
            string title;
            cout << "Название для удаления: "; getline(cin, title);
            bool found = false;
            for (int i = 0; i < count; i++) {
                if (titles[i] == title) {
                    for (int j = i; j < count - 1; j++) {
                        titles[j] = titles[j + 1];
                        authors[j] = authors[j + 1];
                        years[j] = years[j + 1];
                        genres[j] = genres[j + 1];
                    }
                    count--;
                    found = true;
                    cout << "Удалено!" << endl;
                    break;
                }
            }
            if (!found) cout << "Не найдено!" << endl;
            break;
        }

        case 3: {  // Найти по автору
            string author;
            cout << "Автор для поиска: "; getline(cin, author);
            bool found = false;
            for (int i = 0; i < count; i++) {
                if (authors[i] == author) {
                    cout << titles[i] << " (" << years[i] << "), " << genres[i] << endl;
                    found = true;
                }
            }
            if (!found) cout << "Не найдено!" << endl;
            break;
        }

        case 4: {  // Показать все
            if (count == 0) {
                cout << "Библиотека пуста!" << endl;
                break;
            }
            for (int i = 0; i < count; i++) {
                cout << i + 1 << ". " << titles[i] << " - " << authors[i]
                    << " (" << years[i] << ") - " << genres[i] << endl;
            }
            break;
        }

        case 5: {
            cout << "Выход..." << endl;
            break;
        }

        default: {
            cout << "Неверный выбор!" << endl;
        }
        }
    } while (choice != 5);

    return 0;
}