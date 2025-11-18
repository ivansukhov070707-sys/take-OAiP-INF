#include <iostream>

int** transpose(int** matrix, int n, int m) {
    setlocale(LC_ALL, "RU");
    // Выделяем память под новую транспонированную матрицу
    // Размеры меняются местами: m строк, n
    int** transpose(int** matrix, int n, int m);
        // Выделяем память для новой матрицы (m x n)
        int** result = new int* [m];
        for (int i = 0; i < m; ++i) {
            result[i] = new int[n];
        }

        // Транспонируем матрицу
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result[i][j] = matrix[j][i];
            }
        }

        return result;
    }

    // Функция для очистки памяти
    void deleteMatrix(int** matrix, int rows) {
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }