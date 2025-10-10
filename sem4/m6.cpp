#include <iostream>
using namespace std;

int main() {
    // Система уравнений:
    // 5x - y = 9
    // 3x + 2y = 4

    // Матрица коэффициентов A
    double A[2][2] = { {5, -1},
                      {3, 2} };

    // Вектор правой части B
    double B[2] = { 9, 4 };

    // Вычисляем определитель матрицы A
    double det = A[0][0] * A[1][1] - A[0][1] * A[1][0];

    if (det == 0) {
        cout << "Система не имеет единственного решения" << endl;
        return 0;
    }

    // Решение по формулам Крамера
    double det_x = B[0] * A[1][1] - A[0][1] * B[1];
    double det_y = A[0][0] * B[1] - B[0] * A[1][0];

    double x = det_x / det;
    double y = det_y / det;

    cout << "Решение системы:" << endl;
    cout << "5x - y = 9" << endl;
    cout << "3x + 2y = 4" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    return 0;
}