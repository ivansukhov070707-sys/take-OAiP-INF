#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    // ����������� �� 30 ����
    vector<double> energy = { 150, 200, 180, 220, 190, 210, 170, 230, 160, 240,
                            250, 195, 205, 175, 225, 185, 215, 165, 235, 155,
                            245, 200, 180, 220, 190, 210, 170, 230, 160, 240 };

    // ����� �����������
    double total = accumulate(energy.begin(), energy.end(), 0.0);
    cout << "����� �����������: " << total << " ����" << endl;

    // ��������������
    double avg = total / energy.size();
    cout << "��������������: " << avg << " ����" << endl;

    // ������������ � �����������
    auto min_it = min_element(energy.begin(), energy.end());
    auto max_it = max_element(energy.begin(), energy.end());
    cout << "���: " << *min_it << " (���� " << (min_it - energy.begin() + 1) << ")" << endl;
    cout << "����: " << *max_it << " (���� " << (max_it - energy.begin() + 1) << ")" << endl;

    // ������� ��� (> �������� �� 20%)
    double threshold = avg * 1.2;
    cout << "������� ��� (> " << threshold << "): ";
    for (int i = 0; i < energy.size(); i++) {
        if (energy[i] > threshold) {
            cout << "���� " << i + 1 << " (" << energy[i] << ") ";
        }
    }

    return 0;
}