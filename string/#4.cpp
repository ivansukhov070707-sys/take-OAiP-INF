#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cout << "������ A: ";
    getline(cin, a);
    cout << "������ B: ";
    getline(cin, b);

    for (int i = 0; i < b.size(); i++) {
        bool found = false;
        for (int j = 0; j < a.size(); j++) {
            if (b[i] == a[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "���" << endl;
            return 0;
        }
    }

    cout << "��" << endl;
    return 0;
}