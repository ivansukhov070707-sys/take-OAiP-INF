#include <iostream>
int main()
{
    setlocale(LC_ALL, "RU");
    float i = 0;
    std::cout << "������� ����� � ��" << std::endl;
    std::cin >> i;
    std::cout << i / 100 << std::endl;
	return 0;
}
 
 //����� 2
 
#include <iostream>
int main()
{
    setlocale(LC_ALL, "RU");
    float i = 0;
    float b = 0;
    std::cout << "������� �����" << std::endl;
    std::cin >> i;
    std::cout << "������� ������" << std::endl;
    std::cin >> b;
    std::cout << i * b << std::endl;
	return 0;
}
 
 //����� 3
 
#include <iostream>
int main()
{
    setlocale(LC_ALL, "RU");
    float i = 0;
    std::cout << "������� ��������?" << std::endl;
    std::cin >> i;
    std::cout << i * 9 / 5 + 32 << std::endl;
	return 0;
}
 
 //����� 4
 
#include <iostream>
int main()
{
    setlocale(LC_ALL, "RU");
    int i = 0;
    std::cout << "������� �����" << std::endl;
    std::cin >> i;
    if (i % 2 == 0) {
        std::cout << "����� ������" << std::endl;
    }
    else {
        std::cout << "����� ��������" << std::endl;
    }
	return 0;
}
 
 //����� 5
 
#include <iostream>
int main()
{
    setlocale(LC_ALL, "RU");
    int i = 0;
    std::cout << "������� �����" << std::endl;
    std::cin >> i;
    if ((i % 3 == 0) && (i % 5 == 0)) {
        std::cout << "������� �� 5 � �� 3" << std::endl;
    }
    if ((i % 3 == 0) && (i % 5 != 0)) {
        std::cout << "������� �� 3" << std::endl;
    }
    if ((i%3!=0)&&(i%5==0)) {
        std::cout << "������� �� 5" << std::endl;
    }
	return 0;
}

//����� 6

#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int v = 0;
	cout << "������� �������" << endl;
	cin >> v;
	if (v < 18) {
		cout << "��� ����� 18 ���" << endl;
	}
	if ((v >= 18) && (v <= 60)){
		cout << "��� �� 18 �� 60 ��� ������������" << endl;
	}
	if (v > 60) {
		cout << "��� ����� 60 ���" << endl;
	}
	return 0;
}
 
//����� 7
 
#include <iostream>
int main()
{
    setlocale(LC_ALL, "RU");
    int i = 0;
    int k = 0;
    std::cout << "������� �����" << std::endl;
    std::cin >> i;
    while (i > k) {
        k += 1;
        std::cout << pow(k, 2) << std::endl;
    }
	return 0;
}
 
 //����� 8
 
#include <iostream>
#include <string>
using namespace std;
int main() {
    setlocale(LC_ALL, "RU");
    string s;
    int i = 0;
    getline(cin, s);
    string vowels = "aeiouAEIOU";
    for (char c : s) {
        for (char v : vowels) {
            if (c == v) {
                i++;
            }
        }
    }
    cout << "���-��: " << i << endl;
    return 0;
}
 
 //����� 9
 
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
 
 //����� 10
 
#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int n = 0;
	cin >> n;
	if (n == 0){
		cout << "����� ����� ���� " << endl;
	}
	if (n > 0) {
		cout << "����� ������ ����" << endl;
	}
	else {
		cout << "����� ������ ����";
	}
	return 0;
}
 
// ����� 11
 
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    for (int i = 32; i <= 126; i++) {
        cout << "��� " << i << " = ";
        if (i == 32) {
            cout << "������";
        }
        else {
            cout << char(i);
        }
        cout << endl;
    }
    return 0;
}