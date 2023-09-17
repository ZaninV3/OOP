#pragma once
using namespace std;

// Возвращает значение a
// Вернет nullptr, если введенные значения приводят к ошибке
float* getA(float x, float y, float z) {
    // Первая проверка a. Если знаменатель равен 0, то деление невозможно
    if ((z + x * x / 4) != 0) {
        float first = y - sqrt(abs(x));
        float second = x - 4 / (z + pow(x, 2) / 4);

        // Вторая проверка a. Если один из множителей равен 0,
        // то возведение под натур. логарифм невозможно.ы
        if (first != 0 and second != 0) {
            float* result;
            *result = log(abs(first * second));
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
