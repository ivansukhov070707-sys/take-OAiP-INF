#include <iostream>
#include <cctype>
using namespace std;

bool isPalindrome(const char* str) {
    const char* start = str;
    const char* end = str;

    // находим конец строки
    while (*end != '\0') {
        end++;
    }
    end--; // отступаем от '\0'

    while (start < end) {
        // пропускаем не-буквы
        while (start < end && !isalnum(*start)) start++;
        while (start < end && !isalnum(*end)) end--;

        if (tolower(*start) != tolower(*end)) {
            return false;
        }

        start++;
        end--;
    }
    return true;
}

int main() {
    char str[100];
    cout << "Введите строку: ";
    cin.getline(str, 100);

    if (isPalindrome(str)) {
        cout << "Это палиндром!" << endl;
    }
    else {
        cout << "Это не палиндром" << endl;
    }

    return 0;
}