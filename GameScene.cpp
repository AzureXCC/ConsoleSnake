#include "GameScene.h"
#include <stdlib.h>
#include <iostream>

GameScene::GameScene(int x,int y)
{
	gA = (GameArea*)malloc(x * y * sizeof(GameArea));
	mapSize = x * y; sizeX = x; sizeY = y;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if ((i == 0 && j < x) || (j == 0) || (j == x - 1) || (i == y - 1 && j < x))
			{
				gA[x * i + j] = WALL;
			}
			else
			{
				gA[x * i + j] = NONE;

			}
		}

	}
}
GameScene::~GameScene()
{
	free(gA);
}
int GameScene:: createMap()
{
	system("cls");
	for (int i = 0; i < sizeY; i++)
	{
		for (int j = 0; j < sizeX; j++)
		{
			if (gA[sizeX * i + j] == WALL)
			{
				printf("/");
			}
			else if (gA[sizeX * i + j] == HEAD)
			{
				printf("o");
			}
			else if (gA[sizeX * i + j] == BODY)
			{
				printf("*");
			}
			else if (gA[sizeX * i + j] == FOOD)
			{
				printf("X");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}