#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RU");

    int N = 0;
    int matrix[100][100];
    int matrix_1[100][100];
    int matrix_2[100][100];
    int matrix_3[100][100];
    int matrix_4[100][100];
    cout << "������� ������� �������\n";
    cin >> N;
    // ���� ��������� �������
    cout << "������� �������� �������:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    // ����� �������
    cout << "�������:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // ��������� ������������ ������� ���������
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int temp1 = matrix[i][j];
            matrix_1[j][i] = temp1;
        }
    }

    cout << "\n������� ��������� ������������ ������� ���������:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix_1[i][j] << " ";
        }
        cout << endl;
    }


    // ��������� ������������ �������� ���������
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int temp2 = matrix[i][j];
            matrix_2[N - 1 - j][N - 1 - i] = temp2;
        }
    }

    cout << "\n������� ���������� ������������ �������� ���������:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix_2[i][j] << " ";
        }
        cout << endl;
    }


    // ��������� ������������ ������������ ���  
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int temp3 = matrix[i][j];
            matrix_3[i][N - 1 - j] = temp3;
        }
    }

    cout << "\n������� ���������� ������������ ���������:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix_3[i][j] << " ";
        }
        cout << endl;
    }


    // ��������� ������������ �������������� ���
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int temp4 = matrix[i][j];
            matrix_4[N - 1 - i][j] = temp4;
        }
    }

    cout << "\n������� ���������� ������������ �����������:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix_4[i][j] << " ";
        }
        cout << endl;
    }


    // ��������� ��������� ������
    cout << "\n                         " << endl << "��������� ���������� ������" << endl;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix_1[i][j] == matrix_2[i][j] && matrix_3[i][j] == matrix_4[i][j] && matrix_1[i][j] == matrix_3[i][j]) {
                cout << "����������� �������� ���  ��������:" << "(" << i << "," << j << ")" << endl;
            }
            else {
                cout << "NONE " << "(" << i << "," << j << ")" << endl;
            }
        }
    }

    return 0;
}