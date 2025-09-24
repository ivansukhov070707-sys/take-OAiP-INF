#include <iostream>
int main()
{
    setlocale(LC_ALL, "RU");
    int i = 0;
    int k = 0;
    std::cout << "¬ведите число" << std::endl;
    std::cin >> i;
    while (i > k) {
        k += 1;
        std::cout << pow(k, 2) << std::endl;
    }
	return 0;
}