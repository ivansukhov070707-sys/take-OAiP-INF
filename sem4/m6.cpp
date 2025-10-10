#include <iostream>
using namespace std;

int main() {
    // ������� ���������:
    // 5x - y = 9
    // 3x + 2y = 4

    // ������� ������������� A
    double A[2][2] = { {5, -1},
                      {3, 2} };

    // ������ ������ ����� B
    double B[2] = { 9, 4 };

    // ��������� ������������ ������� A
    double det = A[0][0] * A[1][1] - A[0][1] * A[1][0];

    if (det == 0) {
        cout << "������� �� ����� ������������� �������" << endl;
        return 0;
    }

    // ������� �� �������� �������
    double det_x = B[0] * A[1][1] - A[0][1] * B[1];
    double det_y = A[0][0] * B[1] - B[0] * A[1][0];

    double x = det_x / det;
    double y = det_y / det;

    cout << "������� �������:" << endl;
    cout << "5x - y = 9" << endl;
    cout << "3x + 2y = 4" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    return 0;
}