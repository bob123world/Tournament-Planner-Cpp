#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>

//class player
//{
//private:
//	int plid;
//	char name[50];
//	int wins;
//	int loses;
//	double ptn;
//	double oscore;
//	double ascore;
//	int poule;
//	int round;
//public:
//    void nNewPlayer(char name[50]);
//	void ModifyPlayer();
//	int GetId();
//	char GetName();
//	int GetWins();
//	int GetLoses();
//	double GetPtn();
//	double GetOscore();
//	double GetAscore();
//	int GetPoule();
//	int GetRound();
//};

void NewPlayer(char name[50]);
void ManualNewPlayer();
void ListPlayers();
 
#endif