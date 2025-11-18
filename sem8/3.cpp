#include <iostream>
using namespace std;

void free2D(int** arr, int n) {
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

int main() {
    int n = 3, m = 4;

    // Создаем массив
    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m] {i* m, i* m + 1, i* m + 2, i* m + 3};
    }

    // Выводим
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Освобождаем
    free2D(arr, n);

    return 0;
}