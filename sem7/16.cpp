#include <iostream>
#include <vector>
using namespace std;

void analyzePressure(const vector<double>& data, double& min, double& max, double& avg) {
    const double* p = data.data();

    min = max = p[0];
    double sum = 0;

    for (int i = 0; i < data.size(); i++) {
        double val = p[i];
        if (val < min) min = val;
        if (val > max) max = val;
        sum += val;
    }

    avg = sum / data.size();
}

int main() {
    vector<double> pressure = { 101.3, 100.8, 101.9, 100.5, 102.0 };

    double min, max, avg;
    analyzePressure(pressure, min, max, avg);

    cout << "Min: " << min << "\nMax: " << max << "\nAvg: " << avg << endl;

    return 0;
}