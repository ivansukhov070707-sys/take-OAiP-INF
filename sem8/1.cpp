#include <iostream>
using namespace std;

void swapPointers(int** a, int** b) {
    int* temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    int* p1 = &x;
    int* p2 = &y;

    cout << "До: p1->" << *p1 << " p2->" << *p2 << endl;

    swapPointers(&p1, &p2);

    cout << "После: p1->" << *p1 << " p2->" << *p2 << endl;

    return 0;
}