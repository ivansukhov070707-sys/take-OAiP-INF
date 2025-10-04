#include <iostream>
using namespace std;

int main() {
    const int N = 10;
    int a[N];

    // Ввод
    cout << "Введите 10 чисел: ";
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    // Вывод и сумма
    int sum = 0;
    cout << "Массив: ";
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
        sum += a[i];
    }
    cout << "\nСумма: " << sum << endl;

    // Минимум
    int min = a[0];
    for (int i = 1; i < N; i++) {
        if (a[i] < min) min = a[i];
    }
    cout << "Минимум: " << min << endl;

    // Сортировка пузырьком
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }

    // Вывод отсортированного
    cout << "После сортировки: ";
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }

    return 0;
}