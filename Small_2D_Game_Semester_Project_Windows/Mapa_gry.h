#include <iostream>
#include <string>
using namespace std;

#include "Silnik_gry2.h"
#include "zawartosc.h"
#include "komendy.h"
#include "dynamiczne.h"


class Mapa_gry
{
public:


	enum ActionsATM
	{
		IsIdle,
		IsWalking
	};


	Mapa_gry();
	~Mapa_gry();


	int _Width;  //szerokosc mapy

	int _Height; // wysokosc mapu

	float _StateTick= 0;
	


	bool Create(string fileData, olcSprite* sprite, string name); //  sciezka do pliku z ulozeniem kafelek na poziomie, pointer do grafiki i jej nazwa w programie.
	int GetIndex(int x, int y); //Funkcja okreslajaca ktore kafelki z poziomu wyswietlic graczowi. 
	bool GetSolid(int x, int y); //Funkcja okreslajaca czy kafelka stanowi przeszkode dla gracza czy nie.

	string _Nazwa; //nazwa mapy
	olcSprite* _Sprite; //nazwa grafiki

	virtual bool PopulatingMapf(vector<dynamiczne*>& vecDyns)
	{
		return false;
	}
	virtual bool OnInteraction(vector<dynamiczne*>& vecDynobs, dynamiczne* target, ActionsATM ActionsATM)
	{
		return false;
	}
	
private:
	int* _Indices = nullptr; // mapa jest zapamietywana jaka array indeksów, czyli liczb w danych miejscach okreslajacych czy blok (kafelka) jest kolizyjna czy nie i jaka ma nalozona teksture.
	bool* _Solids = nullptr; // array zczytujacy czy kafelka jest kolizyjna. 0- nie 1- tak.
	int* g2 = nullptr;
public:
	static Procesor_Skryptu* Procesor_skryptu;
};

class Mapa11 : public Mapa_gry  // Mapa glowna
{
public:
	Mapa11();
	bool OnInteraction(vector<dynamiczne*>& vecDynobs, dynamiczne* target, ActionsATM ActionsATM) override;
	bool PopulatingMapf(vector<dynamiczne*>& vecDyns) override;
	
};


class Mapa22 : public Mapa_gry // mapa startowa/ dodatkowa
{
public:
	Mapa22();

	bool PopulatingMapf(vector<dynamiczne*>& vecDyns) override;
	bool OnInteraction(vector<dynamiczne*>& vecDynobs, dynamiczne* target, ActionsATM ActionsATM) override;
};
