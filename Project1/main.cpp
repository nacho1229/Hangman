#include <iostream>
#include <sstream> // Для работы со строками в потоках
#include "Hangman.h"

int main()
{
	Hangman hangman;
	hangman.ReadInWords("WordList.txt");
	int choice = 0;
	string input = "";
	while (choice != 2) // Выбор
	{
		system("cls");
		cout << "Welcome to Hangman." << endl << endl;
		cout << "[1] Start to play.\n[2] Exit.\n";
		getline(cin, input);
		if (stringstream(input) >> choice)
		{
			if (choice == 1) // Начать игру
			{
				hangman.Play();
			}
			else if (choice == 2) // Выйти
			{
				break;
			}
		}
	}
    return 0;
}

