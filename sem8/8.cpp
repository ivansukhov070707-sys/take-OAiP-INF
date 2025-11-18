#include <iostream>
#include <iomanip>

// Функция выделения памяти для пластины
double** allocatePlate(int n, int m) {
    setlocale(LC_ALL, "RU");
    double** plate = new double* [n];
    for (int i = 0; i < n; ++i) {
        plate[i] = new double[m];
    }
    return plate;
}

// Функция освобождения памяти
void freePlate(double** plate, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] plate[i];
    }
    delete[] plate;
}

// Функция инициализации пластины
void initializePlate(double** plate, int n, int m) {
    // Инициализируем всю пластину температурой 20.0
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            plate[i][j] = 20.0;
        }
    }

    // Устанавливаем нагреватель в центре
    int center_i = n / 2;
    int center_j = m / 2;
    plate[center_i][center_j] = 100.0;
}

// Функция обновления температуры
void updateTemperature(double** current, double** next, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // Пропускаем нагреватель в центре (фиксированная температура)
            if (i == n / 2 && j == m / 2) {
                next[i][j] = 100.0;
                continue;
            }

            double sum = 0.0;
            int count = 0;

            // Проверяем верхнего соседа
            if (i > 0) {
                sum += current[i - 1][j];
                count++;
            }
            // Проверяем нижнего соседа
            if (i < n - 1) {
                sum += current[i + 1][j];
                count++;
            }
            // Проверяем левого соседа
            if (j > 0) {
                sum += current[i][j - 1];
                count++;
            }
            // Проверяем правого соседа
            if (j < m - 1) {
                sum += current[i][j + 1];
                count++;
            }

            // Вычисляем среднюю температуру
            if (count > 0) {
                next[i][j] = sum / count;
            }
            else {
                next[i][j] = current[i][j];
            }
        }
    }
}

// Функция для вывода пластины
void printPlate(double** plate, int n, int m) {
    std::cout << std::fixed << std::setprecision(1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << std::setw(6) << plate[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Основная функция симуляции
void simulateHeatTransfer(int n, int m, int iterations) {
    // Выделяем память для двух пластин (текущая и следующая)
    double** current = allocatePlate(n, m);
    double** next = allocatePlate(n, m);

    // Инициализируем начальное состояние
    initializePlate(current, n, m);

    std::cout << "Начальное состояние пластины:" << std::endl;
    printPlate(current, n, m);

    // Выполняем итерации
    for (int iter = 0; iter < iterations; ++iter) {
        updateTemperature(current, next, n, m);

        // Меняем указатели местами
        double** temp = current;
        current = next;
        next = temp;

        if ((iter + 1) % 10 == 0) {
            std::cout << "После " << iter + 1 << " итераций:" << std::endl;
            printPlate(current, n, m);
        }
    }

    std::cout << "Финальное состояние после " << iterations << " итераций:" << std::endl;
    printPlate(current, n, m);

    // Освобождаем память
    freePlate(current, n);
    freePlate(next, n);
}

int main() {
    const int N = 7;  // Размер пластины по вертикали
    const int M = 7;  // Размер пластины по горизонтали
    const int K = 30; // Количество итераций

    std::cout << "Моделирование теплопередачи на пластине " << N << "x" << M << std::endl;
    std::cout << "Количество итераций: " << K << std::endl;
    std::cout << "Нагреватель в центре: 100.0°C" << std::endl;
    std::cout << "Начальная температура: 20.0°C" << std::endl << std::endl;

    simulateHeatTransfer(N, M, K);

    return 0;
}