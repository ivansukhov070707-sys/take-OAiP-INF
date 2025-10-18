#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    const int n = 50;
    vector<double> fuel_level(n);

    // ������������� ���������� ��������� �����
    srand(time(0));

    cout << "������� ������� � ����������:" << endl;
    for (int i = 0; i < n; i++) {
        fuel_level[i] = rand() % 501;
    }

    for_each(fuel_level.begin(), fuel_level.end(), [](double elements) {
        cout << elements << ", ";
        });
    cout << endl;

    // 1) ����� ����������� ������� �������
    auto min = min_element(fuel_level.begin(), fuel_level.end());
    cout << "����������� ������� �������: " << *min << " ������" << endl;

    // 2) ���������, �� ����� �� ������� ���� 5% �� �������������
    auto max = max_element(fuel_level.begin(), fuel_level.end());

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (fuel_level[i] < *max * 0.05) {
            count++;
        }
    }

    cout << "������� ������� ����� ���� 5% �� �������������: ";
    if (count > 0) {
        cout << "�� (" << count << " ���)" << endl;
    }
    else {
        cout << "���" << endl;
    }

    // 3) ��������� ������� ����������� (�������� ���������� � ��������� ��������) 
    vector<double> sorted_fuel = fuel_level;
    sort(sorted_fuel.begin(), sorted_fuel.end());

    cout << "\n��������������� ������ ���������:" << endl;
    for_each(sorted_fuel.begin(), sorted_fuel.end(), [](double elements) {
        cout << elements << ", ";
        });
    cout << endl;

    double sredn = sorted_fuel[n - 1] - sorted_fuel[0];
    cout << "������� �����������: " << sredn << " ������" << endl;

    // 4) ����� �������
    double median = 0.0;
    int size = sorted_fuel.size();  // ���������� �������� ������ �������

    double middle1 = sorted_fuel[size / 2 - 1];
    double middle2 = sorted_fuel[size / 2];
    median = (middle1 + middle2) / 2.0;

    cout << "�������: " << median << endl;

    return 0;
}
