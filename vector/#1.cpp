#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    // ������� ������ �� 10 ���������
    vector<int> n(10);

    // ��������� ������� �� 1 �� 10
    int a = 1;
    for_each(n.begin(), n.end(), [&a](int& s) {
        s = a++;
        });

    // ������� � ������� for_each � ������-�������
    cout << "������ ����� �� 1 �� 10: ";
    for_each(n.begin(), n.end(), [](int n) {cout << n << " ";});
    cout << endl;

    return 0;
}