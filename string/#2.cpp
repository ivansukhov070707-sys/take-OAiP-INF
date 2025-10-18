#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "¬ведите строку: ";
    getline(cin, str);

    int count = 0;

    for (int i = 0; i < str.length(); i++) {
        bool found = false;
        for (int j = 0; j < i; j++) {
            if (str[i] == str[j]) {
                found = true;
                break;
            }
        }
        if (!found) count++;
    }

    cout << "”никальных символов: " << count << endl;
    return 0;
}