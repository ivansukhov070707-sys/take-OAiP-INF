#include <iostream>
using namespace std;

union DateTime {
    struct {
        int y, m, d, h, min, sec;
    } c;
};

int main() {
    DateTime dt;

    cout << "¬ведите год: "; cin >> dt.c.y;
    cout << "¬ведите мес€ц: "; cin >> dt.c.m;
    cout << "¬ведите день: "; cin >> dt.c.d;
    cout << "¬ведите час: "; cin >> dt.c.h;
    cout << "¬ведите минуту: "; cin >> dt.c.min;
    cout << "¬ведите секунду: "; cin >> dt.c.sec;

    cout << "\nƒата и врем€: "
        << dt.c.y << "-" << dt.c.m << "-" << dt.c.d << " "
        << dt.c.h << ":" << dt.c.min << ":" << dt.c.sec << endl;

    return 0;
}