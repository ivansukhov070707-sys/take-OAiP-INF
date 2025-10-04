//#include <iostream>
//using namespace std;
//
//int main() {
//    setlocale(LC_ALL, "RU");
//
//    double vertices[3][2];
//
//    cout << "Введите координаты трех вершин треугольника:" << endl;
//    for (int i = 0; i < 3; i++) {
//        cout << "Вершина " << i+1<< " (x y): ";
//        cin >> vertices[i][0] >> vertices[i][1];
//    }
//
//    double x1 = vertices[0][0], y1 = vertices[0][1];
//    double x2 = vertices[1][0], y2 = vertices[1][1];
//    double x3 = vertices[2][0], y3 = vertices[2][1];
//
//    double center_x = (x1 + x2 + x3) / 3;
//    double center_y = (y1 + y2 + y3) / 3;
//
//    cout << "Координаты центра масс: (" << center_x << ", " << center_y << ")" << endl;
//
//    return 0;
//}
