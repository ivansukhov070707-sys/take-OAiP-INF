#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

int main() {
    ifstream input("vibration_log.txt");

    if (!input.is_open()) {
        cout << "Ошибка открытия файла vibration_log.txt!" << endl;
        return 1;
    }

    vector<double> amplitudes;
    double value;

    while (input >> value) {
        amplitudes.push_back(value);
    }
    input.close();

    auto filterAmplitudes = [](const vector<double>& data) {
        vector<double> filtered;
        copy_if(data.begin(), data.end(), back_inserter(filtered),
            [](double amp) { return amp > 0.05; });
        return filtered;
        };

    auto calculateAverage = [](const vector<double>& data) {
        if (data.empty()) return 0.0;
        return accumulate(data.begin(), data.end(), 0.0) / data.size();
        };

    auto findMinMax = [](const vector<double>& data) {
        auto min_it = min_element(data.begin(), data.end());
        auto max_it = max_element(data.begin(), data.end());
        return make_pair(*min_it, *max_it);
        };

    vector<double> filtered = filterAmplitudes(amplitudes);
    double average = calculateAverage(amplitudes);
    auto minmax = findMinMax(filtered);
    double minVal = minmax.first;
    double maxVal = minmax.second;

    ofstream output("vibration_report.txt");

    output << fixed << setprecision(4);
    output << "Количество измерений: " << amplitudes.size() << endl;
    output << "Фильтрованные значения (>0.05): ";
    for (double val : filtered) {
        output << val << " ";
    }
    output << endl;
    output << "Среднее значение: " << average << endl;
    output << "Минимум: " << minVal << endl;
    output << "Максимум: " << maxVal << endl;

    output.close();

    cout << "Анализ вибрационных данных завершён. Отчёт сохранён в vibration_report.txt" << endl;

    return 0;
}