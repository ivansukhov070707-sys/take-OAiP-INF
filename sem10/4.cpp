#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream sourceFile("source.txt");
    if (!sourceFile.is_open()) {
        cout << "Ошибка: не удалось открыть файл source.txt" << endl;
        return 1;
    }
    ofstream copyFile("copy.txt");
    if (!copyFile.is_open()) {
        cout << "Ошибка: не удалось создать файл copy.txt" << endl;
        sourceFile.close();
        return 1;
    }

    string line;
    int lineCount = 0;
    while (getline(sourceFile, line)) {
        copyFile << line << endl;
        lineCount++;
    }
    sourceFile.close();
    copyFile.close();
    cout << "Файл успешно скопирован." << endl;
    cout << "Количество скопированных строк: " << lineCount << endl;

    return 0;
}