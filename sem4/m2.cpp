#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    int N = 0;
    int m[50][50];

    cout << "Введите порядок матрицы\n";
    cin >> N;

    // Ввод элементов матрицы
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> m[i][j];
        }
    }

    // Вывод матрицы
    cout << "\nМатрица" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    // Вычисляем сумму первой строки (остальные суммы будем сравнивать с ней)
    int sum1 = 0;
    for (int j = 0; j < N; j++) {
        sum1 += m[0][j];
    }

    // Проверим суммы всех строк
    for (int i = 1; i < N; i++) {
        int lineSum = 0;
        for (int j = 0; j < N; j++) {
            lineSum += m[i][j];
        }
        if (lineSum != sum1) {
            cout << "NO" << endl;
        }
    }

    // Проверим суммы всех столбцов
    for (int j = 0; j < N; j++) {
        int colSum = 0;
        for (int i = 0; i < N; i++) {
            colSum += m[i][j];
        }
        if (colSum != sum1) {
            cout << "NO" << endl;
        }
    }

    // Проверим сумму элементов главной диагонали
    int maindiagSum = 0;
    for (int i = 0; i < N; i++) {
        maindiagSum += m[i][i];
    }
    if (maindiagSum != sum1) {
        cout << "NO" << endl;
    }

    // Проверим сумму элементов побочной диагонали
    int sidediagSum = 0;
    for (int i = 0; i < N; i++) {
        sidediagSum += m[i][N - 1 - i];
    }
    if (sidediagSum != sum1) {
        cout << "NO" << endl;

    }


    // Если все проверки пройдены
    cout << "YES " << sum1 << endl;

    return 0;
}