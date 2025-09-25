#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    for (int i = 1; i <= 10; i++) {
        cout << i << " - " << i * 10 << " руб"<<endl;
    }
    return 0;
}