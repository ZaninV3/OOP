#include <iostream>
#include <cmath>
#include "calc_and_print_A_and_B.h"

// Задание 11ж
// Даны x, y, z. Вычислить a и b (см. 11zh.png)
int main() {
    // Вводим значения для подсчета
    float x;
    cout << "x = ";
    cin >> x;

    float y;
    cout << "y = ";
    cin >> y;

    float z;
    cout << "z = ";
    cin >> z;

    // Вывод результатов
    cout << "-----------" << endl;
    cout << "a = ";
    printValue(getA(x, y, z));
    cout << "b = ";
    printValue(getB(x));
}
