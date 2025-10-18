#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    // Создаем вектор из 50 значений скорости (от 0 до 180)
    vector<int> speeds(50);
    for_each(speeds.begin(), speeds.end(), [](int& speed) {
        speed = rand() % 181;  // от 0 до 180
        });

    // Выводим исходные скорости
    cout << "Исходные скорости (50 значений): ";
    for_each(speeds.begin(), speeds.end(), [](int speed) {
        cout << speed << " ";
        });
    cout << endl << endl;

    // 1. Отфильтруем превышения скорости > 120
    vector<int> filtered_speeds;
    copy_if(speeds.begin(), speeds.end(), back_inserter(filtered_speeds),
        [](int speed) { return speed <= 120; });

    cout << "После фильтрации (>120): ";
    for_each(filtered_speeds.begin(), filtered_speeds.end(), [](int speed) {
        cout << speed << " ";
        });
    cout << endl;
    cout << "Удалено превышений: " << speeds.size() - filtered_speeds.size() << endl;

    // 2. Находим среднюю скорость (по отфильтрованным данным)
    double average_speed = 0.0;
    if (!filtered_speeds.empty()) {
        average_speed = accumulate(filtered_speeds.begin(), filtered_speeds.end(), 0.0)
            / filtered_speeds.size();
        cout << "Средняя скорость: " << average_speed << " км/ч" << endl;
    }

    // 3. Определяем, были ли все значения больше 0
    bool always_moving = all_of(speeds.begin(), speeds.end(),
        [](int speed) { return speed > 0; });

    if (always_moving) {
        cout << "Автомобиль всегда двигался (все скорости > 0)" << endl;
    }
    else {
        // Находим остановки (скорость = 0)
        int stops_count = count_if(speeds.begin(), speeds.end(),
            [](int speed) { return speed == 0; });
        cout << "Автомобиль останавливался " << stops_count << " раз" << endl;
    }

    // 4. Выводим 10 максимальных значений скорости
    vector<int> sorted_speeds = speeds;
    sort(sorted_speeds.rbegin(), sorted_speeds.rend());  // сортируем по убыванию

    cout << "10 максимальных скоростей: ";
    int count = min(10, (int)sorted_speeds.size());
    for (int i = 0; i < count; i++) {
        cout << sorted_speeds[i] << " ";
    }
    cout << endl;

    // Дополнительная статистика
    cout << endl << "Дополнительная статистика:" << endl;
    auto minmax = minmax_element(speeds.begin(), speeds.end());
    cout << "Минимальная скорость: " << *minmax.first << " км/ч" << endl;
    cout << "Максимальная скорость: " << *minmax.second << " км/ч" << endl;

    // Количество превышений
    int overspeeding_count = count_if(speeds.begin(), speeds.end(),
        [](int speed) { return speed > 120; });
    cout << "Количество превышений скорости (>120): " << overspeeding_count << endl;

    return 0;
}