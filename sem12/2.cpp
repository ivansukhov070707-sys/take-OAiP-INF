#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Структура для банковского счета
struct BankAccount {
    string accountNumber;  // Номер счета
    string ownerName;      // Имя владельца
    double balance;        // Баланс

    // Конструктор
    BankAccount(string num = "", string name = "", double bal = 0.0) {
        accountNumber = num;
        ownerName = name;
        balance = bal;
    }
};

// Функция для поиска счета по номеру
int findAccount(const vector<BankAccount>& accounts, const string& accountNumber) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].accountNumber == accountNumber) {
            return i;  // Возвращаем индекс найденного счета
        }
    }
    return -1;  // Счет не найден
}

// Функция для вывода меню
void displayMenu() {
    cout << "\n=== БАНКОВСКАЯ СИСТЕМА ===" << endl;
    cout << "1. Создать новый банковский счет" << endl;
    cout << "2. Пополнить счет" << endl;
    cout << "3. Снять деньги со счета" << endl;
    cout << "4. Показать информацию о счете" << endl;
    cout << "5. Выйти" << endl;
    cout << "Выберите действие: ";
}

int main() {
    vector<BankAccount> accounts;
    int choice;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore();  // Очищаем буфер

        switch (choice) {
        case 1: {
            // Создание нового счета
            string accNum, name;

            cout << "\n--- Создание нового счета ---" << endl;
            cout << "Введите номер счета: ";
            getline(cin, accNum);

            cout << "Введите имя владельца счета: ";
            getline(cin, name);

            // Проверяем, не существует ли уже такой счет
            if (findAccount(accounts, accNum) != -1) {
                cout << "Ошибка: счет с таким номером уже существует!" << endl;
                break;
            }

            // Создаем новый счет
            BankAccount newAccount(accNum, name, 0.0);
            accounts.push_back(newAccount);

            cout << "Банковский счет создан." << endl;
            break;
        }

        case 2: {
            // Пополнение счета
            string accNum;
            double amount;

            cout << "\n--- Пополнение счета ---" << endl;
            cout << "Введите номер счета для пополнения: ";
            getline(cin, accNum);

            int index = findAccount(accounts, accNum);
            if (index == -1) {
                cout << "Ошибка: счет не найден!" << endl;
                break;
            }

            cout << "Введите сумму для пополнения: ";
            cin >> amount;
            cin.ignore();

            if (amount <= 0) {
                cout << "Ошибка: сумма должна быть положительной!" << endl;
                break;
            }

            accounts[index].balance += amount;
            cout << "Счет пополнен на " << amount << " рублей." << endl;
            break;
        }

        case 3: {
            // Снятие денег
            string accNum;
            double amount;

            cout << "\n--- Снятие денег со счета ---" << endl;
            cout << "Введите номер счета для снятия: ";
            getline(cin, accNum);

            int index = findAccount(accounts, accNum);
            if (index == -1) {
                cout << "Ошибка: счет не найден!" << endl;
                break;
            }

            cout << "Введите сумму для снятия: ";
            cin >> amount;
            cin.ignore();

            if (amount <= 0) {
                cout << "Ошибка: сумма должна быть положительной!" << endl;
                break;
            }

            if (amount > accounts[index].balance) {
                cout << "Ошибка: недостаточно средств на счете!" << endl;
                cout << "Доступно: " << accounts[index].balance << " рублей." << endl;
                break;
            }

            accounts[index].balance -= amount;
            cout << "Со счета снято " << amount << " рублей." << endl;
            break;
        }

        case 4: {
            // Показать информацию о счете
            string accNum;

            cout << "\n--- Информация о счете ---" << endl;
            cout << "Введите номер счета для показа информации: ";
            getline(cin, accNum);

            int index = findAccount(accounts, accNum);
            if (index == -1) {
                cout << "Ошибка: счет не найден!" << endl;
                break;
            }

            cout << "\nНомер счета: " << accounts[index].accountNumber << endl;
            cout << "Имя владельца счета: " << accounts[index].ownerName << endl;
            cout << "Баланс: " << accounts[index].balance << " рублей" << endl;
            break;
        }

        case 5: {
            cout << "\nПрограмма завершена." << endl;
            break;
        }

        default: {
            cout << "Ошибка: неверный выбор! Попробуйте снова." << endl;
            break;
        }
        }

    } while (choice != 5);

    return 0;
}