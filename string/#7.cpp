#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "������� ������: ";
    cin >> s;

    string result = "";
    int i = 0;

    while (i < s.length()) {
        char c = s[i];
        int count = 0;

        // ������� ���������� ������� ������
        while (i < s.length() && s[i] == c) {
            count++;
            i++;
        }

        result += c;
        result += to_string(count);
    }

    cout << result << endl;
    return 0;
}