#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Создаем вектор из 10 чисел
    setlocale(LC_ALL, "RU");
    vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Выводим исходный вектор
    cout << "Исходный вектор: ";
    for_each(numbers.begin(), numbers.end(), [](int n) {
        cout << n << " ";
        });
    cout << endl;

    // Умножаем каждый элемент на 2 с помощью for_each и лямбда-функции
    for_each(numbers.begin(), numbers.end(), [](int& n) {
        n = n * 2;
        });

    // Выводим результат
    cout << "После умножения на 2: ";
    for_each(numbers.begin(), numbers.end(), [](int n) {
        cout << n << " ";
        });
    cout << endl;

    return 0;
}