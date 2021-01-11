#pragma once

#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
using namespace std;

#include "Silnik_gry2.h"
#include "Mapa_gry.h"
#include "zawartosc.h"
#include "dynamiczne.h"
#include "komendy.h"

#include "przedmioty.h"

class Glowny : public olcConsoleGameEngineOOP
{
public:
	Glowny();

private:



	enum
	{
	
		_ACTUAL_MAP_MODE,
		
		_INVENTORY_MODE
		
	};

	int _GameMode = _ACTUAL_MAP_MODE;


	int _Inventory_X = 0;
	int _Inventory_Y = 0;


protected:
	bool While_UsedrCreate() override;
	bool While_UsedrUpdate(float fElapsedTime) override;

	
	bool UpdateLocalMap(float fElapsedTime);

	bool UpdateInventory(float fElapsedTime);



	Mapa_gry* _CurrentLoadedMap = nullptr; // Storuje aktualna mape
	olcSprite* _TextFont = nullptr;

	dynamiczne_creature* _Player_1 = nullptr;

	vector<dynamiczne*> _vectorDynamics;
	vector<dynamiczne*> _vectorProjectiles; 
	Procesor_Skryptu  _Skrypty;
	list<Przedmiot*> _ItemList;
	

	// Camera properties
	float _CameraPosX = 0.0f;
	float _CameraPosY = 0.0f;




	

	vector<string> _vectorDialogShowf;
	bool _Dialog_Show = false;
	float _DialogPosX = 0.0f;
	float _DialogPosY = 0.0f;



public:


	void AddProjectile(dynamiczne_projectile* proj);

	bool GiveItem(Przedmiot* item);
	bool TakeItem(Przedmiot* item);

	void DialogShowf(vector<string> VectorLines);
	void MapChangef(string _MapNamee, float x, float y);

	bool HasItem(Przedmiot* item);

	void Attack(dynamiczne_creature* Attacking_enemy, _Weapon1* weapon);
	void Damage(dynamiczne_projectile* projectile, dynamiczne_creature* _ofiara);


	void DialogDisplayf(vector<string> vecText, int x, int y);
	void Show_textf(string sText, int x, int y);
	

};