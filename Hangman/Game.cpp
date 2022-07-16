#include <iostream>

#include "Game.h"

using namespace std;

Game::Game()
{
	randomWords = {
		"grapefruit",
		"apple",
		"purple",
		"banana",
		"orange",
		"wine",
		"watermelon",
		"mango",
		"liquor",
		"blue",
		"cafe",
		"pineapple",
		"red",
		"green",
		"restaurant",
		"pink",
		"yellow",
		"strawberry",
		"coconut",
		"hotel",
		"cherry",
		"bar",
	};
	tries = 6;
	wordToGuess = Word(ChooseRandomWord());
	unusedLetters = "abcdefghijklmnopqrstuvwxyz";
	usedLetters = "";
}

void Game::Loop()
{
	char letter;
	while (tries > 0)
	{
		DrawHangman(tries);
		cout << endl;
		wordToGuess.Show();
		cout << endl;
		ShowUnusedLetters();
		cout << endl;
		letter = player.ReadInput();
		system("cls");

		if (usedLetters.find(letter) != string::npos)
		{
			cout << "You already used this letter!" << endl;
		}
		else
		{
			if (wordToGuess.CheckLetter(letter))
			{
				cout << "Correct!" << endl;
			}
			else
			{
				cout << "Wrong!" << endl;
				tries--;
			}
			usedLetters.push_back(letter);
			unusedLetters.erase(unusedLetters.find(letter), 1);
		}

		if (wordToGuess.Guessed())
		{
			cout << "You win!" << endl;
			return;
		}
	}

	cout << "You lose!" << endl;
	cout << "The word was: " << wordToGuess.GetWord() << endl;
}

string Game::ChooseRandomWord()
{
	srand(time(0));
	int randomIndex = rand() % randomWords.size();
	return randomWords[randomIndex];
}

void Game::DrawHangman(int tries)
{
	switch (tries)
	{
		case 6:
			cout << "  ______  " << endl;
			cout << "  |    |  " << endl;
			cout << "  |       " << endl;
			cout << "  |       " << endl;
			cout << "  |       " << endl;
			cout << "  |       " << endl;
			cout << "__|__     " << endl;
			break;
		case 5:
			cout << "  ______  " << endl;
			cout << "  |    |  " << endl;
			cout << "  |    O  " << endl;
			cout << "  |       " << endl;
			cout << "  |       " << endl;
			cout << "  |       " << endl;
			cout << "__|__     " << endl;
			break;
		case 4:
			cout << "  ______  " << endl;
			cout << "  |    |  " << endl;
			cout << "  |    O  " << endl;
			cout << "  |    |  " << endl;
			cout << "  |       " << endl;
			cout << "  |       " << endl;
			cout << "__|__     " << endl;
			break;
		case 3:
			cout << "  ______  " << endl;
			cout << "  |    |  " << endl;
			cout << "  |    O  " << endl;
			cout << "  |   /|  " << endl;
			cout << "  |       " << endl;
			cout << "  |       " << endl;
			cout << "__|__     " << endl;
			break;
		case 2:
			cout << "  ______  " << endl;
			cout << "  |    |  " << endl;
			cout << "  |    O  " << endl;
			cout << "  |   /|\\ " << endl;
			cout << "  |       " << endl;
			cout << "  |       " << endl;
			cout << "__|__     " << endl;
			break;
		case 1:
			cout << "  ______  " << endl;
			cout << "  |    |  " << endl;
			cout << "  |    O  " << endl;
			cout << "  |   /|\\ " << endl;
			cout << "  |   /   " << endl;
			cout << "  |       " << endl;
			cout << "__|__     " << endl;
			break;
		case 0:
			cout << "  ______  " << endl;
			cout << "  |    |  " << endl;
			cout << "  |    O  " << endl;
			cout << "  |   /|\\ " << endl;
			cout << "  |   / \\ " << endl;
			cout << "  |       " << endl;
			cout << "__|__     " << endl;
			break;
	}
}

void Game::ShowUnusedLetters()
{
	cout << "Avalable letters: ";
	for (auto i : unusedLetters)
	{
		cout << i << " ";
	}
}