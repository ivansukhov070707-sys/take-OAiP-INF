#include <iostream> 
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int n;
    cin >> n;
    if (n <= 0) {
        cout << "введи натур число" << endl;
    }
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (A[i] <= 0) {
            cout << "Числа должны быть натуральными!" << endl;
        }
    }
    int count = 0;
    cout << "\nРезультаты проверки:" << endl;
    cout << "k\tAk\t2^k\tAk > 2k" << endl;

    for (int k = 1; k <= n; k++) {
        int ak = A[k - 1];
        int two_k = pow(2,k);
        bool condition = (ak > two_k);

        cout << k << "\t" << ak << "\t" << two_k << "\t";
        if (condition) {
            cout << "ДА";
            count++;
        }
        else {
            cout << "нет";
        }
        cout << endl;
    }
    cout << "\nКоличество элементов, удовлетворяющих условию Ak > 2^k: " << count << endl;

    return 0;
}
 
 //номер 2
 
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
 
//номер 3
 
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
 
//номер 4
 
 
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
        cout << "Произведение: " << r << endl;
    }
    else {
        cout << "Условие не выполняется" << endl;
    }
}
 
//номер 5
 
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
        cout << "Среднее арифметическое равно: "<<v;
    }
    else {
        cout << "Не выполнилось";
    }
}
 
//номер 6
 
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
        cout << "Массив после преобразования: ";
        for (int i = 0; i < N; i++) {
            cout << arr[i] << "\n";
        }
    }
    else {
        cout << "не выполняется";
    }
}
 
//номер 7
 
#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RU");
    const int N = 15;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int min = 0;
    int max = 0;
    for (int i = 1; i < N; i++) {
        if (arr[i] < arr[min]) min = i;
        if (arr[i] > arr[max]) max = i;
    }
    if ((arr[min] == 0) || (arr[max] == 0)) {
        for (int i = 0; i < min; i++) {
            arr[i] = 0;
        }
    }
        for (int i = 0; i < N; i++) {
            cout << arr[i];
        }
        return 0;
}
 
//номер 8
 
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