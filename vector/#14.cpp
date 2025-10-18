#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    // ����������� �� 24 ����
    vector<double> consumption = { 150, 180, 200, 220, 250, 300, 350, 400, 450, 420,
                                 380, 350, 320, 300, 280, 260, 240, 220, 200, 180,
                                 160, 140, 120, 100 };

    // ��������� � ������� �����������
    double total = accumulate(consumption.begin(), consumption.end(), 0.0);
    double average = total / consumption.size();
    cout << "���������: " << total << " ����, �������: " << average << " ����" << endl;

    // ��� �������� �����������
    auto max_it = max_element(consumption.begin(), consumption.end());
    int peak_hour = max_it - consumption.begin();
    cout << "������� �����������: " << *max_it << " ���� (��� " << peak_hour << ")" << endl;

    // ���������� �� ��������
    vector<double> deviations(24);
    transform(consumption.begin(), consumption.end(), deviations.begin(),
        [average](double c) { return c - average; });

    // ���-5 ����������� �����
    vector<double> sorted = consumption;
    sort(sorted.begin(), sorted.end());
    cout << "���-5 �����������: ";
    for (int i = 0; i < 5; i++) cout << sorted[i] << " ";

    return 0;
}