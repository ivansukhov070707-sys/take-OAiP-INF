#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "RU");
    const int N = 15;
    double n[N];
    for (int i = 0; i < N; i++) {
        cin >> n[i];
    }
    int min = 0;
    int max = 0;
    for (int i = 1; i < N; i++) {
        if (n[i] < n[min]) min = i;
        if (n[i] > n[max]) max = i;
    }

    double x = n[0];
    n[0] = n[min];
    n[min] = x;

    x = n[14];
    n[14] = n[max];

 
   n[max] = x;

    cout << "Результат:" << endl;
    for (int i = 0; i < N; i++) {
        cout << n[i] << " ";
    }
}