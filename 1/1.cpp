#include <iostream>
using namespace std;

class BankAccount {
public:
    string num;
    string name;
    double balance;

    BankAccount(string n, string nm, double b = 0) {
        num = n;
        name = nm;
        balance = b;
    }

    void deposit(double a) {
        balance += a;
        cout << "+" << a << " Баланс: " << balance << endl;
    }

    void withdraw(double a) {
        if (a <= balance) {
            balance -= a;
            cout << "-" << a << " Баланс: " << balance << endl;
        }
        else {
            cout << "Недостаточно!" << endl;
        }
    }

    void info() {
        cout << "Счет: " << num << " " << name << " " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
public:
    double rate;

    SavingsAccount(string n, string nm, double b, double r)
        : BankAccount(n, nm, b) {
        rate = r;
    }

    void addInterest() {
        double add = balance * rate / 100;
        balance += add;
        cout << "Проценты: " << add << " Баланс: " << balance << endl;
    }
};

int main() {
    BankAccount a1("123", "Алексей", 1000);
    a1.deposit(500);
    a1.withdraw(200);
    a1.info();

    cout << endl;
    SavingsAccount a2("456", "Мария", 5000, 5);
    a2.deposit(1000);
    a2.addInterest();
    a2.info();

    return 0;
}