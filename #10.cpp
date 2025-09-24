#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int n = 0;
	cin >> n;
	if (n == 0){
		cout << "Число равно нулю " << endl;
	}
	if (n > 0) {
		cout << "Число больше нуля" << endl;
	}
	else {
		cout << "число меньше нуля";
	}
	return 0;
}
