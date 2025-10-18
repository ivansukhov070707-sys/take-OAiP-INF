#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    // ������� ������ �� 50 �������� �������� (�� 0 �� 180)
    vector<int> speeds(50);
    for_each(speeds.begin(), speeds.end(), [](int& speed) {
        speed = rand() % 181;  // �� 0 �� 180
        });

    // ������� �������� ��������
    cout << "�������� �������� (50 ��������): ";
    for_each(speeds.begin(), speeds.end(), [](int speed) {
        cout << speed << " ";
        });
    cout << endl << endl;

    // 1. ����������� ���������� �������� > 120
    vector<int> filtered_speeds;
    copy_if(speeds.begin(), speeds.end(), back_inserter(filtered_speeds),
        [](int speed) { return speed <= 120; });

    cout << "����� ���������� (>120): ";
    for_each(filtered_speeds.begin(), filtered_speeds.end(), [](int speed) {
        cout << speed << " ";
        });
    cout << endl;
    cout << "������� ����������: " << speeds.size() - filtered_speeds.size() << endl;

    // 2. ������� ������� �������� (�� ��������������� ������)
    double average_speed = 0.0;
    if (!filtered_speeds.empty()) {
        average_speed = accumulate(filtered_speeds.begin(), filtered_speeds.end(), 0.0)
            / filtered_speeds.size();
        cout << "������� ��������: " << average_speed << " ��/�" << endl;
    }

    // 3. ����������, ���� �� ��� �������� ������ 0
    bool always_moving = all_of(speeds.begin(), speeds.end(),
        [](int speed) { return speed > 0; });

    if (always_moving) {
        cout << "���������� ������ �������� (��� �������� > 0)" << endl;
    }
    else {
        // ������� ��������� (�������� = 0)
        int stops_count = count_if(speeds.begin(), speeds.end(),
            [](int speed) { return speed == 0; });
        cout << "���������� �������������� " << stops_count << " ���" << endl;
    }

    // 4. ������� 10 ������������ �������� ��������
    vector<int> sorted_speeds = speeds;
    sort(sorted_speeds.rbegin(), sorted_speeds.rend());  // ��������� �� ��������

    cout << "10 ������������ ���������: ";
    int count = min(10, (int)sorted_speeds.size());
    for (int i = 0; i < count; i++) {
        cout << sorted_speeds[i] << " ";
    }
    cout << endl;

    // �������������� ����������
    cout << endl << "�������������� ����������:" << endl;
    auto minmax = minmax_element(speeds.begin(), speeds.end());
    cout << "����������� ��������: " << *minmax.first << " ��/�" << endl;
    cout << "������������ ��������: " << *minmax.second << " ��/�" << endl;

    // ���������� ����������
    int overspeeding_count = count_if(speeds.begin(), speeds.end(),
        [](int speed) { return speed > 120; });
    cout << "���������� ���������� �������� (>120): " << overspeeding_count << endl;

    return 0;
}