#include <iostream>
using namespace std;

const char* findSubstring(const char* text, const char* word) {
    const char* t = text;

    while (*t != '\0') {
        const char* t1 = t;
        const char* w = word;

        // Проверяем совпадение
        while (*w != '\0' && *t1 == *w) {
            t1++;
            w++;
        }

        // Если дошли до конца слова - нашли подстроку
        if (*w == '\0') {
            return t;
        }

        t++;
    }

    return nullptr;
}

int main() {
    char text[100];
    char word[100];

    cout << "Введите строку: ";
    cin.getline(text, 100);
    cout << "Введите подстроку для поиска: ";
    cin.getline(word, 100);

    const char* result = findSubstring(text, word);

    if (result != nullptr) {
        cout << "Подстрока найдена на позиции: " << (result - text) << endl;
        cout << "Фрагмент: " << result << endl;
    }
    else {
        cout << "Подстрока не найдена" << endl;
    }

    return 0;
}