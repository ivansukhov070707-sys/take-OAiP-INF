#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream logFile("application.log");
    if (!logFile.is_open()) {
        cout << "Ошибка открытия файла application.log!" << endl;
        return 1;
    }

    const long long PART_SIZE = 1024 * 1024;
    vector<string> partFiles;
    int partNumber = 1;
    long long currentSize = 0;

    string currentPartName = "log_part1.txt";
    ofstream currentPart(currentPartName);
    partFiles.push_back(currentPartName);

    string line;
    while (getline(logFile, line)) {
        long long lineSize = line.length() + 1;

        if (currentSize + lineSize > PART_SIZE && currentSize > 0) {
            currentPart.close();
            partNumber++;
            currentPartName = "log_part" + to_string(partNumber) + ".txt";
            currentPart.open(currentPartName);
            partFiles.push_back(currentPartName);
            currentSize = 0;
        }

        currentPart << line << endl;
        currentSize += lineSize;
    }

    currentPart.close();
    logFile.close();

    ofstream indexFile("log_index.txt");
    indexFile << "Индекс файлов лога:" << endl;
    for (size_t i = 0; i < partFiles.size(); i++) {
        indexFile << "Часть " << (i + 1) << ": " << partFiles[i] << endl;
    }
    indexFile.close();

    cout << "Лог-файл разделен на " << partFiles.size() << " частей." << endl;
    cout << "Информация о частях сохранена в log_index.txt" << endl;

    return 0;
}