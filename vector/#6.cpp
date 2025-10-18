#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Создаем вектор из 20 чисел (с повторениями)
    vector<int> numbers = { 7, 3, 5, 7, 2, 8, 1, 7, 4, 6,
                          9, 3, 5, 2, 8, 1, 4, 6, 9, 7 };

    // Выводим исходный вектор
    cout << "Исходный вектор: ";
    for_each(numbers.begin(), numbers.end(), [](int n) {
        cout << n << " ";
        });
    cout << endl << endl;

    // 1. Проверяем, есть ли число 7 с помощью find
    auto found = find(numbers.begin(), numbers.end(), 7);
    if (found != numbers.end()) {
        cout << "Число 7 найдено на позиции: " << distance(numbers.begin(), found) << endl;
    }
    else {
        cout << "Число 7 не найдено" << endl;
    }

    // Подсчитываем количество семерок
    int count_7 = count(numbers.begin(), numbers.end(), 7);
    cout << "Количество чисел 7 в векторе: " << count_7 << endl << endl;

    // 2. Удаляем все повторяющиеся числа (sort + unique)

    // Сначала сортируем вектор
    sort(numbers.begin(), numbers.end());

    cout << "После сортировки: ";
    for_each(numbers.begin(), numbers.end(), [](int n) { cout << n << " "; });
    cout << endl;

    // Затем используем unique для удаления дубликатов
    auto unique_end = unique(numbers.begin(), numbers.end());

    // Удаляем "хвост" с дубликатами
    numbers.erase(unique_end, numbers.end());

    // 3. Выводим оставшиеся элементы
    cout << "После удаления дубликатов: ";
    for_each(numbers.begin(), numbers.end(), [](int n) {
        cout << n << " ";
        });
    cout << endl;

    cout << "Осталось уникальных элементов: " << numbers.size() << endl;

    return 0;
}