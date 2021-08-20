#pragma once
#include <string>
using namespace std;

const int MAXWORDS = 10; // ����������� ����� ��������� 10 ����
const int MAXGUESSES = 8; // 8 �������

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

