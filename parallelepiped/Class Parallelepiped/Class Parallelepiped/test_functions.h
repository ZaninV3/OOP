#pragma once
#include "parallelepiped.h"  // ���������� ������������ ���� � ����� �������
// ���������� ��������� �������������� �� ����������
Parallelepiped getStartParallelepiped() {
	// �������������� ������ � �������� �����������
	// �������� ��������� ��������� ������ � ������� � ���� �������� �� ���������
	return Parallelepiped(-3, 4, 5, 45, -10);
}

// ������� ������ ������ ��� �������� �� cout
void makeCout() {
	std::cout << std::endl;
}

// ������������� ������� � ����� ��� ��������� ��������
void stepInitializing() {
	makeCout();
	Parallelepiped test_p = getStartParallelepiped();

	// ������� �� ����� ��� �������� �����
	std::cout << "lines: " << test_p.getLineAB() << " " << test_p.getLineBC() << " " << test_p.getLineSide() << std::endl;

	// ������� �������� �����
	std::cout << "angles: " << test_p.getAngleBAD() << " " << test_p.getAngleA1AD() << " " << test_p.getAngleA1AB() << std::endl;
	makeCout();
}

// �������� ��������
void stepCheckSets() {
	makeCout();

	Parallelepiped test_p = getStartParallelepiped();

	// ������� ������ �������� �����
	std::cout << "trying to change the value of line AB" << std::endl;

	// ��� ������ ������������ �������� � ��������� ������ ������� ������
	bool check = test_p.setLineAB(-200.05);
	std::cout << "result0: " << check << " and the value: " << test_p.getLineAB() << std::endl;

	// � ������ ������� �������� ���������� �������� � ��������� ������ ������� ������
	check = test_p.setLineAB(200.05);
	std::cout << "result1: " << check << " and the value: " << test_p.getLineAB() << std::endl;


	// � ������ �������� �����
	std::cout << "\ntrying to change the value of BAD" << std::endl;

	// ���������� ������� ���� � ������
	check = test_p.setAngleBAD(181);
	std::cout << "result2: " << check << " and the value: " << test_p.getAngleBAD() << std::endl;

	check = test_p.setAngleBAD(90);
	std::cout << "result3: " << check << " and the value: " << test_p.getAngleBAD() << std::endl;

	makeCout();
}

// �������� ����������� ���� ���������������
void stepCheckType() {
	makeCout();
	// ������� ��������� �������������� � �������
	std::cout << "creating the object..." << std::endl;
	Parallelepiped test_s = Parallelepiped(3, 4, 5, 65, 32, 78);
	std::cout << "result4: " << test_s.getType() << std::endl;

	// ������������ � ������ �������������� � ������� �� �����
	std::cout << "converting to a straight parallelepiped... " << test_s.setAngleA1AD(90) << test_s.setAngleA1AB(90) << std::endl;
	std::cout << "result5: " << test_s.getType() << std::endl;

	// ������������ � ������������� �������������� � ������� �� �����
	std::cout << "converting to a cuboid... " << test_s.setAngleBAD(90) << std::endl;
	std::cout << "result6: " << test_s.getType() << std::endl;

	// ������������ � ��� � ������� �� �����
	std::cout << "converting to a cube... " << test_s.setLineAB(5) << test_s.setLineBC(5) << test_s.setLineSide(5) << std::endl;
	std::cout << "result7: " << test_s.getType() << std::endl;

	// ������������ � �������� � ������� �� �����
	std::cout << "converting to a rhombohedron... " << test_s.setAngleA1AB(23.4) << std::endl;
	std::cout << "result8: " << test_s.getType() << std::endl;

	makeCout();
}

// �������� �����
void stepCheckHeights() {
	makeCout();
	// ��� ������ �������� ����� ������� � ����� �������� ������
	// ������� ������ ����� ������� ���
	Parallelepiped test_s = Parallelepiped(4, 4, 4, 90, 90, 90);

	std::cout << "result9: " << test_s.getMainHeight() << " and the line AA1: " << test_s.getLineSide() << std::endl;

	// ������� ������� ����
	// �� ���� �� ������ �������� ������ ���� A1AC
	std::cout << "changing values of angles... " << test_s.setAngleA1AB(89) << test_s.setAngleA1AD(91) << std::endl;
	std::cout << "result10: " << test_s.getMainHeight() << " and the line AA1: " << test_s.getLineSide() << std::endl;

	// ��� ������ �� ������ ��������� +- �� ����� �������.
	// ������� ���������� ������ 1 �����
	std::cout << "changing the value of line... " << test_s.setLineSide(16) << std::endl;
	std::cout << "changing the value of angle... " << test_s.setAngleA1AD(65) << std::endl;
	std::cout << "result11: " << test_s.getFrontFirstHeight() << std::endl;

	makeCout();
}

// �������� ����������
void stepCheckDiagonals() {
	makeCout();

	// ��������� ������� ���������� ��� +- ����������, �� �������� ����� ����
	Parallelepiped test_s = getStartParallelepiped();
	std::cout << "result12: " << test_s.getFrontFirstDiagonal() << std::endl;

	makeCout();
}

// �������� �������� � ������
void stepCheckSV() {
	makeCout();

	Parallelepiped test_s = getStartParallelepiped();
	// ������ ��������� �������� ���� ������ �� ������ 0
	test_s.setLineAB(3);

	// ������ �������� �� +- ����� �������, ������� �������� ���������� �������
	std::cout << "result13: " << test_s.getBaseSquare() << std::endl;
	std::cout << "result14: " << test_s.getFullSquare() << std::endl;
	std::cout << "result13: " << test_s.getVolume() << std::endl;

	makeCout();
}