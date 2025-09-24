#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "RU");
    const int N = 15;
    double n[N];
    for (int i = 0; i < N; i++) {
        cin >> n[i];
    }

    int min = 0, max = 0;
    for (int i = 1; i < N; i++) {
        if (n[i] < n[min]) min = i;
        if (n[i] > n[max]) max = i;
    }
    if (max < min) {
        double r = n[min] * n[max];
        cout << "Ïðîèçâåäåíèå: " << r << endl;
    }
    else {
        cout << "Óñëîâèå íå âûïîëíÿåòñÿ" << endl;
    }
return 0;
}
