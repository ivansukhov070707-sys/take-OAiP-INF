#include <iostream>
#include <memory>
#include <iomanip>

// Функция для вычисления среднего значения массива
double calculateAverage(const std::unique_ptr<double[]>& data, int size) {
    if (size == 0) return 0.0;

    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += data[i];
    }
    return sum / size;
}

int main() {
    const int DATA_SIZE = 5;

    // 1. Создаем три unique_ptr для разных параметров
    auto temperatures = std::make_unique<double[]>(DATA_SIZE);
    auto pressures = std::make_unique<double[]>(DATA_SIZE);
    auto humidities = std::make_unique<double[]>(DATA_SIZE);

    // 2. Заполняем массивы значениями вручную

    // Температуры (°C)
    temperatures[0] = 22.5;
    temperatures[1] = 23.1;
    temperatures[2] = 21.8;
    temperatures[3] = 24.2;
    temperatures[4] = 22.9;

    // Давления (мм рт. ст.)
    pressures[0] = 755.2;
    pressures[1] = 756.8;
    pressures[2] = 754.5;
    pressures[3] = 757.1;
    pressures[4] = 755.9;

    // Влажности (%)
    humidities[0] = 65.0;
    humidities[1] = 62.5;
    humidities[2] = 68.2;
    humidities[3] = 60.8;
    humidities[4] = 63.7;

    // 3. Вычисляем средние значения
    double avgTemp = calculateAverage(temperatures, DATA_SIZE);
    double avgPressure = calculateAverage(pressures, DATA_SIZE);
    double avgHumidity = calculateAverage(humidities, DATA_SIZE);

    // 4. Выводим исходные данные
    std::cout << "Исходные данные:" << std::endl;
    std::cout << std::fixed << std::setprecision(1);

    std::cout << "Температуры: ";
    for (int i = 0; i < DATA_SIZE; ++i) {
        std::cout << temperatures[i] << "°C ";
    }
    std::cout << std::endl;

    std::cout << "Давления:    ";
    for (int i = 0; i < DATA_SIZE; ++i) {
        std::cout << pressures[i] << "мм ";
    }
    std::cout << std::endl;

    std::cout << "Влажности:   ";
    for (int i = 0; i < DATA_SIZE; ++i) {
        std::cout << humidities[i] << "% ";
    }
    std::cout << std::endl << std::endl;

    // 5. Выводим таблицу с результатами
    std::cout << " Параметр          Среднее значение " << std::endl;

    std::cout << " " << std::left << std::setw(16) << "Температура"
        << "  " << std::right << std::setw(14) << std::setprecision(1)
        << avgTemp << "°C " << std::endl;

    std::cout << "  " << std::left << std::setw(16) << "Давление"
        << "  " << std::right << std::setw(14) << std::setprecision(1)
        << avgPressure << "мм " << std::endl;

    std::cout << " " << std::left << std::setw(16) << "Влажность"
        << "  " << std::right << std::setw(14) << std::setprecision(1)
        << avgHumidity << "% " << std::endl;

    return 0;
}