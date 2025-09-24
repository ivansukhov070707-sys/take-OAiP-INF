#include <iostream>
int main()
{
    setlocale(LC_ALL, "RU");
    float i = 0;
    std::cout << "Сколько градусов?" << std::endl;
    std::cin >> i;
    std::cout << i * 9 / 5 + 32 << std::endl;
	return 0;
}