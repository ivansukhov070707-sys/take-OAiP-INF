#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int numbers[] = { 15, 23, 7, 42, 18, 91, 3, 56, 77, 10 };
    const int SIZE = 10;

    ofstream outFile("numbers.bin", ios::binary);
    if (!outFile) {
        cout << "Ошибка создания файла!" << endl;
        return 1;
    }

    outFile.write(reinterpret_cast<char*>(numbers), sizeof(numbers));
    outFile.close();

    ifstream inFile("numbers.bin", ios::binary);
    if (!inFile) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    inFile.seekg(0, ios::end);
    size_t file_size = inFile.tellg();
    inFile.seekg(0, ios::beg);

    int buffer[SIZE];
    inFile.read(reinterpret_cast<char*>(buffer), sizeof(buffer));
    inFile.close();

    cout << "Прочитанные числа: ";
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        cout << buffer[i] << " ";
        sum += buffer[i];
    }
    cout << endl;

    cout << "Размер файла: " << file_size << " байт" << endl;
    cout << "Сумма чисел: " << sum << endl;

    return 0;
}