#include <iostream>
using namespace std;

void reverse(char* str) {
    char* start = str;      // указатель на начало
    char* end = str;        // указатель на конец

    // находим конец строки
    while (*end != '\0') {
        end++;
    }
    end--; // отступаем от '\0'

    // мен€ем символы местами
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main() {
    char str[100];
    cout << "¬ведите строку: ";
    cin.getline(str, 100);

    reverse(str);
    cout << "ѕеревернута€ строка: " << str << endl;

    return 0;
}