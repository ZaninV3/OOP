#pragma once

// Класс параллелепипед
// В ../../adt.md есть фото параллелепипеда с названиями точек
class Parallelepiped {
// Закрытый от пользователя раздел. Со всеми переменными мы будем взаимодействовать через public
private:
	// Боковое ребро основания
	float ab_line = 0;
	// Лицевое ребро основания
	float bc_line = 0;
	// Боковое ребро параллелепипеда
	float side_line = 0;

	// Один из углов основания
	float bad_angle = 90;
	// Один из углов лицевой грани
	float a1ad_angle = 90;
	// Один из углов боковой грани
	float a1ab_angle = 90;

public:
	// Безпараметрический конструктор класса
	// Инициализирует объект класса со значениями по умолчанию (все ребра равны 0, а все углы 90)
	Parallelepiped() {}

	// Параметрический конструктор класса
	// Инициализирует объект класса с указанными пользователем значениями, если это возможно
	Parallelepiped(float pab_line, float pbc_line, float pside_line, float pbad_angle = 90, float pa1ad_angle = 90, float pa1ab_angle = 90) {
		// Если pab_line > 0, то меняем значение. Учитывая то, что ab_line = 0 по умолчанию,
		// то можно не проверять на нестрогое равенство, дабы не тратить время на пересваивания с 0 на 0
		if (pab_line > 0) {
			this->ab_line = pab_line;
		}
		// Аналогично выше для всех ребер
		if (pbc_line > 0) {
			this->bc_line = pbc_line;
		}
		if (pside_line > 0) {
			this->side_line = pside_line;
		}

		// С углами условие сложнее. угол должен 0 < угол < 180. с той целью,
		// чтобы во время создания getVolume нам нужно было делать меньше проверок.
		// Заодно мы обезопасили пользователя от такой ситуации, когда он не понимает почему большинство методов возвращают 0
		// Первая часть условия аналогично выше - чтобы не тратить время на переприсваивание одного и того же значения
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

	// Возвращает значение бокового ребра основания
	float getLineAB() const {
		return this->ab_line;
	}

	// Возвращает значение лицевого ребра основания
	float getLineBC() const {
		return this->bc_line;
	}

	// Возвращает значение бокового ребра параллелепипеда
	float getLineSide() const {
		return this->side_line;
	}


	// Возвращает значение одного из углов основания
	float getAngleBAD() const {
		return this->bad_angle;
	}

	// Возвращает значение одного из углов лицевой грани
	float getAngleA1AD() const {
		return this->a1ad_angle;
	}

	// Возвращает значение одного из углов боковой грани
	float getAngleA1AB() const {
		return this->a1ab_angle;
	}


	// Возвращает true, если значение бокового ребра основания было успешно изменено
	bool setLineAB(float pab_line) {
		// Если pab_line >= 0, то переназначаем значение ab_line и возвращаем true, иначе просто возвращаем false
		if (pab_line >= 0) {
			this->ab_line = pab_line;
			return true;
		}
		else {
			return false;
		}
	}

	// Возвращает true, если значение лицевого ребра основания было успешно изменено
	bool setLineBC(float pbc_line) {
		// Если pbc_line >= 0, то переназначаем значение bc_line и возвращаем true, иначе просто возвращаем false
		if (pbc_line >= 0) {
			this->bc_line = pbc_line;
			return true;
		}
		else {
			return false;
		}
	}
	
	// Возвращает true, если значение бокового ребра параллелепипеда было успешно изменено
	bool setLineSide(float pside_line) {
		// Если pside_line >= 0, то переназначаем значение side_line и возвращаем true, иначе просто возвращаем false
		if (pside_line >= 0) {
			this->side_line = pside_line;
			return true;
		}
		else {
			return false;
		}
	}


	// Возвращает true, если значение одного из углов основания было успешно изменено
	bool setAngleBAD(float pbad_angle) {
		// Если  0 < pbad_angle < 180, то переназначаем значение bad_angle и возвращаем true, иначе просто возвращаем false
		if (0 < pbad_angle and pbad_angle < 180) {
			this->bad_angle = pbad_angle;
			return true;
		}
		else {
			return false;
		}
	}

	// Возвращает true, если значение одного из углов лицевой грани было успешно изменено
	bool setAngleA1AD(float pa1ad_angle) {
		// Если  0 < pa1ad_angle < 180, то переназначаем значение a1ad_angle и возвращаем true, иначе просто возвращаем false
		if (0 < pa1ad_angle and pa1ad_angle < 180) {
			this->a1ad_angle = pa1ad_angle;
			return true;
		}
		else {
			return false;
		}
	}

	// Возвращает true, если значение одного из углов боковой грани было успешно изменено
	bool setAngleA1AB(float pa1ab_angle) {
		// Если  0 < pa1ab_angle < 180, то переназначаем значение a1ab_angle и возвращаем true, иначе просто возвращаем false
		if (0 < pa1ab_angle and pa1ab_angle < 180) {
			this->a1ab_angle = pa1ab_angle;
			return true;
		}
		else {
			return false;
		}
	}
};
