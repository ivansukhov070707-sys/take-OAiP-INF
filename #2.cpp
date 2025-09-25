#include <iostream>
int main()
{
    setlocale(LC_ALL, "RU");
    float i = 0;
    float b = 0;
    std::cout << "Введите длину" << std::endl;
    std::cin >> i;
    std::cout << "Введите ширину" << std::endl;
    std::cin >> b;
    std::cout << i * b << std::endl;
	return 0;
}
