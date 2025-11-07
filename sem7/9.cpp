#include <iostream>
using namespace std;

void removeSpaces(char* str) {
    char* read = str;  // читаем отсюда
    char* write = str; // пишем сюда

    while (*read != '\0') {
        if (*read != ' ') {
            *write = *read;
            write++;
        }
        read++;
    }
    *write = '\0'; // завершаем строку
}

int main() {
    char str[100];
    cout << "¬ведите строку с пробелами: ";
    cin.getline(str, 100);

    removeSpaces(str);
    cout << "Ѕез пробелов: " << str << endl;

    return 0;
}