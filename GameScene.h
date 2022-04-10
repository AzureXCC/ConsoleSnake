#pragma once
#include <cstring>

class GameScene
{
	public:
	enum GameArea
	{
		NONE,
		WALL,
		BODY,
		HEAD,
		FOOD
	};
	public:
		int mapSize; 
		int sizeX = 2; 
		int sizeY = 2;
		GameScene(int x,int y);
		~GameScene();
		GameArea *gA;
		int createMap();

};

