#include <iostream>
#include <cctype>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    char input[256];
    cout << "Введите строку из 10 слов: ";
    cin.getline(input, 256);

    char* words[10];
    int wordCount = 0;

    // Сохраняем копию строки для пункта 4
    char original[256];
    for (int i = 0; i < 256; i++) {
        original[i] = input[i];
        if (input[i] == '\0') break;
    }

    // Разбиваем строку на слова с помощью указателей
    char* current = input;
    while (*current && wordCount < 10) {
        // Пропускаем пробелы
        while (*current == ' ') current++;
        if (!*current) break;

        // Находим начало слова
        words[wordCount] = current;
        wordCount++;

        // Находим конец слова
        while (*current && *current != ' ') current++;
        if (*current) {
            *current = '\0';  // Заменяем пробел на конец строки
            current++;
        }
    }

    if (wordCount < 10) {
        cout << "Нужно 10 слов!" << endl;
        return 1;
    }

    // 1. Слова на 'a'
    int countA = 0;
    for (int i = 0; i < 10; i++) {
        if (tolower(words[i][0]) == 'a') countA++;
    }

    // 2. Самое короткое слово
    int minLen = 1000;
    for (int i = 0; i < 10; i++) {
        int len = 0;
        char* p = words[i];
        while (*p++) len++;
        if (len < minLen) minLen = len;
    }

    // 3. Буквы 'a' в последнем слове
    int lastWordA = 0;
    char* lastWord = words[9];
    while (*lastWord) {
        if (tolower(*lastWord) == 'a') lastWordA++;
        lastWord++;
    }

    // 4. В нижний регистр (работаем с копией original)
    char lowerStr[256];
    char* src = original;
    char* dst = lowerStr;
    while (*src) {
        *dst = tolower(*src);
        src++;
        dst++;
    }
    *dst = '\0';

    // 5. Слова где первый == последний
    int sameEnds = 0;
    for (int i = 0; i < 10; i++) {
        char* word = words[i];
        char first = tolower(*word);
        char* lastChar = word;
        while (*lastChar) lastChar++;
        lastChar--;
        if (first == tolower(*lastChar)) sameEnds++;
    }

    // 6. Самая короткая общая подстрока между двумя словами (упрощенная версия)
    char shortestSub[256] = "";
    int shortestLen = 1000;
    bool foundAny = false;

    // Перебираем все пары слов
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            char* word1 = words[i];
            char* word2 = words[j];

            // Перебираем все подстроки первого слова
            for (int start1 = 0; word1[start1] != '\0'; start1++) {
                for (int end1 = start1; word1[end1] != '\0'; end1++) {
                    int currentLen = end1 - start1 + 1;

                    // Пропускаем слишком длинные подстроки
                    if (currentLen >= shortestLen) continue;

                    // Проверяем, есть ли эта подстрока во втором слове
                    bool foundInSecond = false;

                    // Перебираем все позиции во втором слове
                    for (int start2 = 0; word2[start2] != '\0'; start2++) {
                        bool match = true;

                        // Сравниваем символы
                        for (int k = 0; k < currentLen; k++) {
                            // Если вышли за границы второго слова или символы не совпадают
                            if (word2[start2 + k] == '\0' ||
                                tolower(word1[start1 + k]) != tolower(word2[start2 + k])) {
                                match = false;
                                break;
                            }
                        }

                        if (match) {
                            foundInSecond = true;
                            break;
                        }
                    }

                    // Если нашли общую подстроку
                    if (foundInSecond) {
                        foundAny = true;
                        shortestLen = currentLen;

                        // Копируем подстроку вручную
                        int copyIndex = 0;
                        for (int k = start1; k <= end1; k++) {
                            shortestSub[copyIndex] = word1[k];
                            copyIndex++;
                        }
                        shortestSub[copyIndex] = '\0';  // Завершаем строку
                    }
                }
            }
        }
    }

    // Вывод результатов
    cout << "1. Слов на 'a': " << countA << endl;
    cout << "2. Длина самого короткого: " << minLen << endl;
    cout << "3. Букв 'a' в последнем слове: " << lastWordA << endl;
    cout << "4. Строка в нижнем регистре: " << lowerStr << endl;
    cout << "5. Слов с одинаковыми концами: " << sameEnds << endl;

    // Вывод результата 6-й задачи
    if (foundAny) {
        cout << "6. Самая короткая общая подстрока: '" << shortestSub
            << "' (длина: " << shortestLen << ")" << endl;
    }
    else {
        cout << "6. Общих подстрок не найдено" << endl;
    }

    return 0;
}
