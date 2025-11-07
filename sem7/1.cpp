#include <iostream>
using namespace std;

int myStrLen(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int main() {
    char text[100];
    cout << "¬ведите строку: ";
    cin.getline(text, 100);

    int len = myStrLen(text);
    cout << "ƒлина строки: " << len << endl;

    return 0;
}