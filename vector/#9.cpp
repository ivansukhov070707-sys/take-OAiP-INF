#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    const int n = 20;
    vector<int> power(n);

    // ������������� ���������� ��������� �����
    srand(time(0));

    // ���������� ������� ���������� ����������
    for (int i = 0; i < n; ++i) {
        power[i] = rand() % 201 - 50;  // �������� �� -50 �� 150
    }

    // 1) �������� ���� �������� ������ 0
    auto condition = [](int x) {
        return x < 0;
        };

    power.erase(remove_if(power.begin(), power.end(), condition), power.end());

    cout << "�������� ���������:" << endl;
    for_each(power.begin(), power.end(), [](int powers) {
        cout << powers << " ";
        });
    cout << endl;


    // 2) ����� �����������, ������������ � ������� ��������
    auto max = max_element(power.begin(), power.end());
    auto min = min_element(power.begin(), power.end());
    cout << "\n������������ ��������: " << *max << endl;
    cout << "����������� ��������: " << *min << endl;

    double sum = static_cast<double>(accumulate(power.begin(), power.end(), 0)) / power.size();
    cout << "������� ��������: " << sum << endl;

    // 3) �������� ������� �� ��������� �� ����� � �������� �� 10 �� 90 ���
    auto out_diapazon = find_if(power.begin(), power.end(),
        [](auto x) { return x < 10 || x > 90; });

    cout << "\n�������� ������ � �������� 10-90 ���: ";
    if (out_diapazon == power.end()) {
        cout << "�� - ��������� ������� � ���������� ���������" << endl;
    }
    else {
        cout << "��� - ���� ������ �� ������� ���������" << endl;
        cout << "������ ������������ ��������: " << *out_diapazon << " ���" << endl;
    }

    // 4) ������������� �������� �� ����������� � ������� �������
    vector<int> sorted_power = power;
    sort(sorted_power.begin(), sorted_power.end());

    cout << "\n��������������� ������ ���������:" << endl;
    for_each(sorted_power.begin(), sorted_power.end(), [](int powers) {
        cout << powers << "  ";
        });
    cout << endl;

    // ���������� ���������� �������
    double median = 0.0;
    int size = sorted_power.size();  // ���������� �������� ������ �������

    double middle1 = sorted_power[size / 2 - 1];
    double middle2 = sorted_power[size / 2];
    median = (middle1 + middle2) / 2.0;

    cout << "\n�������: " << median << endl;

    return 0;
}