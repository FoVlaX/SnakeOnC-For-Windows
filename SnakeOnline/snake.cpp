#include "snake.h"

int snake::snakeids[10] = { 0 };
int snake::field[30][30] = { 0 };
int snake::currentid = 3;



snake::snake(int x, int y, int size)
{
	id = snake::currentid;
	snake::snakeids[id - 3] = (int)this;
	snake::currentid++;
	if (size < 3 || size > 6)
	{
		MessageBox(0,"Error","Size should be in [3,5]",0);
	}
	body[0].x = x;
	body[0].y = y;

	snake::field[x][y] = id;

	dir = 3;//left 

	body = (Coord*)realloc((void*)body, sizeof(Coord)*size);

	length = size;
	for (int i = 1; i < size; i++)
	{
		body[i].x = x+i;
		body[i].y = y;
		snake::field[body[i].x][body[i].y] = id;
	}

}
void snake::step()
{

}

bool snake::proov()
{
	return true;
}

void snake::setdir(int d)
{
	dir = d;
}

int snake::getdir()
{
	return dir;
}

snake::~snake()
{
	delete[]body;
}


void snake::drawfield()
{
	snake *cs;
	for (int i = 0; i < snake::currentid - 3; i++)
	{
		cs = (snake*)snakeids[i];
		cs->draw();
	}
	cs = NULL;
}


void snake::draw()
{
	for (int i = 0; i < length; i++)
	{
		COORD position;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	// Получение дескриптора устройства стандартного вывода
		position.X = body[i].x;									// Установка координаты X
		position.Y = body[i].y;									// Установка координаты Y
		SetConsoleCursorPosition(hConsole, position);
		printf("#");
	}
}