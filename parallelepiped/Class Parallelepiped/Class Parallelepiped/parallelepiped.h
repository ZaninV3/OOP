#pragma once
#define _USE_MATH_DEFINES  // Подключаем мат. константы из math.h ради M_PI
#include <math.h>  // Библиотека для реализации мат. формул

// Класс параллелепипед
// Автор Занин Вячеслав ВМК-21
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

	// Коэфициент для перевода из градусов в радианы
	// Имеет смысл скрыть, чтобы пользователь не мог "крутить" это значение
	float convert_to_rad_k = M_PI / 180;

public:
	// Безпараметрический конструктор класса
	// Инициализирует объект класса со значениями по умолчанию (все ребра равны 0, а все углы 90)
	Parallelepiped();

	// Параметрический конструктор класса
	// Инициализирует объект класса с указанными пользователем значениями, если это возможно
	Parallelepiped(float pab_line, float pbc_line, float pside_line, float pbad_angle = 90, float pa1ad_angle = 90, float pa1ab_angle = 90);

	// Возвращает значение бокового ребра основания
	float getLineAB() const;
	// const здесь означает, что у функции ограничение на использование 
	// То есть если функция объявлена с константным указателем this,
	// то в теле функции запрещается изменять данные класса

	// Возвращает значение лицевого ребра основания
	float getLineBC() const;

	// Возвращает значение бокового ребра параллелепипеда
	float getLineSide() const;


	// Возвращает значение одного из углов основания
	float getAngleBAD() const;

	// Возвращает значение одного из углов лицевой грани
	float getAngleA1AD() const;

	// Возвращает значение одного из углов боковой грани
	float getAngleA1AB() const;


	// Возвращает строку с названием типа параллелепипеда
	// inclined -- наклонный параллелепипед
	// straight -- прямой параллелепипед (высота параллелепипеда равна боковому ребру)
	// cuboid -- прямоугольный параллелепипед (все грани -- прямоугольники)
	// rhombohedron -- ромбоэдр (все грани -- ромбы)
	// cube -- куб (все грани -- квадраты)
	std::string getType();


	// Возвращает длину диагонали AC
	// Формула, по которой идет подсчет, написана в ../../adt.md
	float getBaseFirstDiagonal();

	// Возвращает длину диагонали BD
	// Формула, по которой идет подсчет, написана в ../../adt.md
	float getBaseSecondDiagonal();

	// Возвращает длину диагонали A1D
	// Формула, по которой идет подсчет, написана в ../../adt.md
	float getFrontFirstDiagonal();

	// Возвращает длину диагонали AB1
	// Формула, по которой идет подсчет, написана в ../../adt.md
	float getFrontSecondDiagonal();

	// Возвращает длину диагонали A1B
	// Формула, по которой идет подсчет, написана в ../../adt.md
	float getSideFirstDiagonal();

	// Возвращает длину диагонали B1A
	// Формула, по которой идет подсчет, написана в ../../adt.md
	float getSideSecondDiagonal();


	// Возвращает угол A1AC
	// Формула, по которой идет подсчет, написана в ../../adt.md
	float getSideAndBaseDiagonalAngle();


	// Вовращает высоту грани от B до AD
	// Формула, по которой идет подсчет, написана в ../../adt.md
	float getBaseFirstHeight();

	// Вовращает высоту грани от A до CD
	// Формула, по которой идет подсчет, написана в ../../adt.md
	float getBaseSecondHeight();

	// Вовращает высоту грани от A1 до AD
	// Формула, по которой идет подсчет, написана в ../../adt.md
	float getFrontFirstHeight();

	// Вовращает высоту грани от A до DD1
	// Формула, по которой идет подсчет, написана в ../../adt.md
	float getFrontSecondHeight();

	// Возвращает высоту грани от A1 до AB
	// Формула, по которой идет подсчет, написана в ../../adt.md
	float getSideFirstHeight();

	// Возвращает высоту грани от A1 до BB1
	// Формула, по которой идет подсчет, написана в ../../adt.md
	float getSideSecondHeight();

	// Возвращает высоту параллелепипеда
	float getMainHeight();


	// Возвращает площадь лицевой грани
	float getFrontSquare();

	// Возвращает площадь боковой грани
	float getSideSquare();

	// Возвращает площадь основания
	float getBaseSquare();

	// Возвращает площадь боковых граней
	float getFrontsAndSidesSquare();

	// Возвращает площадь поверхности
	float getFullSquare();


	// Возвращает объем
	float getVolume();


	// Возвращает true, если значение бокового ребра основания было успешно изменено
	bool setLineAB(float pab_line);

	// Возвращает true, если значение лицевого ребра основания было успешно изменено
	bool setLineBC(float pbc_line);
	
	// Возвращает true, если значение бокового ребра параллелепипеда было успешно изменено
	bool setLineSide(float pside_line);


	// Возвращает true, если значение одного из углов основания было успешно изменено
	bool setAngleBAD(float pbad_angle);

	// Возвращает true, если значение одного из углов лицевой грани было успешно изменено
	bool setAngleA1AD(float pa1ad_angle);

	// Возвращает true, если значение одного из углов боковой грани было успешно изменено
	bool setAngleA1AB(float pa1ab_angle);
};

// Безпараметрический конструктор класса
// Инициализирует объект класса со значениями по умолчанию (все ребра равны 0, а все углы 90)
Parallelepiped::Parallelepiped() {}

// Параметрический конструктор класса
// Инициализирует объект класса с указанными пользователем значениями, если это возможно
Parallelepiped::Parallelepiped(float pab_line, float pbc_line, float pside_line, float pbad_angle, float pa1ad_angle, float pa1ab_angle) {
	// Если pab_line > 0, то меняем значение. Учитывая то, что ab_line = 0 по умолчанию,
	// то можно не проверять на нестрогое равенство, дабы не тратить время на пересваивания с 0 на 0
	if (pab_line > 0) {
		this->ab_line = pab_line;
	}
	// Если pbc_line > 0, то меняем значение. Учитывая то, что bc_line = 0 по умолчанию,
	// то можно не проверять на нестрогое равенство, дабы не тратить время на пересваивания с 0 на 0
	if (pbc_line > 0) {
		this->bc_line = pbc_line;
	}
	// Если side_line > 0, то меняем значение. Учитывая то, что side_line = 0 по умолчанию,
	// то можно не проверять на нестрогое равенство, дабы не тратить время на пересваивания с 0 на 0
	if (pside_line > 0) {
		this->side_line = pside_line;
	}

	// С углами условие сложнее. Угол должен 0 < угол < 180. С той целью,
	// чтобы во время создания getVolume нам нужно было делать меньше проверок.
	// Заодно мы обезопасили пользователя от такой ситуации, когда он не понимает почему большинство методов возвращают 0
	// Первая часть условия аналогично выше - чтобы не тратить время на переприсваивание одного и того же значения
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

// Возвращает значение бокового ребра основания
float Parallelepiped::getLineAB() const {
	return this->ab_line;
}
// const здесь означает, что у функции ограничение на использование 
// То есть если функция объявлена с константным указателем this,
// то в теле функции запрещается изменять данные класса

// Возвращает значение лицевого ребра основания
float Parallelepiped::getLineBC() const {
	return this->bc_line;
}

// Возвращает значение бокового ребра параллелепипеда
float Parallelepiped::getLineSide() const {
	return this->side_line;
}


// Возвращает значение одного из углов основания
float Parallelepiped::getAngleBAD() const {
	return this->bad_angle;
}

// Возвращает значение одного из углов лицевой грани
float Parallelepiped::getAngleA1AD() const {
	return this->a1ad_angle;
}

// Возвращает значение одного из углов боковой грани
float Parallelepiped::getAngleA1AB() const {
	return this->a1ab_angle;
}


// Возвращает строку с названием типа параллелепипеда
// inclined -- наклонный параллелепипед
// straight -- прямой параллелепипед (высота параллелепипеда равна боковому ребру)
// cuboid -- прямоугольный параллелепипед (все грани -- прямоугольники)
// rhombohedron -- ромбоэдр (все грани -- ромбы)
// cube -- куб (все грани -- квадраты)
std::string Parallelepiped::getType() {
	// Разбиваем проверки на части

	// Проверка углов
	// true, если a1ab_angle и a1ad_angle - прямые
	bool a1ab_and_a1ad = this->a1ab_angle == 90 and this->a1ad_angle == 90;
	// true, если все углы прямые
	bool all_angles = this->bad_angle == 90 and a1ab_and_a1ad;

	// Проверка ребер
	// true, если все ребра равны
	bool all_lines = this->ab_line == this->bc_line and this->bc_line == this->side_line;

	// На основе полученных булевых переменных,
	// определяем тип параллелепипеда и возвращаем значение.
	// 
	// Все проверки расставлены по принципу
	// от самых наиболее встречающихся при разных наборах данных
	// к наиболее частным случаям параллелепипеда
	// 
	// Если все false, то параллелепипед наклонный
	if (not all_angles and not all_lines and not a1ab_and_a1ad) {
		return "inclined";
	}
	// Если только a1ab_and_a1ad -- true, то параллелепипед прямой
	else if (not all_angles and not all_lines and a1ab_and_a1ad) {
		return "straignt";
	}
	// Если только all_angles -- true, то параллелепипед прямоугольный
	else if (all_angles and not all_lines) {
		return "cuboid";
	}
	// Если только all_lines -- true, то параллелепипед ромбоэдр
	else if (not all_angles and all_lines) {
		return "rhombohedron";
	}
	// если ничего не подошло, то это куб
	else {
		return "cube";
	}

	// cube - все ребра* равны и углы* равны 90гр.
	// rhombohetron - все ребра* равны
	// cuboid - все углы* равны 90гр.
	// straight - только боковые углы* равны 90гр.
	// inclined - произвольный (никакое условие выше не удовлетворено)
	//
	// * - ребра и углы, которые указаны в private
}


// Возвращает длину диагонали AC
// Формула, по которой идет подсчет, написана в ../../adt.md
float Parallelepiped::getBaseFirstDiagonal() {
	return sqrt(pow(this->ab_line, 2) + pow(this->bc_line, 2) - 2 * this->ab_line * this->bc_line * cos(convert_to_rad_k * (180 - this->bad_angle)));
}

// Возвращает длину диагонали BD
// Формула, по которой идет подсчет, написана в ../../adt.md
float Parallelepiped::getBaseSecondDiagonal() {
	return sqrt(pow(this->ab_line, 2) + pow(this->bc_line, 2) + 2 * this->ab_line * this->bc_line * cos(convert_to_rad_k * (180 - this->bad_angle)));
}

// Возвращает длину диагонали A1D
// Формула, по которой идет подсчет, написана в ../../adt.md
float Parallelepiped::getFrontFirstDiagonal() {
	return sqrt(pow(this->side_line, 2) + pow(this->bc_line, 2) - 2 * this->side_line * this->bc_line * cos(convert_to_rad_k * this->a1ad_angle));
}

// Возвращает длину диагонали AB1
// Формула, по которой идет подсчет, написана в ../../adt.md
float Parallelepiped::getFrontSecondDiagonal() {
	return sqrt(pow(this->side_line, 2) + pow(this->bc_line, 2) + 2 * this->side_line * this->bc_line * cos(convert_to_rad_k * this->a1ad_angle));
}

// Возвращает длину диагонали A1B
// Формула, по которой идет подсчет, написана в ../../adt.md
float Parallelepiped::getSideFirstDiagonal() {
	return sqrt(pow(this->side_line, 2) + pow(this->ab_line, 2) - 2 * this->side_line * this->ab_line * cos(convert_to_rad_k * this->a1ab_angle));
}

// Возвращает длину диагонали B1A
// Формула, по которой идет подсчет, написана в ../../adt.md
float Parallelepiped::getSideSecondDiagonal() {
	return sqrt(pow(this->side_line, 2) + pow(this->ab_line, 2) + 2 * this->side_line * this->ab_line * cos(convert_to_rad_k * this->a1ab_angle));
}


// Возвращает угол A1AC
// Формула, по которой идет подсчет, написана в ../../adt.md
float Parallelepiped::getSideAndBaseDiagonalAngle() {
	// Для начала исключим вариант константного значения
	if (this->a1ab_angle != this->a1ad_angle) {
		// Поскольку формула большая и в ней
		// часто приходится вызывать одни и те же значения
		// объявим переменные, где название каждой переменной
		// имеет соответствующее названию на картинке и в формуле
		// 
		// Если переменная имеет название из 2-х букв
		// то это ребро, иначе угол
		float ab = this->ab_line;
		float ac = getBaseFirstDiagonal();
		float bc = this->bc_line;

		float bad = this->bad_angle;
		float a1ab = this->a1ab_angle;
		float a1ad = this->a1ad_angle;

		// считаем и возвращаем
		return (180 / (acos((pow(ab, 2) + pow(ac, 2) - pow(bc, 2)) / (2 * ab * ac)) * M_PI) / bad) * (a1ad - a1ab) + a1ab;
	}

	// Иначе углы A1AB и A1AD равны
	return this->a1ab_angle;
}


// Вовращает высоту грани от B до AD
// Формула, по которой идет подсчет, написана в ../../adt.md
float Parallelepiped::getBaseFirstHeight() {
	return this->ab_line * sin(convert_to_rad_k * this->bad_angle);
}

// Вовращает высоту грани от A до CD
// Формула, по которой идет подсчет, написана в ../../adt.md
float Parallelepiped::getBaseSecondHeight() {
	return this->bc_line * sin(convert_to_rad_k * (180 - this->bad_angle));
}

// Вовращает высоту грани от A1 до AD
// Формула, по которой идет подсчет, написана в ../../adt.md
float Parallelepiped::getFrontFirstHeight() {
	return this->side_line * sin(convert_to_rad_k * this->a1ad_angle);
}

// Вовращает высоту грани от A до DD1
// Формула, по которой идет подсчет, написана в ../../adt.md
float Parallelepiped::getFrontSecondHeight() {
	return this->bc_line * sin(convert_to_rad_k * (180 - this->a1ad_angle));
}

// Возвращает высоту грани от A1 до AB
// Формула, по которой идет подсчет, написана в ../../adt.md
float Parallelepiped::getSideFirstHeight() {
	return this->side_line * sin(convert_to_rad_k * this->a1ab_angle);
}

// Возвращает высоту грани от A1 до BB1
// Формула, по которой идет подсчет, написана в ../../adt.md
float Parallelepiped::getSideSecondHeight() {
	return this->ab_line * sin(convert_to_rad_k * (180 - this->a1ab_angle));
}

// Возвращает высоту параллелепипеда
float Parallelepiped::getMainHeight() {
	return this->side_line * sin(convert_to_rad_k * getSideAndBaseDiagonalAngle());
}


// Возвращает площадь лицевой грани
float Parallelepiped::getFrontSquare() {
	return getFrontFirstHeight() * this->bc_line;
}

// Возвращает площадь боковой грани
float Parallelepiped::getSideSquare() {
	return getSideFirstHeight() * this->ab_line;
}

// Возвращает площадь основания
float Parallelepiped::getBaseSquare() {
	return getBaseFirstHeight() * this->bc_line;
}

// Возвращает площадь боковых граней
float Parallelepiped::getFrontsAndSidesSquare() {
	return 2 * getFrontSquare() + 2 * getSideSquare();
}

// Возвращает площадь поверхности
float Parallelepiped::getFullSquare() {
	return 2 * (getBaseFirstHeight() * this->bc_line) + getSideSquare();
}


// Возвращает объем
float Parallelepiped::getVolume() {
	return getMainHeight() * getBaseSquare();
}


// Возвращает true, если значение бокового ребра основания было успешно изменено
bool Parallelepiped::setLineAB(float pab_line) {
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
bool Parallelepiped::setLineBC(float pbc_line) {
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
bool Parallelepiped::setLineSide(float pside_line) {
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
bool Parallelepiped::setAngleBAD(float pbad_angle) {
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
bool Parallelepiped::setAngleA1AD(float pa1ad_angle) {
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
bool Parallelepiped::setAngleA1AB(float pa1ab_angle) {
	// Если  0 < pa1ab_angle < 180, то переназначаем значение a1ab_angle и возвращаем true, иначе просто возвращаем false
	if (0 < pa1ab_angle and pa1ab_angle < 180) {
		this->a1ab_angle = pa1ab_angle;
		return true;
	}
	else {
		return false;
	}
}
