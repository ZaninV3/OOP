// Class Parallelepiped.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Автор Занин Вячеслав ВМК-21

#include <iostream>
#include "parallelepiped.h"  // Подключаем заголовочный файл с нашим классом
using namespace std;

// Возвращает начальный параллелепипед со значениями
Parallelepiped getStartParallelepiped() {
	// Инициализируем объект с базовыми параметрами
	// Намерено некоторые параметры делаем с ошибкой и один параметр не указываем
	return Parallelepiped(-3, 4, 5, 45, -10);
}

// Выводим пустую строку для отступов на cout
void makeCout() {
	cout << endl;
}

// Инициализация объекта и вывод его начальных значений
void stepInitializing() {
	makeCout();
	Parallelepiped test_p = getStartParallelepiped();

	// Выводим на экран его значения ребер
	cout << "lines: " << test_p.getLineAB() << " " << test_p.getLineBC() << " " << test_p.getLineSide() << endl;

	// Выводим значения углов
	cout << "angles: " << test_p.getAngleBAD() << " " << test_p.getAngleA1AD() << " " << test_p.getAngleA1AB() << endl;
	makeCout();
}

// Проверка сеттеров
void stepCheckSets() {
	makeCout();

	Parallelepiped test_p = getStartParallelepiped();

	// Пробуем менять значения ребер
	cout << "trying to change the value of line AB" << endl;

	// Для начала некорректное значение и проверяем первую попытку замены
	bool check = test_p.setLineAB(-200.05);
	cout << "result0: " << check << " and the value: " << test_p.getLineAB() << endl;

	// А теперь пробуем добавить корректное значение и проверяем вторую попытку замены
	check = test_p.setLineAB(200.05);
	cout << "result1: " << check << " and the value: " << test_p.getLineAB() << endl;


	// А теперь проверка углов
	cout << "\ntrying to change the value of BAD" << endl;

	// Аналогично примеру выше с ребром
	check = test_p.setAngleBAD(181);
	cout << "result2: " << check << " and the value: " << test_p.getAngleBAD() << endl;

	check = test_p.setAngleBAD(90);
	cout << "result3: " << check << " and the value: " << test_p.getAngleBAD() << endl;
	
	makeCout();
}

// Проверка определения типа параллелепипеда
void stepCheckType() {
	makeCout();
	// Создаем наклонный параллелепипед и выводим
	cout << "creating the object..." << endl;
	Parallelepiped test_s = Parallelepiped(3, 4, 5, 65, 32, 78);
	cout << "result4: " << test_s.getType() << endl;

	// Переделываем в прямой параллелепипед и выводим на экран
	cout << "converting to a straight parallelepiped... " << test_s.setAngleA1AD(90) << test_s.setAngleA1AB(90) << endl;
	cout << "result5: " << test_s.getType() << endl;

	// Переделываем в прямоугольный параллелепипед и выводим на экран
	cout << "converting to a cuboid... " << test_s.setAngleBAD(90) << endl;
	cout << "result6: " << test_s.getType() << endl;

	// Переделываем в куб и выводим на экран
	cout << "converting to a cube... " << test_s.setLineAB(5) << test_s.setLineBC(5) << test_s.setLineSide(5) << endl;
	cout << "result7: " << test_s.getType() << endl;

	// Переделываем в ромбоэдр и выводим на экран
	cout << "converting to a rhombohedron... " << test_s.setAngleA1AB(23.4) << endl;
	cout << "result8: " << test_s.getType() << endl;

	makeCout();
}

// Проверка высот
void stepCheckHeights() {
	makeCout();
	// Для начала проверим самую сложную в плане подсчета высоту
	// Поэтопу первым делом сделаем куб
	Parallelepiped test_s = Parallelepiped(4, 4, 4, 90, 90, 90);
	
	cout << "result9: " << test_s.getMainHeight() << " and the line AA1: " << test_s.getLineSide() << endl;
	
	// Пробуем сменить угол
	// По идее мы должны получить прямой угол A1AC
	cout << "changing values of angles... " << test_s.setAngleA1AB(89) << test_s.setAngleA1AD(91) << endl;
	cout << "result10: " << test_s.getMainHeight() << " and the line AA1: " << test_s.getLineSide() << endl;

	// Все высоты на гранях находятся +- по одной формуле.
	// Поэтому рассмотрим только 1 грань
	cout << "changing the value of line... " << test_s.setLineSide(16) << endl;
	cout << "changing the value of angle... " << test_s.setAngleA1AD(65) << endl;
	cout << "result11: " << test_s.getFrontFirstHeight() << endl;

	makeCout();
}

// Проверка диагоналей
void stepCheckDiagonals() {
	makeCout();

	// Поскольку формулы диагоналей все +- одинаковые, то проверка будет одна
	Parallelepiped test_s = getStartParallelepiped();
	cout << "result12: " << test_s.getFrontFirstDiagonal() << endl;

	makeCout();
}

// Проверка площадей и объема
void stepCheckSV() {
	makeCout();

	Parallelepiped test_s = getStartParallelepiped();
	// Задаем начальное значение всех сторон не равное 0
	test_s.setLineAB(3);

	// Методы работают по +- одной формуле, поэтому проверка нескольких методов
	cout << "result13: " << test_s.getBaseSquare() << endl;
	cout << "result14: " << test_s.getFullSquare() << endl;
	cout << "result13: " << test_s.getVolume() << endl;

	makeCout();
}

int main() {
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

	// Создадим массив из указателей
	Parallelepiped *parallelepipeds[3];
	for (int i = 0; i <= 2; i++) {
		parallelepipeds[i] = new Parallelepiped;
	}

	parallelepipeds[1]->setLineAB(20);
	cout << "element of point's massive " << parallelepipeds[1]->getLineAB() << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
