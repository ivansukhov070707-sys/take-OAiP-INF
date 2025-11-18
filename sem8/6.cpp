#include <iostream>

int sumElements(int** arr, int n, int m) {
    setlocale(LC_ALL, "RU");
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // Используем арифметику указателей вместо arr[i][j]
            sum += *(*(arr + i) + j);
        }
    }

    return sum;
}