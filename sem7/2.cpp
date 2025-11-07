#include <iostream>
using namespace std;

void myStrCopy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // не забываем про конец строки
}

int main() {
    char source[100];
    char destination[100];

    cout << "¬ведите строку: ";
    cin.getline(source, 100);

    myStrCopy(destination, source);
    cout << "—копированна€ строка: " << destination << endl;

    return 0;
}