#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    vector<int> numbers(15);
    generate(numbers.begin(), numbers.end(), []() { return rand() % 201 - 100; });

    cout << "�������� ������: ";
    for_each(numbers.begin(), numbers.end(), [](int n) { cout << n << " "; });
    cout << endl;

    // �������� � ���� ������ (erase-remove idiom)
    numbers.erase(
        remove_if(numbers.begin(), numbers.end(), [](int n) { return n < 0; }),
        numbers.end()
    );

    cout << "��� ������������� �����: ";
    for_each(numbers.begin(), numbers.end(), [](int n) { cout << n << " "; });
    cout << endl;

    return 0;
}