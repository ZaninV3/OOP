# Список готовых конспектов
- [x] Значения аргументов функций по умолчанию
- [ ] Ключевое слово `static`
- [ ] Отчёт по __Git__
- [x] Этапы компиляции программы на __C++__
- [x] Синонимы типов с помощью `using` и `typedef`
- [ ] Компиляция в командной строке
- [ ] Умные указатели. `unique_ptr`, функция `make_unique`
- [x] Совместный цикл
# Значения агрументов функций по умолчанию
__Аргумент по умолчанию__ – это такой аргумент функции, который программист __может не указывать при вызове__ функции. Аргумент по умолчанию добавляется компилятором автоматически.

Например, ниже объявляется функция `f()`, имеющая аргументом целую переменную, значением которой по умолчанию является величина `1`:
```
void foo(int i = 1) {
  // Тело функции
}
```
Теперь функция `foo()` может вызываться двумя способами, как показано ниже:
```
foo(10);  // явная передача значения
foo();  // функция использует значение по умолчанию
```
В первом случае аргументу `i` будет присвоено значение `10`. Во втором случае `i` получит значение по умолчанию, равное `1`.
__При использовании__ аргументов по умолчанию __обратите внимание__ на следующие моменты:
* Аргументы по умолчанию используются только в вызовах функции, в которых опущены заключительные __аргументы__ - они __должны быть__ последними аргументами. Поэтому следующий код недопустим:
  ```
  int print( double dvalue = 0.0, int prec );
  ```
* __Переопределение__ аргумента по умолчанию в последующих объявлениях __не допускается__, даже если переопределение совпадает с оригиналом. Поэтому приведенный ниже код вызывает ошибку:
  ```
    // Prototype for print function.
  int print( double dvalue, int prec = 2 );
  
  // ...
  
  // Definition for print function.
  int print( double dvalue, int prec = 2 ) {
  // ...
  }
  ```
* __В последующих определениях допускается__ добавлять дополнительные аргументы по умолчанию.
* Аргументы по умолчанию могут указываться для указателей на функции.
* Помимо функций аргументы по умолчанию также допускается использовать в конструкторах и методах класса. Пример:
  ```
  // класс, который описывает круг
  class Circle {
    // внутренние переменные класса
    double x, y, radius;
    
    public:
      // конструктор, который принимает аргументы по умолчанию
      Circle(double nx=10, double ny = 10, double nradius = 1) {
        x = nx;
        y = ny;
        radius = nradius;
      }
      
      // Методы доступа
      // чтение значений x, y, r
      double GetX(void) { return x; }
      double GetY(void) { return y; }
      double GetR(void) { return radius; }
      
      // метод, который содержит аргументы по умолчанию
      void SetXYR(double nx=0, double ny=0, double nradius=1) {
        x = nx;
        y = ny;
        radius = nradius;
      }
  };
  ```
Во время __объявления__ функции, аргументы по умолчанию __задаются только один раз__. Здесь возможны два случая. Первый, если функция имеет __прототип и реализацию__. Второй случай, если функция не имеет прототипа, а имеет __только реализацию__.
Пример:
```
// объявление аргументов по умолчанию в прототипе функции
double GetAreaCircle(double r = 1);

// функция не имеет прототипа, поэтому аргумент по умолчанию задается непосредственно в реализации
double GetVolumeSphere(double r = 1){
  return 4.0/3 * Pi*r*r*r;
}

// реализация функции - аргументы по умолчанию уже заданы в прототипе
double GetAreaCircle(double r) {
  return Pi * r * r;
}
```
__Преимущества__ использования аргументов по умолчанию:
* __Сокращается листинг__ программного кода за счет избегания написания лишних функций, которые выполняют ту же работу только с другими значениями аргументов;
* Обеспечивается __простой, естественный и эффективный стиль__ программирования;
* В некоторых случаях аргументы по умолчанию есть сокращенной формой перегрузки функции. Это, в свою очередь улучшает читабельность программного кода и __упрощает вызов__ функции.

Источники:
* https://www.bestprog.net/ru/2018/07/30/functions-arguments-by-default-in-functions_ru/
* https://www.c-cpp.ru/books/znacheniya-argumentov-funkcii-po-umolchaniyu
* https://learn.microsoft.com/ru-ru/cpp/cpp/default-arguments?view=msvc-170

# Ключевое слово `static`
`static` — это ключевое слово в __C++__, используемое для __придания__ элементу __особых характеристик__. Для статических элементов __выделение__ памяти происходит __только один__ раз и существуют эти элементы __до завершения__ программы. Хранятся все эти элементы не в `heap` и не на `stack`, а в __специальных сегментах__ памяти, которые называются `.data` и `.bss` (зависит от того инициализированы статические данные или нет). На картинке ниже показан типичный макет программной памяти:

<p align="center">
  <img src="https://github.com/ZaninV3/OOP/blob/main/pictures/programs_memory.png">
</p>

## Статические переменные внутри функции

__Статические переменные__ при использовании внутри функции __инициализируются__ только __один__ раз, а затем они сохраняют свое значение. Эти статические переменные __хранятся__ в __статической__ области памяти (`.data` или `.bss`), а не в стеке, что -__позволяет хранить__ и __использовать__ значение переменной на протяжении __всей жизни__ программы. Давайте рассмотрим две почти одинаковые программы и их поведение.

Первая программа:
```
#include <iostream>

void counter() {
  static int count = 0;  // строка 3
  std::cout << count++;
}

int main() {
  for (int i = 0; i < 10; ++i) {
    counter();
  }
}
```
Вторая программа:
```
#include <iostream>

void counter() {
  int count = 0;  // строка 3
  std::cout << count++;
}

int main() {
  for (int i = 0; i < 10; ++i) {
    counter();
  }
}
```
По итогу обе __программы__ выведут __разный__ результат: `0123456789` для первой и `0000000000` для второй. Если __не использовать__ `static` в строке `3`, выделение памяти и __инициализация__ переменной `count` происходит __при каждом вызове__ функции `counter()`, и __уничтожается каждый раз__, когда функция завершается. Но если мы __сделаем__ переменную __статической__, после инициализации (при первом вызове функции `counter()`) __область видимости__ `count` будет до __конца функции__ `main()`, и переменная будет __хранить__ свое значение __между вызовами__ функции `counter()`.

## Статические объекты класса

Второе использование `static` — __внутри__ определения __класса__. Хотя __большинство__ переменных, объявленных внутри класса, могут иметь __разное значение__ в __каждом экземпляре__ класса, __статические__ поля класса будут иметь __то же значение для всех__ экземпляров данного класса и даже __не обязательно создавать__ экземпляр этого класса. Полезно представить себе, что статические переменные класса содержат информацию, необходимую для создания новых объектов. Например, если вы хотите __пронумеровать экземпляры__ класса, можно использовать статическую переменную __для отслеживания последнего__ используемого номера.

Пусть есть класс Base имеющий только конструктор и деструктор. В качестве примера будем работать с `void foo()`.
```
#include <iostream>

class Base {
  public:
    Base() {
      std::cout << "Constructor" << std::endl;
    }

    ~Base() {
      std::cout << "Destructor" << std::endl;
    }
};

void foo();  // Объявление функции

int main() {
  foo();
  std::cout << "End of main()" << std::endl;
}
```
Реализация функции `foo()` в первом случае:
```
void foo() {
  Base obj;
}
```
Во втором случае:
```
void foo() {
  static Base obj;
}
```
В первом случае программа выведет:
```
Constructor
Destructor
End of main()
```
Во втором:
```
Constructor
End of main()
Destructor
```
Из-за того, что объект __статический__, деструктор __вызывается__ не при выходе из функции `foo()`, а только __при завершении__ программы, т.к. статический объект __разрушается при завершении__ программы. Если мы уберем `static` при создании переменной в функции `foo()`, то разрушение объекта будет происходить в конце каждого вызова функции.

__Важно__ отметить, что хорошим тоном при использовании статических переменных класса является __использование__ `class_name::х`, а не `instance_of_class.x`. Это __помогает напомнить__ программисту, что статические переменные __не принадлежат к одному__ экземпляру класса, и что вам __не обязательно создавать__ экземпляр этого класса. Как вы уже, наверное, заметили, для доступа к `static` можно использовать оператор области видимости, `::`, когда вы обращаетесь к нему через имя класса.

## Статические функции

Статические функции пришли в __С++__ из __С__. По умолчанию все функции в __С__ глобальные и, если вы __захотите создать__ две функции с __одинаковым именем__ в двух разных `.c`(`.cpp`) файлах одного проекта, то получите __ошибку__ о том, что данная функция __уже определена__ (`fatal error LNK1169: one or more multiply defined symbols found`). Для того чтобы исправить данную проблему, одну из функций необходимо __объявлять статической__. Вы говорите компилятору, что доступ к статическим функциям __ограничен файлом__, в котором они объявлены. Таким образом, используя `static` для функции, мы можем ограничить область видимости этой функции, и данная функция не будет видна в других файлах, если, конечно, это не заголовочный файл (`.h`).

## Статические функции-члены класса (методы)

Статическую функцию-член вы можете использовать без создания объекта класса. Доступ к статическим функциям осуществляется с использованием имени класса и оператора разрешения области видимости (`::`). При использовании статической функции-члена есть ограничения, такие как:
1.	Внутри функции обращаться можно только к статическим членам данных, другим статическим функциям-членам и любым другим функциям извне класса.
2.	Статические функции-члены имеют область видимости класса, в котором они находятся.
3.	Вы не имеете доступа к указателю `this` класса, потому что мы не создаем никакого объекта для вызова этой функции.

Источники:
* https://habr.com/ru/articles/527044/
* http://cppstudio.com/post/3298/

# Отчёт по Git

Во время разработки требуется хранить как минимум 2 версии исходного кода программы: версию находящийся в активной разработке и последнюю гарантировано рабочую версию.

Копия программы нужна чтобы __продемонстрировать__ заказчику или чтобы вернуться к ней, если с текущей версией случится что-нибудь __плохое__.

Решить эту проблемы, автоматизировать рутинные операции призвана __система управления версиями__.

__Система управления версиями__ (Version Control System, VCS) – программное обеспечение для облегчения работы с изменяющейся информацией.

`Git` - один из видов __VCS__.

В целом VCS можно разделить таким образом:
* __Локальные__ - все файлы хранятся только __в вашей ОС__, например, разложены по папкам с версиями.
* __Централизованные__ - проект хранится __на сервере__, а ваша рабочая версия включает только текущий набор файлов.
* __Распределенные__ - копии проекта (и вся информация о версиях) располагаются __не только на сервере__, __но и на__ нескольких __клиентских машинах__, чтобы обеспечить устойчивость к отказу сервера.

__Репозиторием__ называют хранилище вашего кода и историю его изменений. `Git` работает __локально__ и все ваши репозитории хранятся в определенных папках на жестком диске.

__Коммит__ - это способ __сохранения изменений в коде__. Каждый `commit` содержит информацию о том, __что было изменено__ в коде __и кем__ были внесены эти изменения. Они позволяют разработчикам отслеживать изменения в своем (или чужом) коде и возвращаться к предыдущим версиям, если это необходимо.

__Ветка__ - это __набор__ `commit`, которые идут __друг за другом__. У ветки __есть название__, основную ветку чаще всего называют `master`. Если говорить простыми словами, то ветка `master` — это наш проект.

## Навигация через Git Bash

* `clear` — Очистить консоль
* `pwd` — Показать текущий каталог
* `ls` - Показать файлы в данной папке, включая и скрытые
* `ls -f` — Показать файлы в данной папке, кроме скрытых
* `cd c:/` — Перейти в конкретный каталог
* `cd` - — Вернуться назад
* `cd ..` — Выйти на 1 уровень вверх
* `cd ../..` — Выйти на 2 уровня вверх
* `mkdir` — Создать папку
* `cd !$` — Перейти в только что созданную папку
* `mkdir -p {app1,app2}` — Создать сразу несколько папок
* `mkdir -p app/{css,js}` — Создать сразу несколько вложенных папок
* `touch index.html — Создать файл index.html`
* `touch app/{css/main.css,js/main.js,index.html}` — Создать сразу несколько файлов, никаких лишних пробелов быть не должно
* `touch` — позволяет создавать файлы
* `rm test` — Удалить пустую папку `test`
* `rm -r test` — Удалить папку `test` с файлами внутри неё
* `mv app1/*.* app2` — Переместить все файлы из папки `app1` в папку `app2`

## Работа с репозиторием

* `git init` – создание репозитория в текущей директории
* `git status` – проверка статуса директории (если репозитория нет, то будет выведено сообщение)
* `git add <название_файла>` – добавление файла в отслеживаемые (Для того, чтобы добавить все файлы сразу то в место файла нужно поставить точку или `--all`. Просмотреть можно через `git status`)
* `git clone <cсылка> <новое_название>` - клонирование существующего репозитория
* `get fetch <названия репозитория>` - копирование изменений удаленного репозитория
* `git commit -m “описание”` – создание коммита
* `git ls-files` – просмотр отслеживаемых файлов
* `git log` – просмотр всех коммитов
* `git diff` – показывает разницу между текущим состоянием файлов и предыдущим коммитом
* `git diff <исходная_ветка> <целевая_ветка>` - показывает разницу между двух веток
* `git branch <название_ветки>` – создание новой ветки (если не указывать название ветки, то будет отображен список всех веток)
* `git branch -d <название_ветки>` - удаление ветки
* `git checkout <название_ветки>` – переключение между ветками
* `git pull origin master` – обновление локальной ветки `master`
* `git merge <название_ветки>` - слияние ветки
* `git push origin master` – отправка изменений ветки `master` на удаленный репозиторий (нужно обязательно находиться на этой ветке)
* `git clone <адрес_репозитория>` - клонирование существующего репозитория через ссылку
* `git help` - справочник

Источники:
* https://github.com/VetrovSV/Programming/blob/master/git_lec.pdf
* https://habr.com/ru/articles/541258/
* https://selectel.ru/blog/tutorials/git-setup-and-common-commands/
* https://git-scm.com/book/ru/v2/%D0%9E%D1%81%D0%BD%D0%BE%D0%B2%D1%8B-Git-%D0%A1%D0%BE%D0%B7%D0%B4%D0%B0%D0%BD%D0%B8%D0%B5-Git-%D1%80%D0%B5%D0%BF%D0%BE%D0%B7%D0%B8%D1%82%D0%BE%D1%80%D0%B8%D1%8F
* https://gist.github.com/sasstr/03d819bd98272ae261dd29ef731e9a6f
* https://www.learnqa.ru/tpost/z1k65h4um1-chto-takoe-commit-v-git
* https://habr.com/ru/articles/542616/
* https://docs.github.com/ru/get-started/using-git/getting-changes-from-a-remote-repository

# Этапы компиляции программы на C++

<p align="center">
  <img src="https://github.com/ZaninV3/OOP/blob/main/pictures/compilation_c++.png">
</p>

В качестве примера рассмотрим следующую программу:
```
// driver.cpp
#include <iostream>
using namespace std;
#define RETURN return 0

int main() {
  // printing “Hello, world!” to console
  cout << "Hello, world!" << endl;
  RETURN;
}
```

## Перпроцессоринг

__Препроцессор__ — это __макропроцессор__, который преобразовывает вашу программу для дальнейшего компилирования. На данной стадии происходит __работа с препроцессорными директивами__. Например, __препроцессор__ добавляет хэдеры в код (`#include`), __убирает__ комментирования, __заменяет__ макросы (`#define`) их значениями, выбирает нужные куски кода в соответствии с условиями `#if`, `#ifdef`, `#elif`, `#else`, `#endif`.

Получим __препроцессированный код__ в выходной __файл__ `driver.ii` (прошедшие через стадию препроцессинга __C++__ файлы имеют расширение `.ii`), используя флаг `-E`, который сообщает компилятору, что компилировать (об этом далее) файл не нужно, а только провести его препроцессинг:
```
g++ -E driver.cpp -o driver.ii
```
__На выходе__ препроцессора получаются так называемые __компиляционные листы__, состоящие исключительно из __выражений__ языка __C++__, которых должно быть достаточно для создания объектных файлов на следующих этапах обработки. Последнее означает, что на момент использования каких-либо символов языка из других файлов, __объявления этих символов должны присутствовать__ в компиляционном листе выше. Именно такие подстановки и призван осуществлять препроцессор. Часто, на вход препроцессора поступает файл размером в несколько десятков строк, а на выходе получается компиляционный лист из десятков тысяч строк.

Если рассмотреть нашу функцию `main()` после препроцессинга, то макрос `RETURN` был заменен: 
```
int main() {
  cout << "Hello, world!" << endl;
  return 0;
}
```

## Компилирование

На данном шаге __g++__ выполняет свою главную задачу — __компилирует__, то есть преобразует полученный на прошлом шаге код без директив в __ассемблерный код__. Это промежуточный шаг между высокоуровневым языком и машинным (бинарным) кодом.

__Ассемблерный код__ — это доступное для понимания человеком представление машинного кода.

Используя __флаг__ `-S`, который сообщает компилятору остановиться после стадии компиляции, получим ассемблерный код в выходном файле `driver.s`:
```
$ g++ -S driver.ii -o driver.s
```

## Ассемблирование
В данном случае, мы имеем __компилятор__ с __языка ассемблера__. Результатом его работы является __объектный файл__ полученный на основе всего того текста, что был предоставлен в __компиляционном листе__. Поэтому можно говорить, что каждый объектный файл проекта соответствует одному __компиляционному листу__ проекта.

__Объектный файл__ — это созданный ассемблером промежуточный файл, __хранящий кусок машинного кода__. Этот кусок машинного кода, который еще не был связан вместе с другими кусками машинного кода в конечную выполняемую программу, называется объектным кодом.

Получим машинный код с помощью ассемблера (`as`) в выходной объектный файл `driver.o`:
```
$ as driver.s -o driver.o
```
Ассемблирование __не является обязательным__ процессом обработки файлов на языке __C++__. В данном случае, мы наблюдаем лишь общий подход в архитектуре проекта коллекции компиляторов __GNU__. Чтобы максимально объединить разные языки в одну коллекцию, __для каждого__ из языков реализуется __свой транслятор__ на язык ассемблера и, при необходимости, препроцессор, а компилятор с языка ассемблера и линковщик делаются общими для всех языков коллекции.

## Линковка
Также называется __связывание__, __сборка__ или __линковка__.

На этапе линковки выполняется __объединение всех__ объектных __файлов__ проекта, откомпилированных по соответствующим компиляционным листам проекта в __единую сущность__ (исполняемый файл). Это может быть приложение, статическая или динамическая библиотека. Разница в бинарных заголовках целевых файлов и несколько различной внутренней организацией. Первичной задачей линковки следует назвать задачу по __подстановке адресов вызова__ внешних __объектов__, которые были образованы в объектных файлах проекта. Соответствующие __реализации сущностей с адресами__ их размещения должны __находится в видимости__ линковщика. Эти сущности должны быть __либо в объектных файлах__, тогда они __должны быть указаны в списке__ линковки, либо __во внешних библиотеках__ функций, статических или динамических, тогда они должны быть указаны __в списке внешних библиотек__.

Источники:
* https://habr.com/ru/articles/478124/
* https://ejudge.179.ru/tasks/cpp/total/105.html
* https://knzsoft.ru/cpp-bgr-ls1/
* https://cpp-kt.github.io/cpp-notes/05_compilation.html


# Синонимы типов с помощью using и typedef

__Объявление псевдонима__ можно использовать для __объявления имени__, используемого в качестве синонима для ранее объявленного типа. (Этот механизм также неофициально называется __псевдонимом типа__). Этот механизм также можно использовать для создания __шаблона псевдонима__, который может быть полезен для __пользовательских распределителей__.

__Псевдоним не вводит новый тип__ и не может изменить __значение существующего имени__ типа.
```
using identifier = type;
```
где:
```
identifier // Имя псевдонима
type // Идентификатор типа, для который создается псевдоним
```
Простейшая __форма__ псевдонима __эквивалентна__ механизму `typedef` из __C++03__:
```
// C++11
using counter = long;

// C++03 equivalent:
// typedef long counter;
```
Главное __отличие__ `using` перед `typedef` - при __работе с шаблонами__. __Объявление__ псевдонимов могут быть __шаблонизированы__, в то время как `typedef` – __нет__ (__можно__, но для этого __придется использовать__ `struct`). Также `typedef` отличается от `using` том, что второе __позволяет избавится__ от наследия из __C__ с рядом некоторых __добавок__.
```
template<typename T> using ptr = T*;

// the name 'ptr<T>' is now an alias for pointer to T
ptr<int> ptr_int;
```
__Объявление__ `typedef` __вводит имя__, которое __в пределах__ своей области становится __синонимом__ типа, __заданного частью__ объявления типа.

Источники:
* https://learn.microsoft.com/ru-ru/cpp/cpp/aliases-and-typedefs-cpp?view=msvc-170
* https://ru.stackoverflow.com/questions/499481/%D0%9E%D1%82%D0%BB%D0%B8%D1%87%D0%B8%D0%B5-using-%D0%BE%D1%82-typedef

# Умные указатели. unique_ptr, функция make_unique

Стандартная библиотека __C++__ включает смарт-указатели, которые используются для обеспечения того, чтобы программы были свободны от утечки памяти (неконтролируемое уменьшение свободной оперативной или виртуальной памяти компьютера) и ресурсов и являются исключениями.

В отличие от управляемых языков, __C++__ не имеет автоматической сборки мусора, внутренний процесс, который освобождает кучи памяти и другие ресурсы в процессе выполнения программы. Программа __C++__ отвечает за возврат всех приобретенных ресурсов в операционную систему. Неиспользуемый ресурс называется утечкой. Утечка ресурсов недоступна другим программам до тех пор, пока процесс не завершится. Утечки памяти, в частности, являются распространенными причинами ошибок в программировании в стиле __C__.

В следующем примере сравниваются объявления необработанного и интеллектуального указателей:
```
void UseRawPointer() {
    // Using a raw pointer -- not recommended.
    Song* pSong = new Song(L"Nothing on You", L"Bruno Mars"); 

    // Use pSong...

    // Don't forget to delete!
    delete pSong;   
}

void UseSmartPointer() {
    // Declare a smart pointer on stack and pass it the raw pointer.
    unique_ptr<Song> song2(new Song(L"Nothing on You", L"Bruno Mars"));

    // Use song2...
    wstring s = song2->duration_;
    //...

} // song2 is deleted automatically here.
```
Как показано в примере, интеллектуальный указатель — это шаблон класса, который объявляется в стеке и инициализируется с помощью необработанного указателя, указывающего на размещенный в куче объект. После инициализации интеллектуальный указатель становится владельцем необработанного указателя. Это означает, что интеллектуальный указатель отвечает за удаление памяти, заданной необработанным указателем. Деструктор интеллектуального указателя содержит вызов для удаления, и поскольку интеллектуальный указатель объявлен в стеке, его деструктор вызывается, как только интеллектуальный указатель оказывается вне области, даже если исключение создается где-либо в другой части стека.

Интеллектуальные указатели определяются в `std` пространстве имен в файле заголовка `<memory>`.

Указатель `unique_ptr<T>` представляет указатель на тип `T`, который является "уникальным" в том смысле, что что может быть только один объект `unique_ptr`, который содержит один и тот же адрес. То есть не может одновременно быть двух или более объектов `unique_ptr<T>`, которые указывают один и тот же адрес памяти. Если же мы попробуем определить два одновременно существующих указателя, которые указывают на один и тот же адрес, компилятор не скопирует код.

И когда `unique_ptr` уничтожается, уничтожается и значение, на которое он указывает. Соответственно данный тип указателей полезен, когда нужен указатель на объект, на который НЕ будет других указателей и который будет удален после удаления указателя.

По умолчанию `unique_ptr<T>` инициализируется значением `nullptr`.
```
std::unique_ptr<int> ptr; // ptr = nullptr
// аналогично
std::unique_ptr<int> ptr{};
std::unique_ptr<int> ptr{nullptr};
```
Чтобы выделить память и создать в ней объект, на который будет указывать указатель, применяется функция `std::make_unique<T>`. В качестве параметра в нее передается объект, на который будет указывать указатель:
```
std::unique_ptr<int> ptr { std::make_unique<int>(125) };
```
Стоит отметить, что до принятия стандарта `C++14` применялась другая форма создания указателя:
```
std::unique_ptr<int> ptr { new int(125) };
```
Для получения стандартного указателя из `std::unique_ptr` применяется функция `get()`:
```
std::unique_ptr<int> ptr { std::make_unique<int>(125) };
int* pointer = ptr.get();
```
Стоит отметить, что начиная со стандарта `C++20` получить адрес из smart-указателя мы можем напрямую без функции `get`.

После определения интеллектуального указателя мы можем получать и изменять значение, на которое он указывает, так же, как и при работе с обычными указателями:
```
// указатель ptr указывает на объект 125
std::unique_ptr<int> ptr { std::make_unique<int>(125) };
std::cout << "Address: " << ptr.get() << std::endl;   // получим адрес объекта
std::cout << "Initial value: " << *ptr << std::endl;  // получим значение объекта
// изменяем значение
*ptr = 254;
std::cout << "New value: " << *ptr << std::endl;      // получим значение объекта
```
Если потребуется освободить память, на которую указывает указатель, то можно применить функцию `reset()`.

Источники:
* https://learn.microsoft.com/ru-ru/cpp/cpp/smart-pointers-modern-cpp?view=msvc-170
* https://learn.microsoft.com/ru-ru/cpp/standard-library/memory?view=msvc-170
* https://metanit.com/cpp/tutorial/11.1.php

# Совместный цикл

Цикл, задающий выполнение некоторой операции для объектов из заданного множества, без явного указания порядка перечисления этих объектов. Такие циклы называются совместными (а также циклами по коллекции, циклами просмотра) и представляют собой формальную запись инструкции вида: «Выполнить операцию __X__ для всех элементов, входящих во множество __M__».

Для __C++__ особая форма цикла `for`, которая предназначена специально для работы с последовательностями значений. Эта форма имеет следующее формальное определение:
```
//поддерживается, начиная со стандарта C++11
for(тип переменная : последовательность) {
  инструкции;
}
```
Например:
```
#include <iostream>

int main() {
  for (int n : {2, 3, 4, 5}) {
    std::cout << n << std::endl;
  }
}
```
Здесь выражение `{2, 3, 4, 5}` как раз представляет последовательность значений - чисел `int`. Цикл перебирает всю эту последовательность и помещает каждое значение в переменную `n`, значение которой выводится на консоль.

Другой пример. Строка фактически представляет собой последовательность символов, которую также можно перебрать с помощью данного вида циклов:
```
#include <iostream>
  
int main() {   
  for (char c : "Hello") {
    std::cout << c << std::endl;
  }
}
```
Давайте возьмем пример вектора целых чисел, чтобы увидеть, как цикл for-each можно использовать для перебора его элементов:
```
std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

for (int elem : vec) {
  std::cout << elem << " ";
}
```
В приведенном выше примере мы объявляем вектор целых чисел vec и присваиваем ему некоторые значения. Затем мы используем цикл for-each для перебора каждого элемента вектора и вывода его на консоль. Вывод приведенного выше кода будет:
```
3 1 4 1 5 9 2 6 5 3 5 
```
Менять значения элементов возможно (Обратите внимание, что мы используем ссылку на элемент вместо копии, чтобы модификация выполнялась на месте):
```
// Modify all elements of the array
for (int& x : arr) {
  x *= 2;
}
```
Как и любая программная конструкция, цикл for-each также имеет свои ограничения. Одним из самых больших ограничений цикла for-each в C++ является то, что его можно использовать только с контейнерами, предоставляющими итераторы. Это означает, что циклы for-each нельзя использовать с массивами, которые являются важной структурой данных в C++. Более того, циклы for-each не обеспечивают доступ к индексу текущего элемента. Это означает, что если вам нужно получить доступ к индексу текущего элемента, вам придется использовать вместо этого традиционный цикл. Кроме того, цикл for-each нельзя использовать для изменения контейнера во время его обхода. Если вам нужно изменить контейнер, вместо этого вам придется использовать традиционный цикл.

Источники:
* https://metanit.com/cpp/tutorial/2.13.php
* https://ru.wikipedia.org/wiki/%D0%A6%D0%B8%D0%BA%D0%BB_(%D0%BF%D1%80%D0%BE%D0%B3%D1%80%D0%B0%D0%BC%D0%BC%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5)#:~:text=%D0%A1%D0%BE%D0%B2%D0%BC%D0%B5%D1%81%D1%82%D0%BD%D1%8B%D0%B9%20%D1%86%D0%B8%D0%BA%D0%BB,-%D0%95%D1%89%D1%91%20%D0%BE%D0%B4%D0%BD%D0%B8%D0%BC%20%D0%B2%D0%B0%D1%80%D0%B8%D0%B0%D0%BD%D1%82%D0%BE%D0%BC&text=%D0%A2%D0%B0%D0%BA%D0%B8%D0%B5%20%D1%86%D0%B8%D0%BA%D0%BB%D1%8B%20%D0%BD%D0%B0%D0%B7%D1%8B%D0%B2%D0%B0%D1%8E%D1%82%D1%81%D1%8F%20%D1%81%D0%BE%D0%B2%D0%BC%D0%B5%D1%81%D1%82%D0%BD%D1%8B%D0%BC%D0%B8%20(%D0%B0,%2C%20%D0%B2%D1%85%D0%BE%D0%B4%D1%8F%D1%89%D0%B8%D1%85%20%D0%B2%D0%BE%20%D0%BC%D0%BD%D0%BE%D0%B6%D0%B5%D1%81%D1%82%D0%B2%D0%BE%20M%C2%BB
* https://dev.to/emilossola/mastering-the-for-each-loop-in-c-5e8l
