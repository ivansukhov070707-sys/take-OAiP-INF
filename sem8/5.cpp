#include <iostream>
#include <algorithm>

// Функция для вычисления суммы элементов строки
int rowSum(int* row, int cols) {
    setlocale(LC_ALL, "RU");
    int sum = 0;
    for (int i = 0; i < cols; ++i) {
        sum += row[i];
    }
    return sum;
}

// Функция сортировки строк по сумме элементов
void sortRowsBySum(int** arr, int rows, int cols) {
    // Создаем массив пар: сумма строки + указатель на строку
    std::pair<int, int*>* rowsWithSums = new std::pair<int, int*>[rows];

    // Заполняем массив суммами и указателями
    for (int i = 0; i < rows; ++i) {
        rowsWithSums[i] = { rowSum(arr[i], cols), arr[i] };
    }

    // Сортируем по возрастанию суммы
    std::sort(rowsWithSums, rowsWithSums + rows,
        [](const std::pair<int, int*>& a, const std::pair<int, int*>& b) {
            return a.first < b.first;
        });

    // Переставляем указатели в исходном массиве
    for (int i = 0; i < rows; ++i) {
        arr[i] = rowsWithSums[i].second;
    }

    delete[] rowsWithSums;
}