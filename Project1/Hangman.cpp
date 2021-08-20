#include "Hangman.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>
#include <windows.h>
void Hangman::displayWord(string word) //Прорисовка каждой буквы на экран
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
	guess = char(tolower(guess)); //Проверка на регистр
	for (int i = 0; i < word.length(); i++) // Проверка каждой буквы
	{
		if (word[i] == guess) // Вставка правильной буквы
		{
			found = true;
			unknownWord[i] = guess;
		}
	}
	return found;
}
Hangman::Hangman() // Конструктор 
{
}
Hangman::~Hangman() // Дуструктор
{
}

void Hangman::ReadInWords(string filename) // Загрузка всех 
{
	ifstream file(filename);
	string s;
	while (getline(file, s))
	{
		wordList[numWords] = s;
		numWords++;
		if (numWords == MAXWORDS) // Проверка оверфлов
		{
			cout << "Maximum amount of words reached.\n";
			break;
		}
	}
	file.close();
}

void Hangman::Play() // Начало игры
{
	//Select a word
	srand(time(NULL));
	int start = clock(); // Начало таймера
	int randNum = rand() % numWords; // Случайное слово
	string word = wordList[randNum];
	string unknownWord(word.length(), '_'); // Прорисовка _ от кол букв
	
	int numGuesses = 0; // Кол попыток пользователя
	string userGuesses; // Введёные буквы пользователя
	while (numGuesses < MAXGUESSES)
	{
		system("cls");
		displayWord(unknownWord);
		cout << "Number of wrong guesses left: " << MAXGUESSES - numGuesses << endl;
		cout << "Enter your guess: ";
		char guess;
		string input;
		getline(cin, input); // Ввод буквы
		if (stringstream(input) >> guess)
		if (checkGuess(guess, word, unknownWord) == true) // Проверка победы
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
	int end = clock(); // Конец таймера
	if (numGuesses == MAXGUESSES) // Проигрыш
	{
		system("CLS");
		cout << "You lost." << endl << endl;
		numLosses++;
	}
	else
	{
		system("CLS");
		cout << "You win!" << endl << endl;//Победа
		numWins++;
	}
	//Статистика игры
	int time = (end - start) / CLOCKS_PER_SEC;
	cout << "Wins - " << numWins << endl;
	cout << "Losses - " << numLosses << endl;
	cout << "Word - " << word << endl;
	cout << "Used letters - " << userGuesses << endl;
	cout << "Time - " << time << " sec" << endl << endl;
	system("pause");
	return;
}
