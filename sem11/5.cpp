#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Student {
    int id;
    char name[50];
    int age;
    double average_grade;
};

int main() {
    Student students[] = {
        {1, "Иван Петров", 20, 4.5},
        {2, "Мария Сидорова", 19, 4.8},
        {3, "Алексей Иванов", 21, 4.2}
    };

    ofstream outFile("students.dat", ios::binary);
    if (!outFile) {
        cout << "Ошибка создания файла!" << endl;
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        outFile.write(reinterpret_cast<char*>(&students[i]), sizeof(Student));
    }
    outFile.close();

    ifstream inFile("students.dat", ios::binary);
    if (!inFile) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    inFile.seekg(0, ios::end);
    int file_size = inFile.tellg();
    int student_count = file_size / sizeof(Student);
    inFile.seekg(0, ios::beg);

    cout << "Список всех студентов:" << endl;

    Student current_student;
    Student best_student;
    double max_grade = 0;

    for (int i = 0; i < student_count; i++) {
        inFile.read(reinterpret_cast<char*>(&current_student), sizeof(Student));

        cout << "ID: " << current_student.id << endl;
        cout << "Имя: " << current_student.name << endl;
        cout << "Возраст: " << current_student.age << endl;
        cout << "Средний балл: " << current_student.average_grade << endl;

        if (current_student.average_grade > max_grade) {
            max_grade = current_student.average_grade;
            best_student = current_student;
        }
    }

    inFile.close();

    cout << "Общее количество студентов: " << student_count << endl;
    cout << "Студент с самым высоким баллом:" << endl;
    cout << "ID: " << best_student.id << endl;
    cout << "Имя: " << best_student.name << endl;
    cout << "Возраст: " << best_student.age << endl;
    cout << "Средний балл: " << best_student.average_grade << endl;

    return 0;
}