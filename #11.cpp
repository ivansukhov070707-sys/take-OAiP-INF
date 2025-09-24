#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    for (int i = 32; i <= 126; i++) {
        cout << "Код " << i << " = ";
        if (i == 32) {
            cout << "Пробел";
        }
        else {
            cout << char(i);
        }
        cout << endl;
    }
    return 0;
}
