#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "������� �����: ";
    getline(cin, s);

    // ������ ����� ���������
    s[0] = toupper(s[0]);

    for (int i = 1; i < s.size(); i++) {
        // ����� . ! ? ��������� ����� ������ ���������
        if (s[i - 1] == '.' || s[i - 1] == '!' || s[i - 1] == '?') {
            s[i] = toupper(s[i]);
        }
        // ��������� ����� - ��������
        else {
            s[i] = tolower(s[i]);
        }
    }

    cout << s << endl;
    return 0;
}