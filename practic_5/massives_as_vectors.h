#pragma once
#include <iostream>
#include <vector>

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

    // Деструктор
    ~Massive() {}
};
