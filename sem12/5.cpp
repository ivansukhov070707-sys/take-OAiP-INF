#include <iostream>
#include <cmath>  // для M_PI
using namespace std;

// Объединение для фигур
union Shape {
    struct {
        double radius;  // для круга
    } circle;

    struct {
        double length;  // для прямоугольника
        double width;
    } rectangle;
};

int main() {
    Shape shape;
    int choice;

    cout << "Выберите фигуру (1 - круг, 2 - прямоугольник): ";
    cin >> choice;

    switch (choice) {
    case 1: {
        // Круг
        const double PI = 3.141592653589793;
        cout << "Введите радиус круга: ";
        cin >> shape.circle.radius;

        if (shape.circle.radius <= 0) {
            cout << "Ошибка: радиус должен быть положительным!" << endl;
            return 1;
        }

        double area = PI * shape.circle.radius * shape.circle.radius;
        cout << "Площадь круга: " << area << endl;
        break;
    }

    case 2: {
        // Прямоугольник
        cout << "Введите длину прямоугольника: ";
        cin >> shape.rectangle.length;
        cout << "Введите ширину прямоугольника: ";
        cin >> shape.rectangle.width;

        if (shape.rectangle.length <= 0 || shape.rectangle.width <= 0) {
            cout << "Ошибка: длина и ширина должны быть положительными!" << endl;
            return 1;
        }

        double area = shape.rectangle.length * shape.rectangle.width;
        cout << "Площадь прямоугольника: " << area << endl;
        break;
    }

    default:
        cout << "Ошибка: неверный выбор!" << endl;
    }

    return 0;
}