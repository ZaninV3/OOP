#pragma once

#include <iostream>  // Для cout и cin
using namespace std;  // Пространство имен для всей стандартной библиотеки C++

namespace massives {
    // Возвращает массив, который заполняется вручную действительными числами
    float* getMassive(unsigned int count) {

        // Создаем массив
        float* massive = new float[count];

        // Огранизуем заполнение данных массива
        for (unsigned int i = 0; i < count; i++) {

            // Информация пользователю, чтобы он понимал что он вводит
            cout << "mass[" << i << "]: ";

            // Сам ввод
            cin >> massive[i];
        }

        // Возвращаем полученный массив
        return massive;
    }

    // Вычисление суммы всех элементов массива
    // А смысл убирать count, если он известен по условию задачи?
    //
    // massive -- массив с действительными числами
    // count -- количество элементов массива
    float getSum(float* massive, unsigned int count) {

        // Переменная-результат
        float result = 0;

        // Перебор элементов массива
        for (unsigned int i = 0; i < count; i++) {

            // Суммируем элементы массива
            result += massive[i];
        }

        // Возвращаем результат
        return result;
    }
}
