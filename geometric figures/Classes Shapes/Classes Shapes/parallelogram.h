#pragma once
#include "rectangle.h"  // Там наш базовый класс
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
class Parallelogram : public Rectangle {
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
	float getSquare() const override final;

	// Ну а для периметра нет смысла переопределять функцию

	// Меняет значение angle_bad при условии, что указанное значение > 0 и < 180
	// Возвращает true, если параметр удовлетворяет условию
	bool setAngle(float pangle_bad = 90);
};
