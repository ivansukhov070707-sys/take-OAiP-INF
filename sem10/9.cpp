#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

int main() {
    ifstream input("temperature_data.txt");

    if (!input.is_open()) {
        cout << "Ошибка открытия файла temperature_data.txt!" << endl;
        return 1;
    }

    map<string, vector<double>> sensorData;
    string line;

    while (getline(input, line)) {
        stringstream ss(line);
        string sensorName;
        double temperature;

        if (ss >> sensorName >> temperature) {
            sensorData[sensorName].push_back(temperature);
        }
    }
    input.close();

    ofstream output("report.txt");

    if (!output.is_open()) {
        cout << "Ошибка создания файла report.txt!" << endl;
        return 1;
    }

    output << fixed << setprecision(1);

    for (const auto& sensor : sensorData) {
        const string& name = sensor.first;
        const vector<double>& temps = sensor.second;

        double minTemp = *min_element(temps.begin(), temps.end());
        double maxTemp = *max_element(temps.begin(), temps.end());
        double sum = accumulate(temps.begin(), temps.end(), 0.0);
        double avgTemp = sum / temps.size();

        output << name << ": min = " << minTemp << ", max = " << maxTemp
            << ", avg = " << avgTemp << endl;
    }
    output.close();

    cout << "Отчёт о температурных данных сохранён в report.txt" << endl;

    return 0;
}