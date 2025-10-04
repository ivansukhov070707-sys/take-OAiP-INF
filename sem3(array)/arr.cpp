#include <iostream> 
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int n;
    cin >> n;
    if (n <= 0) {
        cout << "ââåäè íàòóð ÷èñëî" << endl;
    }
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (A[i] <= 0) {
            cout << "×èñëà äîëæíû áûòü íàòóðàëüíûìè!" << endl;
        }
    }
    int count = 0;
    cout << "\nÐåçóëüòàòû ïðîâåðêè:" << endl;
    cout << "k\tAk\t2^k\tAk > 2k" << endl;

    for (int k = 1; k <= n; k++) {
        int ak = A[k - 1];
        int two_k = pow(2,k);
        bool condition = (ak > two_k);

        cout << k << "\t" << ak << "\t" << two_k << "\t";
        if (condition) {
            cout << "ÄÀ";
            count++;
        }
        else {
            cout << "íåò";
        }
        cout << endl;
    }
    cout << "\nÊîëè÷åñòâî ýëåìåíòîâ, óäîâëåòâîðÿþùèõ óñëîâèþ Ak > 2^k: " << count << endl;

    return 0;
}
 
 //íîìåð 2
 
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
    cout << "Ââåäèòå ïîñëåäîâàòåëüíîñòü èç " << n << " ÷èñåë:" << endl;
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
        cout << "Íàèáîëüøåå íå÷åòíîå: " << max << endl;
    }
    else {
        cout << "Íå÷åòíûõ ÷èñåë íåò" << endl;
    }
    cout << "Êîëè÷åñòâî ÷åòíûõ: " << t << endl;
    return 0;
}
 
//íîìåð 3
 
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

    cout << "Ðåçóëüòàò:" << endl;
    for (int i = 0; i < N; i++) {
        cout << n[i] << " ";
    }
}
 
//íîìåð 4
 
 
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
}
 
//íîìåð 5
 
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
}
 
//íîìåð 6
 
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
        cout << "Ìàññèâ ïîñëå ïðåîáðàçîâàíèÿ: ";
        for (int i = 0; i < N; i++) {
            cout << arr[i] << "\n";
        }
    }
    else {
        cout << "íå âûïîëíÿåòñÿ";
    }
}
 
//íîìåð 7
 
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
 
//íîìåð 8
 
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
    cout << "Íîâûé ìàññèâ: ";
    for (int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
