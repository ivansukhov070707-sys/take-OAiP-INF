#include <iostream>
int main()
{
    setlocale(LC_ALL, "RU");
    int i = 0;
    std::cout << "Введите число" << std::endl;
    std::cin >> i;
    if ((i % 3 == 0) && (i % 5 == 0)) {
        std::cout << "Делится на 5 и на 3" << std::endl;
    }
    if ((i % 3 == 0) && (i % 5 != 0)) {
        std::cout << "Делится на 3" << std::endl;
    }
    if ((i%3!=0)&&(i%5==0)) {
        std::cout << "Делится на 5" << std::endl;
    }
	return 0;
}