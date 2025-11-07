#include <iostream>
using namespace std;

int main() {
    char str[100];
    cout << "Введите строку: ";
    cin.getline(str, 100);

    char* ptr = str;

    while (*ptr != '\0') {
        if (*ptr == ' ') {
            *ptr = '_'; // заменяем пробел на подчёркивание
        }
        ptr++;
    }

    cout << "Результат: " << str << endl;

    return 0;
}