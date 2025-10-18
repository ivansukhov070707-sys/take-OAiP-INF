#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    string stroka;
    cout << "Введите строку: ";  // убрал endl для красоты
    getline(cin, stroka);

    // Удаление знаков препинания и пробелов, перевод в нижний регистр
    string cleaned;
    for (char c : stroka) {
        if (isalnum(c)) {
            cleaned += tolower(c);
        }
    }

    // Разворот строки
    string reversed = cleaned;
    reverse(reversed.begin(), reversed.end());

    // Проверка палиндрома
    if (cleaned == reversed) {
        cout << "Строка является палиндромом" << endl;
    }
    else {
        cout << "Строка не является палиндромом" << endl;
    }

    return 0;
}