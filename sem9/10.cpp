#include <iostream>
#include <memory>

// Функция создает и заполняет массив
std::unique_ptr<int[]> createArray(int n) {
    auto arr = std::make_unique<int[]>(n);
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    return arr; // Неявный std::move
}

int main() {
    setlocale(LC_ALL, "RU");
    int n;

    std::cout << "Введите размер массива: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Размер должен быть положительным!" << std::endl;
        return 1;
    }

    // Получаем unique_ptr из функции
    auto array = createArray(n);

    // Выводим элементы
    std::cout << "Массив: ";
    for (int i = 0; i < n; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}