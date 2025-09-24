#include <iostream>
using namespace std;
int main() 
{
    setlocale(LC_ALL, "RU");
    const int N = 15;
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
    if (min == 1 && max == 0) {
        for (int i = 0; i < N; i++) {
            arr[i] /= 2;
        }
        cout << "ћассив после преобразовани€: ";
        for (int i = 0; i < N; i++) {
            cout << arr[i] << "\n";
        }
    }
    else {
        cout << "не выполн€етс€";
    }
}