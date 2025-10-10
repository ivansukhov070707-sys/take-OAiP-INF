#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int m[100][100];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> m[i][j];

    int top = 0, b = N - 1, left = 0, right = M - 1;

    while (top <= b && left <= right) {
        // ¬право
        for (int j = left; j <= right; j++)
            cout << m[top][j] << " ";
        top++;

        // ¬низ
        for (int i = top; i <= b; i++)
            cout << m[i][right] << " ";
        right--;

        // ¬лево (если есть строки)
        if (top <= b) {
            for (int j = right; j >= left; j--)
                cout << m[b][j] << " ";
            b--;
        }

        // ¬верх (если есть столбцы)
        if (left <= right) {
            for (int i = b; i >= top; i--)
                cout << m[i][left] << " ";
            left++;
        }
    }

    return 0;
}