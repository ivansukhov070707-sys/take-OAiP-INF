#include <iostream>
int main()
{
    setlocale(LC_ALL, "RU");
    int i = 0;
    std::cout << "Введите число" << std::endl;
    std::cin >> i;
    if (i % 2 == 0) {
        std::cout << "Число четное" << std::endl;
    }
    else {
        std::cout << "Число нечетное" << std::endl;
    }
	return 0;
}