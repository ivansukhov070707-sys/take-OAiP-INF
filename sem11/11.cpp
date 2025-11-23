#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

int main() {
    ifstream inputFile("sensor_data.txt");
    if (!inputFile.is_open()) {
        cout << "Ошибка открытия файла sensor_data.txt!" << endl;
        return 1;
    }

    vector<double> temperatures;
    double temperature;

    while (inputFile >> temperature) {
        temperatures.push_back(temperature);
    }
    inputFile.close();

    auto isValidTemperature = [](double temp) {
        return temp >= -50.0 && temp <= 50.0;
        };

    vector<double> filteredTemperatures;
    copy_if(temperatures.begin(), temperatures.end(),
        back_inserter(filteredTemperatures), isValidTemperature);

    ofstream outputFile("filtered_sensor_data.txt");
    if (!outputFile.is_open()) {
        cout << "Ошибка создания файла filtered_sensor_data.txt!" << endl;
        return 1;
    }

    outputFile << fixed << setprecision(1);
    for (double temp : filteredTemperatures) {
        outputFile << temp << endl;
    }
    outputFile.close();

    if (!filteredTemperatures.empty()) {
        double sum = accumulate(filteredTemperatures.begin(), filteredTemperatures.end(), 0.0);
        double average = sum / filteredTemperatures.size();

        cout << "Обработка данных завершена!" << endl;
        cout << "Всего измерений: " << temperatures.size() << endl;
        cout << "Корректных измерений: " << filteredTemperatures.size() << endl;
        cout << "Некорректных измерений: " << temperatures.size() - filteredTemperatures.size() << endl;
        cout << "Средняя температура: " << fixed << setprecision(2) << average << "°C" << endl;
        cout << "Отфильтрованные данные сохранены в filtered_sensor_data.txt" << endl;
    }
    else {
        cout << "Нет корректных данных для анализа!" << endl;
    }

    return 0;
}