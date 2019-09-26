#include <stdio.h>
#include <Windows.h>
#include "snake.h"
using namespace std;

int main()
{
	snake zm(15, 15, 4);
	snake zm1(10, 10, 3);
	snake::drawfield();
	return 0;
}
