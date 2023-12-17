#pragma once  // Позволяет подключать заголовочный файл не более 1 раза
#include "square.h"  // Подключаем класс Square для Rectangle
// Занин Вячеслав ВМК-21

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
class Rectangle : public Square {
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
	virtual float getSquare() const override;

	// Возвращает периметр квадрата
	// P = 2 * side + 2 * second_side
	float getPerimeter() const override final;

	// Меняет значение second_side при условии, что указанное значение > 0
	// Возвращает true, если параметр удовлетворяет условию
	bool setSecondSide(float psecond_side);
};