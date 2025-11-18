#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <unordered_set>

int main() {
    setlocale(LC_ALL, "RU");
    // Исходный журнал сообщений
    std::vector<std::string> logs = {
        "INFO: Start",
        "ERROR: Disk failure",
        "WARNING: Low memory",
        "ERROR: Disk failure",
        "INFO: Stop",
        "ERROR: Network timeout",
        "WARNING: High CPU usage",
        "ERROR: Network timeout"
    };

    // Обертываем вектор в shared_ptr
    auto pLogs = std::make_shared<std::vector<std::string>>(logs);

    // Выводим исходный журнал
    std::cout << "Исходный журнал:" << std::endl;
    for (const auto& log : *pLogs) {
        std::cout << log << std::endl;
    }
    std::cout << std::endl;

    // Создаем коллекцию для сообщений об ошибках
    std::vector<std::string> errors;

    // Лямбда-функция для фильтрации ошибок
    auto filterErrors = [](std::shared_ptr<std::vector<std::string>> logs_ptr) {
        std::vector<std::string> result;
        for (const auto& log : *logs_ptr) {
            if (log.find("ERROR:") == 0) { // Начинается с "ERROR:"
                result.push_back(log);
            }
        }
        return result;
        };

    // Лямбда-функция для удаления дубликатов
    auto removeDuplicates = [](std::vector<std::string>& vec) {
        std::unordered_set<std::string> seen;
        std::vector<std::string> result;

        for (const auto& str : vec) {
            if (seen.find(str) == seen.end()) {
                seen.insert(str);
                result.push_back(str);
            }
        }
        return result;
        };

    // Лямбда-функция для вывода результатов
    auto printResults = [](const std::vector<std::string>& errors) {
        std::cout << "Уникальные ошибки:" << std::endl;
        for (const auto& error : errors) {
            std::cout << error << std::endl;
        }
        };

    // Применяем фильтрацию
    errors = filterErrors(pLogs);

    // Удаляем дубликаты
    errors = removeDuplicates(errors);

    // Выводим результаты
    printResults(errors);

    // Дополнительная информация
    std::cout << "\nСтатистика:" << std::endl;
    std::cout << "Всего записей в журнале: " << pLogs->size() << std::endl;
    std::cout << "Уникальных ошибок: " << errors.size() << std::endl;
    std::cout << "use_count pLogs: " << pLogs.use_count() << std::endl;

    return 0;
}