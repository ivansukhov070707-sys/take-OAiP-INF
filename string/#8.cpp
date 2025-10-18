#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Введите текст: ";
    getline(cin, s);

    // Первая буква заглавная
    s[0] = toupper(s[0]);

    for (int i = 1; i < s.size(); i++) {
        // После . ! ? следующую букву делаем заглавной
        if (s[i - 1] == '.' || s[i - 1] == '!' || s[i - 1] == '?') {
            s[i] = toupper(s[i]);
        }
        // Остальные буквы - строчные
        else {
            s[i] = tolower(s[i]);
        }
    }

    cout << s << endl;
    return 0;
}