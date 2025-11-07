#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double computeRMS(const vector<double>& signal) {
    const double* p = signal.data();
    double sum = 0.0;

    for (int i = 0; i < signal.size(); i++) {
        sum += p[i] * p[i]; // доступ через указатель и индекс
    }

    return sqrt(sum / signal.size());
}

int main() {
    vector<double> data = { 2.0, 3.0, 1.0, 4.0, 3.0 };
    cout << "RMS: " << computeRMS(data) << endl;
    return 0;
}