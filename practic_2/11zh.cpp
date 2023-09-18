#include <iostream>

// Расскоментрировать, чтобы отключить assert()
// #define NDEBUG
#define FLT_EPSILON 1.192092896e-07

#include <assert.h>
// Все assert будут отключены, если компилировать в release

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

    // Предварительная проверка getFirstPartOfA(x, y).
    // Если единственный параметр assert будет равен 0
    // работа программы прекратится
    assert((getFirstPartOfA(x, y) - y) < FLT_EPSILON);  // наименьшее float
    // Поскольку невозможно корректное сравнение
    // вещественных чисел без округления

    // Вывод результатов
    cout << "-----------" << endl;
    cout << "a = ";
    printValue(getA(x, y, z));
    cout << "b = ";
    printValue(getB(x));
}
