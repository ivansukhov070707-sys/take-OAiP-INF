#include <iostream>
using namespace std;

int main() {
    const int N = 10;
    int a[N];

    // ����
    cout << "������� 10 �����: ";
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    // ����� � �����
    int sum = 0;
    cout << "������: ";
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
        sum += a[i];
    }
    cout << "\n�����: " << sum << endl;

    // �������
    int min = a[0];
    for (int i = 1; i < N; i++) {
        if (a[i] < min) min = a[i];
    }
    cout << "�������: " << min << endl;

    // ���������� ���������
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }

    // ����� ����������������
    cout << "����� ����������: ";
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }

    return 0;
}