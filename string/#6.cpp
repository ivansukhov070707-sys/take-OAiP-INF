#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int n;

    cout << "Текст: ";
    getline(cin, s);
    cout << "Сдвиг: ";
    cin >> n;

    for (char& c : s) {
        if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' + n) % 26 + 'A';
        }
        else if (c >= 'a' && c <= 'z') {
            c = (c - 'a' + n) % 26 + 'a';
        }
    }

    cout << "Результат: " << s << endl;
    return 0;
}