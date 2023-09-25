#pragma once
#include <iostream>  // cout, cin и endl
#include <vector>  // массив
#include <typeinfo>  // Для определения типа
#include <cstring>  // Для работы со строками
#include <cmath>  // Математические методы
#include <fstream>  // Работа с файлами


// Класс массив, использующий vector
template <typename T>
class Massive {
private:
    // Сам массив
    std::vector <T> massive;

    // True, если указанный индекс принадлежит massive
    bool checkIndex(int index) {
        if (0 <= index < massive.size()) {
            return true;
        }
        else {
            return false;
        }
    }

    // true, если massive числовой
    bool isNumber() {
        char* list_of_types[] = {"int",
                                 "float",
                                 "short",
                                 "long",
                                 "long long",
                                 "double",
                                 "unsigned int",
                                 "unsigned float",
                                 "unsigned short",
                                 "unsigned long",
                                 "unsigned long long",
                                 "unsigned double"
                             };
        const char* first_type = typeid(massive[0]).name();

        // Пусть тип элементов не числовой
        bool flag = false;

        // Если first_type окажется не числовой, то возвращаем последнее
        // значение элемента массива
        for (int i = 0; i < 10; i++) {
            if (strcmp(first_type, list_of_types[i])) {
                flag = true;
                break;
            }
        }

        return flag;
    }

    // Возвращает факториал числа
    int factorial(int number) {
        if (number = 0) {
            return 1;
        }
        else {
            int result = 1;
            for (int i = 2; i <= number; i++) {
                result = result * i;
            }

            return result;
        }
    }
public:
    // Конструктор, создающий пустой массив
    Massive() {}

    // Добавляет элемент в конец массива
    void appendElement(T element) {
        massive.push_back(element);
    }

    // Добавляет элемент по индексу
    // Существующий элемент смещается по индексу на +1
    // Если метод выполнен успешно, возвращает true
    bool addElement(T element, int index) {
        if (checkIndex(index)) {
            // Создаем новый массив, который будет позже скопирован в massive
            std::vector <T> buffer(massive.size() + 1);

            // Итеративно лучше, так мы защищены от переполнения стека
            for (int i = 0; i < massive.size(); i++) {
                if (i < index) {
                    buffer[i] = massive[i];
                }
                else if (i > index) {
                    buffer[i + 1] = massive[i];
                }
                else {
                    buffer[i] = element;
                    buffer[i + 1] = massive[i];
                }
            }

            massive = buffer;
            return true;
        }
        else {
            return false;
        }
    }


    // Заменяет старый элемент массива на новый
    // Возвращает значение старого элемента
    // Если индекс указан некоректно, то возвращает element
    T changeElement(T element, int index) {
        if (checkIndex(index)) {
            T buffer = massive[index];
            massive[index] = element;
            return buffer;
        }
        return element;
    }

    // Удаляет элемент по индексу
    // Если index указан некорректно, то ничего не происходит
    void removeElement(int index) {
        if (checkIndex(index)) {
            massive.erase(massive.begin() + index);
        }
    }

    // Возвращает размер массива
    int getSize() {
        return massive.size();
    }

    // Выводит на экран элементы массива
    // Если массив пустой, то выводит сообщение "the massive is empty"
    void printMassive() {
        if (massive.size() == 0) {
            std::cout << "the massive is empty" << std::endl;
        }
        else {
            for (int i = 0; i < massive.size(); i++) {
                std::cout << massive[i] << std::endl;
            }
        }
    }

    // Возвращает элемент по индексу
    // Если индекс указан некорректно,
    // возвращает пустую переменную типа T
    T getElement(int index) {
        if (checkIndex(index)) {
            return massive[index];
        }
        else {  // Нам нужно хоть что-то вернуть
            T val;
            return val;
        }
    }


    // Удаление всех элементов массива
    void clearMassive() {
        massive.clear();
    }

    // Ввод множества значений
    void setManyElements(unsigned int count) {
        for (unsigned int i = 0; i < count; i++) {
            std::cout << "massive[" << i << "]: ";
            T input;
            std::cin >> input;
            massive.push_back(input);
        }
    }

    // Возвращает сумму элементов, если они считаются числовыми
    T getSum() {
        // Пустой ли массив
        if (massive.size() != 0) {
            // Методу можно работать, если он числовой
            if (isNumber()) {
                T result = 0;  // Переменная-результат

                // Само суммирование посредством перебора элементов массива
                for (int i = 0; i < massive.size(); i++) {
                    result = result + massive[i];
                }

                return result;  // Возвращаем результат
            }
            // Значит массив не числовой
            else {
                // Возвращаем неопределенное значение
                T el;
                return el;
            }
        }
        // Значит массив пустой
        else {
            // Возвращаем неопределенное значение
            T el;
            return el;
        }
    }

    // Возвращает произведение элементов, если они считаются числовыми
    T getMultiplication() {
        // Пустой ли массив
        if (massive.size() != 0) {
            // Методу можно работать, если он числовой
            if (isNumber()) {
                T result = 1;  // Переменная-результат

                // Само умножение посредством перебора элементов массива
                for (int i = 0; i < massive.size(); i++) {
                    result = result * massive[i];
                }

                return result;  // Возвращаем результат
            }
            // Значит массив не числовой
            else {
                // Возвращаем неопределенное значение
                T el;
                return el;
            }
        }
        // Значит массив пустой
        else {
            // Возвращаем неопределенное значение
            T el;
            return el;
        }
    }

    // Возвращает сумму модулей элементов, если они считаются числовыми
    T getSumModule() {
        // Пустой ли массив
        if (massive.size() != 0) {
            // Методу можно работать, если он числовой
            if (isNumber()) {
                T result = 0;  // Переменная-результат

                // Само суммирование модулей
                // посредством перебора элементов массива
                for (int i = 0; i < massive.size(); i++) {
                    result = result + fabs(massive[i]);
                }

                return result;  // Возвращаем результат
            }
            // Значит массив не числовой
            else {
                // Возвращаем неопределенное значение
                T el;
                return el;
            }
        }
        // Значит массив пустой
        else {
            // Возвращаем неопределенное значение
            T el;
            return el;
        }
    }

    // Возвращает произведение модулей элементов, если они считаются числовыми
    T getMultiplicationModule() {
        // Пустой ли массив
        if (massive.size() != 0) {
            // Методу можно работать, если он числовой
            if (isNumber()) {
                T result = 1;  // Переменная-результат

                // Само умножение модулей посредством перебора элементов массива
                for (int i = 0; i < massive.size(); i++) {
                    result = result * fabs(massive[i]);
                }

                return result;  // Возвращаем результат
            }
            // Значит массив не числовой
            else {
                // Возвращаем неопределенное значение
                T el;
                return el;
            }
        }
        // Значит массив пустой
        else {
            // Возвращаем неопределенное значение
            T el;
            return el;
        }
    }

    // Возвращает сумму квадратов элементов, если они считаются числовыми
    T getSumSquare() {
        // Пустой ли массив
        if (massive.size() != 0) {
            // Методу можно работать, если он числовой
            if (isNumber()) {
                T result = 0;  // Переменная-результат

                // Само суммирование квадратов
                // посредством перебора элементов массива
                for (int i = 0; i < massive.size(); i++) {
                    result = result + massive[i] * massive[i];
                }

                return result;  // Возвращаем результат
            }
            // Значит массив не числовой
            else {
                // Возвращаем неопределенное значение
                T el;
                return el;
            }
        }
        // Значит массив пустой
        else {
            // Возвращаем неопределенное значение
            T el;
            return el;
        }
    }

    // Далее алгоритмы методов перестают поддаваться адекватному именованию
    // Поэтому следующие методы получают названия заданий из задачника
    // https://ivtipm.github.io/Programming/Glava06/index06.htm#z136

    // 136ZH
    T getResultOf136zh() {
        // Пустой ли массив
        if (massive.size() != 0) {
            // Методу можно работать, если он числовой
            if (isNumber()) {
                T result = 0;  // Переменная-результат

                // Сама операция посредством перебора элементов массива
                for (int i = 0; i < massive.size(); i++) {
                    result = result + (massive[i] * pow(-1, i));
                }

                return result;  // Возвращаем результат
            }
            // Значит массив не числовой
            else {
                // Возвращаем неопределенное значение
                T el;
                return el;
            }
        }
        // Значит массив пустой
        else {
            // Возвращаем неопределенное значение
            T el;
            return el;
        }
    }

    // 136Z
    T getResultOf136z() {
        // Пустой ли массив
        if (massive.size() != 0) {
            // Методу можно работать, если он числовой
            if (isNumber()) {
                T result = 0;  // Переменная-результат

                // Сама операция посредством перебора элементов массива
                for (int i = 0; i < massive.size(); i++) {
                    result = result + ((massive[i] * pow(-1, i + 1))/factorial(i + 1));
                }

                return result;  // Возвращаем результат
            }
            // Значит массив не числовой
            else {
                // Возвращаем неопределенное значение
                T el;
                return el;
            }
        }
        // Значит массив пустой
        else {
            // Возвращаем неопределенное значение
            T el;
            return el;
        }
    }

    // 136I
    T getResultOf136i() {
        // Пустой ли массив
        if (massive.size() != 0) {
            // Методу можно работать, если он числовой
            if (isNumber()) {
                T result = 0;  // Переменная-результат

                // Сама операция посредством перебора элементов массива
                for (int i = 0; i < massive.size(); i++) {
                    result = result + massive[i] / factorial(i);
                }

                return result;  // Возвращаем результат
            }
            // Значит массив не числовой
            else {
                // Возвращаем неопределенное значение
                T el;
                return el;
            }
        }
        // Значит массив пустой
        else {
            // Возвращаем неопределенное значение
            T el;
            return el;
        }
    }

    // 136K
    T getResultOf136k() {
        // Пустой ли массив
        if (massive.size() != 0) {
            // Методу можно работать, если он числовой
            if (isNumber()) {
                T result = 0;  // Переменная-результат

                // Сама операция посредством перебора элементов массива
                for (int i = 0; i < massive.size(); i++) {
                    result = result + massive[i];
                }
                result = 2 * pow(result, 2);

                return result;  // Возвращаем результат
            }
            // Значит массив не числовой
            else {
                // Возвращаем неопределенное значение
                T el;
                return el;
            }
        }
        // Значит массив пустой
        else {
            // Возвращаем неопределенное значение
            T el;
            return el;
        }
    }

    // 136L
    T getResultOf136l() {
        // Пустой ли массив
        if (massive.size() != 0) {
            // Методу можно работать, если он числовой
            if (isNumber()) {
                T result = 1;  // Переменная-результат

                // Сама операция посредством перебора элементов массива
                for (int i = 0; i < massive.size(); i++) {
                    result = result * massive[i];
                }
                result = sqrt(fabs(result));

                return result;  // Возвращаем результат
            }
            // Значит массив не числовой
            else {
                // Возвращаем неопределенное значение
                T el;
                return el;
            }
        }
        // Значит массив пустой
        else {
            // Возвращаем неопределенное значение
            T el;
            return el;
        }
    }

    // 136M
    T getResultOf136m() {
        // Пустой ли массив
        if (massive.size() != 0) {
            // Методу можно работать, если он числовой
            if (isNumber()) {
                T result = 0;  // Переменная-результат

                // Сама операция посредством перебора элементов массива
                for (int i = 0; i < massive.size(); i++) {
                    result = result + massive[i];
                }
                result = sin(fabs(result));

                return result;  // Возвращаем результат
            }
            // Значит массив не числовой
            else {
                // Возвращаем неопределенное значение
                T el;
                return el;
            }
        }
        // Значит массив пустой
        else {
            // Возвращаем неопределенное значение
            T el;
            return el;
        }
    }

    // 136N
    T getResultOf136n() {
        // Пустой ли массив
        if (massive.size() != 0) {
            // Методу можно работать, если он числовой
            if (isNumber()) {
                T result = 0;  // Переменная-результат

                // Сама операция посредством перебора элементов массива
                for (int i = 0; i < massive.size(); i++) {
                    result = result + pow((sqrt(fabs(massive[i])) - massive[i]),
                                          2);
                }

                return result;  // Возвращаем результат
            }
            // Значит массив не числовой
            else {
                // Возвращаем неопределенное значение
                T el;
                return el;
            }
        }
        // Значит массив пустой
        else {
            // Возвращаем неопределенное значение
            T el;
            return el;
        }
    }

    // 136O
    T getResultOf136o() {
        // Пустой ли массив
        if (massive.size() != 0) {
            // Методу можно работать, если он числовой
            if (isNumber()) {
                T result = 0;  // Переменная-результат

                // Сама операция посредством перебора элементов массива
                for (int i = 0; i < massive.size(); i++) {
                    result = result + sqrt(10 + pow(massive[i], 2));
                }

                return result;  // Возвращаем результат
            }
            // Значит массив не числовой
            else {
                // Возвращаем неопределенное значение
                T el;
                return el;
            }
        }
        // Значит массив пустой
        else {
            // Возвращаем неопределенное значение
            T el;
            return el;
        }
    }

    // Деструктор
    ~Massive() {}
};

// Создание бинарного файла
bool createBinFile(std::string filename) {
    // Создаем файл в режиме binary
    std::ofstream afile(filename, std::ios::binary);

    // Сразу закрываем
    afile.close();

    // Заново открываем для проверки создания
    std::ifstream file(filename, std::ios::binary);

    if (file.is_open()) {
        // Сообщаем пользователю, что файл создан успешно
        std::cout << "file " << filename << " has been created" << std::endl;
        afile.close();
        return true;
    }
    else {
        std::cout << "file " << filename << " hasn't been created" << std::endl;
        afile.close();
        return false;
    }
}

// Запись в бинарный файл
template <typename Y>
bool writeMassiveBinFile(std::string filename, Massive <Y> variable) {
    // Открываем файл для записи
    std::ofstream file(filename, std::ios::binary);

    // Проверяем успешность открытия файла
    if (file.is_open()) {
        std::cout << "file " << filename << " has been opened";

        // Получаем размер массива
        int count = variable.getSize();

        // Начинаем запись в файл
        for (unsigned int i = 0; i < count; i++) {
            // Передаем значение элемента массива
            Y x = variable.getElement(i);
            // file.write(massive_of_char, size_of_element) -- запись в бинарник
            // (char*)&x -- чтение значения x как массива из sizeof(x) байт
            file.write((char*)&x, sizeof(x));
        }

        // Не забываем закрыть файл
        file.close();

        // Сообщаем об успешности операции
        std::cout << " and wrote" << std::endl;
        return true;
    }
    // Если файл не открылся
    else {
        // Сообщаем о провале
        std::cout << "it hasnt been opened" << std::endl;

        // ...
        file.close();
        return false;
    }
}

// Чтение из бинарного файла
Massive <int> readMassiveBinFile(std::string filename) {
    // Открываем файл
    std::ifstream file(filename, std::ios::binary);


    if (file.is_open()) {
        // Сообщаем об успехе открытия
        std::cout << "file " << filename << " has been opened" << std::endl;

        // Создаем новый массив для записи результата
        Massive <int> mass;

        // Переменная для записи
        int x;

        // Начинаем запись в массив
        file.seekg(0, std::ios::end);  // Перенос каретки в конец
        unsigned int file_size = file.tellg();
        file.seekg(0);  // перенос каретки в начало

        for (unsigned int i = 0; i < (file_size / sizeof(int)); i++) {
            // Аналог file.write (см. writeMassiveBinFile())
            file.read((char*)&x, sizeof(int));

            // Записываем вв новый массив
            mass.appendElement(x);
        }

        file.close();

        return mass;
    }
    else {
        std::cout << "file " << filename << " hasnt been opened" << std::endl;
        file.close();

        // Нам нужно хоть что-то вернуть
        Massive <int> mass;
        return mass;
    }
}
