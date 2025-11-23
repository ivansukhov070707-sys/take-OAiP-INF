#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    vector<int> numbers;
    for (int i = 0; i < 100000; i++) {
        numbers.push_back(i);
    }

    auto measureTime = [](const string& operationName, auto operation) {
        auto start = steady_clock::now();
        operation();
        auto end = steady_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        cout << operationName << ": " << duration.count() << " мс" << endl;
        return duration;
        };

    auto individualWrite = [&numbers]() {
        ofstream file1("individual.bin", ios::binary);
        for (int num : numbers) {
            file1.write(reinterpret_cast<const char*>(&num), sizeof(int));
        }
        file1.close();
        };

    auto bulkWrite = [&numbers]() {
        ofstream file2("bulk.bin", ios::binary);
        file2.write(reinterpret_cast<const char*>(numbers.data()), numbers.size() * sizeof(int));
        file2.close();
        };

    cout << "Сравнение скорости записи в файл:" << endl;
    cout << "=================================" << endl;

    auto time1 = measureTime("Запись по одному числу", individualWrite);
    auto time2 = measureTime("Запись всех чисел сразу", bulkWrite);

    if (time1 > time2) {
        cout << "Запись всех чисел сразу быстрее в "
            << static_cast<double>(time1.count()) / time2.count()
            << " раз" << endl;
    }
    else {
        cout << "Запись по одному числу быстрее в "
            << static_cast<double>(time2.count()) / time1.count()
            << " раз" << endl;
    }

    return 0;
}