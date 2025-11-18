#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <iomanip>

int main() {
    setlocale(LC_ALL, "RU");
    int N;

    // Ввод количества измерений
    std::cout << "Введите количество измерений: ";
    std::cin >> N;

    if (N <= 0) {
        std::cout << "Количество измерений должно быть положительным!" << std::endl;
        return 1;
    }

    // Создаем и заполняем вектор сигналов
    std::vector<double> signals(N);
    std::cout << "Введите " << N << " значений температуры:" << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << "Сигнал " << i + 1 << ": ";
        std::cin >> signals[i];
    }

    // Вывод исходных данных
    std::cout << "\nИсходные данные: ";
    for (double val : signals) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Создаем динамический массив через unique_ptr и копируем значения
    auto signals_ptr = std::make_unique<double[]>(N);
    for (int i = 0; i < N; ++i) {
        signals_ptr[i] = signals[i];
    }

    // Лямбда-функция для вычисления среднего значения
    auto mean = [](const std::unique_ptr<double[]>& arr, int size) -> double {
        double sum = 0.0;
        for (int i = 0; i < size; ++i) {
            sum += arr[i];
        }
        return sum / size;
        };

    // Лямбда-функция для нормализации
    auto normalize = [](std::unique_ptr<double[]>& arr, int size, double max_val) {
        if (max_val == 0) return;
        for (int i = 0; i < size; ++i) {
            arr[i] /= max_val;
        }
        };

    // Лямбда-функция для копирования обратно в вектор
    auto copyBack = [&](const std::unique_ptr<double[]>& arr, int size) {
        for (int i = 0; i < size; ++i) {
            signals[i] = arr[i];
        }
        };

    // Вычисляем среднее значение
    double average = mean(signals_ptr, N);
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Среднее значение: " << average << std::endl;

    // Находим максимальное значение для нормализации
    double max_signal = *std::max_element(signals.begin(), signals.end());

    // Нормализуем данные
    normalize(signals_ptr, N, max_signal);

    // Копируем нормализованные значения обратно в вектор
    copyBack(signals_ptr, N);

    // Выводим нормализованные сигналы
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "Нормализованные сигналы: ";
    for (double val : signals) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}