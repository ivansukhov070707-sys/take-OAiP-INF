#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    // Потребление за 24 часа
    vector<double> consumption = { 150, 180, 200, 220, 250, 300, 350, 400, 450, 420,
                                 380, 350, 320, 300, 280, 260, 240, 220, 200, 180,
                                 160, 140, 120, 100 };

    // Суммарное и среднее потребление
    double total = accumulate(consumption.begin(), consumption.end(), 0.0);
    double average = total / consumption.size();
    cout << "Суммарное: " << total << " кВт·ч, Среднее: " << average << " кВт·ч" << endl;

    // Час пикового потребления
    auto max_it = max_element(consumption.begin(), consumption.end());
    int peak_hour = max_it - consumption.begin();
    cout << "Пиковое потребление: " << *max_it << " кВт·ч (час " << peak_hour << ")" << endl;

    // Отклонение от среднего
    vector<double> deviations(24);
    transform(consumption.begin(), consumption.end(), deviations.begin(),
        [average](double c) { return c - average; });

    // Топ-5 минимальных часов
    vector<double> sorted = consumption;
    sort(sorted.begin(), sorted.end());
    cout << "Топ-5 минимальных: ";
    for (int i = 0; i < 5; i++) cout << sorted[i] << " ";

    return 0;
}