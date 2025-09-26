#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	const int s = 10;
	int arr[s];
	for (int i = 0;i<s;i++){
		cin >> arr[i];
	}
	cout << "Начальный массив: " << endl;
	for (int i = 0;i<s;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	int sum = 0;
	for (int i = 0; i < s; i++) {
		sum += arr[i];
	}
	cout << "Сумма = " << sum << endl;
		int min = 0;
		for (int i = 1; i < s; i++) {
			if (arr[i] < arr[min])
				min = arr[i];
	}
	cout <<"Минимальный элемент массива "<< min << endl;
	for (int i = 0; i < s-1; i++){
		for (int w = 0; w < s - i - 1; w++) {
			if (arr[w] > arr[w + 1]) {
				int t = arr[w];
				arr[w] = arr[w + 1];
				arr[w + 1] = t;
			}
		}
	}
	cout << "Итоговый массив " << endl;
	for (int i = 0; i < s; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}	