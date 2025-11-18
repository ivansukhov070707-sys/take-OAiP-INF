#include <iostream>
#include <memory>
#include <cstring>
#include <cctype>

// Функция для проверки, является ли символ гласной буквой
bool isVowel(char c) {
    c = std::tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'y' || c == 'а' || c == 'е' || c == 'и' || c == 'о' ||
        c == 'у' || c == 'ы' || c == 'э' || c == 'ю' || c == 'я');
}

// Функция для проверки, является ли символ буквой
bool isAlpha(char c) {
    return std::isalpha(static_cast<unsigned char>(c));
}

int main() {
    setlocale(LC_ALL, "RU");
    // Исходная строка
    const char* originalString = "Hello, World! Programming is fun!";
    int length = std::strlen(originalString);

    std::cout << "Исходная строка: \"" << originalString << "\"" << std::endl;
    std::cout << "Длина строки: " << length << std::endl;

    // 1. Создаем динамический массив символов с помощью unique_ptr
    auto charArray = std::make_unique<char[]>(length + 1); // +1 для нуль-терминатора

    // 2. Заполняем массив строкой
    std::strcpy(charArray.get(), originalString);
    std::cout << "\nСкопированная строка: \"" << charArray.get() << "\"" << std::endl;

    // 3. Подсчитываем количество гласных и согласных
    int vowelCount = 0;
    int consonantCount = 0;
    int otherCount = 0;

    for (int i = 0; i < length; ++i) {
        char c = charArray[i];
        if (isAlpha(c)) {
            if (isVowel(c)) {
                vowelCount++;
            }
            else {
                consonantCount++;
            }
        }
        else {
            otherCount++;
        }
    }

    std::cout << "\nСтатистика строки:" << std::endl;
    std::cout << "Гласные буквы: " << vowelCount << std::endl;
    std::cout << "Согласные буквы: " << consonantCount << std::endl;
    std::cout << "Другие символы: " << otherCount << std::endl;

    // 4. Создаем новый массив только с гласными буквами
    if (vowelCount > 0) {
        auto vowelsArray = std::make_unique<char[]>(vowelCount + 1);
        int vowelIndex = 0;

        for (int i = 0; i < length; ++i) {
            if (isVowel(charArray[i])) {
                vowelsArray[vowelIndex++] = charArray[i];
            }
        }
        vowelsArray[vowelCount] = '\0'; // Добавляем нуль-терминатор

        std::cout << "\nМассив гласных букв: \"" << vowelsArray.get() << "\"" << std::endl;
        std::cout << "Количество гласных: " << vowelCount << std::endl;
    }
    else {
        std::cout << "\nВ строке нет гласных букв!" << std::endl;
    }

    // 5. Память автоматически освобождается при выходе из области видимости
    std::cout << "\nПамять будет автоматически освобождена при выходе из main()" << std::endl;

    return 0;
}