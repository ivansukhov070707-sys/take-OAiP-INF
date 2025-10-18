#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    string ans = "";

    for (int i = 0; i < s1.size(); i++) {
        for (int j = 0; j < s2.size(); j++) {
            int k = 0;
            while (i + k < s1.size() && j + k < s2.size() && s1[i + k] == s2[j + k]) {
                k++;
            }
            if (k > ans.size()) {
                ans = s1.substr(i, k);
            }
        }
    }

    cout << ans << endl;
    return 0;
}