#include <iostream>

#include "Word.h"

using namespace std;

Word::Word(string word)
{
	this->word = word;
	this->lettersGuessed = new bool[word.length()];

	//debug show word
	cout << "word: " << word << endl;
}

void Word::Show()
{
	for (int i = 0; i < word.length(); i++)
	{
		if (lettersGuessed[i])
		{
			cout << word[i] + " ";
		}
		else
		{
			cout << "_ ";
		}
	}
	cout << endl;
}

bool Word::CheckLetter(char letter)
{
	bool didWeFindALetter = false;
	for (int i = 0; i < word.length(); i++)
	{
		if (word[i] == letter)
		{
			lettersGuessed[i] = true;
			didWeFindALetter = true;
		}
	}
	return didWeFindALetter;
}

bool Word::Guessed()
{
	bool guessed = true;
	for (int i = 0; i < word.length(); i++)
	{
		if (!lettersGuessed[i])
		{
			guessed = false;
		}
	}
	return guessed;
}
