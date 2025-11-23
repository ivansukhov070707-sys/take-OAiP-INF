#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    fstream configFile("config.txt", ios::in | ios::out);
    if (!configFile.is_open()) {
        cout << "Ошибка открытия файла config.txt!" << endl;
        return 1;
    }
    string searchKey;
    cout << "Введите параметр для изменения (например: timeout): ";
    cin >> searchKey;
    searchKey += "=";
    string newValue;
    cout << "Введите новое значение: ";
    cin >> newValue;

    vector<string> lines;
    string line;
    bool parameterFound = false;
    int lineNumber = -1;

    while (getline(configFile, line)) {
        lines.push_back(line);
        if (line.find(searchKey) == 0) {
            parameterFound = true;
            lineNumber = lines.size() - 1;
        }
    }
    if (!parameterFound) {
        cout << "Параметр '" << searchKey << "' не найден в файле!" << endl;
        configFile.close();
        return 1;
    }
    string oldLine = lines[lineNumber];
    size_t equalsPos = oldLine.find('=');
    if (equalsPos != string::npos) {
        string newLine = oldLine.substr(0, equalsPos + 1) + newValue;
        lines[lineNumber] = newLine;
    }
    configFile.clear();
    configFile.seekp(0);
    for (const string& currentLine : lines) {
        configFile << currentLine << endl;
    }

    configFile.close();

    ofstream truncateFile("config.txt", ios::app);
    truncateFile.close();

    cout << "Параметр успешно изменен!" << endl;
    cout << "Было: " << oldLine << endl;
    cout << "Стало: " << lines[lineNumber] << endl;

    return 0;
}