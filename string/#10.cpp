#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int start = 0;
    for (int i = 0; i <= s.size(); i++) {
        if (i == s.size() || s[i] == ' ') {
            reverse(&s[start], &s[i]);
            start = i + 1;
        }
    }

    cout << s << endl;
    return 0;
}