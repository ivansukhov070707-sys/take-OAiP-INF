#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    string stroka;
    cout << "������� ������: ";  // ����� endl ��� �������
    getline(cin, stroka);

    // �������� ������ ���������� � ��������, ������� � ������ �������
    string cleaned;
    for (char c : stroka) {
        if (isalnum(c)) {
            cleaned += tolower(c);
        }
    }

    // �������� ������
    string reversed = cleaned;
    reverse(reversed.begin(), reversed.end());

    // �������� ����������
    if (cleaned == reversed) {
        cout << "������ �������� �����������" << endl;
    }
    else {
        cout << "������ �� �������� �����������" << endl;
    }

    return 0;
}