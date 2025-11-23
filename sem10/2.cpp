#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main() {
	ofstream f("input.txt");
	if (f.is_open()) {
		f << "Privet strana" << endl;
		f << "Zdarovo Rodina" << endl;
		f << "Bomonka top!!!" << endl;
	}
	f.close();
	ifstream inf("input.txt");
	string line;
	int k = 0;
	if (inf.is_open()) {
		string line;
		while (getline(inf, line)) {
			k++;
			cout << line << endl;
		}
		inf.close();
		cout << k << endl;
	}
	else {
		cerr << "Не удалось открыть файл для чтения." << endl;
	}
}