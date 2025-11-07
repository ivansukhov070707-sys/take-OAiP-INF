#include <iostream>
using namespace std;

int myStrCmp(const char* s1, const char* s2) {
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2) {
            return *s1 - *s2;
        }
        s1++;
        s2++;
    }

    // Если одна строка закончилась раньше
    return *s1 - *s2;
}

int main() {
    char str1[100], str2[100];

    cout << "Введите первую строку: ";
    cin.getline(str1, 100);
    cout << "Введите вторую строку: ";
    cin.getline(str2, 100);

    int result = myStrCmp(str1, str2);

    if (result == 0) {
        cout << "Строки равны" << endl;
    }
    else if (result < 0) {
        cout << "Первая строка меньше второй" << endl;
    }
    else {
        cout << "Первая строка больше второй" << endl;
    }

    cout << "Результат сравнения: " << result << endl;

    return 0;
}