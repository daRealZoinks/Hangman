#include <iostream>

#include "Game.h"

using namespace std;

void main()
{
	Game game;
	srand(time(0));

	game.Loop();
}