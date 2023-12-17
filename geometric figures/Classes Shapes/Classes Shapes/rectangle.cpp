// Файл с реализацией методов и конструктора класса Rectangle
#include "rectangle.h" // Подключаем, дабы при компиляции rectangle.cpp был связан с заголовком
// Занин Вячеслав ВМК-21

// Конструктор 
// Инициализирует значения side и second_side, если указанные значения больше или равно 0
// Иначе задает им по умолчанию 0
Rectangle::Rectangle(float pside, float psecond_side) : Square(pside) {
	// Если не удалось пронинициализировать second_side
	// то принудительно задаем ему 0
	if (!this->setSecondSide(psecond_side)) this->second_side = 0;
}
// Вызывается конструктор класса Square
// а после отрабатывается код этого конструктора

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
	return (this->second_side * 2) + (this->getSide() * 2);
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