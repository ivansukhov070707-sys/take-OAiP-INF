#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int m[100][100] = { 0 };

    int num = 1;
    int top = 0, b = N - 1, left = 0, right = N - 1;

    while (num <= N * N) {
        // ������
        for (int j = left; j <= right; j++) {
            m[top][j] = num++;
        }
        top++;

        // ����
        for (int i = top; i <= b; i++) {
            m[i][right] = num++;
        }
        right--;

        // �����
        for (int j = right; j >= left; j--) {
            m[b][j] = num++;
        }
        b--;

        // �����
        for (int i = b; i >= top; i--) {
            m[i][left] = num++;
        }
        left++;
    }

    // ����� �������
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}