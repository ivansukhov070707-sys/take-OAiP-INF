#include <iostream>
using namespace std;
float main() {
	setlocale(LC_ALL, "RU");
	float d = 0;
	cout << "������� ���� �����"<<endl;
	cin >> d;
	if (d < 50000) {
		d = d - d * 0.13;
		cout << "����� � ������ ������: " << d;
	}
	if ((d > 50000) && (d <= 100000)) {
		d = d - d * 0.2;
		cout << "����� � ������ ������: " << d;
	}
	if (d > 100000) {
		d = d - d * 0.25;
		cout << "����� � ������ ������: " << d;
	}
	return 0;
}