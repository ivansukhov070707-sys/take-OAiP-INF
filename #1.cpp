#include <iostream>
int main()
{
    setlocale(LC_ALL, "RU");
    float i = 0;
    std::cout << "Введите длину в см" << std::endl;
    std::cin >> i;
    std::cout << i / 100 << std::endl;
	return 0;
}
