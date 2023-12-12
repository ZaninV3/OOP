#pragma once
#include "square.h"  // ���������� ������������� ����� � ������� Square

// ����� �������������
// �������� ������� ������� ��� Parallelogram � ����������� ������� ��� Square
// 
// ����� ������ 2 ���� -- ����� ���� ������
// 
// ������ ������:
// float getSide() const -- ���������� ����� ������ �������
// float getSecondSide() const -- ���������� ����� ������ �������
// float getSquare() const -- ���������� �������
// float getPerimeter() const -- ���������� ��������
// bool setSide(float side) -- ������ �������� ����� ������ ������� � ���������� true, ���� ������ ������ �������
// bool setSecondSide(float side) -- ������ �������� ����� ������ ������� � ���������� true, ���� ������ ������ �������
class Rectangle: public Square {
private:
	// ����� ������ �������
	float second_side;
public:
	// ����������� 
	// �������������� �������� side � second_side, ���� ��������� �������� ������ ��� ����� 0
	// ����� ������ �� �� ��������� 0
	Rectangle(float pside = 0, float psecond_side = 0);

	// ���������� �������� ������ �������
	float getSecondSide() const;

	// ���������� ������� ��������
	// S = side * second_side
	float getSquare() const;

	// ���������� �������� ��������
	// P = 2 * side + 2 * second_side
	float getPerimeter() const;
	
	// ������ �������� second_side ��� �������, ��� ��������� �������� > 0
	// ���������� true, ���� �������� ������������� �������
	bool setSecondSide(float psecond_side);
};

// ����������� 
// �������������� �������� side � second_side, ���� ��������� �������� ������ ��� ����� 0
// ����� ������ �� �� ��������� 0
Rectangle::Rectangle(float pside, float psecond_side) : Square(pside) {
	// � �������� Square(float pside = 0) �������������� ������ �������
	if (psecond_side < 0) this->second_side = 0;
	else this->second_side = psecond_side;
}

// ���������� �������� ������ �������
float Rectangle::getSecondSide() const {
	return this->second_side;
}

// ���������� ������� ��������
// S = side * second_side
float Rectangle::getSquare() const {
	return this->second_side * this->getSide();
}
// ��������� ��� ������������ ���������� ��� ������ ������ Square
// �� ������ Square::getSquare ��� Rectangle �����������
// ������� ������������� ��� �������

// ���������� �������� ��������
// P = 2 * side + 2 * second_side
float Rectangle::getPerimeter() const {
	return this->second_side * 2 + this->getSide() * 2;
}
// ����������� ��������, ��� � Rectangle::getSquare

// ������ �������� second_side ��� �������, ��� ��������� �������� > 0
// ���������� true, ���� �������� ������������� �������
bool Rectangle::setSecondSide(float psecond_side) {
	// ���� psecond_side ������ 0, �� ���������� false
	if (psecond_side < 0) return false;
	// ����� �������� ������ ���������
	else {
		this->second_side = psecond_side;
		return true;
	}
}
