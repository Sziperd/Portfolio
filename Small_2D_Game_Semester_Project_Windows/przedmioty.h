#pragma once

#include "dynamiczne.h"

class Glowny;

class Przedmiot
{
public:
	Przedmiot(string name, olcSprite* sprite, string desc);

	virtual bool OnInteract(dynamiczne* object) { return false; }
	virtual bool While_Used(dynamiczne* object) { return false; }

	string _Nazwa;
	string _Description;
	olcSprite* _Sprite;
	bool PodswietlonyItem = false;
	bool IsEquipable = false;

	static Glowny* automator_engine;
};



class Przedmiot_Health : public Przedmiot //dodaj 10hp bazowo
{
public:
	Przedmiot_Health();
	bool OnInteract(dynamiczne* object) override;
	bool While_Used(dynamiczne* object) override;
};

class Przedmiot_HealthBoost : public Przedmiot // podnies hp o 10
{
public:
	Przedmiot_HealthBoost();
	bool While_Used(dynamiczne* object) override;
	bool OnInteract(dynamiczne* object) override;
	
};


class _Weapon1 : public Przedmiot
{
public:
	_Weapon1(string name, olcSprite* sprite, string desc, int dmg);
	int ZadawanyDamage = 0;
	bool OnInteract(dynamiczne* object) override;
	bool While_Used(dynamiczne* object) override;

	
};


class _Melee_Weapon : public _Weapon1
{
public:
	_Melee_Weapon();

	bool While_Used(dynamiczne* object) override;
};