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