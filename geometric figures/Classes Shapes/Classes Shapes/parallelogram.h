#pragma once
#define _USE_MATH_DEFINES // ƒл€ M_PI
#include "rectangle.h"  // ѕоключение заголовочного файла с классами Square и Rectangle

//  ласс параллелограм
// явл€етс€  производным классом дл€ Rectangle
// 
// »меет только 3 пол€ -- длины двух сторон и угол между ними BAD
// 
// ћетоды класса:
// float getSide() const -- возвращает длину первой стороны
// float getSecondSide() const -- возвращает длину второй стороны
// float getAngle() const -- возвращает значение угла BAD в градусах
// float getSquare() const -- возвращает площадь
// float getPerimeter() const -- возвращает периметр
// bool setSide(float side) -- ћен€ет значение длины первой стороны и возвращает true, если замена прошла успешно
// bool setSecondSide(float side) -- ћен€ет значение длины второй стороны и возвращает true, если замена прошла успешно
// bool setAngle(float angle) -- ћен€ет значение угла и возвращает true, если замена прошла успешно
class Parallelogram: public Rectangle {
private:
	// «начение угла BAD в градусах
	float angle_bad;
public:
	//  онструктор 
	// »нициализирует значени€ side, second_side и angle_bad, если указанные значени€ больше или равно 0 и 0 < angle_bad < 180
	// »наче задает им по умолчанию 0, 0 и 90 соответственно
	Parallelogram(float pside = 0, float psecond_side = 0, float pangle_bad = 90);


	// ¬озвращает значение угла
	float getAngle() const;

	// ¬озвращает площадь квадрата
	// S = side * second_side * sin(angle_bad)
	float getSquare() const;

	// Ќу а дл€ периметра нет смысла переопредел€ть функцию


	// ћен€ет значение angle_bad при условии, что указанное значение > 0 и < 180
	// ¬озвращает true, если параметр удовлетвор€ет условию
	bool setAngle(float pangle_bad = 90);
};

//  онструктор 
// »нициализирует значени€ side, second_side и angle_bad, если указанные значени€ больше или равно 0 и 0 < angle_bad < 180
// »наче задает им по умолчанию 0, 0 и 90 соответственно
Parallelogram::Parallelogram(float pside, float psecond_side, float pangle_bad) : Rectangle(pside, psecond_side) {
	// ¬ аналогии с конструкторами Rectangle и Square
	if (0 < pangle_bad and pangle_bad < 180) this->angle_bad = pangle_bad;
	else this->angle_bad = 90;
}

// ¬озвращает значение угла
float Parallelogram::getAngle() const {
	return this->angle_bad;
}

// ¬озвращает площадь квадрата
// S = side * second_side * sin(angle_bad)
float Parallelogram::getSquare() const {
	return this->getSecondSide() * this->getSide() * sinf(this->angle_bad * 180 / M_PI);  // Ќеобходим перевод градусов в радианы
}

// ћен€ет значение angle_bad при условии, что указанное значение > 0 и < 180
// ¬озвращает true, если параметр удовлетвор€ет условию
bool Parallelogram::setAngle(float pangle_bad) {
	// ≈сли pangle_bad < 0 или > 180, то возвращаем false
	if (pangle_bad < 0 or pangle_bad > 180) return false;
	// »наче параметр указан корректно
	else {
		this->angle_bad = pangle_bad;
		return true;
	}
}
