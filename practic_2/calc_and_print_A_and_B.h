#pragma once

// Для мат. констант
#define _USE_MATH_DEFINES
#include <math.h>  // Мат. константы и функции

using namespace std;


// Возвращает первую часть выражения a
float getFirstPartOfA(float x, float y) {
    return y - sqrt(abs(x));
}

// Возвращает вторую часть выражения a
float getSecondPartOfA(float x, float y, float denominator) {
    return x - y / denominator;
}

// Возвращает 0, если значенатель при значениях x и z равен 0
// Иначе значение знаменателя
float getDenominatorOfA(float x, float z) {
    return z + pow(x, 2) / 4;
}


// Возвращает значение a
// Вернет nullptr, если введенные значения приводят к ошибке
float* getA(float x, float y, float z) {
    // Первая проверка a. Если знаменатель равен 0, то деление невозможно
    float denominator = getDenominatorOfA(x, z);
    if (denominator != 0) {
        float first = getFirstPartOfA(x, y);
        float second = getSecondPartOfA(x, y, denominator);

        // Вторая проверка a. Если один из множителей равен 0,
        // то возведение под натур. логарифм невозможно.ы
        if (first != 0 and second != 0) {
            float* result;
            float res = log(abs(first * second));
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
