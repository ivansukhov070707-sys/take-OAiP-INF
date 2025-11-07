#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = { 1, 2, 3 };

    // Сумма через указатель
    int sum = 0;
    int* p = v.data();
    for (int i = 0; i < v.size(); i++) {
        sum += p[i];
    }
    cout << "Сумма: " << sum << endl;

    // Увеличение на 10 через указатель
    p = v.data();
    for (int i = 0; i < v.size(); i++) {
        p[i] += 10;
    }

    cout << "После увеличения: ";
    for (int num : v) {
        cout << num << " ";
    }

    return 0;
}