#pragma once
#include <conio.h>
#include "GameScene.h"
#include <Windows.h>
#include <iostream>

class Player
{
	public:
		int HP = 1;
		int score = 0;
		void gotoxy(int x, int y);//�Լ�����һ��gotoxy�����������x��y�� 
		int nowX;
		int nowY;
		int playerPos;
		char direction = 'w';
		void createPlayer(GameScene* gS);
		/*Player();
		~Player();*/
		void movement(GameScene* gS);
};

