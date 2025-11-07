#include <iostream>
using namespace std;

int main() {
    char str[100];
    char target;

    cout << "Введите строку: ";
    cin.getline(str, 100);
    cout << "Введите символ для поиска: ";
    cin >> target;

    int count = 0;
    char* ptr = str; // указатель на начало строки

    while (*ptr != '\0') {
        if (*ptr == target) {
            count++;
        }
        ptr++; // двигаем указатель
    }

    cout << "Символ '" << target << "' встречается " << count << " раз" << endl;

    return 0;
}