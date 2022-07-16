#pragma once
#include <string>
#include <vector>

#include "Player.h"
#include "Word.h"

using namespace std;

class Game
{
public:
	Game();
	void Loop();
	string ChooseRandomWord();
	void DrawHangman(int tries);

private:
	int tries;
	Word wordToGuess;
	Player player;
	vector<string> randomWords;
	string lettersOfTheAlphabet;
};