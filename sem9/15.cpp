#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <string>

int main() {
    setlocale(LC_ALL, "RU");
    // Исходный список маршрутов
    std::vector<std::string> routes = {
        "Moscow-Berlin",
        "Berlin-Paris",
        "Paris-Rome",
        "Rome-Moscow"
    };

    // Создаем shared_ptr для вектора маршрутов
    auto ptrRoutes = std::make_shared<std::vector<std::string>>(routes);

    // Лямбда для подсчета маршрутов с заданным городом
    auto countCity = [](std::shared_ptr<std::vector<std::string>> routesPtr,
        const std::string& city) {
            int count = 0;
            for (const auto& route : *routesPtr) {
                if (route.find(city) != std::string::npos) {
                    count++;
                }
            }
            return count;
        };

    // Лямбда для сортировки маршрутов по длине (по убыванию)
    auto sortByLength = [](std::shared_ptr<std::vector<std::string>> routesPtr) {
        std::sort(routesPtr->begin(), routesPtr->end(),
            [](const std::string& a, const std::string& b) {
                return a.length() > b.length();
            });
        };

    // Лямбда для объединения маршрутов в одну строку
    auto concat = [](std::shared_ptr<std::vector<std::string>> routesPtr) {
        std::string result;
        for (size_t i = 0; i < routesPtr->size(); ++i) {
            if (i > 0) {
                result += " -> ";
            }
            result += (*routesPtr)[i];
        }
        return result;
        };

    // Подсчитываем маршруты с "Paris"
    int parisCount = countCity(ptrRoutes, "Paris");
    std::cout << "Количество маршрутов с \"Paris\": " << parisCount << std::endl;

    // Сортируем маршруты по длине
    sortByLength(ptrRoutes);

    // Выводим отсортированные маршруты
    std::cout << "Отсортированные маршруты:" << std::endl;
    for (const auto& route : *ptrRoutes) {
        std::cout << route << std::endl;
    }

    // Объединяем маршруты в одну строку
    std::string combinedRoute = concat(ptrRoutes);
    std::cout << "Общий маршрут:" << std::endl;
    std::cout << combinedRoute << std::endl;

    return 0;
}