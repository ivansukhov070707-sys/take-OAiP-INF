#include <iostream>
#include <memory>

int main() {
    setlocale(LC_ALL, "RU");
    // 1. Создаем умный указатель и выделяем память с помощью make_unique
    std::unique_ptr<int> ptr = std::make_unique<int>();

    // 2. Присваиваем значение 10 и выводим на экран
    *ptr = 10;
    std::cout << "Значение после первого присваивания: " << *ptr << std::endl;

    // 3. Изменяем значение на 25 и снова выводим
    *ptr = 25;
    std::cout << "Значение после изменения: " << *ptr << std::endl;

    return 0;
}