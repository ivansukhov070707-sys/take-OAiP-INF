#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    // Давление в трубопроводе (50 измерений)
    vector<double> pressure = { 5.2, 3.8, 7.1, 9.5, 2.3, 8.9, 4.7, 6.4, 1.8, 10.2,
                              3.5, 7.8, 5.9, 8.3, 2.7, 9.1, 4.3, 6.8, 1.5, 11.8,
                              5.7, 3.2, 7.9, 8.7, 2.9, 9.8, 4.1, 6.3, 1.9, 12.5,
                              5.4, 3.7, 7.3, 8.1, 2.5, 9.3, 4.9, 6.7, 1.7, -2.1,
                              5.8, 3.9, 7.5, 8.5, 2.8, 9.7, 4.5, 6.9, 1.6, 13.2 };

    // Удаляем ошибочные значения (< 0 или > 12)
    pressure.erase(
        remove_if(pressure.begin(), pressure.end(),
            [](double p) { return p < 0 || p > 12; }),
        pressure.end()
    );

    // Среднее давление
    double avg = accumulate(pressure.begin(), pressure.end(), 0.0) / pressure.size();
    cout << "Среднее давление: " << avg << " бар" << endl;

    // Минимальное и максимальное давление
    auto minmax = minmax_element(pressure.begin(), pressure.end());
    cout << "Мин: " << *minmax.first << " бар, Макс: " << *minmax.second << " бар" << endl;

    // Значения > 8 бар
    cout << "Давление > 8 бар: ";
    for_each(pressure.begin(), pressure.end(), [](double p) {
        if (p > 8) cout << p << " ";
        });

    return 0;
}