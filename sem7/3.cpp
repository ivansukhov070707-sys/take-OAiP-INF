#include <iostream>
using namespace std;

void myStrCat(char* dest, const char* src) {
    // Находим конец первой строки
    int i = 0;
    while (dest[i] != '\0') {
        i++;
    }

    // Добавляем вторую строку
    int j = 0;
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0'; // не забываем про конец строки
}

int main() {
    char str1[200] = "Hello "; // место должно хватить для обеих строк
    char str2[100];

    cout << "Введите вторую строку: ";
    cin.getline(str2, 100);

    myStrCat(str1, str2);
    cout << "Результат: " << str1 << endl;

    return 0;
}