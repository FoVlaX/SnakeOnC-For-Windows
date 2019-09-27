#include <stdio.h>
#include <Windows.h>
#include "snake.h"
using namespace std;



int main()
{
	snake *zm = new snake(15, 15, 4); // создание змеи
	snake::drawfield(); //отрисовка пол€
	while (true) {
		if (!snake::GAME_OVER)
		{
			snake::CONTROL(); // обработчик нажати€ клавишь и изменени€ направлени€ движени€ подконтрольной змеи;
			snake::stepall(); // шаг всех змей
			Sleep(120); //ожидание
		}
		else
		{
			if (GetAsyncKeyState(VK_ESCAPE))
			{
				break;
			}
		}
	}
	zm->destroy();
	return 0;
}
