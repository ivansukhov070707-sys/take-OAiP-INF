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
    cout << "Выберите критерий фильтрации:" << endl;
    cout << "1 - Товары дороже указанной цены" << endl;
    cout << "2 - Товары дешевле указанной цены" << endl;
    cout << "3 - Товары из определенной категории" << endl;
    cout << "4 - Товары с количеством больше указанного" << endl;
    cout << "Введите номер: ";
    cin >> choice;

    vector<Product> filteredProducts;

    if (choice == 1) {
        double minPrice;
        cout << "Введите минимальную цену: ";
        cin >> minPrice;

        auto priceFilter = [minPrice](const Product& p) { return p.price > minPrice; };
        copy_if(products.begin(), products.end(), back_inserter(filteredProducts), priceFilter);
    }
    else if (choice == 2) {
        double maxPrice;
        cout << "Введите максимальную цену: ";
        cin >> maxPrice;

        auto priceFilter = [maxPrice](const Product& p) { return p.price < maxPrice; };
        copy_if(products.begin(), products.end(), back_inserter(filteredProducts), priceFilter);
    }
    else if (choice == 3) {
        string category;
        cout << "Введите категорию: ";
        cin.ignore();
        getline(cin, category);

        auto categoryFilter = [category](const Product& p) { return p.category == category; };
        copy_if(products.begin(), products.end(), back_inserter(filteredProducts), categoryFilter);
    }
    else if (choice == 4) {
        int minQuantity;
        cout << "Введите минимальное количество: ";
        cin >> minQuantity;

        auto quantityFilter = [minQuantity](const Product& p) { return p.quantity > minQuantity; };
        copy_if(products.begin(), products.end(), back_inserter(filteredProducts), quantityFilter);
    }
    else {
        cout << "Неверный выбор!" << endl;
        return 1;
    }

    writeProducts(filteredProducts, "filtered_products.csv");

    cout << "Найдено товаров: " << filteredProducts.size() << endl;
    cout << "Результаты сохранены в filtered_products.csv" << endl;

    return 0;
}