#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file("input.txt");

    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    char ch;
    int count = 0;

    while (file.get(ch)) {
        count++;
    }

    file.close();

    cout << "Количество символов в файле: " << count << endl;

    return 0;
}