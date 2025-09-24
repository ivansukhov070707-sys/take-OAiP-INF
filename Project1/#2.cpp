#include <iostream>
#include <climits>
using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");
    int n;
    cin >> n;
    int number;
    int max = INT_MIN;
    int t = 0;
    cout << "Введите последовательность из " << n << " чисел:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> number;
        if (number % 2 == 0) {
            t++;
        }
        else {
            if (number > max) {
                max = number;
            }
        }
    }
    if (max != INT_MIN) {
        cout << "Наибольшее нечетное: " << max << endl;
    }
    else {
        cout << "Нечетных чисел нет" << endl;
    }
    cout << "Количество четных: " << t << endl;
    return 0;
}