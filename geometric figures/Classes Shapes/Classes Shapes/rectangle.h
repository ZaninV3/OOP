#pragma once
#include "square.h"  // Поключение заголовочного файла с классом Square
// Занин Вячеслав ВМК-21

// Указать override где это необходимо
// Вывести все реализации в отдельныые cpp
// Вызов конструктора базового класса  -- воткнуть куда надо

// Класс прямоугольник
// Является базовым классом для Parallelogram и производным классом для Square
// 
// Имеет только 2 поля -- длины двух сторон
// 
// Методы класса:
// float getSide() const -- возвращает длину первой стороны
// float getSecondSide() const -- возвращает длину второй стороны
// float getSquare() const -- возвращает площадь
// float getPerimeter() const -- возвращает периметр
// bool setSide(float side) -- Меняет значение длины первой стороны и возвращает true, если замена прошла успешно
// bool setSecondSide(float side) -- Меняет значение длины второй стороны и возвращает true, если замена прошла успешно
class Rectangle: public Square {
private:
	// Длина второй стороны
	float second_side;
public:
	// Конструктор 
	// Инициализирует значения side и second_side, если указанные значения больше или равно 0
	// Иначе задает им по умолчанию 0
	Rectangle(float pside = 0, float psecond_side = 0);

	// Возвращает значение второй стороны
	float getSecondSide() const;

	// Возвращает площадь квадрата
	// S = side * second_side
	float getSquare() const;

	// Возвращает периметр квадрата
	// P = 2 * side + 2 * second_side
	float getPerimeter() const;
	
	// Меняет значение second_side при условии, что указанное значение > 0
	// Возвращает true, если параметр удовлетворяет условию
	bool setSecondSide(float psecond_side);
};

// Конструктор 
// Инициализирует значения side и second_side, если указанные значения больше или равно 0
// Иначе задает им по умолчанию 0
Rectangle::Rectangle(float pside, float psecond_side) : Square(pside) {
	// В аналогии Square(float pside = 0) инициализируем вторую сторону
	if (psecond_side < 0) this->second_side = 0;
	else this->second_side = psecond_side;
}

// Возвращает значение второй стороны
float Rectangle::getSecondSide() const {
	return this->second_side;
}

// Возвращает площадь квадрата
// S = side * second_side
float Rectangle::getSquare() const {
	return this->second_side * this->getSide();
}
// Поскольку при наследовании передаются все методы класса Square
// то работа Square::getSquare для Rectangle некорректна
// поэтому переопределим эту функцию

// Возвращает периметр квадрата
// P = 2 * side + 2 * second_side
float Rectangle::getPerimeter() const {
	return this->second_side * 2 + this->getSide() * 2;
}
// Аналогичная ситуация, как и Rectangle::getSquare

// Меняет значение second_side при условии, что указанное значение > 0
// Возвращает true, если параметр удовлетворяет условию
bool Rectangle::setSecondSide(float psecond_side) {
	// Если psecond_side меньше 0, то возвращаем false
	if (psecond_side < 0) return false;
	// Иначе параметр указан корректно
	else {
		this->second_side = psecond_side;
		return true;
	}
}
