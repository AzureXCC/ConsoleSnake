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
		void gotoxy(int x, int y);//自己定义一个gotoxy，将光标跳到x列y行 
		int nowX;
		int nowY;
		int playerPos;
		char direction = 'w';
		void createPlayer(GameScene* gS);
		/*Player();
		~Player();*/
		void movement(GameScene* gS);
};

