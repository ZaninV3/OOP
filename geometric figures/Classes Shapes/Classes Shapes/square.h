#pragma once  // ��������� ���������� ������������ ���� �� ����� 1 ����
#include <cmath>  // �������������� �������

// ����� �������
// �������� ������� ������� ��� Rectangle � Parallelogram
// 
// ����� ������ 1 ���� -- ����� �������
// 
// ������ ������:
// float getSide() const -- ���������� ����� �������
// float getSquare() const -- ���������� �������
// float getPerimeter() const -- ���������� ��������
// bool setSide(float side) -- ������ �������� ����� � ���������� true, ���� ������ ������ �������
class Square {
private:
	float side;
public:
	// ����������� 
	// �������������� �������� side, ���� ��������� �������� ������ ��� ����� 0
	// ����� ������ �� ��������� 0
	Square(float pside = 0) {
		// ���� pside ������ 0, �� ������ �������� �� ���������
		if (pside < 0) this->side = 0;
		// ����� �������� ������ ���������
		else this->side = pside;
	}

	// ���������� �������� �������
	float getSide() const {
		return this->side;
	}
	// const ����� ��������, ��� � ������� ����������� �� ������������� 
	// �� ���� ���� ������� ��������� � ����������� ���������� this,
	// �� � ���� ������� ����������� �������� ������ ������

	// ���������� ������� ��������
	// S = side^2
	float getSquare() const {
		return powf(this->side, 2);
	}

	float getPerimeter() const {
		return this->side * 4;
	}

	// ������ �������� side ��� �������, ��� ��������� �������� > 0
	// ���������� true, ���� �������� ������������� �������
	bool setSide(float pside) {
		// ���� pside ������ 0, �� ���������� false
		if (pside < 0) return false;
		// ����� �������� ������ ���������
		else {
			this->side = pside;
			return true;
		}
	}
};
