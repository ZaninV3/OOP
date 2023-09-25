#include "massives_as_vectors.h"
using namespace massive_and_files;


// Выводит на экран линию-разделитель
void printLine() {
    std::cout << "-------------------------" << std::endl;
}

int main() {
    printLine();
    printLine();

    // Создаем экземпляр класса
    Massive <int> mass;
    std::cout << "mass of Massive has been created" << std::endl;
    printLine();

    // Моделируем ситуацию, когда добавляется элемент на место,
    // которого пока не существует
    std::cout << "mass.addElement(666, 17): ";  // для наглядности
    mass.addElement(666, 17);

    // Массив, конечно же, пустой
    mass.printMassive();
    printLine();


    // Пробуем добавить элемент в конец
    // Каких-либо испключительных ситуаций быть не должно
    std::cout << "mass.appendElement(25): ";
    mass.appendElement(25);

    // В массиве теперь есть один элемент, значение которого 25
    mass.printMassive();
    printLine();


    // Для показа работы следующих медотов
    // добавим Еще несколько элементов
    std::cout << "There is a massive has: " << std::endl;
    mass.appendElement(36);
    mass.appendElement(47);
    mass.appendElement(58);
    mass.appendElement(69);
    mass.printMassive();
    printLine();
    // Выведем количество элементов
    std::cout << "The size of massive is " << mass.getSize() << std::endl;
    printLine();

    // А теперь удалим 58 по индексу (его индекс 3)
    std::cout << "mass.removeElement(3): " << std::endl;
    mass.removeElement(3);
    mass.printMassive();
    printLine();

    // Попробуем заменить число 25 на 666
    std::cout << "mass.changeElement(666, 0): " << std::endl;
    mass.changeElement(666, 0);
    mass.printMassive();
    printLine();

    // Добавим между 47 и 69 число -5
    std::cout << "mass.addElement(-5, 3): " << std::endl;
    mass.addElement(-5, 3);
    mass.printMassive();
    printLine();

    // Можно выборочно получить значение элемента по индексу
    std::cout << "mass.getElement(2): " << mass.getElement(2) << std::endl;
    printLine();

    // Пробуем удалить все элементы разом
    std::cout << "mass.clearMassive(): ";
    mass.clearMassive();
    mass.printMassive();
    printLine();

    // Множественный ввод для массива из 7 элементов
    std::cout << "mass.setManyElements(7): " << std::endl;
    mass.setManyElements(7);
    mass.printMassive();
    printLine();



    // Сумма всех элементов массива
    std::cout << "mass.getSum(): " << mass.getSum() << std::endl;

    // Произведение всех элементов массива
    std::cout << "mass.getMultiplication(): ";
    std::cout << mass.getMultiplication() << std::endl;

    // Сумма всех модулей элементов массива
    std::cout << "mass.getSumModule(): " << mass.getSumModule() << std::endl;

    // Произведение всех модулей элементов массива
    std::cout << "mass.getMultiplicationModule(): ";
    std::cout << mass.getMultiplicationModule() << std::endl;

    // Сумма всех квадратов элементов массива
    std::cout << "mass.getSumSquare(): " << mass.getSumSquare() << std::endl;

    // Далее алгоритмы методов перестают поддаваться адекватному именованию
    // Поэтому следующие методы получают названия заданий из задачника
    // https://ivtipm.github.io/Programming/Glava06/index06.htm#z136

    // 136ZH
    std::cout << "mass.getResultOf136zh(): ";
    std::cout << mass.getResultOf136zh() << std::endl;

    // 136Z
    std::cout << "mass.getResultOf136z(): ";
    std::cout << mass.getResultOf136z() << std::endl;

    // 136I
    std::cout << "mass.getResultOf136i(): ";
    std::cout << mass.getResultOf136i() << std::endl;

    // 136K
    std::cout << "mass.getResultOf136k(): ";
    std::cout << mass.getResultOf136k() << std::endl;

    // 136L
    std::cout << "mass.getResultOf136l(): ";
    std::cout << mass.getResultOf136l() << std::endl;

    // 136M
    std::cout << "mass.getResultOf136m(): ";
    std::cout << mass.getResultOf136m() << std::endl;

    // 136N
    std::cout << "mass.getResultOf136n(): ";
    std::cout << mass.getResultOf136n() << std::endl;

    // 136O
    std::cout << "mass.getResultOf136o(): ";
    std::cout << mass.getResultOf136o() << std::endl;
    printLine();

    // Создание файла
    std::cout << "createBinFile(file_bin.txt): ";
    createBinFile("file_bin.txt");

    // Запись в файл mass
    std::cout << "writeBinFile(file_bin.txt, mass): ";
    writeMassiveBinFile("file_bin.txt", mass);

    // Чтение из бинарного файла
    std::cout << "readMassiveBinFile(file_bin.txt): ";
    Massive <int> mass1 = readMassiveBinFile("file_bin.txt");
    mass1.printMassive();

    printLine();
    printLine();
}
