#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RU");
    const int N = 10;
    int n[N];
    for (int i = 0; i < N; i++) {
        cin >> n[i];
    }
    int min = 0;
    int max = 0;
    for (int i = 1; i < N; i++) {
        if (n[i] < n[min]) min = i;
        if (n[i] > n[max]) max = i;
    }
    if (min == 4 && max == 9) {
        double v = (n[min] * n[max]) / 2;
        cout << "Ñðåäíåå àðèôìåòè÷åñêîå ðàâíî: "<<v;
    }
    else {
        cout << "Íå âûïîëíèëîñü";
    }
return 0;
}
