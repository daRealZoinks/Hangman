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
	string GetWord();

private:
	string word;
	bool* lettersGuessed;
};