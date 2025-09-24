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
