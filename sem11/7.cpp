#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

struct Product {
    int id;
    string name;
    string category;
    double price;
    int quantity;
};

int main() {
    ifstream csvFile("products.csv");
    if (!csvFile) {
        cout << "Ошибка открытия файла products.csv!" << endl;
        return 1;
    }

    vector<Product> products;
    string line;
    getline(csvFile, line);

    while (getline(csvFile, line)) {
        stringstream ss(line);
        string token;
        Product product;

        getline(ss, token, ',');
        product.id = stoi(token);

        getline(ss, product.name, ',');
        getline(ss, product.category, ',');

        getline(ss, token, ',');
        product.price = stod(token);

        getline(ss, token, ',');
        product.quantity = stoi(token);

        products.push_back(product);
    }
    csvFile.close();

    cout << "Список всех товаров:" << endl;
    int totalQuantity = 0;
    double totalValue = 0;
    Product mostExpensive = products[0];
    Product cheapest = products[0];

    for (const auto& product : products) {
        cout << "ID: " << product.id << endl;
        cout << "Название: " << product.name << endl;
        cout << "Категория: " << product.category << endl;
        cout << "Цена: " << fixed << setprecision(2) << product.price << " руб." << endl;
        cout << "Количество: " << product.quantity << " шт." << endl;

        totalQuantity += product.quantity;
        totalValue += product.price * product.quantity;

        if (product.price > mostExpensive.price) {
            mostExpensive = product;
        }
        if (product.price < cheapest.price) {
            cheapest = product;
        }
    }

    cout << "СТАТИСТИКА:" << endl;
    cout << "Общее количество товаров: " << totalQuantity << " шт." << endl;
    cout << "Суммарная стоимость: " << fixed << setprecision(2) << totalValue << " руб." << endl;
    cout << "Самый дорогой товар: " << mostExpensive.name << " (" << mostExpensive.price << " руб.)" << endl;
    cout << "Самый дешевый товар: " << cheapest.name << " (" << cheapest.price << " руб.)" << endl;

    return 0;
}