#include <iostream>
#include <cctype>
#include <cstring>
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

    // 6. Самая короткая общая подстрока между двумя словами
    char shortestSub[256] = "";  // Для хранения самой короткой подстроки
    int shortestLen = 1000;      // Длина самой короткой подстроки
    
    // Перебираем все пары слов
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            char* word1 = words[i];  // Первое слово пары
            char* word2 = words[j];  // Второе слово пары
            
            // Перебираем все возможные подстроки первого слова
            for (int start = 0; word1[start] != '\0'; start++) {
                for (int end = start; word1[end] != '\0'; end++) {
                    int subLen = end - start + 1;  // Длина текущей подстроки
                    
                    // Пропускаем если подстрока длиннее уже найденной самой короткой
                    if (subLen >= shortestLen) continue;
                    
                    // Создаем временную подстроку
                    char tempSub[256];
                    int pos = 0;
                    for (int k = start; k <= end; k++) {
                        tempSub[pos++] = word1[k];
                    }
                    tempSub[pos] = '\0';  // Завершаем строку
                    
                    // Проверяем, содержится ли эта подстрока во втором слове
                    bool found = false;
                    for (int m = 0; word2[m] != '\0'; m++) {
                        bool match = true;
                        // Проверяем совпадение символов
                        for (int n = 0; n < subLen; n++) {
                            if (word2[m + n] == '\0' || 
                                tolower(word1[start + n]) != tolower(word2[m + n])) {
                                match = false;
                                break;
                            }
                        }
                        if (match) {
                            found = true;
                            break;
                        }
                    }
                    
                    // Если нашли общую подстроку и она короче текущей самой короткой
                    if (found && subLen < shortestLen) {
                        shortestLen = subLen;
                        strcpy(shortestSub, tempSub);  // Копируем найденную подстроку
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
    if (shortestLen < 1000) {
        cout << "6. Самая короткая общая подстрока: '" << shortestSub 
             << "' (длина: " << shortestLen << ")" << endl;
    } else {
        cout << "6. Общих подстрок не найдено" << endl;
    }

    return 0;
}
