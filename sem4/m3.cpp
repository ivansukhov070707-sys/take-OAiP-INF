#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int matrix[100][100];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> matrix[i][j];

    // Заранее вычисляем min/max для строк и столбцов
    int rowMin[100], rowMax[100];
    int colMin[100], colMax[100];

    // Инициализируем
    for (int i = 0; i < N; i++) {
        rowMin[i] = matrix[i][0];
        rowMax[i] = matrix[i][0];
    }
    for (int j = 0; j < M; j++) {
        colMin[j] = matrix[0][j];
        colMax[j] = matrix[0][j];
    }

    // Вычисляем min/max для строк
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] < rowMin[i]) rowMin[i] = matrix[i][j];
            if (matrix[i][j] > rowMax[i]) rowMax[i] = matrix[i][j];
        }
    }

    // Вычисляем min/max для столбцов
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            if (matrix[i][j] < colMin[j]) colMin[j] = matrix[i][j];
            if (matrix[i][j] > colMax[j]) colMax[j] = matrix[i][j];
        }
    }

    // Ищем седловые точки
    bool found = false;

    // Тип A: минимален в строке и максимален в столбце
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]) {
                cout << "A " << matrix[i][j] << " " << i + 1 << " " << j + 1 << endl;
                found = true;
            }
        }
    }

    // Тип B: максимален в строке и минимален в столбце
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] == rowMax[i] && matrix[i][j] == colMin[j]) {
                cout << "B " << matrix[i][j] << " " << i + 1 << " " << j + 1 << endl;
                found = true;
            }
        }
    }

    if (!found) cout << "NONE" << endl;

    return 0;
}