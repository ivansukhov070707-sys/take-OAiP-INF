#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file1("file1.txt");
    ifstream file2("file2.txt");

    if (!file1.is_open() || !file2.is_open()) {
        cout << "Ошибка открытия файлов!" << endl;
        return 1;
    }

    string line1, line2;
    bool identical = true;

    while (getline(file1, line1) && getline(file2, line2)) {
        if (line1 != line2) {
            identical = false;
            break;
        }
    }

    if (identical && file1.eof() && file2.eof()) {
        cout << "Файлы идентичны." << endl;
    }
    else {
        cout << "Файлы различаются." << endl;
    }

    file1.close();
    file2.close();

    return 0;
}