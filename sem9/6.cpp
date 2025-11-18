#include <iostream>
#include <memory>

int main() {
    setlocale(LC_ALL, "RU");
    // Создаем shared_ptr и инициализируем значением 100
    std::shared_ptr<int> ptr1 = std::make_shared<int>(100);

    std::cout << "После создания ptr1:" << std::endl;
    std::cout << "ptr1 значение: " << *ptr1 << std::endl;
    std::cout << "use_count(): " << ptr1.use_count() << std::endl;
    std::cout << std::endl;

    // Создаем копии (разделяем владение)
    std::shared_ptr<int> ptr2 = ptr1;
    std::cout << "После создания ptr2 = ptr1:" << std::endl;
    std::cout << "ptr2 значение: " << *ptr2 << std::endl;
    std::cout << "use_count(): " << ptr1.use_count() << std::endl;
    std::cout << std::endl;

    // Создаем третью копию
    std::shared_ptr<int> ptr3 = ptr1;
    std::cout << "После создания ptr3 = ptr1:" << std::endl;
    std::cout << "ptr3 значение: " << *ptr3 << std::endl;
    std::cout << "use_count(): " << ptr1.use_count() << std::endl;
    std::cout << std::endl;

    // Уничтожаем одну из копий (выход из scope)
    {
        std::shared_ptr<int> ptr4 = ptr1;
        std::cout << "Внутри блока после создания ptr4:" << std::endl;
        std::cout << "use_count(): " << ptr1.use_count() << std::endl;
    }

    std::cout << "После выхода из блока (ptr4 уничтожен):" << std::endl;
    std::cout << "use_count(): " << ptr1.use_count() << std::endl;
    std::cout << std::endl;

    // Явно уничтожаем ptr2
    ptr2.reset();
    std::cout << "После ptr2.reset():" << std::endl;
    std::cout << "ptr2: " << (ptr2 ? "не пустой" : "пустой") << std::endl;
    std::cout << "use_count(): " << ptr1.use_count() << std::endl;

    return 0;
}