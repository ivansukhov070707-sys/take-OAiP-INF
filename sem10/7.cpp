#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file("numbers.txt");

    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    int number;
    int count = 0;
    int sum = 0;

    while (file >> number) {
        count++;
        sum += number;
    }

    file.close();

    cout << "Количество чисел: " << count << endl;
    cout << "Сумма: " << sum << endl;

    if (count > 0) {
        double average = static_cast<double>(sum) / count;
        cout << "Среднее: " << average << endl;
    }
    else {
        cout << "Среднее: 0" << endl;
    }

    return 0;
}