#include <stdio.h>
#include <Windows.h>
#include "snake.h"
using namespace std;



int main()
{
	snake *zm = new snake(15, 15, 4); // �������� ����
	snake::drawfield(); //��������� ����
	while (true) {
		if (!snake::GAME_OVER)
		{
			snake::CONTROL(); // ���������� ������� ������� � ��������� ����������� �������� �������������� ����;
			snake::stepall(); // ��� ���� ����
			Sleep(120); //��������
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
