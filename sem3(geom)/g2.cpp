#include <iostream>
#include <cmath> //sqrt() � pow()
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    const int V = 4;
    double arr[V][2];
    for (int i = 0; i < V; i++) {
        cout << "������� " << i + 1 << " (x y): ";
        cin >> arr[i][0] >> arr[i][1];
    }
    double p = 0.0;
    for (int i = 0; i < V; i++) {
        int n = (i + 1) % V; // ��������� ������a 
        double dx = arr[n][0] - arr[i][0];
        double dy = arr[n][1] - arr[i][1];
        double distance = sqrt(dx * dx + dy * dy);
        p += distance;
        cout << "���������� ����� �������� " << i + 1 << " � " << n + 1
            << ": " << distance << endl;
    }
    cout << "\n���������� ������ ��������������:" << endl;
    for (int i = 0; i < V; i++) {
        cout << "������� " << i + 1 << ": (" << arr[i][0]
            << ", " << arr[i][1] << ")" << endl;
    }
    cout << "�������� ��������������: " << p << endl;
    return 0;
}