#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    int N = 0;
    int m[50][50];

    cout << "������� ������� �������\n";
    cin >> N;

    // ���� ��������� �������
    cout << "������� �������� �������:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> m[i][j];
        }
    }

    // ����� �������
    cout << "\n�������" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    // ��������� ����� ������ ������ (��������� ����� ����� ���������� � ���)
    int sum1 = 0;
    for (int j = 0; j < N; j++) {
        sum1 += m[0][j];
    }

    // �������� ����� ���� �����
    for (int i = 1; i < N; i++) {
        int lineSum = 0;
        for (int j = 0; j < N; j++) {
            lineSum += m[i][j];
        }
        if (lineSum != sum1) {
            cout << "NO" << endl;
        }
    }

    // �������� ����� ���� ��������
    for (int j = 0; j < N; j++) {
        int colSum = 0;
        for (int i = 0; i < N; i++) {
            colSum += m[i][j];
        }
        if (colSum != sum1) {
            cout << "NO" << endl;
        }
    }

    // �������� ����� ��������� ������� ���������
    int maindiagSum = 0;
    for (int i = 0; i < N; i++) {
        maindiagSum += m[i][i];
    }
    if (maindiagSum != sum1) {
        cout << "NO" << endl;
    }

    // �������� ����� ��������� �������� ���������
    int sidediagSum = 0;
    for (int i = 0; i < N; i++) {
        sidediagSum += m[i][N - 1 - i];
    }
    if (sidediagSum != sum1) {
        cout << "NO" << endl;

    }


    // ���� ��� �������� ��������
    cout << "YES " << sum1 << endl;

    return 0;
}