#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;

    for (int i = 0; i <= s.size() - k; i++) {
        string sub = s.substr(i, k);
        bool ok = true;

        for (int a = 0; a < sub.size(); a++) {
            for (int b = a + 1; b < sub.size(); b++) {
                if (sub[a] == sub[b]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }

        if (ok) cout << sub << endl;
    }

    return 0;
}