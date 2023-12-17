#define _USE_MATH_DEFINES // Для M_PI
#include <cmath>  // Для sinf()
#include "parallelogram.h"  // Подключаем, дабы при компиляции parallelogram.cpp был связан с заголовком
// Занин Вячеслав ВМК-21

// Конструктор 
// Инициализирует значения side, second_side и angle_bad, если указанные значения больше или равно 0 и 0 < angle_bad < 180
// Иначе задает им по умолчанию 0, 0 и 90 соответственно
Parallelogram::Parallelogram(float pside, float psecond_side, float pangle_bad) : Rectangle(pside, psecond_side) {
	// Если инициализация при таком значении аргумента неудачная
	// То принудительно задаем 90 градусов
	if (!this->setAngle(pangle_bad)) this->angle_bad = 90.0f;
}
// Вызывается конструктор Rectangle
// который, в свою очередь, вызывает конструктор Square
// после выполняется код Rectangle
// и только после всей этого
// выполняется этот код

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