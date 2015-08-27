#include"player.h"

using namespace std;

int playerid = 1;

class player
{
private:
	int plid;
	char name[50];
	int wins;
	int loses;
	double ptn;
	double oscore;
	double ascore;
	int poule;
	int round;
public:
	void nNewPlayer(char name[50]);
	void PlotPlayerInfoList() const;
	// Set
	void SetId(int nid)
	{
		plid = nid;
	}
	void SetName(char nname[50])
	{
		strcpy_s(name, nname);
	}
	void SetWins(int nwins)
	{
		wins = nwins;
	}
	void SetLoses(int nloses)
	{
		loses = nloses;
	}
	void SetPtn(double nptn)
	{
		ptn = nptn;
	}
	void SetOscore(double noscore)
	{
		oscore = noscore;
	}
	void SetAscore(double nascore)
	{
		ascore = nascore;
	}
	void SetPoule(int npoule)
	{
		poule = npoule;
	}
	void SetRound(int nround)
	{
		round = nround;
	}
	// Get
	int GetId()
	{
		return plid;
	}
	char GetName()
	{
		return name[50];
	}
	int GetWins()
	{
		return wins;
	}
	int GetLoses()
	{
		return loses;
	}
	double GetPtn()
	{
		return ptn;
	}
	double GetOscore()
	{
		return oscore;
	}
	double GetAscore()
	{
		return ascore;
	}
	int GetPoule()
	{
		return poule;
	}
	int GetRound()
	{
		return round;
	}
};

void player::nNewPlayer(char nname[50])
{
	plid = playerid++;
	strcpy_s(name, nname);
	wins = 0;
	loses = 0;
	ptn = 0.0;
	oscore = 0.0;
	ascore = 0.0;
	poule = 0;
	round = 0;
}

void player::PlotPlayerInfoList() const
{
	cout << setw(3) << right << plid << " " << setw(36) << left << name << " ";
	cout << setw(3) << wins << " " << setw(4) << loses << " " << setw(5) << ptn << " " << setw(5) << oscore << " ";
	cout << setw(5) << ascore << " " << setw(5) << poule << " " << setw(5) << round << endl;
}

void NewPlayer(char name[50])
{
	player pl;
	ofstream outFile;
	outFile.open("player.dat", ios::binary | ios::app);
	pl.nNewPlayer(name);
	outFile.write(reinterpret_cast<char *> (&pl), sizeof(player));
	outFile.close();
}

void ManualNewPlayer()
{
	char name[50];
	system("cls");
	cout << "\n\n\tNew Player";
	cout << "\n\t---------";
	cout << "\n\n\tWhat is the name of the player?";
	cout << "\n\t";
	cin.ignore();
	cin.getline(name, 50);
	NewPlayer(name);
}

void ListPlayers()
{
	system("cls");
	player pl;
	ifstream inFile;
	inFile.open("player.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	cout << "\n\n\t\t\t\tPlayers in Tournament";
	cout << "\n\t\t\t\t---------------------\n";
	cout << "===============================================================================\n";
	cout << "No. Name                                 Win Lose ptn   off   def   poule round\n";
	cout << "===============================================================================\n";
	while (inFile.read(reinterpret_cast<char *> (&pl), sizeof(player)))
	{
		pl.PlotPlayerInfoList();
	}
	inFile.close();
	cout << "===============================================================================\n";
	//system("pause");
}

void ModifyPlayer()
{
	player pl;
	fstream File;
	int number,inp1;
	double inp2;
	char ch, inp3[50];

	File.open("player.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	while (!File.eof())
	{

		do {
			system("cls");
			ListPlayers();
			cout << "\n\n\tWhich player would you like to modify?";
			cout << "\n\n\t> ";
			cin >> number;

			File.read(reinterpret_cast<char *> (&pl), sizeof(player));
			if (pl.GetId() == number)
			{
				int pos = (-1)*static_cast<int>(sizeof(player));
				File.seekp(pos, ios::cur);
				do {
					cout << "\n\n\tWhich field would you like to adjust?";
					cout << "\n\t1. Name";
					cout << "\n\t2. Wins";
					cout << "\n\t3. Loses";
					cout << "\n\t4. Points (Ptn)";
					cout << "\n\t5. Offensive Score (Oscore)";
					cout << "\n\t6. Against Score (Ascore)";
					cout << "\n\t7. Poule";
					cout << "\n\t8. Round";
					cout << "\n\t9. None, Exit...";
					cout << "\n\n\t> ";
					cin >> ch;

					switch (ch)
					{
					case '1':
						cout << "\n\n\tNew Name: ";
						cin.ignore();
						cin.getline(inp3, 50);
						// Check for completion
						pl.SetName(inp3);
						break;
					case '2':
						cout << "\n\n\tAmount of wins: ";
						cin >> inp1;
						pl.SetWins(inp1);
						break;
					case '3':
						cout << "\n\n\tAmount of loses: ";
						cin >> inp2;
						pl.SetLoses(inp2);
						break;
					case '4':
						cout << "\n\n\tAmount of points (double): ";
						cin >> inp2;
						pl.SetPtn(inp2);
						break;
					case '5':
						cout << "\n\n\tAmount of offensive scores (double): ";
						cin >> inp2;
						pl.SetOscore(inp2);
						break;
					case '6':
						cout << "\n\n\tAmount of against scores (double): ";
						cin >> inp2;
						pl.SetOscore(inp2);
						break;
					case '7':
						cout << "\n\n\tNew Poule: ";
						cin >> inp1;
						pl.SetPoule(inp1);
						break;
					case '8':
						cout << "\n\n\tNew Round: ";
						cin >> inp1;
						pl.SetRound(inp1);
						break;
					case '9':
						break;
					default:cout << "\a";
					}
				} while (ch != 9);
				File.write(reinterpret_cast<char *> (&pl), sizeof(player));
			}
			else
			{
				cout << "\n\n Record Not Found ";
			}
		} while (number != 0);
		File.close();
	}
}

void DeletePlayer()
{
	player pl;
	ifstream inFile;
	ofstream outFile;
	int number;
	char input;
	bool yn = true;

	do {
		system("cls");
		ListPlayers();
		cout << "\n\n\tWhich player would you like to delete?\n";
		cout << "\tWhen you don't want to delete any more players enter 0!\n\n";
		cout << "\t> ";
		cin >> number;
		if(number > 0 || number > 10000)
		{
			do {
				cout << "\n\n\tAre You certain you want to delete this player?";
				cout << "\n\n\ty\tn";
				cout << "\n\t";
				cin >> input;
				if (input == 'y' || input == 'Y')
				{
					yn = false;
				}
				else if (input == 'n' || input == 'N')
				{
					yn = true;
				}
				else
				{
					cout << "\n\n\tInput not recognised!\n\n\tUse y for yes or n for no!\n\n\t";
					yn = true;
					system("pause");
					system("cls");
				}
			} while (yn);

			inFile.open("player.dat", ios::binary);
			if (!inFile)
			{
				cout << "File could not be open !! Press any Key...";
				return;
			}
			outFile.open("temp.dat", ios::binary);
			inFile.seekg(0, ios::beg);
			while (inFile.read(reinterpret_cast<char *> (&pl), sizeof(player)))
			{
				if (pl.GetId() != number)
				{
					outFile.write(reinterpret_cast<char *> (&pl), sizeof(player));
				}
			}
			inFile.close();
			outFile.close();
			remove("player.dat");
			rename("temp.dat", "player.dat");
			cout << "\n\n\tPlayer Deleted ..";
		}
		else if(number == 0)
		{

		}
		else
		{
			cout << "\n\tInput was not correct!\n";
		}

	} while (number != 0);

	
}