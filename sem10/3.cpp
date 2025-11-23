#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file("text.txt");
    if (!file.is_open()) {
        cout << "Ошибка: не удалось открыть файл text.txt" << endl;
        return 1;
    }
    string word;
    int wordCount = 0;
    while (file >> word) {
        wordCount++;
    }
    file.close();
    cout << "Количество слов в файле: " << wordCount << endl;
    return 0;
}