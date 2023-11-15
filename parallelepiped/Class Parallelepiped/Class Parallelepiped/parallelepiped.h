#pragma once
#include <math.h>  // ���������� ��� ���������� ���. ������

// ����� ��������������
// � ../../adt.md ���� ���� ��������������� � ���������� �����
class Parallelepiped {
// �������� �� ������������ ������. �� ����� ����������� �� ����� ����������������� ����� public
private:
	// ������� ����� ���������
	float ab_line = 0;
	// ������� ����� ���������
	float bc_line = 0;
	// ������� ����� ���������������
	float side_line = 0;

	// ���� �� ����� ���������
	float bad_angle = 90;
	// ���� �� ����� ������� �����
	float a1ad_angle = 90;
	// ���� �� ����� ������� �����
	float a1ab_angle = 90;

	// ���������� ��� �������� �� �������� � �������
	// ����� ����� ������, ����� ������������ �� ��� "�������" ��� ��������
	float convert_to_rad_k = 3.141592653589793238462643 / 180;

public:
	// ������������������ ����������� ������
	// �������������� ������ ������ �� ���������� �� ��������� (��� ����� ����� 0, � ��� ���� 90)
	Parallelepiped() {}

	// ��������������� ����������� ������
	// �������������� ������ ������ � ���������� ������������� ����������, ���� ��� ��������
	Parallelepiped(float pab_line, float pbc_line, float pside_line, float pbad_angle = 90, float pa1ad_angle = 90, float pa1ab_angle = 90) {
		// ���� pab_line > 0, �� ������ ��������. �������� ��, ��� ab_line = 0 �� ���������,
		// �� ����� �� ��������� �� ��������� ���������, ���� �� ������� ����� �� ������������� � 0 �� 0
		if (pab_line > 0) {
			this->ab_line = pab_line;
		}
		// ���� pbc_line > 0, �� ������ ��������. �������� ��, ��� bc_line = 0 �� ���������,
		// �� ����� �� ��������� �� ��������� ���������, ���� �� ������� ����� �� ������������� � 0 �� 0
		if (pbc_line > 0) {
			this->bc_line = pbc_line;
		}
		// ���� side_line > 0, �� ������ ��������. �������� ��, ��� side_line = 0 �� ���������,
		// �� ����� �� ��������� �� ��������� ���������, ���� �� ������� ����� �� ������������� � 0 �� 0
		if (pside_line > 0) {
			this->side_line = pside_line;
		}

		// � ������ ������� �������. ���� ������ 0 < ���� < 180. � ��� �����,
		// ����� �� ����� �������� getVolume ��� ����� ���� ������ ������ ��������.
		// ������ �� ����������� ������������ �� ����� ��������, ����� �� �� �������� ������ ����������� ������� ���������� 0
		// ������ ����� ������� ���������� ���� - ����� �� ������� ����� �� ���������������� ������ � ���� �� ��������
		if (pbad_angle != 90 and 0 < pbad_angle and pbad_angle < 180) {
			this->bad_angle = pbad_angle;
		}
		if (pa1ad_angle != 90 and 0 < pa1ad_angle and pa1ad_angle < 180) {
			this->a1ad_angle = pa1ad_angle;
		}
		if (pa1ab_angle != 90 and 0 < pa1ab_angle and pa1ab_angle < 180) {
			this->a1ab_angle = pa1ab_angle;
		}
	}

	// ���������� �������� �������� ����� ���������
	float getLineAB() const {
		return this->ab_line;
	}

	// ���������� �������� �������� ����� ���������
	float getLineBC() const {
		return this->bc_line;
	}

	// ���������� �������� �������� ����� ���������������
	float getLineSide() const {
		return this->side_line;
	}


	// ���������� �������� ������ �� ����� ���������
	float getAngleBAD() const {
		return this->bad_angle;
	}

	// ���������� �������� ������ �� ����� ������� �����
	float getAngleA1AD() const {
		return this->a1ad_angle;
	}

	// ���������� �������� ������ �� ����� ������� �����
	float getAngleA1AB() const {
		return this->a1ab_angle;
	}


	// ���������� ������ � ��������� ���� ���������������
	// inclined -- ��������� ��������������
	// straight -- ������ �������������� (������ ��������������� ����� �������� �����)
	// cuboid -- ������������� �������������� (��� ����� -- ��������������)
	// rhombohedron -- �������� (��� ����� -- �����)
	// cube -- ��� (��� ����� -- ��������)
	std::string getType() {
		// ��������� �������� �� �����

		// �������� �����
		// true, ���� a1ab_angle � a1ad_angle - ������
		bool a1ab_and_a1ad = this->a1ab_angle == 90 and this->a1ad_angle == 90;
		// true, ���� ��� ���� ������
		bool all_angles = this->bad_angle == 90 and a1ab_and_a1ad;

		// �������� �����
		// true, ���� ��� ����� �����
		bool all_lines = this->ab_line == this->bc_line and this->bc_line == this->side_line;

		// �� ������ ���������� ������� ����������,
		// ���������� ��� ��������������� � ���������� ��������.
		// 
		// ��� �������� ����������� �� ��������
		// �� ����� �������� ������������� ��� ������ ������� ������
		// � �������� ������� ������� ���������������
		// 
		// ���� ��� false, �� �������������� ���������
		if (not all_angles and not all_lines and not a1ab_and_a1ad) {
			return "inclined";
		}
		// ���� ������ a1ab_and_a1ad -- true, �� �������������� ������
		else if (not all_angles and not all_lines and a1ab_and_a1ad) {
			return "straignt";
		}
		// ���� ������ all_angles -- true, �� �������������� �������������
		else if (all_angles and not all_lines) {
			return "cuboid";
		}
		// ���� ������ all_lines -- true, �� �������������� ��������
		else if (not all_angles and all_lines) {
			return "rhombohedron";
		}
		// ���� ������ �� �������, �� ��� ���
		else {
			return "cube";
		}
	}


	// ���������� ����� ��������� AC
	// �������, �� ������� ���� �������, �������� � ../../adt.md
	float getBaseFirstDiagonal() {
		return sqrt(pow(this->ab_line, 2) + pow(this->bc_line, 2) - 2 * this->ab_line * this->bc_line * cos(convert_to_rad_k * (180 - this->bad_angle)));
	}

	// ���������� ����� ��������� BD
	// �������, �� ������� ���� �������, �������� � ../../adt.md
	float getBaseSecondDiagonal() {
		return sqrt(pow(this->ab_line, 2) + pow(this->bc_line, 2) + 2 * this->ab_line * this->bc_line * cos(convert_to_rad_k * (180 - this->bad_angle)));
	}

	// ���������� ����� ��������� A1D
	// �������, �� ������� ���� �������, �������� � ../../adt.md
	float getFrontFirstDiagonal() {
		return sqrt(pow(this->side_line, 2) + pow(this->bc_line, 2) - 2 * this->side_line * this->bc_line * cos(convert_to_rad_k * this->a1ad_angle));
	}

	// ���������� ����� ��������� AB1
	// �������, �� ������� ���� �������, �������� � ../../adt.md
	float getFrontSecondDiagonal() {
		return sqrt(pow(this->side_line, 2) + pow(this->bc_line, 2) + 2 * this->side_line * this->bc_line * cos(convert_to_rad_k * this->a1ad_angle));
	}

	// ���������� ����� ��������� A1B
	// �������, �� ������� ���� �������, �������� � ../../adt.md
	float getSideFirstDiagonal() {
		return sqrt(pow(this->side_line, 2) + pow(this->ab_line, 2) - 2 * this->side_line * this->ab_line * cos(convert_to_rad_k * this->a1ab_angle));
	}

	// ���������� ����� ��������� B1A
	// �������, �� ������� ���� �������, �������� � ../../adt.md
	float getSideSecondDiagonal() {
		return sqrt(pow(this->side_line, 2) + pow(this->ab_line, 2) + 2 * this->side_line * this->ab_line * cos(convert_to_rad_k * this->a1ab_angle));
	}


	// ���������� ���� A1AC
	// �������, �� ������� ���� �������, �������� � ../../adt.md
	float getSideAndBaseDiagonalAngle() {
		// ��� ������ �������� ������� ������������ ��������
		if (this->a1ab_angle != this->a1ad_angle) {
			// ��������� ������� ������� � � ���
			// ����� ���������� �������� ���� � �� �� ��������
			// ������� ����������, ��� �������� ������ ����������
			// ����� ��������������� �������� �� �������� � � �������
			// 
			// ���� ���������� ����� �������� �� 2-� ����
			// �� ��� �����, ����� ����
			float ab = this->ab_line;
			float ac = getBaseFirstDiagonal();
			float bc = this->bc_line;

			float bad = this->bad_angle;
			float a1ab = this->a1ab_angle;
			float a1ad = this->a1ad_angle;

			// ������� � ����������
			return (180 / (acos((pow(ab, 2) + pow(ac, 2) - pow(bc, 2)) / (2 * ab * ac)) * 3.141592653589793238462643) / bad) * (a1ad - a1ab) + a1ab;
		}

		// ����� ���� A1AB � A1AD �����
		return this->a1ab_angle;
	}


	// ��������� ������ ����� �� B �� AD
	// �������, �� ������� ���� �������, �������� � ../../adt.md
	float getBaseFirstHeight() {
		return this->ab_line * sin(convert_to_rad_k * this->bad_angle);
	}

	// ��������� ������ ����� �� A �� CD
	// �������, �� ������� ���� �������, �������� � ../../adt.md
	float getBaseSecondHeight() {
		return this->bc_line * sin(convert_to_rad_k * (180 - this->bad_angle));
	}

	// ��������� ������ ����� �� A1 �� AD
	// �������, �� ������� ���� �������, �������� � ../../adt.md
	float getFrontFirstHeight() {
		return this->side_line * sin(convert_to_rad_k * this->a1ad_angle);
	}

	// ��������� ������ ����� �� A �� DD1
	// �������, �� ������� ���� �������, �������� � ../../adt.md
	float getFrontSecondHeight() {
		return this->bc_line * sin(convert_to_rad_k * (180 - this->a1ad_angle));
	}

	// ���������� ������ ����� �� A1 �� AB
	// �������, �� ������� ���� �������, �������� � ../../adt.md
	float getSideFirstHeight() {
		return this->side_line * sin(convert_to_rad_k * this->a1ab_angle);
	}

	// ���������� ������ ����� �� A1 �� BB1
	// �������, �� ������� ���� �������, �������� � ../../adt.md
	float getSideSecondHeight() {
		return this->ab_line * sin(convert_to_rad_k * (180 - this->a1ab_angle));
	}

	// ���������� ������ ���������������
	float getMainHeight() {
		return this->side_line * sin(convert_to_rad_k * getSideAndBaseDiagonalAngle());
	}


	// ���������� true, ���� �������� �������� ����� ��������� ���� ������� ��������
	bool setLineAB(float pab_line) {
		// ���� pab_line >= 0, �� ������������� �������� ab_line � ���������� true, ����� ������ ���������� false
		if (pab_line >= 0) {
			this->ab_line = pab_line;
			return true;
		}
		else {
			return false;
		}
	}

	// ���������� true, ���� �������� �������� ����� ��������� ���� ������� ��������
	bool setLineBC(float pbc_line) {
		// ���� pbc_line >= 0, �� ������������� �������� bc_line � ���������� true, ����� ������ ���������� false
		if (pbc_line >= 0) {
			this->bc_line = pbc_line;
			return true;
		}
		else {
			return false;
		}
	}
	
	// ���������� true, ���� �������� �������� ����� ��������������� ���� ������� ��������
	bool setLineSide(float pside_line) {
		// ���� pside_line >= 0, �� ������������� �������� side_line � ���������� true, ����� ������ ���������� false
		if (pside_line >= 0) {
			this->side_line = pside_line;
			return true;
		}
		else {
			return false;
		}
	}


	// ���������� true, ���� �������� ������ �� ����� ��������� ���� ������� ��������
	bool setAngleBAD(float pbad_angle) {
		// ����  0 < pbad_angle < 180, �� ������������� �������� bad_angle � ���������� true, ����� ������ ���������� false
		if (0 < pbad_angle and pbad_angle < 180) {
			this->bad_angle = pbad_angle;
			return true;
		}
		else {
			return false;
		}
	}

	// ���������� true, ���� �������� ������ �� ����� ������� ����� ���� ������� ��������
	bool setAngleA1AD(float pa1ad_angle) {
		// ����  0 < pa1ad_angle < 180, �� ������������� �������� a1ad_angle � ���������� true, ����� ������ ���������� false
		if (0 < pa1ad_angle and pa1ad_angle < 180) {
			this->a1ad_angle = pa1ad_angle;
			return true;
		}
		else {
			return false;
		}
	}

	// ���������� true, ���� �������� ������ �� ����� ������� ����� ���� ������� ��������
	bool setAngleA1AB(float pa1ab_angle) {
		// ����  0 < pa1ab_angle < 180, �� ������������� �������� a1ab_angle � ���������� true, ����� ������ ���������� false
		if (0 < pa1ab_angle and pa1ab_angle < 180) {
			this->a1ab_angle = pa1ab_angle;
			return true;
		}
		else {
			return false;
		}
	}
};
