#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    setlocale(LC_ALL, "RU");
    // Создаем три указателя на части отчета
    std::unique_ptr<std::string> part1 = std::make_unique<std::string>("Sensor data:");
    std::unique_ptr<std::string> part2 = std::make_unique<std::string>("Voltage stable.");
    std::unique_ptr<std::string> part3 = std::make_unique<std::string>("System nominal.");

    // Сохраняем в вектор
    std::vector<std::unique_ptr<std::string>> reportParts;
    reportParts.push_back(std::move(part1));
    reportParts.push_back(std::move(part2));
    reportParts.push_back(std::move(part3));

    // Лямбда-функция для объединения частей
    auto concatParts = [](const std::vector<std::unique_ptr<std::string>>& parts) {
        std::string result;
        for (const auto& part : parts) {
            if (!result.empty()) {
                result += "\n";
            }
            result += *part;
        }
        return result;
        };

    // Лямбда-функция для подсчета вхождений слова
    auto countWord = [](const std::string& text, const std::string& word) {
        int count = 0;
        size_t pos = 0;
        while ((pos = text.find(word, pos)) != std::string::npos) {
            count++;
            pos += word.length();
        }
        return count;
        };

    // Объединяем части в один текст
    std::string report = concatParts(reportParts);

    // Подсчитываем вхождения слова "data"
    int wordCount = countWord(report, "data");

    // Выводим результаты
    std::cout << "Отчёт:" << std::endl;
    std::cout << report << std::endl;
    std::cout << "Слово \"data\" встречается " << wordCount << " раз" << std::endl;

    return 0;
}