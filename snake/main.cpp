#include <stdio.h>
#include <Windows.h>
#include "snake.h"
using namespace std;



int main()
{
	snake zm(15, 15, 4); // �������� ����
	snake::drawfield(); //��������� ����
	while (true) {
		snake::CONTROL(); // ���������� ������� ������� � ��������� ����������� �������� �������������� ����;
		snake::stepall(); // ��� ���� ����
		Sleep(60); //��������
	}
	return 0;
}
