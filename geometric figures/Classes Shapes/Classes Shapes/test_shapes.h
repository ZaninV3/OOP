#pragma once  // Чтобы заголовок подключали только 1 раз
#define ZERO 0.0f
#define CORRECT_VALUE 10.2f
#define SECOND_CORRECT_VALUE 25.34f
#define UNCORRECT_VALUE -4.5f
#define SECOND_UNCORRECT_VALUE -32.912f
#define CORRECT_ANGLE 23.8f
#define UNCORRECT_ANGLE 183.06f
#define DEFAULT_ANGLE 90.0f
#define _USE_MATH_DEFINES // Для M_PI
#include "parallelogram.h"  // Подключены все классы
#include <iostream>  // Ввод/вывод в консоль
#include <assert.h>  // Для проверок корректности кода
// Занин Вячеслав ВМК-21

// Выводит на экран пустую строку
void printEmptyLine() {
	std::cout << std::endl;
}

// Проверка работоспособности класса Square
void base_test_square() {
	{
		// Объявление без параметров
		Square test_square = Square();
		// Получим результат
		const float without_parameter_value = test_square.getSide();

		std::cout << "The side of square's costructor without a parameter = " <<
			without_parameter_value << std::endl;
		// Проверка корректности
		assert(without_parameter_value == ZERO);



		// Сразу проверка setSide
		//
		// Сохраним результат смены для проверки и получим значение
		// для пропуска через assert-ы и для отображения
		const bool is_change_correct_complete = test_square.setSide(CORRECT_VALUE);
		const float change_correct_value = test_square.getSide();

		// Выведем на экран
		std::cout << "Trying to change the correct value of object (" <<
			CORRECT_VALUE << "). result = ";
		std::cout << change_correct_value << std::endl;

		// Проверки
		assert(is_change_correct_complete == true);
		assert(change_correct_value == CORRECT_VALUE);



		// Пробуем неравильно. В аналогии с корректным присваиванием
		const bool is_change_wrong_complete = test_square.setSide(UNCORRECT_VALUE);
		const float change_wrong_value = test_square.getSide();

		std::cout << "Trying to change the wrong value of object (" <<
			UNCORRECT_VALUE << "). result = ";
		std::cout << change_wrong_value << std::endl;

		assert(is_change_wrong_complete == false);
		assert(change_wrong_value == CORRECT_VALUE);  // Потому что значение не должно меняться
	}

	printEmptyLine();

	{
		// Пробуем объявить с неправильным параметром
		Square test_square = Square(UNCORRECT_VALUE);
		const float wrong_value = test_square.getSide();

		std::cout << "The side of square's constructor with a wrong parameter = " <<
			wrong_value << std::endl;
		assert(wrong_value == ZERO);  // По умолчанию должно быть 0
	}

	printEmptyLine();

	// А теперь с правильным параметром
	// Не буду ограничивать область видимости
	// Так как в дальнейшем нужно проверить остальные методы
	Square test_square = Square(SECOND_CORRECT_VALUE);
	const float correct_value = test_square.getSide();
	std::cout << "The side of square's constructor with a correct parameter = " <<
		test_square.getSide() << std::endl;
	assert(correct_value == SECOND_CORRECT_VALUE);

	// Проверка площади и периметра
	const float correct_square = test_square.getSquare();
	std::cout << "Square's square :) = " << correct_square << std::endl;
	assert(correct_square == SECOND_CORRECT_VALUE * SECOND_CORRECT_VALUE);

	const float correct_perimeter = test_square.getPerimeter();
	std::cout << "Square's perimeter = " << test_square.getPerimeter() << std::endl;
	assert(correct_perimeter == SECOND_CORRECT_VALUE * 4);

	printEmptyLine();
	printEmptyLine();
}

// Проверка работоспособности класса Rectangle
void base_test_rectangle() {
	{
		// Объявление без параметров
		Rectangle test_rectangle = Rectangle();
		const float first_value = test_rectangle.getSide();
		const float second_value = test_rectangle.getSecondSide();
		std::cout << "The sides of rectangle's costructor without parameters = " <<
			 first_value << " " << second_value << std::endl;
		assert(first_value == ZERO);  // Потому что по умолчанию параметры задаются нулями
		assert(second_value == ZERO);


		// Сразу проверка setSide и setSecondSide
		// Для начала проверка неправильных замен значений
		const bool is_wrong_first_value = test_rectangle.setSide(UNCORRECT_VALUE);
		const float wrong_first_value = test_rectangle.getSide();

		const bool is_wrong_second_value = test_rectangle.setSecondSide(SECOND_UNCORRECT_VALUE);
		const float wrong_second_value = test_rectangle.getSecondSide();

		std::cout << "Trying to change the wrong values of object (" << UNCORRECT_VALUE <<
			" and " << SECOND_UNCORRECT_VALUE << "): ";
		std::cout << wrong_first_value << " " << wrong_second_value << std::endl;

		assert(is_wrong_first_value == false);
		assert(is_wrong_second_value == false);
		assert(wrong_first_value == ZERO);
		assert(wrong_second_value == ZERO);


		// А теперь правильные замены значений
		const bool is_correct_first_value = test_rectangle.setSide(CORRECT_VALUE);
		const float correct_first_value = test_rectangle.getSide();

		const bool is_correct_second_value = test_rectangle.setSecondSide(SECOND_CORRECT_VALUE);
		const float correct_second_value = test_rectangle.getSecondSide();

		std::cout << "Trying to change the correct values of object (" << CORRECT_VALUE <<
			" and " << SECOND_CORRECT_VALUE << "): ";
		std::cout << correct_first_value << " " << correct_second_value << std::endl;

		assert(is_correct_first_value == true);
		assert(is_correct_second_value == true);
		assert(correct_first_value == CORRECT_VALUE);
		assert(correct_second_value == SECOND_CORRECT_VALUE);
	}

	printEmptyLine();

	{
		// Пробуем объявить с неправильным параметром
		Rectangle test_rectangle = Rectangle(UNCORRECT_VALUE, SECOND_UNCORRECT_VALUE);

		const float wrong_first_value = test_rectangle.getSide();
		const float wrong_second_value = test_rectangle.getSecondSide();

		std::cout << "The sides of rectangle's constructor with wrong parameters = " <<
			wrong_first_value << " " << wrong_second_value << std::endl;

		assert(wrong_first_value == ZERO);
		assert(wrong_second_value == ZERO);

		printEmptyLine();
	}

	// А теперь с правильным параметром
	// Не буду ограничивать область видимости
	// Так как в дальнейшем нужно проверить остальные методы
	Rectangle test_rectangle = Rectangle(CORRECT_VALUE, SECOND_CORRECT_VALUE);

	const float correct_first_value = test_rectangle.getSide();
	const float correct_second_value = test_rectangle.getSecondSide();
	std::cout << "The sides of rectangle's constructor with correct parameters = " <<
		correct_first_value << " " << correct_second_value << std::endl;
	assert(correct_first_value == CORRECT_VALUE);
	assert(correct_second_value == SECOND_CORRECT_VALUE);

	const float square_value = test_rectangle.getSquare();
	std::cout << "Rectangle's square = " << square_value << std::endl;
	assert(square_value == CORRECT_VALUE * SECOND_CORRECT_VALUE);

	const float perimeter_value = test_rectangle.getPerimeter();
	std::cout << "Rectangle's perimeter = " << perimeter_value << std::endl;
	assert(perimeter_value == CORRECT_VALUE + CORRECT_VALUE + SECOND_CORRECT_VALUE + SECOND_CORRECT_VALUE);

	printEmptyLine();
	printEmptyLine();
}

// Базовая проверка работоспособности класса Parallelogram
// Проверяет работоспособность каждого метода
void base_test_parallelogram() {
	{
		// Объявление без параметров
		Parallelogram test_parallelogram = Parallelogram();
		const float first_value = test_parallelogram.getSide();
		const float second_value = test_parallelogram.getSecondSide();
		const float angle_value = test_parallelogram.getAngle();
		std::cout << "The sides and the angle of parallelogram's costructor without parameters = " <<
			first_value << " " << second_value << " " << angle_value << std::endl;
		assert(first_value == ZERO);  // Потому что по умолчанию параметры задаются нулями
		assert(second_value == ZERO);
		assert(angle_value == DEFAULT_ANGLE);  // А угол по умолчанию 


		// Сразу проверка setSide, setSecondSide и setAngle
		// Для начала проверка неправильных замен значений
		const bool is_wrong_first_value = test_parallelogram.setSide(UNCORRECT_VALUE);
		const float wrong_first_value = test_parallelogram.getSide();

		const bool is_wrong_second_value = test_parallelogram.setSecondSide(SECOND_UNCORRECT_VALUE);
		const float wrong_second_value = test_parallelogram.getSecondSide();

		const bool is_wrong_angle = test_parallelogram.setAngle(UNCORRECT_ANGLE);
		const float wrong_angle = test_parallelogram.getAngle();

		std::cout << "Trying to change the wrong values of object (" << UNCORRECT_VALUE <<
			", " << SECOND_UNCORRECT_VALUE << " and " << UNCORRECT_ANGLE << "): ";
		std::cout << wrong_first_value << " " << wrong_second_value << " " << wrong_angle << std::endl;

		assert(is_wrong_first_value == false);  // Значения не должны были поменяться
		assert(is_wrong_second_value == false);
		assert(is_wrong_angle == false);
		assert(wrong_first_value == ZERO);
		assert(wrong_second_value == ZERO);
		assert(wrong_angle == DEFAULT_ANGLE);


		// А теперь правильные замены значений
		const bool is_correct_first_value = test_parallelogram.setSide(CORRECT_VALUE);
		const float correct_first_value = test_parallelogram.getSide();

		const bool is_correct_second_value = test_parallelogram.setSecondSide(SECOND_CORRECT_VALUE);
		const float correct_second_value = test_parallelogram.getSecondSide();

		const bool is_correct_angle = test_parallelogram.setAngle(CORRECT_ANGLE);
		const float correct_angle = test_parallelogram.getAngle();

		std::cout << "Trying to change the correct values of object (" << CORRECT_VALUE <<
			", " << SECOND_CORRECT_VALUE << " and " << CORRECT_ANGLE << "): ";
		std::cout << correct_first_value << " " << correct_second_value << " " << correct_angle << std::endl;

		assert(is_correct_first_value == true);
		assert(is_correct_second_value == true);
		assert(is_correct_angle == true);
		assert(correct_first_value == CORRECT_VALUE);
		assert(correct_second_value == SECOND_CORRECT_VALUE);
		assert(correct_angle == CORRECT_ANGLE);
	}

	printEmptyLine();

	{
		// Пробуем объявить с неправильным параметром
		Parallelogram test_parallelogram = Parallelogram(UNCORRECT_VALUE, SECOND_UNCORRECT_VALUE, UNCORRECT_ANGLE);

		const float wrong_first_value = test_parallelogram.getSide();
		const float wrong_second_value = test_parallelogram.getSecondSide();
		const float wrong_angle = test_parallelogram.getAngle();

		std::cout << "The sides and the angle of parallelogram's constructor with wrong parameters = " <<
			wrong_first_value << " " << wrong_second_value << " " << wrong_angle << std::endl;

		assert(wrong_first_value == ZERO);
		assert(wrong_second_value == ZERO);
		assert(wrong_angle == DEFAULT_ANGLE);

		printEmptyLine();
	}

	// А теперь с правильным параметром
	// Не буду ограничивать область видимости
	// Так как в дальнейшем нужно проверить остальные методы
	Parallelogram test_parallelogram = Parallelogram(CORRECT_VALUE, SECOND_CORRECT_VALUE, CORRECT_ANGLE);

	const float correct_first_value = test_parallelogram.getSide();
	const float correct_second_value = test_parallelogram.getSecondSide();
	const float correct_angle = test_parallelogram.getAngle();
	std::cout << "The sides and the angle of parallelogram's constructor with correct parameters = " <<
		correct_first_value << " " << correct_second_value << " " << correct_angle << std::endl;
	assert(correct_first_value == CORRECT_VALUE);
	assert(correct_second_value == SECOND_CORRECT_VALUE);
	assert(correct_angle == CORRECT_ANGLE);

	const float square_value = test_parallelogram.getSquare();
	std::cout << "Parallelogram's square = " << square_value << std::endl;
	assert(square_value == CORRECT_VALUE * SECOND_CORRECT_VALUE * sinf(CORRECT_ANGLE * 180 / M_PI));

	const float perimeter_value = test_parallelogram.getPerimeter();
	std::cout << "Parallelogram's perimeter = " << perimeter_value << std::endl;
	assert(perimeter_value == CORRECT_VALUE + CORRECT_VALUE + SECOND_CORRECT_VALUE + SECOND_CORRECT_VALUE);

	printEmptyLine();
	printEmptyLine();
}
