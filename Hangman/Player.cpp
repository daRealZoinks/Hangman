#include <iostream>

#include "Player.h"

using namespace std;

char Player::ReadInput()
{
	char input;
	cout << "Choose a letter: ";
	cin >> input;
	return input;
}