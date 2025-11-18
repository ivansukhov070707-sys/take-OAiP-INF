#include <iostream>
#include <cstring>
#include <algorithm>

// Функция сортировки слов в лексикографическом порядке
void sortWords(char** words, int count) {
    setlocale(LC_ALL, "RU");
    std::sort(words, words + count, [](const char* a, const char* b) {
        return strcmp(a, b) < 0;
        });
}