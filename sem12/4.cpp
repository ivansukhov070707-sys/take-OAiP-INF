#include <iostream>
using namespace std;

union Variant {
    int i;
    double d;
    char c;
};

int main() {
    Variant var;
    char type;
    bool valid = true;

    do {
        cout << "Тип (i-int, d-double, c-char): ";
        cin >> type;

        switch (type) {
        case 'i':
            cout << "Целое число: ";
            if (!(cin >> var.i)) {
                cout << "Ошибка ввода!" << endl;
                cin.clear();
                valid = false;
            }
            else {
                cout << "int: " << var.i << endl;
            }
            break;

        case 'd':
            cout << "Дробное число: ";
            if (!(cin >> var.d)) {
                cout << "Ошибка ввода!" << endl;
                cin.clear();
                valid = false;
            }
            else {
                cout << "double: " << var.d << endl;
            }
            break;

        case 'c':
            cout << "Символ: ";
            if (!(cin >> var.c)) {
                cout << "Ошибка ввода!" << endl;
                cin.clear();
                valid = false;
            }
            else {
                cout << "char: " << var.c << endl;
            }
            break;

        default:
            cout << "Неверный тип!" << endl;
            valid = false;
        }
        cin.ignore(); // Очистка буфера

        cout << "\nПродолжить? (y/n): ";
        char cont;
        cin >> cont;
        if (cont != 'y') break;

    } while (true);

    return 0;
}