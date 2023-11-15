// Class Parallelepiped.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "parallelepiped.h"  // Подключаем заголовочный файл с нашим классом
using namespace std;

// Возвращает начальный параллелепипед со значениями
Parallelepiped getStartParallelepiped() {
	// Инициализируем объект с базовыми параметрами
	// Намерено некоторые параметры делаем с ошибкой и один параметр не указываем
	return Parallelepiped(-3, 4, 5, 45, -10);
}

// Инициализация объекта и вывод его начальных значений
void stepInitializing() {
	cout << endl;
	Parallelepiped test_p = getStartParallelepiped();

	// Выводим на экран его значения ребер
	cout << "lines: " << test_p.getLineAB() << " " << test_p.getLineBC() << " " << test_p.getLineSide() << endl;

	// Выводим значения углов
	cout << "angles: " << test_p.getAngleBAD() << " " << test_p.getAngleA1AD() << " " << test_p.getAngleA1AB() << endl;
	cout << endl;
}

// Проверка сеттеров
void stepCheckSets() {
	cout << endl;

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
	
	cout << endl;
}

int main() {
	// Для удобной отладки разбил все действия на этапы
	stepInitializing();
	stepCheckSets();
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
