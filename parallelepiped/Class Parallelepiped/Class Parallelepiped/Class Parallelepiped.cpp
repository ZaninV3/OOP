// Автор Занин Вячеслав ВМК-21

#include <iostream>
#include <fstream>  // Для работы с бинарными файлами
#include <stdlib.h>  // Для генерации случайных чисел
#include "test_functions.h"  // Для функций-тестировщиков класса Parallelepiped. Туда же поключен заголовочный файл parallelepiped.h 
using namespace std;

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
std::string Parallelepiped::getType() const {
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
float Parallelepiped::getBaseFirstDiagonal() const{
	return sqrt(pow(this->ab_line, 2) + pow(this->bc_line, 2) - 2 * this->ab_line * this->bc_line * cos(this->convert_to_rad_k * (180 - this->bad_angle)));
}

// Возвращает длину диагонали BD
// Формула, по которой идет подсчет, написана в ../../adt.md
float Parallelepiped::getBaseSecondDiagonal() const {
	return sqrt(pow(this->ab_line, 2) + pow(this->bc_line, 2) + 2 * this->ab_line * this->bc_line * cos(convert_to_rad_k * (180 - this->bad_angle)));
}

// Возвращает длину диагонали A1D
// Формула, по которой идет подсчет, написана в ../../adt.md
float Parallelepiped::getFrontFirstDiagonal() const {
	return sqrt(pow(this->side_line, 2) + pow(this->bc_line, 2) - 2 * this->side_line * this->bc_line * cos(convert_to_rad_k * this->a1ad_angle));
}

// Возвращает длину диагонали AB1
// Формула, по которой идет подсчет, написана в ../../adt.md
float Parallelepiped::getFrontSecondDiagonal() const {
	return sqrt(pow(this->side_line, 2) + pow(this->bc_line, 2) + 2 * this->side_line * this->bc_line * cos(convert_to_rad_k * this->a1ad_angle));
}

// Возвращает длину диагонали A1B
// Формула, по которой идет подсчет, написана в ../../adt.md
float Parallelepiped::getSideFirstDiagonal() const {
	return sqrt(pow(this->side_line, 2) + pow(this->ab_line, 2) - 2 * this->side_line * this->ab_line * cos(convert_to_rad_k * this->a1ab_angle));
}

// Возвращает длину диагонали B1A
// Формула, по которой идет подсчет, написана в ../../adt.md
float Parallelepiped::getSideSecondDiagonal() const {
	return sqrt(pow(this->side_line, 2) + pow(this->ab_line, 2) + 2 * this->side_line * this->ab_line * cos(convert_to_rad_k * this->a1ab_angle));
}


// Возвращает угол A1AC
// Формула, по которой идет подсчет, написана в ../../adt.md
float Parallelepiped::getSideAndBaseDiagonalAngle() const {
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
float Parallelepiped::getBaseFirstHeight() const {
	return this->ab_line * sin(convert_to_rad_k * this->bad_angle);
}

// Вовращает высоту грани от A до CD
// Формула, по которой идет подсчет, написана в ../../adt.md
float Parallelepiped::getBaseSecondHeight() const {
	return this->bc_line * sin(convert_to_rad_k * (180 - this->bad_angle));
}

// Вовращает высоту грани от A1 до AD
// Формула, по которой идет подсчет, написана в ../../adt.md
float Parallelepiped::getFrontFirstHeight() const {
	return this->side_line * sin(convert_to_rad_k * this->a1ad_angle);
}

// Вовращает высоту грани от A до DD1
// Формула, по которой идет подсчет, написана в ../../adt.md
float Parallelepiped::getFrontSecondHeight() const {
	return this->bc_line * sin(convert_to_rad_k * (180 - this->a1ad_angle));
}

// Возвращает высоту грани от A1 до AB
// Формула, по которой идет подсчет, написана в ../../adt.md
float Parallelepiped::getSideFirstHeight() const {
	return this->side_line * sin(convert_to_rad_k * this->a1ab_angle);
}

// Возвращает высоту грани от A1 до BB1
// Формула, по которой идет подсчет, написана в ../../adt.md
float Parallelepiped::getSideSecondHeight() const {
	return this->ab_line * sin(convert_to_rad_k * (180 - this->a1ab_angle));
}

// Возвращает высоту параллелепипеда
float Parallelepiped::getMainHeight() const {
	return this->side_line * sin(convert_to_rad_k * getSideAndBaseDiagonalAngle());
}


// Возвращает площадь лицевой грани
float Parallelepiped::getFrontSquare() const {
	return getFrontFirstHeight() * this->bc_line;
}

// Возвращает площадь боковой грани
float Parallelepiped::getSideSquare() const {
	return getSideFirstHeight() * this->ab_line;
}

// Возвращает площадь основания
float Parallelepiped::getBaseSquare() const {
	return getBaseFirstHeight() * this->bc_line;
}

// Возвращает площадь боковых граней
float Parallelepiped::getFrontsAndSidesSquare() const {
	return 2 * getFrontSquare() + 2 * getSideSquare();
}

// Возвращает площадь поверхности
float Parallelepiped::getFullSquare() const {
	return 2 * (getBaseFirstHeight() * this->bc_line) + getSideSquare();
}


// Возвращает объем
float Parallelepiped::getVolume() const {
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

// Здесь тело самой программы
int main() {
	// Генерация случайных чисел
	srand(time(NULL));

	// Для удобной отладки разбил все действия на этапы
	stepInitializing();
	stepCheckSets();
	stepCheckType();
	stepCheckHeights();
	stepCheckDiagonals();
	stepCheckSV();

	// Динамическая инициализация параллелепипеда
	Parallelepiped *dinamic_object = new Parallelepiped;
	cout << "dinamic " << dinamic_object->getType() << endl;

	// Создадим массив из объектов, где все стороны случайны
	Parallelepiped paral_mass[3];   // Память инициализирована
	for (int i = 0; i <= 2; i++) {  // Случайно зададим им значения боковых сторон
		paral_mass[i].setLineSide(rand() + 1);
	}
	cout << "First side's element of massive " << paral_mass[0].getLineSide() << endl;
	cout << "Second side's element of massive " << paral_mass[1].getLineSide() << endl;
	cout << "Third side's element of massive " << paral_mass[2].getLineSide() << endl;
	makeCout();

	// Создадим массив из указателей
	Parallelepiped *parallelepipeds[3];  // Память не инициализирована
	for (int i = 0; i <= 2; i++) {       // Поэтому инициализируем ее вручную
		parallelepipeds[i] = new Parallelepiped;
	}
	parallelepipeds[1]->setLineAB(20);
	cout << "element of point's massive " << parallelepipeds[1]->getLineAB() << endl;
	makeCout();
	
	// Запись в бинарный файл
	Parallelepiped paral_for_fin = getStartParallelepiped();
	ofstream fin("bin.txt", ios::out | ios::binary);
	if (fin.is_open()) {
		// Объявляем и инициализируем объект с некоторыми параметрами
		
		// Объявим переменные для записи значений полей класса
		float ab = paral_for_fin.getLineAB();
		float bc = paral_for_fin.getLineBC();
		float side = paral_for_fin.getLineSide();

		float bad = paral_for_fin.getAngleBAD();
		float a1ad = paral_for_fin.getAngleA1AD();
		float a1ab = paral_for_fin.getAngleA1AB();

		// Запишем в файл
		fin.write(reinterpret_cast<const char*> (&ab), sizeof(ab));
		fin.write(reinterpret_cast<const char*> (&bc), sizeof(bc));
		fin.write(reinterpret_cast<const char*> (&side), sizeof(side));

		fin.write(reinterpret_cast<const char*> (&bad), sizeof(bad));
		fin.write(reinterpret_cast<const char*> (&a1ad), sizeof(a1ad));
		fin.write(reinterpret_cast<const char*> (&a1ab), sizeof(a1ab));
	}
	fin.close();

	// Чтение из бинарного файла
	Parallelepiped paral_for_fout;
	ifstream fout("bin.txt", ios::in | ios::binary);
	if (fout.is_open()) {
		// Чтение из файла и запись в объект
		float var;
		fout.read(reinterpret_cast<char*> (&var), sizeof(var));
		paral_for_fout.setLineAB(var);
		fout.read(reinterpret_cast<char*> (&var), sizeof(var));
		paral_for_fout.setLineBC(var);
		fout.read(reinterpret_cast<char*> (&var), sizeof(var));
		paral_for_fout.setLineSide(var);

		fout.read(reinterpret_cast<char*> (&var), sizeof(var));
		paral_for_fout.setAngleBAD(var);
		fout.read(reinterpret_cast<char*> (&var), sizeof(var));
		paral_for_fout.setAngleA1AD(var);
		fout.read(reinterpret_cast<char*> (&var), sizeof(var));
		paral_for_fout.setAngleA1AB(var);
	}
	fout.close();

	// Проверка результата
	// Должно быть 5, согласно функции getStartParallelepiped()
	cout << paral_for_fout.getLineSide() << endl;
	cout << paral_for_fin.getLineSide() << endl;
}
