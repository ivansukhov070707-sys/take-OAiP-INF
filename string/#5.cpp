#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "������� �����: ";
    getline(cin, s);

    int v = 0, c = 0;

    for (char ch : s) {
        char letter = tolower(ch);

        if (letter >= 'a' && letter <= 'z') {
            if (letter == 'a' || letter == 'e' || letter == 'i' ||
                letter == 'o' || letter == 'u' || letter == 'y') {
                v++;
            }
            else {
                c++;
            }
        }
    }

    cout << "�������: " << v << "\n���������: " << c << endl;
    return 0;
}