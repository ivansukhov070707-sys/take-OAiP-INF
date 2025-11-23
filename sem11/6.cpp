#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    string categories[] = { "Электроника", "Аксессуары", "Одежда", "Книги", "Спорт", "Мебель", "Игрушки", "Красота" };
    string products[] = { "Ноутбук", "Мышь", "Клавиатура", "Монитор", "Телефон", "Наушники", "Планшет", "Часы",
                        "Футболка", "Джинсы", "Кроссовки", "Роман", "Учебник", "Мяч", "Стул", "Стол",
                        "Кукла", "Машинка", "Крем", "Шампунь" };

    ofstream csvFile("products.csv");
    if (!csvFile) {
        cout << "Ошибка создания файла!" << endl;
        return 1;
    }

    csvFile << "id,name,category,price,quantity" << endl;

    for (int i = 1; i <= 20; i++) {
        string name = products[rand() % 20];
        string category = categories[rand() % 8];
        double price = (rand() % 9900 + 100) + (rand() % 100) / 100.0;
        int quantity = rand() % 100 + 1;

        csvFile << i << "," << name << " " << to_string(rand() % 1000)
            << "," << category << "," << fixed << setprecision(2) << price
            << "," << quantity << endl;
    }

    csvFile.close();

    ifstream checkFile("products.csv");
    if (!checkFile) {
        cout << "Ошибка проверки файла!" << endl;
        return 1;
    }

    string line;
    int lineCount = 0;
    while (getline(checkFile, line)) {
        lineCount++;
    }
    checkFile.close();

    cout << "Файл products.csv успешно создан!" << endl;
    cout << "Количество записей: " << lineCount - 1 << " (плюс заголовок)" << endl;

    return 0;
}