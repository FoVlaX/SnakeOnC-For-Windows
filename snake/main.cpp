#include <stdio.h>
#include <Windows.h>
#include "snake.h"
using namespace std;

int main()
{
	bool conte = false;
	 do {
		 conte = false;
		
		 snake::allnull();

		 snake* zm = new snake(15, 15, 4); // �������� ����
		 snake::drawfield(); //��������� ����
		 snake::GAME_OVER = false;
		 while (true) {
			 if (!snake::GAME_OVER)
			 {
				 snake::CONTROL(); // ���������� ������� ������ � ��������� ����������� �������� �������������� ����;
				 snake::stepall(); // ��� ���� ����
				 Sleep(120); //��������
			 }
			 else
			 {

				 snake::showPressDel();
				 if (GetAsyncKeyState(VK_ESCAPE))
				 {
					 break;
				 }
				 if (GetAsyncKeyState(VK_DELETE))
				 {
					 conte = true;
					 break;
				 }
				 Sleep(120);
			 }
		 }
		 zm->destroy();
	 } while (conte);
	return 0;
}
