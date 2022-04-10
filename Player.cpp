#include "Player.h"

void Player::createPlayer(GameScene* gS)
{
	playerPos = 2500;
	gS->gA[playerPos] = gS->HEAD;
	gS->createMap();
}
void Player:: gotoxy(int x, int y)//自己定义一个gotoxy，将光标跳到x列y行 
{
	COORD c;     //定义一个光标类
	c.X = x - 1; //设置这个光标的位置
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);   //调用WindowsAPI来设置光标位置
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

