#pragma once
#include <string>
using namespace std;

const int MAXWORDS = 10; // ћаксимально можно загрузить 10 слов
const int MAXGUESSES = 8; // 8 попыток

class Hangman
{
private:

	string wordList[MAXWORDS];
	int numWords = 0;
	int numWins = 0;
	int numLosses = 0;

	void displayWord(string word);
	bool checkGuess(char guess, string word, string & unknownWord);
public:
	Hangman();
	~Hangman();
	void ReadInWords(string filename);
	void Play();
};

