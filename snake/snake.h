


#pragma once
#include <windows.h>
#include <stdio.h>



struct Coord {
	int x;
	int y;
};

class snake
{
	static int snakeids[10]; //массив с указателями на объекты змей
	static int field[30][30]; // 0 - пусто , 1 - преиятсвие , 2 - корм , >=3 змейки
	static int currentid; //следущий присваиваемый ид
	static int controlid; // ид подконтрольной ид
	static void addeat();
public:
	static bool GAME_OVER;
	static void CONTROL(); // контроль подконтрольной змеи
	static void setdircontrolsnake(int d); // установка направления подконтрольнйо змеи
	static void setcontrolsnakeid(int i); // установка змеи для контроля
	static void drawfield(); // отрисовка поля
	static void stepall(); // выполнить все шаги всех змей
	snake(int x, int y, int size); //конструктор
	void step(); //выполенние перемещения
	void setdir(int d); //установить направление
	int getdir(); // вернуть направление
	void draw(); // отрисовать змею
	~snake(); //деструктор
	bool proov(); // проверка на смертность возмон обудет удалена
	void destroy();
private:
	Coord *body= new Coord; // тело змеи
	int dir = 0; //направление
	int id; //ид змеи
	int length = 1; // длина змеи
};

// 0 - up, 1 - right, 2 - down, 3 -  left;