#include <stdio.h>
#include <Windows.h>
#include "snake.h"
using namespace std;



int main()
{
	snake zm(15, 15, 4); // создание змеи
	snake::drawfield(); //отрисовка пол€
	while (true) {
		snake::CONTROL(); // обработчик нажати€ клавишь и изменени€ направлени€ движени€ подконтрольной змеи;
		snake::stepall(); // шаг всех змей
		Sleep(120); //ожидание
	}
	return 0;
}
