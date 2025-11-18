#include <iostream>
#include <memory>
#include <iomanip>

int main() {
    setlocale(LC_ALL, "RU");
    int N, M;

    // Ввод размеров таблицы
    std::cout << "Введите количество строк N: ";
    std::cin >> N;
    std::cout << "Введите количество столбцов M: ";
    std::cin >> M;

    if (N <= 0 || M <= 0) {
        std::cout << "Размеры должны быть положительными числами!" << std::endl;
        return 1;
    }

    // Создание одномерного массива для хранения двумерной таблицы
    auto table = std::make_unique<int[]>(N * M);

    // Заполнение таблицы произведениями индексов
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            table[i * M + j] = i * j;
        }
    }

    // Вывод таблицы с отступами
    std::cout << "\nТаблица произведений индексов " << N << "?" << M << ":" << std::endl;
    std::cout << std::setw(4) << " ";
    for (int j = 0; j < M; ++j) {
        std::cout << std::setw(4) << j;
    }
    std::cout << std::endl;

    for (int i = 0; i < N; ++i) {
        std::cout << std::setw(3) << i << "|";
        for (int j = 0; j < M; ++j) {
            std::cout << std::setw(4) << table[i * M + j];
        }
        std::cout << std::endl;
    }

    return 0;
}