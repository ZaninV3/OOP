#pragma once
#include "parallelepiped.h"  // Подключаем заголовочный файл с нашим классом
// Возвращает начальный параллелепипед со значениями
Parallelepiped getStartParallelepiped() {
	// Инициализируем объект с базовыми параметрами
	// Намерено некоторые параметры делаем с ошибкой и один параметр не указываем
	return Parallelepiped(-3, 4, 5, 45, -10);
}

// Выводим пустую строку для отступов на cout
void makeCout() {
	std::cout << std::endl;
}

// Инициализация объекта и вывод его начальных значений
void stepInitializing() {
	makeCout();
	Parallelepiped test_p = getStartParallelepiped();

	// Выводим на экран его значения ребер
	std::cout << "lines: " << test_p.getLineAB() << " " << test_p.getLineBC() << " " << test_p.getLineSide() << std::endl;

	// Выводим значения углов
	std::cout << "angles: " << test_p.getAngleBAD() << " " << test_p.getAngleA1AD() << " " << test_p.getAngleA1AB() << std::endl;
	makeCout();
}

// Проверка сеттеров
void stepCheckSets() {
	makeCout();

	Parallelepiped test_p = getStartParallelepiped();

	// Пробуем менять значения ребер
	std::cout << "trying to change the value of line AB" << std::endl;

	// Для начала некорректное значение и проверяем первую попытку замены
	bool check = test_p.setLineAB(-200.05);
	std::cout << "result0: " << check << " and the value: " << test_p.getLineAB() << std::endl;

	// А теперь пробуем добавить корректное значение и проверяем вторую попытку замены
	check = test_p.setLineAB(200.05);
	std::cout << "result1: " << check << " and the value: " << test_p.getLineAB() << std::endl;


	// А теперь проверка углов
	std::cout << "\ntrying to change the value of BAD" << std::endl;

	// Аналогично примеру выше с ребром
	check = test_p.setAngleBAD(181);
	std::cout << "result2: " << check << " and the value: " << test_p.getAngleBAD() << std::endl;

	check = test_p.setAngleBAD(90);
	std::cout << "result3: " << check << " and the value: " << test_p.getAngleBAD() << std::endl;

	makeCout();
}

// Проверка определения типа параллелепипеда
void stepCheckType() {
	makeCout();
	// Создаем наклонный параллелепипед и выводим
	std::cout << "creating the object..." << std::endl;
	Parallelepiped test_s = Parallelepiped(3, 4, 5, 65, 32, 78);
	std::cout << "result4: " << test_s.getType() << std::endl;

	// Переделываем в прямой параллелепипед и выводим на экран
	std::cout << "converting to a straight parallelepiped... " << test_s.setAngleA1AD(90) << test_s.setAngleA1AB(90) << std::endl;
	std::cout << "result5: " << test_s.getType() << std::endl;

	// Переделываем в прямоугольный параллелепипед и выводим на экран
	std::cout << "converting to a cuboid... " << test_s.setAngleBAD(90) << std::endl;
	std::cout << "result6: " << test_s.getType() << std::endl;

	// Переделываем в куб и выводим на экран
	std::cout << "converting to a cube... " << test_s.setLineAB(5) << test_s.setLineBC(5) << test_s.setLineSide(5) << std::endl;
	std::cout << "result7: " << test_s.getType() << std::endl;

	// Переделываем в ромбоэдр и выводим на экран
	std::cout << "converting to a rhombohedron... " << test_s.setAngleA1AB(23.4) << std::endl;
	std::cout << "result8: " << test_s.getType() << std::endl;

	makeCout();
}

// Проверка высот
void stepCheckHeights() {
	makeCout();
	// Для начала проверим самую сложную в плане подсчета высоту
	// Поэтопу первым делом сделаем куб
	Parallelepiped test_s = Parallelepiped(4, 4, 4, 90, 90, 90);

	std::cout << "result9: " << test_s.getMainHeight() << " and the line AA1: " << test_s.getLineSide() << std::endl;

	// Пробуем сменить угол
	// По идее мы должны получить прямой угол A1AC
	std::cout << "changing values of angles... " << test_s.setAngleA1AB(89) << test_s.setAngleA1AD(91) << std::endl;
	std::cout << "result10: " << test_s.getMainHeight() << " and the line AA1: " << test_s.getLineSide() << std::endl;

	// Все высоты на гранях находятся +- по одной формуле.
	// Поэтому рассмотрим только 1 грань
	std::cout << "changing the value of line... " << test_s.setLineSide(16) << std::endl;
	std::cout << "changing the value of angle... " << test_s.setAngleA1AD(65) << std::endl;
	std::cout << "result11: " << test_s.getFrontFirstHeight() << std::endl;

	makeCout();
}

// Проверка диагоналей
void stepCheckDiagonals() {
	makeCout();

	// Поскольку формулы диагоналей все +- одинаковые, то проверка будет одна
	Parallelepiped test_s = getStartParallelepiped();
	std::cout << "result12: " << test_s.getFrontFirstDiagonal() << std::endl;

	makeCout();
}

// Проверка площадей и объема
void stepCheckSV() {
	makeCout();

	Parallelepiped test_s = getStartParallelepiped();
	// Задаем начальное значение всех сторон не равное 0
	test_s.setLineAB(3);

	// Методы работают по +- одной формуле, поэтому проверка нескольких методов
	std::cout << "result13: " << test_s.getBaseSquare() << std::endl;
	std::cout << "result14: " << test_s.getFullSquare() << std::endl;
	std::cout << "result13: " << test_s.getVolume() << std::endl;

	makeCout();
}