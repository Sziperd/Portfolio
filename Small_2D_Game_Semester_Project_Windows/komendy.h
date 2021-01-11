#pragma once


#include "dynamiczne.h"
#include <list>

using namespace std;

class Glowny;

class komenda
{
public:
	komenda() {}
	virtual ~komenda() {}

	bool IsStarted = false;
	bool IsCompleted = false;

	virtual void Start() {}
	virtual void Update(float fElapsedTime) {};

	static Glowny* automator_engine;
};

class Procesor_Skryptu
{
public:

	void ProcessCommands(float fElapsedTime);

	void CompleteCommand();

	Procesor_Skryptu();

	void AddCommand(komenda* cmd);
	

	bool IsUserControlEnabled;

private:
	list<komenda*> Lista_Komend;
};


class komenda_DialogShowf : public komenda
{
public:
	komenda_DialogShowf(vector<string> line);
	void Start() override;

private:
	vector<string> VectorLines;
};

class komenda_MapChangef : public komenda
{
public:
	komenda_MapChangef(string mapName, float mapPosX, float mapPosY);
	void Start() override;

private:
	string _Nazwa_Mapy;
	float _Map_PosX;
	float _Map_PosY;
};



class komenda_AddMob : public komenda
{
public:
	komenda_AddMob();
	bool AddMob(vector<dynamiczne*>& vecDyns);





private:
};