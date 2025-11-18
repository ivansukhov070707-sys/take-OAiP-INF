#include <iostream>
#include <memory>
#include <vector>
#include <iomanip>

int main() {
    setlocale(LC_ALL, "RU");
    int N, M;

    // Ввод размеров матрицы
    std::cout << "Введите размеры матрицы N и M: ";
    std::cin >> N >> M;

    if (N <= 0 || M <= 0) {
        std::cout << "Размеры должны быть положительными!" << std::endl;
        return 1;
    }

    // Создание динамической матрицы
    auto matrix = std::make_unique<double[]>(N * M);

    // Заполнение матрицы
    std::cout << "Введите элементы матрицы " << N << "x" << M << ":" << std::endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << "Элемент [" << i << "][" << j << "]: ";
            std::cin >> matrix[i * M + j];
        }
    }

    // Вывод матрицы
    std::cout << "\nВведенная матрица:" << std::endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << std::setw(6) << matrix[i * M + j] << " ";
        }
        std::cout << std::endl;
    }

    // Лямбда для вычисления сумм столбцов
    auto sumColumns = [](const std::unique_ptr<double[]>& mat, int n, int m) {
        std::vector<double> columnSums(m, 0.0);
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                columnSums[j] += mat[i * m + j];
            }
        }
        return columnSums;
        };

    // Лямбда для нахождения индекса максимального элемента
    auto maxIndex = [](const std::vector<double>& vec) {
        int maxIdx = 0;
        double maxVal = vec[0];
        for (size_t i = 1; i < vec.size(); ++i) {
            if (vec[i] > maxVal) {
                maxVal = vec[i];
                maxIdx = i;
            }
        }
        return std::make_pair(maxIdx, maxVal);
        };

    // Вычисляем суммы столбцов
    std::vector<double> columnSums = sumColumns(matrix, N, M);

    // Находим столбец с максимальной суммой
    auto result = maxIndex(columnSums);
    int maxColIndex = result.first;
    double maxSum = result.second;

    // Вывод результатов
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "\nСуммы столбцов: [";
    for (size_t i = 0; i < columnSums.size(); ++i) {
        std::cout << columnSums[i];
        if (i < columnSums.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    std::cout << "Столбец с максимальной суммой: " << (maxColIndex + 1)
        << " (" << maxSum << ")" << std::endl;

    return 0;
}