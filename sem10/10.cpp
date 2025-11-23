#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <numeric>
#include <iomanip>

using namespace std;

int main() {
    ifstream input("power_log.txt");

    if (!input.is_open()) {
        cout << "Ошибка открытия файла power_log.txt!" << endl;
        return 1;
    }

    map<string, vector<double>> deviceData;
    string line;

    while (getline(input, line)) {
        stringstream ss(line);
        string timestamp, deviceName;
        double power;

        if (ss >> timestamp >> deviceName >> power) {
            deviceData[deviceName].push_back(power);
        }
    }
    input.close();

    ofstream output("energy_report.txt");

    if (!output.is_open()) {
        cout << "Ошибка создания файла energy_report.txt!" << endl;
        return 1;
    }

    output << fixed << setprecision(2);

    for (const auto& device : deviceData) {
        const string& name = device.first;
        const vector<double>& powers = device.second;

        int measurements = powers.size();
        double total = accumulate(powers.begin(), powers.end(), 0.0);
        double average = total / measurements;

        output << name << ": measurements = " << measurements
            << ", total = " << total << " kWh, average = "
            << average << " kW" << endl;
    }
    output.close();

    cout << "Анализ завершён. Результаты сохранены в energy_report.txt" << endl;

    return 0;
}