#include <iostream>
#include <string>
#include <vector>

using namespace std;

string pickAWord()
{
	vector<string> possibleWords = {
		"apple",
		"banana",
		"orange",
		"coconut",
		"strawberry",
		"lime",
		"grapefruit",
		"watermelon",
		"mango",
		"cherry",
		"peach",
		"pear",
		"kiwi",
		"avocado",
		"pineapple",
		"blueberry",
		"blackberry",
		"raspberry",
		"gooseberry",
		"blackcurrant",
		"cranberry",
		"clementine",
		"fig",
		"date",
		"elderberry",
		"ginkgo",
		"grape",
		"guava",
		"jackfruit",
		"jambul",
		"jicama",
		"kiwano",
		"kumquat",
		"lemon",
		"lime",
		"loquat",
		"lychee",
		"mango",
		"melon",
		"nectarine",
		"nut",
		"olive",
		"orange",
		"papaya",
		"passionfruit",
		"peach",
		"pear",
		"persimmon",
		"physalis",
		"plum",
		"pomegranate",
		"pomelo",
		"quince",
		"raspberry",
		"rambutan",
		"ramie",
		"raspberries",
		"rhubarb",
		"rock melon",
		"salal",
		"salmonberry",
		"satsuma",
		"soursop",
		"star fruit",
		"strawberry",
		"tamarillo",
		"tangerine",
		"tomato",
	}

	int randomIndex = rand() % possibleWords.size();
	return possibleWords[randomIndex];
}

main()
{
	auto wordToGuess = pickAWord();

	auto guessedLetters = vector<char>();

	auto guessesRemaining = 10;

	while(guessesRemaining > 0)
	{
		auto letter = ' ';
		cout << "Guess a letter: ";
		cin >> letter;
		guessedLetters.push_back(letter);
		cout << "You guessed: ";
		for(auto letter : guessedLetters)
		{
			cout << letter << " ";
		}
		cout << endl;
		cout << "You have " << guessesRemaining << " guesses remaining." << endl;
		cout << "The word to guess is: " << wordToGuess << endl;
		cout << "The word to guess is: ";
		for(auto letter : wordToGuess)
		{
			if(find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end())
			{
				cout << letter << " ";
			}
			else
			{
				cout << "_ ";
			}
		}
		cout << endl;
		guessesRemaining--;
	}
}