#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void createConfig() {
    ofstream file("config.json");
    file << "{\n";
    file << "  \"app_name\": \"My Application\",\n";
    file << "  \"version\": \"1.0.0\",\n";
    file << "  \"settings\": {\n";
    file << "    \"max_connections\": 100,\n";
    file << "    \"timeout\": 30,\n";
    file << "    \"debug_mode\": true\n";
    file << "  },\n";
    file << "  \"database\": {\n";
    file << "    \"host\": \"localhost\",\n";
    file << "    \"port\": 5432,\n";
    file << "    \"username\": \"admin\"\n";
    file << "  }\n";
    file << "}";
    file.close();
    cout << "Конфигурационный файл создан\n";
}

void readConfig() {
    ifstream file("config.json");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла config.json!" << endl;
        return;
    }

    string line;
    cout << "Содержимое config.json:" << endl;
    cout << "========================" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void updateConfig() {
    ifstream inFile("config.json");
    if (!inFile.is_open()) {
        cout << "Ошибка открытия файла config.json!" << endl;
        return;
    }

    vector<string> lines;
    string line;
    while (getline(inFile, line)) {
        lines.push_back(line);
    }
    inFile.close();

    string settingKey;
    string newValue;
    cout << "Введите название настройки для изменения (например: timeout): ";
    cin >> settingKey;
    cout << "Введите новое значение: ";
    cin >> newValue;

    bool found = false;
    for (string& currentLine : lines) {
        if (currentLine.find("\"" + settingKey + "\"") != string::npos) {
            size_t colonPos = currentLine.find(':');
            if (colonPos != string::npos) {
                string beforeColon = currentLine.substr(0, colonPos + 1);
                string afterColon = currentLine.substr(colonPos + 1);

                size_t valueStart = afterColon.find_first_not_of(" ");
                if (valueStart != string::npos) {
                    string newLine = beforeColon + " " + newValue;
                    if (currentLine.find(',') != string::npos) {
                        newLine += ",";
                    }
                    currentLine = newLine;
                    found = true;
                    break;
                }
            }
        }
    }

    if (found) {
        ofstream outFile("config.json");
        for (const string& currentLine : lines) {
            outFile << currentLine << endl;
        }
        outFile.close();
        cout << "Настройка '" << settingKey << "' успешно изменена на '" << newValue << "'" << endl;
    }
    else {
        cout << "Настройка '" << settingKey << "' не найдена!" << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\nМеню работы с конфигурацией:" << endl;
        cout << "1 - Создать конфигурационный файл" << endl;
        cout << "2 - Просмотреть конфигурацию" << endl;
        cout << "3 - Изменить настройку" << endl;
        cout << "0 - Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            createConfig();
            break;
        case 2:
            readConfig();
            break;
        case 3:
            updateConfig();
            break;
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный выбор!" << endl;
        }
    } while (choice != 0);

    return 0;
}