#pragma once
#include "square.h"  // ѕоключение заголовочного файла с классом Square

//  ласс пр€моугольник
// явл€етс€ базовым классом дл€ Parallelogram и производным классом дл€ Square
// 
// »меет только 2 пол€ -- длины двух сторон
// 
// ћетоды класса:
// float getSide() const -- возвращает длину первой стороны
// float getSecondSide() const -- возвращает длину второй стороны
// float getSquare() const -- возвращает площадь
// float getPerimeter() const -- возвращает периметр
// bool setSide(float side) -- ћен€ет значение длины первой стороны и возвращает true, если замена прошла успешно
// bool setSecondSide(float side) -- ћен€ет значение длины второй стороны и возвращает true, если замена прошла успешно
class Rectangle: public Square {
private:
	// ƒлина второй стороны
	float second_side;
public:
	//  онструктор 
	// »нициализирует значени€ side и second_side, если указанные значени€ больше или равно 0
	// »наче задает им по умолчанию 0
	Rectangle(float pside = 0, float psecond_side = 0);

	// ¬озвращает значение второй стороны
	float getSecondSide() const;

	// ¬озвращает площадь квадрата
	// S = side * second_side
	float getSquare() const;

	// ¬озвращает периметр квадрата
	// P = 2 * side + 2 * second_side
	float getPerimeter() const;
	
	// ћен€ет значение second_side при условии, что указанное значение > 0
	// ¬озвращает true, если параметр удовлетвор€ет условию
	bool setSecondSide(float psecond_side);
};

//  онструктор 
// »нициализирует значени€ side и second_side, если указанные значени€ больше или равно 0
// »наче задает им по умолчанию 0
Rectangle::Rectangle(float pside, float psecond_side) : Square(pside) {
	// ¬ аналогии Square(float pside = 0) инициализируем вторую сторону
	if (psecond_side < 0) this->second_side = 0;
	else this->second_side = psecond_side;
}

// ¬озвращает значение второй стороны
float Rectangle::getSecondSide() const {
	return this->second_side;
}

// ¬озвращает площадь квадрата
// S = side * second_side
float Rectangle::getSquare() const {
	return this->second_side * this->getSide();
}
// ѕоскольку при наследовании передаютс€ все методы класса Square
// то работа Square::getSquare дл€ Rectangle некорректна
// поэтому переопределим эту функцию

// ¬озвращает периметр квадрата
// P = 2 * side + 2 * second_side
float Rectangle::getPerimeter() const {
	return this->second_side * 2 + this->getSide() * 2;
}
// јналогична€ ситуаци€, как и Rectangle::getSquare

// ћен€ет значение second_side при условии, что указанное значение > 0
// ¬озвращает true, если параметр удовлетвор€ет условию
bool Rectangle::setSecondSide(float psecond_side) {
	// ≈сли psecond_side меньше 0, то возвращаем false
	if (psecond_side < 0) return false;
	// »наче параметр указан корректно
	else {
		this->second_side = psecond_side;
		return true;
	}
}
