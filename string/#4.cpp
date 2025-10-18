#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cout << "Строка A: ";
    getline(cin, a);
    cout << "Строка B: ";
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
            cout << "Нет" << endl;
            return 0;
        }
    }

    cout << "Да" << endl;
    return 0;
}