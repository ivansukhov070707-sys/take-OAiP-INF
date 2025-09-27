#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL,"RU");
    const int s = 10;
    int arr[s];
    cout << "Введите 10 целых чисел:" << endl;
    for (int i = 0; i < s; i++) {
        cin >> arr[i];
    }
    cout << "Начальный массив: ";
    for (int i = 0; i < s; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int sum = 0;
    for (int i = 0; i < s; i++) {
        sum += arr[i];
    }
    cout << "Сумма: " << sum << endl;
    int min = arr[0];
    for (int i = 1; i < s; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    cout << "Минимальный элемент: " << min << endl;
    for (int i = 0; i < s - 1; i++) {
        for (int w = 0; w < s - i - 1; w++) {
            if (arr[w] > arr[w + 1]) {
                // Обмен элементов
                int temp = arr[w];
                arr[w] = arr[w + 1];
                arr[w + 1] = temp;
            }
        }
    }
    cout << "Отсортированный массив: ";
    for (int i = 0; i < s; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
