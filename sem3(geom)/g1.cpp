//#include <iostream>
//#include <cmath> // для abs()
//using namespace std;
//
//int main() {
//    setlocale(LC_ALL, "RU");
//    double v[3][2];
//    cout << "Введите координаты " << endl;
//    for (int i = 0; i < 3; i++) 
//    {
//        cout << "Вершина " << (i+1) << " (x y): ";
//        cin >> v[i][0] >> v[i][1];
//    }
//
//    double x1 = v[0][0], y1 = v[0][1];
//    double x2 = v[1][0], y2 = v[1][1];
//    double x3 = v[2][0], y3 = v[2][1];
//
//    double a = 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
//    cout << "Площадь треугольника: " << a;
//    return 0;
//}
// 
//
// номер 2
// 
//#include <iostream>
//#include <cmath> //sqrt() и pow()
//using namespace std;
//
//int main() {
//    setlocale(LC_ALL, "RU");
//    const int V = 4;
//    double arr[V][2];
//    for (int i = 0; i < V; i++) {
//        cout << "Вершина " << i + 1 << " (x y): ";
//        cin >> arr[i][0] >> arr[i][1];
//    }
//    double p = 0.0;
//    for (int i = 0; i < V; i++) {
//        int n = (i + 1) % V; // следующая вершинa 
//        double dx = arr[n][0] - arr[i][0];
//        double dy = arr[n][1] - arr[i][1];
//        double distance = sqrt(dx * dx + dy * dy);
//        p += distance;
//        cout << "Расстояние между вершиной " << i + 1 << " и " << n + 1
//            << ": " << distance << endl;
//    }
//    cout << "\nКоординаты вершин многоугольника:" << endl;
//    for (int i = 0; i < V; i++) {
//        cout << "Вершина " << i + 1 << ": (" << arr[i][0]
//            << ", " << arr[i][1] << ")" << endl;
//    }
//    cout << "Периметр многоугольника: " << p << endl;
//    return 0;
//}