//#include <iostream>
//using namespace std;
//
//int main() {
//    setlocale(LC_ALL, "RU");
//    int n;
//    cout << "Введите количество вершин: ";
//    cin >> n;
//
//    int x[10], y[10]; // массивы для координат
//
//    cout << "Введите координаты вершин:" << endl;
//    for (int i = 0; i < n; i++) {
//        cout << "Вершина " << i + 1 << " (x y): ";
//        cin >> x[i] >> y[i];
//    }
//
//    int pX, pY;
//    cout << "Введите координаты точки (x y): ";
//    cin >> pX >> pY;
//
//    bool inside = true;
//
//    for (int i = 0; i < n; i++) {
//        int next = (i + 1) % n;
//
//        int cross = (x[next] - x[i]) * (pY - y[i]) -
//            (y[next] - y[i]) * (pX - x[i]);
//
//        if (cross < 0) {
//            inside = false;
//            break;
//        }
//    }
//
//    cout << "Точка " << (inside ? "ВНУТРИ" : "СНАРУЖИ") << " многоугольника" << endl;
//
//    return 0;
//}