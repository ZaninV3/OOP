#include <iostream>
#include <cmath>
using namespace std;

// Задание 11ж
// Даны x, y, z. Вычислить a и b (см. 11zh.png)

// Возвращает значение a
// Вернет nullptr, если введенные значения приводят к ошибке
float* getA(float x, float y, float z) {
    // Первая проверка a. Если знаменатель равен 0, то деление невозможно
    if ((z + pow(x, 2) / 4) != 0) {
        float first = y - sqrt(fabs(x));
        float second = x - y / (z + pow(x, 2) / 4);

        // Вторая проверка a. Если один из множителей равен 0,
        // то возведение под натур. логарифм невозможно.
        if (first != 0 and second != 0) {
            float* result;
            float res = log(fabs(first * second));
            result = &res;
            return result;
        }
        else return nullptr;
    }
    else return nullptr;
}

// Возвращает значение b
// Делать проверки, подобно в getA() не имеет смысла
float* getB(float x) {
    float* result;
    // Для удобства 3! и 5! заранее подсчитаны 6 и 120 соответственно
    float res = x - (pow(x, 2) / 6) + (pow(x, 5) / 120);
    result = &res;
    return result;
}

// Обработка и вывод результатов работы функций getA и getB
void printValue(float* result) {
    // Если результат -- нулевой указатель, то сообщаем об ошибке
    if (result == nullptr) cout << "error" << endl;
    else cout << *result << endl;  // Иначе выводим результат
}


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
