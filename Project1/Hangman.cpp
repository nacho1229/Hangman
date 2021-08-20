#include "Hangman.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>
#include <windows.h>
void Hangman::displayWord(string word) //���������� ������ ����� �� �����
{
	for (int i = 0; i < word.length(); i++)
	{
		cout << word[i];
		if (i + 1 < word.length())
		{
			cout << ' ';
		}
	}
	cout << endl;
	return;
}

bool Hangman::checkGuess(char guess, string word, string & unknownWord) 
{
	bool found = false;
	guess = char(tolower(guess)); //�������� �� �������
	for (int i = 0; i < word.length(); i++) // �������� ������ �����
	{
		if (word[i] == guess) // ������� ���������� �����
		{
			found = true;
			unknownWord[i] = guess;
		}
	}
	return found;
}
Hangman::Hangman() // ����������� 
{
}
Hangman::~Hangman() // ����������
{
}

void Hangman::ReadInWords(string filename) // �������� ���� 
{
	ifstream file(filename);
	string s;
	while (getline(file, s))
	{
		wordList[numWords] = s;
		numWords++;
		if (numWords == MAXWORDS) // �������� ��������
		{
			cout << "Maximum amount of words reached.\n";
			break;
		}
	}
	file.close();
}

void Hangman::Play() // ������ ����
{
	//Select a word
	srand(time(NULL));
	int start = clock(); // ������ �������
	int randNum = rand() % numWords; // ��������� �����
	string word = wordList[randNum];
	string unknownWord(word.length(), '_'); // ���������� _ �� ��� ����
	
	int numGuesses = 0; // ��� ������� ������������
	string userGuesses; // ������� ����� ������������
	while (numGuesses < MAXGUESSES)
	{
		system("cls");
		displayWord(unknownWord);
		cout << "Number of wrong guesses left: " << MAXGUESSES - numGuesses << endl;
		cout << "Enter your guess: ";
		char guess;
		string input;
		getline(cin, input); // ���� �����
		if (stringstream(input) >> guess)
		if (checkGuess(guess, word, unknownWord) == true) // �������� ������
		{
			if (unknownWord == word)
			{
				displayWord(word);
				cout << "Congratulations! You guessed the word!" << endl;
				system("pause");
				break;
			}
			userGuesses += guess;
			userGuesses += " ";
		}
		else
		{
			numGuesses++;
			userGuesses += guess;
			userGuesses += " ";
		}
	}
	int end = clock(); // ����� �������
	if (numGuesses == MAXGUESSES) // ��������
	{
		system("CLS");
		cout << "You lost." << endl << endl;
		numLosses++;
	}
	else
	{
		system("CLS");
		cout << "You win!" << endl << endl;//������
		numWins++;
	}
	//���������� ����
	int time = (end - start) / CLOCKS_PER_SEC;
	cout << "Wins - " << numWins << endl;
	cout << "Losses - " << numLosses << endl;
	cout << "Word - " << word << endl;
	cout << "Used letters - " << userGuesses << endl;
	cout << "Time - " << time << " sec" << endl << endl;
	system("pause");
	return;
}
