#pragma once
#include "square.h"  // Поключение заголовочного файла с классом Square
#include <iostream>  // Ввод/вывод в консоль

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
}