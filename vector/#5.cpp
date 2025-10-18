#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    vector<int> numbers = { 45, 12, 89, 3, 67, 23, 91, 5, 78, 34,
                          56, 19, 82, 7, 61, 29, 95, 14, 73, 41 };

    cout << "Исходный вектор: ";
    for_each(numbers.begin(), numbers.end(), [](int n) { cout << n << " "; });
    cout << endl << endl;

    // Минимум и максимум
    auto minmax = minmax_element(numbers.begin(), numbers.end());
    cout << "Min: " << *minmax.first << ", Max: " << *minmax.second << endl;

    // Среднее
    double avg = accumulate(numbers.begin(), numbers.end(), 0.0) / numbers.size();
    cout << "Среднее: " << avg << endl;

    // Медиана
    vector<int> sorted = numbers;
    sort(sorted.begin(), sorted.end());
    double median = sorted.size() % 2 ?
        sorted[sorted.size() / 2] :
        (sorted[sorted.size() / 2 - 1] + sorted[sorted.size() / 2]) / 2.0;
    cout << "Медиана: " << median << endl;

    return 0;
}