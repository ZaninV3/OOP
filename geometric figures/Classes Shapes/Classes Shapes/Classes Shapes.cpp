#include "square.h"  // Поключение заголовочного файла с классом Square
#include <iostream>  // Ввод/вывод в консоль

// Точка входа и выхода из программы
int main() {
	Square test_square = Square();
	std::cout << test_square.getSide() << std::endl;
	
	std::cout << "trying to change value..." << test_square.setSide(5.9f) << std::endl;
	std::cout << test_square.getSide() << std::endl;
}
