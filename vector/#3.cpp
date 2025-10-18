#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numbers = { 45, 12, 89, 3, 67, 23, 91, 5, 78, 34, 56, 19, 82, 7, 61, 29, 95, 14, 73, 41 };

    cout << "������: ";
    for_each(numbers.begin(), numbers.end(), [](int n) { cout << n << " "; });
    cout << endl;

    // ����� ��������� � �������-������������
    auto max_iterator = max_element(numbers.begin(), numbers.end(),
        [](int x, int y) -> bool {
            return x < y;
        }
    );

    if (max_iterator != numbers.end()) {
        cout << "������������ ��������: " << *max_iterator << endl;
        cout << "��������� �� �������: " << (max_iterator - numbers.begin()) << endl;
    }

    return 0;
}