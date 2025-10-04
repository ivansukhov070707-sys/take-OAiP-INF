#include <iostream> 
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int n;
    cin >> n;
    if (n <= 0) {
        cout << "����� ����� �����" << endl;
    }
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (A[i] <= 0) {
            cout << "����� ������ ���� ������������!" << endl;
        }
    }
    int count = 0;
    cout << "\n���������� ��������:" << endl;
    cout << "k\tAk\t2^k\tAk > 2k" << endl;

    for (int k = 1; k <= n; k++) {
        int ak = A[k - 1];
        int two_k = pow(2,k);
        bool condition = (ak > two_k);

        cout << k << "\t" << ak << "\t" << two_k << "\t";
        if (condition) {
            cout << "��";
            count++;
        }
        else {
            cout << "���";
        }
        cout << endl;
    }
    cout << "\n���������� ���������, ��������������� ������� Ak > 2^k: " << count << endl;

    return 0;
}
 
 //����� 2
 
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
    cout << "������� ������������������ �� " << n << " �����:" << endl;
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
        cout << "���������� ��������: " << max << endl;
    }
    else {
        cout << "�������� ����� ���" << endl;
    }
    cout << "���������� ������: " << t << endl;
    return 0;
}
 
//����� 3
 
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

    cout << "���������:" << endl;
    for (int i = 0; i < N; i++) {
        cout << n[i] << " ";
    }
}
 
//����� 4
 
 
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
        cout << "������������: " << r << endl;
    }
    else {
        cout << "������� �� �����������" << endl;
    }
}
 
//����� 5
 
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
        cout << "������� �������������� �����: "<<v;
    }
    else {
        cout << "�� �����������";
    }
}
 
//����� 6
 
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
        cout << "������ ����� ��������������: ";
        for (int i = 0; i < N; i++) {
            cout << arr[i] << "\n";
        }
    }
    else {
        cout << "�� �����������";
    }
}
 
//����� 7
 
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
 
//����� 8
 
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
    cout << "����� ������: ";
    for (int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }
    return 0;
}