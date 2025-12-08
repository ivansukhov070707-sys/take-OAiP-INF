#include <iostream>
using namespace std;

class Shape {
public:
    double length;
};

class Rectangle : public Shape {
public:
    double width;

    double area() { return length * width; }
    double perimeter() { return 2 * (length + width); }

    void info() {
        cout << "Длина: " << length
            << ", Ширина: " << width
            << ", Площадь: " << area()
            << ", Периметр: " << perimeter() << endl;
    }
};

int main() {
    Rectangle r;
    r.length = 5;
    r.width = 3;
    r.info();
    return 0;
}