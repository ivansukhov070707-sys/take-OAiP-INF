#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    // Создаем вектор из 10 элементов
    vector<int> n(10);

    // Заполняем числами от 1 до 10
    int a = 1;
    for_each(n.begin(), n.end(), [&a](int& s) {
        s = a++;
        });

    // Выводим с помощью for_each и лямбда-функции
    cout << "Вектор чисел от 1 до 10: ";
    for_each(n.begin(), n.end(), [](int n) {cout << n << " ";});
    cout << endl;

    return 0;
}