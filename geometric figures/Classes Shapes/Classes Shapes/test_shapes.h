#pragma once
#include "parallelogram.h"  // Поключение заголовочного файла с классами Square, Rectangle и Parallelogram
#include <iostream>  // Ввод/вывод в консоль
// Занин Вячеслав ВМК-21

// Сделать проверку сравнения результатов

// Выводит на экран пустую строку
void printEmptyLine() {
	std::cout << std::endl;
}

// Базовая проверка работоспособности класса Square
// Проверяет работоспособность каждого метода
void base_test_square() {
	{
		// Объявление без параметров
		Square test_square = Square();
		std::cout << "The side of square's costructor without a parameter = " <<
			test_square.getSide() << std::endl;

		// Сразу проверка setSide
		std::cout << "Trying to change the wrong value of object (-4.5f): " <<
			test_square.setSide(-4.5f) << "... and result = ";
		std::cout << test_square.getSide() << std::endl;
		std::cout << "Trying to change the correct value of object (4.5f): " <<
			test_square.setSide(4.5f) << "... and result = ";
		std::cout << test_square.getSide() << std::endl;
	}

	printEmptyLine();

	{
		// Пробуем объявить с неправильным параметром
		Square test_square = Square(-6.4f);
		std::cout << "The side of square's constructor with a wrong parameter = " <<
			test_square.getSide() << std::endl;
	}

	// А теперь с правильным параметром
	// Не буду ограничивать область видимости
	// Так как в дальнейшем нужно проверить остальные методы
	Square test_square = Square(10.2f);
	std::cout << "The side of square's constructor with a correct parameter = " <<
		test_square.getSide() << std::endl;

	printEmptyLine();

	std::cout << "Square's square :) = " << test_square.getSquare() << std::endl;
	std::cout << "Square's perimeter = " << test_square.getPerimeter() << std::endl;

	printEmptyLine();
	printEmptyLine();
}

// Базовая проверка работоспособности класса Rectangle
// Проверяет работоспособность каждого метода
void base_test_rectangle() {
	{
		// Объявление без параметров
		Rectangle test_rectangle = Rectangle();
		std::cout << "The sides of rectangle's costructor without parameters = " <<
			test_rectangle.getSide() << " " << test_rectangle.getSecondSide() << std::endl;

		// Сразу проверка setSide и setSecondSide
		std::cout << "Trying to change the wrong values of object (-4.5f and -55.3f): " <<
			test_rectangle.setSide(-4.5f) << test_rectangle.setSecondSide(-55.3f) << "... and result = ";
		std::cout << test_rectangle.getSide() << " " << test_rectangle.getSecondSide() << std::endl;
		std::cout << "Trying to change the correct values of object (4.5f and 55.3f): " <<
			test_rectangle.setSide(4.5f) << test_rectangle.setSecondSide(55.3f) << "... and result = ";
		std::cout << test_rectangle.getSide() << " " << test_rectangle.getSecondSide() << std::endl;
	}

	printEmptyLine();

	{
		// Пробуем объявить с неправильным параметром
		Rectangle test_rectangle = Rectangle(-6.4f, -34.1f);
		std::cout << "The sides of rectangle's constructor with wrong parameters = " <<
			test_rectangle.getSide() << " " << test_rectangle.getSecondSide() << std::endl;
	}

	// А теперь с правильным параметром
	// Не буду ограничивать область видимости
	// Так как в дальнейшем нужно проверить остальные методы
	Rectangle test_rectangle = Rectangle(10.2f, 12.51f);
	std::cout << "The sides of rectangle's constructor with correct parameters = " <<
		test_rectangle.getSide() << " " << test_rectangle.getSecondSide() << std::endl;

	printEmptyLine();

	std::cout << "Rectangle's square = " << test_rectangle.getSquare() << std::endl;
	std::cout << "Rectangle's perimeter = " << test_rectangle.getPerimeter() << std::endl;

	printEmptyLine();
	printEmptyLine();
}

// Базовая проверка работоспособности класса Parallelogram
// Проверяет работоспособность каждого метода
void base_test_parallelogram() {
	{
		// Объявление без параметров
		Parallelogram test_parallelogram = Parallelogram();
		std::cout << "The sides of parallelogram's costructor without parameters = " <<
			test_parallelogram.getSide() << " " << test_parallelogram.getSecondSide() <<
			" " << test_parallelogram.getAngle() << std::endl;

		// Сразу проверка setSide, setSecondSide и setAngle
		std::cout << "Trying to change the wrong values of object (-4.5f, -55.3f and 194.2f): " <<
			test_parallelogram.setSide(-4.5f) << test_parallelogram.setSecondSide(-55.3f);
		std::cout << " " << test_parallelogram.setAngle(194.2f) << "... and result = ";
		std::cout << test_parallelogram.getSide() << " " << test_parallelogram.getSide() <<
			" " << test_parallelogram.getAngle() << std::endl;
		std::cout << "Trying to change the correct values of object (4.5f, 55.3f and 104.2f): " <<
			test_parallelogram.setSide(4.5f) << test_parallelogram.setSecondSide(55.3f);
		std::cout << " " << test_parallelogram.setAngle(104.2f) << "... and result = ";
		std::cout << test_parallelogram.getSide() << " " << test_parallelogram.getSecondSide() << 
			" " << test_parallelogram.getAngle() << std::endl;
	}

	printEmptyLine();

	{
		// Пробуем объявить с неправильным параметром
		Parallelogram test_parallelogram = Parallelogram(-6.4f, -34.1f, 194.2f);
		std::cout << "The sides of parallelogram's constructor with wrong parameters = " <<
			test_parallelogram.getSide() << " " << test_parallelogram.getSecondSide() << 
			" " << test_parallelogram.getAngle() << std::endl;
	}

	// А теперь с правильным параметром
	// Не буду ограничивать область видимости
	// Так как в дальнейшем нужно проверить остальные методы
	Parallelogram test_parallelogram = Parallelogram(10.2f, 12.51f, 104.2f);
	std::cout << "The sides of parallelogram's constructor with correct parameters = " <<
		test_parallelogram.getSide() << " " << test_parallelogram.getSecondSide() <<
		" " << test_parallelogram.getAngle() << std::endl;

	printEmptyLine();

	std::cout << "Parallelogram's square = " << test_parallelogram.getSquare() << std::endl;
	std::cout << "Parallelogram's perimeter = " << test_parallelogram.getPerimeter() << std::endl;

	printEmptyLine();
	printEmptyLine();
}
