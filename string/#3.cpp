#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    string str;
    cout << "������� ������: ";  // ����� endl ��� ������������
    getline(cin, str);

    // �������� ���� � �������� ����� ������
    string without_digits;
    for (char c : str) {
        if (!isdigit(c)) {  // ����� ��������� ������
            without_digits += c;
        }
    }

    // ����� ����������
    cout << "������ ��� ����: " << without_digits << endl;

    return 0;
}