#include "Player.h"

void Player::createPlayer(GameScene* gS)
{
	playerPos = 2500;
	gS->gA[playerPos] = gS->HEAD;
	gS->createMap();
}
void Player:: gotoxy(int x, int y)//�Լ�����һ��gotoxy�����������x��y�� 
{
	COORD c;     //����һ�������
	c.X = x - 1; //�����������λ��
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);   //����WindowsAPI�����ù��λ��
}


void Player:: movement(GameScene* gS)
{
	int flag = 1;
	char ch = 'w';
	while (flag)
	{
		if(_kbhit())
			ch = _getch();
		switch (ch)
		{
		case 'w':
			direction = 'w';
			break;
		case 's':
			direction = 's';

			break;
		case 'a':
			direction = 'a';

			break;
		case 'd':
			direction = 'd';

			break;
		}
		//Sleep(100);
		if (direction == 'w')
		{

			int newPos = playerPos - gS->sizeX;
			if(gS->gA[newPos] != gS->WALL)
			{
				nowY--;

				gS->gA[playerPos] = gS->NONE;
				gS->gA[newPos] = gS->HEAD;
				playerPos = newPos;
				gS->createMap();
			}
		}
		else if (direction == 's')
		{

			int newPos = playerPos + gS->sizeX;
			if (gS->gA[newPos] != gS->WALL)
			{
				nowY++;

				gS->gA[playerPos] = gS->NONE;
				gS->gA[newPos] = gS->HEAD;
				playerPos = newPos;

				gS->createMap();
			}
		}
		else if (direction == 'a')
		{

			int newPos = playerPos - 1;
			if (gS->gA[newPos] != gS->WALL)
			{
				nowX--;
				gS->gA[playerPos] = gS->NONE;
				gS->gA[newPos] = gS->HEAD;
				playerPos = newPos;
				gS->createMap();
			}
		}
		else if (direction == 'd')
		{

			int newPos = playerPos +1;
			if (gS->gA[newPos] != gS->WALL)
			{
				nowX++;
				gS->gA[playerPos] = gS->NONE;
				gS->gA[newPos] = gS->HEAD;
				playerPos = newPos;
				gS->createMap();
			}
		}
	}
}

