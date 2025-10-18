#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    string str;
    cout << "Введите строку: ";  // убрал endl для компактности
    getline(cin, str);

    // Удаление цифр и создание новой строки
    string without_digits;
    for (char c : str) {
        if (!isdigit(c)) {  // более привычная запись
            without_digits += c;
        }
    }

    // Вывод результата
    cout << "Строка без цифр: " << without_digits << endl;

    return 0;
}