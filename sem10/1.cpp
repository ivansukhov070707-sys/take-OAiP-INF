#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main() {
	ofstream f("input.txt"); // Открытие файла для чтения
	if (f.is_open()) {
		f << "Privet strana" << endl;
		f << "Zdarovo Rodina" << endl;
		f << "Bomonka top!!!" << endl;
	}
	f.close();
	ifstream inf("input.txt");
	string line;
	if (inf.is_open()) {
		string line;
		while (getline(inf, line)) {
			cout << line << endl;
		}
		inf.close();
	}
	else {
		cerr << "Не удалось открыть файл для чтения." << endl;
	}
}