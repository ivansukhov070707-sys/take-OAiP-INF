#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // ������� ������ �� 20 ����� (� ������������)
    vector<int> numbers = { 7, 3, 5, 7, 2, 8, 1, 7, 4, 6,
                          9, 3, 5, 2, 8, 1, 4, 6, 9, 7 };

    // ������� �������� ������
    cout << "�������� ������: ";
    for_each(numbers.begin(), numbers.end(), [](int n) {
        cout << n << " ";
        });
    cout << endl << endl;

    // 1. ���������, ���� �� ����� 7 � ������� find
    auto found = find(numbers.begin(), numbers.end(), 7);
    if (found != numbers.end()) {
        cout << "����� 7 ������� �� �������: " << distance(numbers.begin(), found) << endl;
    }
    else {
        cout << "����� 7 �� �������" << endl;
    }

    // ������������ ���������� �������
    int count_7 = count(numbers.begin(), numbers.end(), 7);
    cout << "���������� ����� 7 � �������: " << count_7 << endl << endl;

    // 2. ������� ��� ������������� ����� (sort + unique)

    // ������� ��������� ������
    sort(numbers.begin(), numbers.end());

    cout << "����� ����������: ";
    for_each(numbers.begin(), numbers.end(), [](int n) { cout << n << " "; });
    cout << endl;

    // ����� ���������� unique ��� �������� ����������
    auto unique_end = unique(numbers.begin(), numbers.end());

    // ������� "�����" � �����������
    numbers.erase(unique_end, numbers.end());

    // 3. ������� ���������� ��������
    cout << "����� �������� ����������: ";
    for_each(numbers.begin(), numbers.end(), [](int n) {
        cout << n << " ";
        });
    cout << endl;

    cout << "�������� ���������� ���������: " << numbers.size() << endl;

    return 0;
}