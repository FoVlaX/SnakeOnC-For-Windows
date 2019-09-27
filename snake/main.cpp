#include <stdio.h>
#include <Windows.h>
#include "snake.h"
using namespace std;



int main()
{
	snake zm(15, 15, 4);
	snake::drawfield();
	while (true) {
		if (GetAsyncKeyState(VK_UP)) snake::setdircontrolsnake(0);
		if (GetAsyncKeyState(VK_DOWN)) snake::setdircontrolsnake(2);
		if (GetAsyncKeyState(VK_RIGHT)) snake::setdircontrolsnake(1);
		if (GetAsyncKeyState(VK_LEFT)) snake::setdircontrolsnake(3);
		snake::stepall();
		Sleep(60);
	}
	return 0;
}
