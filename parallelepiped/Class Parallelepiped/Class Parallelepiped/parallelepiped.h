#pragma once

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
		// ���������� ���� ��� ���� �����
		if (pbc_line > 0) {
			this->bc_line = pbc_line;
		}
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
		// ...
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
