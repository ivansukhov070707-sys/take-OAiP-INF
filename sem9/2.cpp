#include <iostream>
#include <memory>

int main() {
    setlocale(LC_ALL, "RU");
    int N;

    // Ввод размера массива
    std::cout << "Введите размер массива N: ";
    std::cin >> N;

    // Проверка корректности ввода
    if (N <= 0) {
        std::cout << "Размер массива должен быть положительным числом!" << std::endl;
        return 1;
    }

    // Создание динамического массива через unique_ptr<int[]>
    auto arr = std::make_unique<int[]>(N);

    // Заполнение массива числами от 1 до N
    for (int i = 0; i < N; ++i) {
        arr[i] = i + 1;
    }

    // Вывод содержимого массива
    std::cout << "Содержимое массива:" << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}