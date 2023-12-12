#pragma once
#include "square.h"  // ���������� ������������� ����� � ������� Square
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
}