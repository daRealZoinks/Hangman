#pragma once
#include <string>

using namespace std;

class Word
{
public:
	Word(string word = "");
	void Show();
	bool CheckLetter(char letter);
	bool Guessed();
private:
	string word;
	bool* lettersGuessed;
};