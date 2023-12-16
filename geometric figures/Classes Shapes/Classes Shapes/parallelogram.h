#pragma once
#define _USE_MATH_DEFINES // Для M_PI
#include "rectangle.h"  // Поключение заголовочного файла с классами Square и Rectangle
// Занин Вячеслав ВМК-21

// Класс параллелограм
// Является  производным классом для Rectangle
// 
// Имеет только 3 поля -- длины двух сторон и угол между ними BAD
// 
// Методы класса:
// float getSide() const -- возвращает длину первой стороны
// float getSecondSide() const -- возвращает длину второй стороны
// float getAngle() const -- возвращает значение угла BAD в градусах
// float getSquare() const -- возвращает площадь
// float getPerimeter() const -- возвращает периметр
// bool setSide(float side) -- Меняет значение длины первой стороны и возвращает true, если замена прошла успешно
// bool setSecondSide(float side) -- Меняет значение длины второй стороны и возвращает true, если замена прошла успешно
// bool setAngle(float angle) -- Меняет значение угла и возвращает true, если замена прошла успешно
class Parallelogram: public Rectangle {
private:
	// Значение угла BAD в градусах
	float angle_bad;
public:
	// Конструктор 
	// Инициализирует значения side, second_side и angle_bad, если указанные значения больше или равно 0 и 0 < angle_bad < 180
	// Иначе задает им по умолчанию 0, 0 и 90 соответственно
	Parallelogram(float pside = 0, float psecond_side = 0, float pangle_bad = 90);


	// Возвращает значение угла
	float getAngle() const;

	// Возвращает площадь квадрата
	// S = side * second_side * sin(angle_bad)
	float getSquare() const;

	// Ну а для периметра нет смысла переопределять функцию


	// Меняет значение angle_bad при условии, что указанное значение > 0 и < 180
	// Возвращает true, если параметр удовлетворяет условию
	bool setAngle(float pangle_bad = 90);
};

// Конструктор 
// Инициализирует значения side, second_side и angle_bad, если указанные значения больше или равно 0 и 0 < angle_bad < 180
// Иначе задает им по умолчанию 0, 0 и 90 соответственно
Parallelogram::Parallelogram(float pside, float psecond_side, float pangle_bad) : Rectangle(pside, psecond_side) {
	// В аналогии с конструкторами Rectangle и Square
	if (0 < pangle_bad and pangle_bad < 180) this->angle_bad = pangle_bad;
	else this->angle_bad = 90;
}

// Возвращает значение угла
float Parallelogram::getAngle() const {
	return this->angle_bad;
}

// Возвращает площадь квадрата
// S = side * second_side * sin(angle_bad)
float Parallelogram::getSquare() const {
	return this->getSecondSide() * this->getSide() * sinf(this->angle_bad * 180 / M_PI);  // Необходим перевод градусов в радианы
}

// Меняет значение angle_bad при условии, что указанное значение > 0 и < 180
// Возвращает true, если параметр удовлетворяет условию
bool Parallelogram::setAngle(float pangle_bad) {
	// Если pangle_bad < 0 или > 180, то возвращаем false
	if (pangle_bad < 0 or pangle_bad > 180) return false;
	// Иначе параметр указан корректно
	else {
		this->angle_bad = pangle_bad;
		return true;
	}
}
