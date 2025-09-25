#include <iostream>
using namespace std;
float main() {
	setlocale(LC_ALL, "RU");
	float d = 0;
	cout << "Укажите свой доход"<<endl;
	cin >> d;
	if (d < 50000) {
		d = d - d * 0.13;
		cout << "Доход с учетом налога: " << d;
	}
	if ((d > 50000) && (d <= 100000)) {
		d = d - d * 0.2;
		cout << "Доход с учетом налога: " << d;
	}
	if (d > 100000) {
		d = d - d * 0.25;
		cout << "Доход с учетом налога: " << d;
	}
	return 0;
}
//#include <iostream>
//using namespace std;
//
//int main() {
//	setlocale(LC_ALL, "RU");
//	for (int i = 1; i <= 10; i++) {
//		cout << i << " - " << i * 10 << " руб" << endl;
//	}
//	return 0;
//}