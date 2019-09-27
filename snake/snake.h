


#pragma once
#include <windows.h>
#include <stdio.h>


struct Coord {
	int x;
	int y;
};

class snake
{
	static int snakeids[10];
	static int field[30][30]; // 0 - пусто , 1 - преиятсвие , 2 - корм , >=3 змейки
	static int currentid;
	static int controlid;
public:
	static void setdircontrolsnake(int d);
	static void setcontrolsnakeid(int i);
	static void drawfield();
	static void stepall();
	snake(int x, int y, int size);
	void step();
	void setdir(int d);
	int getdir();
	void draw();
	~snake();
	bool proov();
	
private:
	Coord *body= new Coord;
	int dir = 0;
	int id;
	int length = 1;
};

// 0 - up, 1 - right, 2 - down, 3 -  left;