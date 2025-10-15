#include <iostream>
#include <cctype>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    char input[256];
    cout << "������� ������ �� 10 ����: ";
    cin.getline(input, 256);

    char* words[10];
    int wordCount = 0;

    // ��������� ����� ������ ��� ������ 4
    char original[256];
    for (int i = 0; i < 256; i++) {
        original[i] = input[i];
        if (input[i] == '\0') break;
    }

    // ��������� ������ �� ����� � ������� ����������
    char* current = input;
    while (*current && wordCount < 10) {
        // ���������� �������
        while (*current == ' ') current++;
        if (!*current) break;

        // ������� ������ �����
        words[wordCount] = current;
        wordCount++;

        // ������� ����� �����
        while (*current && *current != ' ') current++;
        if (*current) {
            *current = '\0';  // �������� ������ �� ����� ������
            current++;
        }
    }

    if (wordCount < 10) {
        cout << "����� 10 ����!" << endl;
        return 1;
    }

    // 1. ����� �� 'a'
    int countA = 0;
    for (int i = 0; i < 10; i++) {
        if (tolower(words[i][0]) == 'a') countA++;
    }

    // 2. ����� �������� �����
    int minLen = 1000;
    for (int i = 0; i < 10; i++) {
        int len = 0;
        char* p = words[i];
        while (*p++) len++;
        if (len < minLen) minLen = len;
    }

    // 3. ����� 'a' � ��������� �����
    int lastWordA = 0;
    char* lastWord = words[9];
    while (*lastWord) {
        if (tolower(*lastWord) == 'a') lastWordA++;
        lastWord++;
    }

    // 4. � ������ ������� (�������� � ������ original)
    char lowerStr[256];
    char* src = original;
    char* dst = lowerStr;
    while (*src) {
        *dst = tolower(*src);
        src++;
        dst++;
    }
    *dst = '\0';

    // 5. ����� ��� ������ == ���������
    int sameEnds = 0;
    for (int i = 0; i < 10; i++) {
        char* word = words[i];
        char first = tolower(*word);
        char* lastChar = word;
        while (*lastChar) lastChar++;
        lastChar--;
        if (first == tolower(*lastChar)) sameEnds++;
    }

    // ����� �����������
    cout << "1. ���� �� 'a': " << countA << endl;
    cout << "2. ����� ������ ���������: " << minLen << endl;
    cout << "3. ���� 'a' � ��������� �����: " << lastWordA << endl;
    cout << "4. ������ � ������ ��������: " << lowerStr << endl;
    cout << "5. ���� � ����������� �������: " << sameEnds << endl;

    return 0;
}