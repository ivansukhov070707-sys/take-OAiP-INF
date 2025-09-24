#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int n = 0;
	cin >> n;
	int s = 0;
	for (int i = 1; i <= n; i++) {
		if ((i % 2 == 0) || (i % 5 == 0)) {
			cout << i<< " "<<endl;
			s += i;
		}
	}
	cout << s;
	return 0;
}
