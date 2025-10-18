#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numbers = { 45, 12, 89, 3, 67, 23, 91, 5, 78, 34, 56, 19, 82, 7, 61, 29, 95, 14, 73, 41 };

    cout << "Вектор: ";
    for_each(numbers.begin(), numbers.end(), [](int n) { cout << n << " "; });
    cout << endl;

    // Поиск максимума с лямбдой-компаратором
    auto max_iterator = max_element(numbers.begin(), numbers.end(),
        [](int x, int y) -> bool {
            return x < y;
        }
    );

    if (max_iterator != numbers.end()) {
        cout << "Максимальное значение: " << *max_iterator << endl;
        cout << "Находится на позиции: " << (max_iterator - numbers.begin()) << endl;
    }

    return 0;
}