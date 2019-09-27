#include "snake.h"

int snake::snakeids[10] = { 0 };
int snake::field[30][30] = { 0 };
int snake::currentid = 3;
int snake::controlid = 3;

void snake::CONTROL()
{
	if (GetAsyncKeyState(VK_UP)) snake::setdircontrolsnake(0);
	if (GetAsyncKeyState(VK_DOWN)) snake::setdircontrolsnake(2);
	if (GetAsyncKeyState(VK_RIGHT)) snake::setdircontrolsnake(1);
	if (GetAsyncKeyState(VK_LEFT)) snake::setdircontrolsnake(3);
}

void snake :: setdircontrolsnake(int d) {
	snake* cs;
	cs = (snake*)snakeids[controlid-3];
	int cd = cs->getdir();
	if (d == 2 && cd != 0) cs->setdir(d);
	if (d == 0 && cd != 2) cs->setdir(d);
	if (d == 1 && cd != 3) cs->setdir(d);
	if (d == 3 && cd != 1) cs->setdir(d);
	cs = NULL;
	delete(cs);
}

void snake::setcontrolsnakeid(int i)
{
	controlid = i;
}

void snake::stepall()
{
	snake *cs;
	for (int i = 0; i < snake::currentid-3; i++)
	{
		cs = (snake*)snakeids[i];
		cs->step();
	}
	cs = NULL;
	delete(cs);
}

void snake::addeat()
{
	int rx = 0;
	int ry = 0;

	do
	{
		rx = rand() % 26 + 2;
		ry = rand() % 26 + 2;
	} while (snake::field[rx][ry] != 0);
	
	snake::field[rx][ry] = 2;

	COORD position;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	// Получение дескриптора устройства стандартного вывода (console)
	position.X = rx;									// Установка координаты X
	position.Y = ry;									// Установка координаты Y
	SetConsoleCursorPosition(hConsole, position);
	printf("*");


}

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

	COORD position;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	// Получение дескриптора устройства стандартного вывода (console)
	position.X = body[length - 1].x;									// Установка координаты X
	position.Y = body[length - 1].y;									// Установка координаты Y
	SetConsoleCursorPosition(hConsole, position);
	printf(" ");
	snake::field[body[length - 1].x][body[length - 1].y] = 0;
	int lastx = body[length - 1].x;
	int lasty = body[length - 1].y;
	bool EatExist = false; // есть ли на пути еда
	bool DangerExist = false; // есть ли на пути препятсвие
	for (int i = length - 1; i > 0; i--)
	{
		body[i].x = body[i - 1].x;
		body[i].y = body[i - 1].y;
	}
	if (dir == 0) // up
	{
		if (body[0].y - 1 > 1)
		{
			body[0].y--;
		}
		else
		{
			body[0].y = 29;
		}
	}

	if (dir == 1) // right
	{
		if (body[0].x + 1 < 30)
		{
			body[0].x++;
		}
		else
		{
			body[0].x = 2;
		}
	}

	if (dir == 2) // down
	{
		if (body[0].y + 1 < 30)
		{
			body[0].y++;
		}
		else
		{
			body[0].y = 2;
		}
	}

	if (dir == 3) // left
	{
		if (body[0].x - 1 > 1)
		{
			body[0].x--;
		}
		else
		{
			body[0].x = 29;
		}
	}
	if (snake::field[body[0].x][body[0].y] == 2)
	{
		EatExist = true;
	}
	snake::field[body[0].x][body[0].y] = id;
	position.X = body[0].x;									// Установка координаты X
	position.Y = body[0].y;									// Установка координаты Y
	SetConsoleCursorPosition(hConsole, position);
	printf("#");
	if (EatExist)
	{
		length++;
		body = (Coord*)realloc((void*)body, sizeof(Coord) * length);
		body[length - 1].x = lastx;
		body[length - 1].y = lasty;
		snake::field[body[length - 1].x][body[length - 1].y] = id;
		snake::addeat();
	}
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
	COORD position;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	// Получение дескриптора устройства стандартного вывода (console)
	
	for (int i = 1; i <= 30; i++)
	{
		position.X = i;									// Установка координаты X
		position.Y = 1;									// Установка координаты Y
		SetConsoleCursorPosition(hConsole, position);
		printf("O");
	}

	for (int i = 1; i <= 30; i++)
	{
		position.X = i;									// Установка координаты X
		position.Y = 30;									// Установка координаты Y
		SetConsoleCursorPosition(hConsole, position);
		printf("O");
	}

	for (int i = 1; i <= 30; i++)
	{
		position.X = 1;									// Установка координаты X
		position.Y = i;									// Установка координаты Y
		SetConsoleCursorPosition(hConsole, position);
		printf("O");
	}

	for (int i = 1; i <= 30; i++)
	{
		position.X = 30;									// Установка координаты X
		position.Y = i;									// Установка координаты Y
		SetConsoleCursorPosition(hConsole, position);
		printf("O");
	}

	position.X = 23;									// Установка координаты X
	position.Y = 23;									// Установка координаты Y
	SetConsoleCursorPosition(hConsole, position);
	printf("*");
	snake::field[23][23] = 2;
	for (int i = 0; i < snake::currentid - 3; i++)
	{
		cs = (snake*)snakeids[i];
		cs->draw();
	}
	cs = NULL;
	delete(cs);
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