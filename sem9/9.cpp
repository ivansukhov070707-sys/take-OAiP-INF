#include <iostream>
#include <memory>
#include <vector>

// Функция увеличивает все элементы на 1
void processA(std::shared_ptr<std::vector<int>> buf) {
    std::cout << "processA: увеличиваем все элементы на 1" << std::endl;
    for (auto& num : *buf) {
        num += 1;
    }
}

// Функция умножает все элементы на 2
void processB(std::shared_ptr<std::vector<int>> buf) {
    std::cout << "processB: умножаем все элементы на 2" << std::endl;
    for (auto& num : *buf) {
        num *= 2;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    // Создаем общий буфер
    auto buffer = std::make_shared<std::vector<int>>();

    // Заполняем числами 1-10
    for (int i = 1; i <= 10; i++) {
        buffer->push_back(i);
    }

    // Выводим исходный буфер
    std::cout << "Исходный буфер: ";
    for (auto num : *buffer) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "use_count: " << buffer.use_count() << std::endl << std::endl;

    // Вызываем функции обработки
    processA(buffer);
    std::cout << "После processA: ";
    for (auto num : *buffer) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "use_count: " << buffer.use_count() << std::endl << std::endl;

    processB(buffer);
    std::cout << "После processB: ";
    for (auto num : *buffer) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "use_count: " << buffer.use_count() << std::endl;

    return 0;
}