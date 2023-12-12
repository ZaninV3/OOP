#pragma once  // Позволяет подключать заголовочный файл не более 1 раза
#include <cmath>  // Математические функции

// Класс квадрат
// Является базовым классом для Rectangle и Parallelogram
// 
// Имеет только 1 поле -- длина стороны
// 
// Методы класса:
// float getSide() const -- возвращает длину стороны
// float getSquare() const -- возвращает площадь
// float getPerimeter() const -- возвращает периметр
// bool setSide(float side) -- Меняет значение длины и возвращает true, если замена прошла успешно
class Square {
private:
	float side;
public:
	// Конструктор 
	// Инициализирует значение side, если указанное значение больше или равно 0
	// Иначе задает по умолчанию 0
	Square(float pside = 0) {
		// Если pside меньше 0, то задаем значение по умолчанию
		if (pside < 0) this->side = 0;
		// Иначе параметр указан корректно
		else this->side = pside;
	}

	// Возвращает значение стороны
	float getSide() const {
		return this->side;
	}
	// const здесь означает, что у функции ограничение на использование 
	// То есть если функция объявлена с константным указателем this,
	// то в теле функции запрещается изменять данные класса

	// Возвращает площадь квадрата
	// S = side^2
	float getSquare() const {
		return powf(this->side, 2);
	}

	float getPerimeter() const {
		return this->side * 4;
	}

	// Меняет значение side при условии, что указанное значение > 0
	// Возвращает true, если параметр удовлетворяет условию
	bool setSide(float pside) {
		// Если pside меньше 0, то возвращаем false
		if (pside < 0) return false;
		// Иначе параметр указан корректно
		else {
			this->side = pside;
			return true;
		}
	}
};
