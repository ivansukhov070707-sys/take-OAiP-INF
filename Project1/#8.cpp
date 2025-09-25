#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RU");
    const int N = 10;
    double arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int min = 0;
    int max = 0;
    for (int i = 1; i < N; i++) {
        if (arr[i] < arr[min]) min = i;
        if (arr[i] > arr[max]) max = i;
    }
    if (min == 4 && max == 1) {
        for (int i = min; i < N; i++) {
            arr[i] = arr[max];
        }
    }
    cout << "Новый массив: ";
    for (int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
