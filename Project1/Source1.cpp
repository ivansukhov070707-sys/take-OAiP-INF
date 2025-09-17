#include <iostream>
int main()
{
    setlocale(LC_ALL, "RU");
    float i = 0;
    std::cout << "Введите длину в см" << ;
    std::cin >> i;
    std::cout << i / 100 << std:endl
}
//#include <iostream>
//int main()
//{
//	setlocale(LC_ALL, "RU");
//	float i = 0;
//	std::cout << "Какая температура ? ";
//	std::cin >> i;
//	if (i < 0) {
//		std::cout << "Надеть зимнюю шапку. ";
//	}
//	if ((i >= 0) && (i <= 10)) {
//		std::cout << "Надеть теплую одежду";
//	}
//	if ((i >= 11) && (i <= 20)) {
//		std::cout << "Надеть легкую одежду";
//		if (i > 20) {
//			std::cout << "Надеть летнюю одежду";
//		}
//	}
//}