#include"game.h"

using namespace std;

int gameid = 1;

class game
{
private:
	int gaid;
	int pl1id;
	int pl2id;
	int winid;
	double ptnho;
	double ptnaw;
	int round;
	int court;
	int time;
public:
	void nNewGame(int npl1id, int npl2id);
	//set
	void SetId(int nid)
	{
		gaid = nid;
	}
	void SetPl1id(int npl1)
	{
		pl1id = npl1;
	}
	void SetPl2id(int npl2)
	{
		pl2id = npl2;
	}
	void SetWinid(int nwin)
	{
		winid = nwin;
	}
	void SetPtnho(double nptnho)
	{
		ptnho = nptnho;
	}
	void SetPtnaw(double nptnaw)
	{
		ptnaw = nptnaw;
	}
	void SetRound(int nround)
	{
		round = nround;
	}
	void SetCourt(int ncourt)
	{
		court = ncourt;
	}
	void SetTime(int ntime)
	{
		time = ntime;
	}
	//get
	int GetId()
	{
		return gaid;
	}
	int GetPl1id()
	{
		return pl1id;
	}
	int GetPl2id()
	{
		return pl2id;
	}
	int GetWinid()
	{
		return winid;
	}
	double GetPtnho()
	{
		return ptnho;
	}
	double GetPtnaw()
	{
		double ptnaw;
	}
	int GetRound()
	{
		return round;
	}
	int GetCourt()
	{
		return court;
	}
	int GetTime()
	{
		return time;
	}
};

void game::nNewGame(int npl1id, int npl2id)
{
	gaid = gameid++;
	pl1id = npl1id;
	pl2id = npl2id;
	winid = 0;
	ptnho = 0.0;
	ptnaw = 0.0;
	round = 0;
	court = 0;
	time = 0;
}

void NewGame(int npl1id, int npl2id)
{
	game ga;
	ofstream outFile;
	outFile.open("player.dat", ios::binary | ios::app);
	ga.nNewGame(npl1id,npl2id);
	outFile.write(reinterpret_cast<char *> (&ga), sizeof(game));
	outFile.close();
}