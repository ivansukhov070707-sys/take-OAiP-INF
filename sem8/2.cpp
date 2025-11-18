#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    // Создание
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    
    // Заполнение
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = i * m + j; // последовательные числа
        }
    }
    
    // Вывод
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    // Удаление
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    
    return 0;
}