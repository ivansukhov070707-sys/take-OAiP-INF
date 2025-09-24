#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int v = 0;
	cout << "Введите возраст" << endl;
	cin >> v;
	if (v < 18) {
		cout << "Вам менее 18 лет" << endl;
	}
	if ((v >= 18) && (v <= 60)){
		cout << "Вам от 18 до 60 лет включительно" << endl;
	}
	if (v > 60) {
		cout << "Вам более 60 лет" << endl;
	}
	return 0;
}
