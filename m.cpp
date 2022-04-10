#include <iostream>
#include "GameScene.h"
#include "Player.h"

int main()
{
	GameScene gS(90,30);
	gS.createMap();

	Player player;
	player.createPlayer(&gS);
	player.movement(&gS);

	return 0;
}