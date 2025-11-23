#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream file("output.txt");

    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    string line;

    cout << "Введите строки (пустая строка завершает ввод):" << endl;

    while (true) {
        getline(cin, line);

        if (line.empty()) {
            break;
        }

        file << line << endl;
    }

    file.close();

    cout << "Данные записаны в файл output.txt." << endl;

    return 0;
}