#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    const int n = 10;
    vector<double> temp(n);

    cout << "������� ����������� (������ 20 �����)" << endl;
    for_each(temp.begin(), temp.end(), [](double& element) {
        cin >> element;
        });

    cout << "������:" << endl;
    for_each(temp.begin(), temp.end(), [](double element) {
        cout << element << "  ";
        });

    // 1) �������� ���� �������� ��� ��������� [-50;50]

    auto condition = [](double x) {   // �������, �������� �������� [-50;50]
        return x <= -50 || x >= 50;
        };

    temp.erase(remove_if(temp.begin(), temp.end(), condition), temp.end()); // �������� �� �������

    cout << "\n ������ ������ ��������� [-50;50]:" << endl;
    for_each(temp.begin(), temp.end(), [](double element) {
        cout << element << "  ";
        });


    // 2) ����� �������� � ���������

    auto max = max_element(temp.begin(), temp.end());
    auto min = min_element(temp.begin(), temp.end());
    cout << "\n������������ �����������:" << *max << endl;
    cout << "����������� �����������:" << *min << endl;

    // 3) ���������� ������� ��������

    double sum = accumulate(temp.begin(), temp.end(), 0) / temp.size();
    cout << "������� �����������:" << sum << endl;

    // 4) ��������, ��������� �� ��� ����������� -10 ��������

    auto check_temp = find_if(temp.begin(), temp.end(), [](double x) {
        return x <= -10;
        });

    if (check_temp == temp.end()) {
        cout << "��� ����������� ��������� -10 ��������" << endl;
    }
    else {
        cout << "�� ��� ����������� ��������� -10 ��������" << endl;
    }


    return 0;
}
