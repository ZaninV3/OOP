#pragma once
#define _USE_MATH_DEFINES // ��� M_PI
#include "rectangle.h"  // ���������� ������������� ����� � �������� Square � Rectangle

// ����� �������������
// ��������  ����������� ������� ��� Rectangle
// 
// ����� ������ 3 ���� -- ����� ���� ������ � ���� ����� ���� BAD
// 
// ������ ������:
// float getSide() const -- ���������� ����� ������ �������
// float getSecondSide() const -- ���������� ����� ������ �������
// float getAngle() const -- ���������� �������� ���� BAD � ��������
// float getSquare() const -- ���������� �������
// float getPerimeter() const -- ���������� ��������
// bool setSide(float side) -- ������ �������� ����� ������ ������� � ���������� true, ���� ������ ������ �������
// bool setSecondSide(float side) -- ������ �������� ����� ������ ������� � ���������� true, ���� ������ ������ �������
// bool setAngle(float angle) -- ������ �������� ���� � ���������� true, ���� ������ ������ �������
class Parallelogram: public Rectangle {
private:
	// �������� ���� BAD � ��������
	float angle_bad;
public:
	// ����������� 
	// �������������� �������� side, second_side � angle_bad, ���� ��������� �������� ������ ��� ����� 0 � 0 < angle_bad < 180
	// ����� ������ �� �� ��������� 0, 0 � 90 ��������������
	Parallelogram(float pside = 0, float psecond_side = 0, float pangle_bad = 90);


	// ���������� �������� ����
	float getAngle() const;

	// ���������� ������� ��������
	// S = side * second_side * sin(angle_bad)
	float getSquare() const;

	// �� � ��� ��������� ��� ������ �������������� �������


	// ������ �������� angle_bad ��� �������, ��� ��������� �������� > 0 � < 180
	// ���������� true, ���� �������� ������������� �������
	bool setAngle(float pangle_bad = 90);
};

// ����������� 
// �������������� �������� side, second_side � angle_bad, ���� ��������� �������� ������ ��� ����� 0 � 0 < angle_bad < 180
// ����� ������ �� �� ��������� 0, 0 � 90 ��������������
Parallelogram::Parallelogram(float pside, float psecond_side, float pangle_bad) : Rectangle(pside, psecond_side) {
	// � �������� � �������������� Rectangle � Square
	if (0 < pangle_bad and pangle_bad < 180) this->angle_bad = pangle_bad;
	else this->angle_bad = 90;
}

// ���������� �������� ����
float Parallelogram::getAngle() const {
	return this->angle_bad;
}

// ���������� ������� ��������
// S = side * second_side * sin(angle_bad)
float Parallelogram::getSquare() const {
	return this->getSecondSide() * this->getSide() * sinf(this->angle_bad * 180 / M_PI);  // ��������� ������� �������� � �������
}

// ������ �������� angle_bad ��� �������, ��� ��������� �������� > 0 � < 180
// ���������� true, ���� �������� ������������� �������
bool Parallelogram::setAngle(float pangle_bad) {
	// ���� pangle_bad < 0 ��� > 180, �� ���������� false
	if (pangle_bad < 0 or pangle_bad > 180) return false;
	// ����� �������� ������ ���������
	else {
		this->angle_bad = pangle_bad;
		return true;
	}
}
