//#include <iostream>
//int main()
//{
//    setlocale(LC_ALL, "RU");
//    float i = 0;
//    std::cout << "Введите длину в см" << std::endl;
//    std::cin >> i;
//    std::cout << i / 100 << std::endl;
//}
//#include <iostream>
//int main()
//{
//    setlocale(LC_ALL, "RU");
//    float i = 0;
//    float b = 0;
//    std::cout << "Введите длину" << std::endl;
//    std::cin >> i;
//    std::cout << "Введите ширину" << std::endl;
//    std::cin >> b;
//    std::cout << i * b << std::endl;
//}
//#include <iostream>
//int main()
//{
//    setlocale(LC_ALL, "RU");
//    float i = 0;
//    std::cout << "Сколько градусов?" << std::endl;
//    std::cin >> i;
//    std::cout << i * 9 / 5 + 32 << std::endl;
//}
//#include <iostream>
//int main()
//{
//    setlocale(LC_ALL, "RU");
//    int i = 0;
//    std::cout << "Введите число" << std::endl;
//    std::cin >> i;
//    if (i % 2 == 0) {
//        std::cout << "Число четное" << std::endl;
//    }
//    else {
//        std::cout << "Число нечетное" << std::endl;
//    }
//}
//#include <iostream>
//int main()
//{
//    setlocale(LC_ALL, "RU");
//    int i = 0;
//    std::cout << "Введите число" << std::endl;
//    std::cin >> i;
//    if ((i % 3 == 0) && (i % 5 == 0)) {
//        std::cout << "Делится на 5 и на 3" << std::endl;
//    }
//    if ((i % 3 == 0) && (i % 5 != 0)) {
//        std::cout << "Делится на 3" << std::endl;
//    }
//    if ((i%3!=0)&&(i%5==0)) {
//        std::cout << "Делится на 5" << std::endl;
//    }
//}
//#include <iostream>
//int main()
//{
//    setlocale(LC_ALL, "RU");
//    int i = 0;
//    int k = 0;
//    std::cout << "Введите число" << std::endl;
//    std::cin >> i;
//    while (i > k) {
//        k += 1;
//        std::cout << pow(k, 2) << std::endl;
//    }
//}
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() 
//{
//    setlocale(LC_ALL, "RU");
//    string s;
//    int i = 0;
//    cout << "Введите строку: ";
//    getline(cin, s);
//    string vowels = "aeiouAEIOU";
//    for (char c : s) 
//    {
//        for (char v : vowels) 
//        {
//            if (c == v) 
//            {
//                i++;
//                break;
//            }
//        }
//    }
//    cout << "Количество гласных букв в строке: " << i << endl;
//    return 0;
//}
	