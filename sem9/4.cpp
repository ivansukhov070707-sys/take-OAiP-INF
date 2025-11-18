#include <iostream>
#include <memory>

int main() {
    setlocale(LC_ALL, "RU");
    // Создаем unique_ptr и инициализируем значением 42
    std::unique_ptr<int> ptr1 = std::make_unique<int>(42);

    std::cout << "После создания:" << std::endl;
    std::cout << "ptr1: " << (ptr1 ? "не пустой" : "пустой");
    if (ptr1) std::cout << ", значение = " << *ptr1;
    std::cout << std::endl;

    // Передаем владение через std::move
    std::unique_ptr<int> ptr2 = std::move(ptr1);

    std::cout << "\nПосле передачи владения через std::move:" << std::endl;
    std::cout << "ptr1: " << (ptr1 ? "не пустой" : "пустой") << std::endl;
    std::cout << "ptr2: " << (ptr2 ? "не пустой" : "пустой");
    if (ptr2) std::cout << ", значение = " << *ptr2;
    std::cout << std::endl;

    // Проверяем условие задачи
    std::cout << "\nПроверка условий:" << std::endl;
    std::cout << "ptr1 == nullptr: " << (ptr1 == nullptr ? "true" : "false") << std::endl;
    std::cout << "ptr2 хранит значение: " << (ptr2 ? "true" : "false");
    if (ptr2) std::cout << " (" << *ptr2 << ")";
    std::cout << std::endl;

    return 0;
}