#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    double x1, x2, y1, y2;

    cout << "������ ����� (x1, y1):" << endl;
    cin >> x1 >> y1;
    cout << "������ ����� (x2, y2):" << endl;
    cin >> x2 >> y2;

    double dx = x2 - x1;
    double dy = y2 - y1;
    double l = sqrt(dx * dx + dy * dy);

    cout << "���������� ����� ( " << x1 << "," << y1 << ") � ( " << x2 << "," << y2 << ") ���������   " << l;

    return 0;

}
