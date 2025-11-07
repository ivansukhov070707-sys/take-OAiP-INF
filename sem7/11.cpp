#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    int sum = 0;
    int* p = &numbers[0]; // указатель на первый элемент

    for (int i = 0; i < numbers.size(); i++) {
        sum += *p; // добавляем значение
        p++;       // переходим к следующему элементу
    }

    cout << "Сумма элементов: " << sum << endl;

    return 0;
}