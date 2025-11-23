#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Product {
    int id;
    string name;
    string category;
    double price;
    int quantity;
};

vector<Product> readProducts(const string& filename) {
    vector<Product> products;
    ifstream csvFile(filename);
    if (!csvFile) {
        cout << "Ошибка открытия файла!" << endl;
        return products;
    }

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
    return products;
}

void writeProducts(const vector<Product>& products, const string& filename) {
    ofstream csvFile(filename);
    if (!csvFile) {
        cout << "Ошибка создания файла!" << endl;
        return;
    }

    csvFile << "id,name,category,price,quantity" << endl;
    for (const auto& product : products) {
        csvFile << product.id << "," << product.name << "," << product.category
            << "," << fixed << setprecision(2) << product.price
            << "," << product.quantity << endl;
    }
    csvFile.close();
}

int main() {
    vector<Product> products = readProducts("products.csv");
    if (products.empty()) {
        return 1;
    }

    int choice;
    cout << "Выберите критерий сортировки:" << endl;
    cout << "1 - По цене (от дешевых к дорогим)" << endl;
    cout << "2 - По цене (от дорогих к дешевым)" << endl;
    cout << "3 - По названию (алфавитный порядок)" << endl;
    cout << "4 - По количеству (от большего к меньшему)" << endl;
    cout << "Введите номер: ";
    cin >> choice;

    if (choice == 1) {
        auto priceAsc = [](const Product& a, const Product& b) { return a.price < b.price; };
        sort(products.begin(), products.end(), priceAsc);
    }
    else if (choice == 2) {
        auto priceDesc = [](const Product& a, const Product& b) { return a.price > b.price; };
        sort(products.begin(), products.end(), priceDesc);
    }
    else if (choice == 3) {
        auto nameAsc = [](const Product& a, const Product& b) { return a.name < b.name; };
        sort(products.begin(), products.end(), nameAsc);
    }
    else if (choice == 4) {
        auto quantityDesc = [](const Product& a, const Product& b) { return a.quantity > b.quantity; };
        sort(products.begin(), products.end(), quantityDesc);
    }
    else {
        cout << "Неверный выбор!" << endl;
        return 1;
    }

    writeProducts(products, "sorted_products.csv");

    cout << "Товары отсортированы и сохранены в sorted_products.csv" << endl;

    return 0;
}