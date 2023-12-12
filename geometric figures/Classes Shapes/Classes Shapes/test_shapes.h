#pragma once
#include "rectangle.h"  // ���������� ������������� ����� � �������� Square � Rectangle
#include <iostream>  // ����/����� � �������

// ������� �� ����� ������ ������
void printEmptyLine() {
	std::cout << std::endl;
}

// ������� �������� ����������������� ������ Square
// ��������� ����������������� ������� ������
void base_test_square() {
	{
		// ���������� ��� ����������
		Square test_square = Square();
		std::cout << "The side of square's costructor without a parameter = " <<
			test_square.getSide() << std::endl;

		// ����� �������� setSide
		std::cout << "Trying to change the wrong value of object (-4.5f): " <<
			test_square.setSide(-4.5f) << "... and result = ";
		std::cout << test_square.getSide() << std::endl;
		std::cout << "Trying to change the correct value of object (4.5f): " <<
			test_square.setSide(4.5f) << "... and result = ";
		std::cout << test_square.getSide() << std::endl;
	}

	printEmptyLine();

	{
		// ������� �������� � ������������ ����������
		Square test_square = Square(-6.4f);
		std::cout << "The side of square's constructor with a wrong parameter = " <<
			test_square.getSide() << std::endl;
	}

	// � ������ � ���������� ����������
	// �� ���� ������������ ������� ���������
	// ��� ��� � ���������� ����� ��������� ��������� ������
	Square test_square = Square(10.2f);
	std::cout << "The side of square's constructor with a correct parameter = " <<
		test_square.getSide() << std::endl;

	printEmptyLine();

	std::cout << "Square's square :) = " << test_square.getSquare() << std::endl;
	std::cout << "Square's perimeter = " << test_square.getPerimeter() << std::endl;

	printEmptyLine();
	printEmptyLine();
}

// ������� �������� ����������������� ������ Rectangle
// ��������� ����������������� ������� ������
void base_test_rectangle() {
	{
		// ���������� ��� ����������
		Rectangle test_rectangle = Rectangle();
		std::cout << "The sides of rectangle's costructor without parameters = " <<
			test_rectangle.getSide() << " " << test_rectangle.getSecondSide() << std::endl;

		// ����� �������� setSide
		std::cout << "Trying to change the wrong values of object (-4.5f and -55.3f): " <<
			test_rectangle.setSide(-4.5f) << test_rectangle.setSecondSide(-55.3f) << "... and result = ";
		std::cout << test_rectangle.getSide() << " " << test_rectangle.getSide() << std::endl;
		std::cout << "Trying to change the correct values of object (4.5f and 55.3f): " <<
			test_rectangle.setSide(4.5f) << test_rectangle.setSecondSide(55.3f) << "... and result = ";
		std::cout << test_rectangle.getSide() << " " << test_rectangle.getSecondSide() << std::endl;
	}

	printEmptyLine();

	{
		// ������� �������� � ������������ ����������
		Rectangle test_rectangle = Rectangle(-6.4f, -34.1f);
		std::cout << "The sides of rectangle's constructor with wrong parameters = " <<
			test_rectangle.getSide() << " " << test_rectangle.getSecondSide() << std::endl;
	}

	// � ������ � ���������� ����������
	// �� ���� ������������ ������� ���������
	// ��� ��� � ���������� ����� ��������� ��������� ������
	Rectangle test_rectangle = Rectangle(10.2f, 12.51f);
	std::cout << "The sides of rectangle's constructor with correct parameters = " <<
		test_rectangle.getSide() << " " << test_rectangle.getSecondSide() << std::endl;

	printEmptyLine();

	std::cout << "Rectangle's square = " << test_rectangle.getSquare() << std::endl;
	std::cout << "Rectangle's perimeter = " << test_rectangle.getPerimeter() << std::endl;

	printEmptyLine();
	printEmptyLine();
}
