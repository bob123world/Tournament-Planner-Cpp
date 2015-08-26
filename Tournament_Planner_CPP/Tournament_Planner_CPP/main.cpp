#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<string>
#include <sstream>
#include"player.h"

using namespace std;

void PlayerMenu();

void intro()
{
	char input;
	bool nt = true;
	do {
		system("cls");
		cout << "\n\n\tNew Tournament?";
		cout << "\n\n\ty\tn";
		cout << "\n\t";
		cin >> input;
		if (input == 'y' || input == 'Y')
		{
			nt = true;
			// Alle bestanden resetten!
		}
		else if (input == 'n' || input == 'N')
		{
			nt = false;
		}
		else
		{
			cout << "\n\n\tInput not recognised!\n\n\tUse y for yes or n for no!\n\n\t";
			nt = true;
			system("pause");
		}
	} while (nt);
}

void MainMenu()
{
	char ch;
	do {
		system("cls");
		cout << "\n\n\tTournament Planner (v1)";
		cout << "\n\n\tMain Menu";
		cout << "\n\t---------";
		cout << "\n\n\t1. List Players";
		cout << "\n\n\t2. Modify Players";
		cout << "\n\n\t3. Generate Games";
		cout << "\n\n\t4. Adjust Game";
		cout << "\n\n\t5. Set Results";
		cout << "\n\n\t6. Exit Tournament Planner";
		cout << "\n\n\t";
		cin >> ch;

		switch (ch)
		{
		case '1':
			ListPlayers();
			system("pause");
			break;
		case '2':
			PlayerMenu();
			break;
		case '3':
			break;
		case '4':
			break;
		case '5':
			break;
		case '6':
			break;
		default:cout << "\a";
		}
	} while (ch != '6');
}

void PlayerMenu()
{
	char ch;
	do {
		system("cls");
		cout << "\n\n\tTournament Planner (v1)";
		cout << "\n\n\tPlayer Menu";
		cout << "\n\t---------";
		cout << "\n\n\t1. List Players";
		cout << "\n\n\t2. Add Player";
		cout << "\n\n\t3. Add Player From File";
		cout << "\n\n\t4. Modify Player";
		cout << "\n\n\t5. Delete Player";
		cout << "\n\n\t6. Delete All Players";
		cout << "\n\n\t7. Return To Main Menu";
		cout << "\n\n\t";
		cin >> ch;

		switch (ch)
		{
		case '1':
			ListPlayers();
			system("pause");
			break;
		case '2':
			ManualNewPlayer();
			break;
		case '3':
			break;
		case '4':
			ListPlayers();

			break;
		case '5':
			DeletePlayer();
			break;
		case '6':
			break;
		case '7':
			break;
		default:cout << "\a";
		}
	} while (ch != '7');
	return;
}

int main()
{
	//intro();
	MainMenu();
	system("Pause");
}