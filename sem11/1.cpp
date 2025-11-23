#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main() {
    ifstream bookFile("book.txt");
    if (!bookFile.is_open()) {
        cout << "Ошибка открытия файла book.txt!" << endl;
        return 1;
    }
    string searchWord;
    cout << "Введите слово для поиска: ";
    cin >> searchWord;

    vector<pair<int, int>> positions;
    string line;
    int lineNumber = 0;
    int totalCount = 0;

    while (getline(bookFile, line)) {
        lineNumber++;
        size_t pos = 0;
        while ((pos = line.find(searchWord, pos)) != string::npos) {
            positions.push_back(make_pair(lineNumber, static_cast<int>(pos + 1)));
            totalCount++;
            pos += searchWord.length();
        }
    }
    bookFile.close();
    ofstream resultFile("search_results.txt");
    if (!resultFile.is_open()) {
        cout << "Ошибка создания файла результатов!" << endl;
        return 1;
    }
    resultFile << "Результаты поиска слова: \"" << searchWord << "\"" << endl;
    resultFile << "Общее количество найденных вхождений: " << totalCount << endl;
    for (const auto& position : positions) {
        resultFile << "Строка " << position.first << ", позиция " << position.second
            << ": " << searchWord << endl;
    }

    resultFile.close();
    cout << "Поиск завершен!" << endl;
    cout << "Найдено вхождений: " << totalCount << endl;
    cout << "Результаты сохранены в файл search_results.txt" << endl;

    return 0;
}