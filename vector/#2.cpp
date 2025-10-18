#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // ������� ������ �� 10 �����
    setlocale(LC_ALL, "RU");
    vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // ������� �������� ������
    cout << "�������� ������: ";
    for_each(numbers.begin(), numbers.end(), [](int n) {
        cout << n << " ";
        });
    cout << endl;

    // �������� ������ ������� �� 2 � ������� for_each � ������-�������
    for_each(numbers.begin(), numbers.end(), [](int& n) {
        n = n * 2;
        });

    // ������� ���������
    cout << "����� ��������� �� 2: ";
    for_each(numbers.begin(), numbers.end(), [](int n) {
        cout << n << " ";
        });
    cout << endl;

    return 0;
}