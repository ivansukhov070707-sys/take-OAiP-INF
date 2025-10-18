#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    // Потребление за 30 дней
    vector<double> energy = { 150, 200, 180, 220, 190, 210, 170, 230, 160, 240,
                            250, 195, 205, 175, 225, 185, 215, 165, 235, 155,
                            245, 200, 180, 220, 190, 210, 170, 230, 160, 240 };

    // Общее потребление
    double total = accumulate(energy.begin(), energy.end(), 0.0);
    cout << "Общее потребление: " << total << " кВт·ч" << endl;

    // Среднесуточное
    double avg = total / energy.size();
    cout << "Среднесуточное: " << avg << " кВт·ч" << endl;

    // Максимальное и минимальное
    auto min_it = min_element(energy.begin(), energy.end());
    auto max_it = max_element(energy.begin(), energy.end());
    cout << "Мин: " << *min_it << " (день " << (min_it - energy.begin() + 1) << ")" << endl;
    cout << "Макс: " << *max_it << " (день " << (max_it - energy.begin() + 1) << ")" << endl;

    // Пиковые дни (> среднего на 20%)
    double threshold = avg * 1.2;
    cout << "Пиковые дни (> " << threshold << "): ";
    for (int i = 0; i < energy.size(); i++) {
        if (energy[i] > threshold) {
            cout << "день " << i + 1 << " (" << energy[i] << ") ";
        }
    }

    return 0;
}