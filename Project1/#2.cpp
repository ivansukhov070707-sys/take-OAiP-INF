#include <iostream>
#include <climits>
using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");
    int n;
    cin >> n;
    int number;
    int max = INT_MIN;
    int t = 0;
    cout << "������� ������������������ �� " << n << " �����:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> number;
        if (number % 2 == 0) {
            t++;
        }
        else {
            if (number > max) {
                max = number;
            }
        }
    }
    if (max != INT_MIN) {
        cout << "���������� ��������: " << max << endl;
    }
    else {
        cout << "�������� ����� ���" << endl;
    }
    cout << "���������� ������: " << t << endl;
    return 0;
}