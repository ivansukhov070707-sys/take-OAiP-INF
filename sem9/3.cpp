#include <iostream>
#include <memory>

// Функция для заполнения массива квадратами индексов
void fillArray(std::unique_ptr<int[]>& arr, int n) {
    for (int i = 0; i < n; ++i) {
        arr[i] = i * i;
    }
}
int main() {
    setlocale(LC_ALL, "RU");
    int n;

    // Ввод размера массива
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Размер массива должен быть положительным числом!" << std::endl;
        return 1;
    }

    // Создание unique_ptr для массива
    auto arr = std::make_unique<int[]>(n);

    // Передача по ссылке в функцию заполнения
    fillArray(arr, n);

    // Вывод результатов
    std::cout << "Массив квадратов:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "arr[" << i << "] = " << i << "? = " << arr[i] << std::endl;
    }

    return 0;
}