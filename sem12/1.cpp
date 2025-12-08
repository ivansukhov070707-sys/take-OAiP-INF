#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Структура для хранения информации о сотруднике
struct Employee {
    string name;      // Имя
    int age;          // Возраст
    string position;  // Должность
    double salary;    // Зарплата
};

int main() {
    int n;
    cout << "Введите количество сотрудников: ";
    cin >> n;
    cin.ignore();  // Очищаем буфер после ввода числа

    vector<Employee> employees(n);

    // Ввод данных о сотрудниках
    for (int i = 0; i < n; i++) {
        cout << "\nВведите имя сотрудника: ";
        getline(cin, employees[i].name);

        cout << "Введите возраст сотрудника: ";
        cin >> employees[i].age;
        cin.ignore();

        cout << "Введите должность сотрудника: ";
        getline(cin, employees[i].position);

        cout << "Введите зарплату сотрудника: ";
        cin >> employees[i].salary;
        cin.ignore();
    }

    // Поиск самого молодого и старшего сотрудника
    Employee youngest = employees[0];
    Employee oldest = employees[0];
    double totalSalary = 0;

    for (const auto& emp : employees) {
        // Поиск самого молодого
        if (emp.age < youngest.age) {
            youngest = emp;
        }

        // Поиск самого старшего
        if (emp.age > oldest.age) {
            oldest = emp;
        }

        // Суммирование зарплат
        totalSalary += emp.salary;
    }

    // Расчет средней зарплаты
    double averageSalary = totalSalary / n;

    // Вывод результатов
    cout << "\n=== Результаты ===" << endl;

    cout << "\nСамый молодой сотрудник: "
        << youngest.name
        << ", возраст: " << youngest.age
        << ", должность: " << youngest.position
        << ", зарплата: " << youngest.salary << endl;

    cout << "\nСамый старший сотрудник: "
        << oldest.name
        << ", возраст: " << oldest.age
        << ", должность: " << oldest.position
        << ", зарплата: " << oldest.salary << endl;

    cout << "\nСредняя зарплата всех сотрудников: "
        << averageSalary << endl;

    return 0;
}