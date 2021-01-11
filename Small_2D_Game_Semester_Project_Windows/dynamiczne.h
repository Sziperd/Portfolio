#pragma once


#include "Silnik_gry2.h"
#include "zawartosc.h"

class Glowny;
class Przedmiot;
class _Weapon1;

class dynamiczne
{



public:
	dynamiczne(string n);
	~dynamiczne();





	
	bool Hitbox_Vs_Map; // kolizja na mapie
	bool Hitbox_Vs_DynObj; // kolicja z dynamicznym obiektem
	
	bool _isAprojectile; // czy jest pociskiem?
	bool _IsAttackable; // czy da sie zaatakowac?

	float px, py; // pozycja, y i x
	float vx, vy; // predkosc y i x

	

	bool _isFriendly; // atakuje czy nie?
	bool _isRedundant; // powinien byc renderowany dalej czy nie?


	virtual void RenderSelf(olcConsoleGameEngineOOP * gfx, float ox, float oy){}  // funkcja virtualna aby mogla byc overriden. korzysta z silnika oraz koordynatow (w tym przypadku offsetu kamery)
	static Glowny* automator_engine;
	virtual void OnInteract(dynamiczne* player = nullptr) {}

	string _Nazwa; // nazwa dynamicznego obiektu

	virtual void Update(float fElapsedTime, dynamiczne* player = nullptr) {}
};

class dynamiczne_creature : public dynamiczne
{

public:
	void RenderSelf(olcConsoleGameEngineOOP* gfx, float ox, float oy)override;
	void Update(float fElapsedTime, dynamiczne* player = nullptr) override;
	virtual void EntityBehaviour(float fElapsedTime, dynamiczne* player = nullptr);
	int IsFacing() { return _Is_Facing_directionn; };
	virtual void Attack_Perform() {};
	void KnockBack(float dx, float dy, float dist);

	_Weapon1* Weapon_Equiped = nullptr;


	float _StateTick;
	int RoundCounter;
	int AktualneHP;
	int AktualnaRunda;
	int MaxHp;
	int _Controlable = true;
	bool IsAlive;



	float _Durationn;
	dynamiczne_creature(string n, olcSprite* sprite);

protected:
	//float _StateTick;
	olcSprite *_Sprite_rend;
	float _Timerr;

	enum { SOUTH = 0, WEST = 1, NORTH = 2, EAST = 3 } _Is_Facing_directionn;
	enum {STANDING, WALKING, OTHER, DEAD} _Is_doing;

	int _spritesheet_graph_counter;



	float _KnockBack_Coords_Y = 0.0f;
	float _Time_KnockBack = 0.0f;
	float _KnockBack_Coords_X = 0.0f;
	

};

class dynamiczne_Robot : public dynamiczne_creature
{
public:
	dynamiczne_Robot();
	float _Durationn;
	void EntityBehaviour(float fElapsedTime, dynamiczne* player = nullptr) override; //d
	void Attack_Perform() override;
	
};



class dynamiczne_Teleport : public dynamiczne
{
public:

	string _MapNamee;
	float X_MapPos;
	float Y_MapPos;
	dynamiczne_Teleport(float x, float y, string _MapNamee, float tx, float ty);
	void RenderSelf(olcConsoleGameEngineOOP* gfx, float ox, float oy) override;
	void Update(float fElapsedTime, dynamiczne* player = nullptr) override;


	
};

class dynamiczne_projectile : public dynamiczne
{
public:

	olcSprite* _Sprite = nullptr;
	float _SpriteX_leng;
	float _SpriteY_leng;
	float _Durationn;
	bool bOneHit = true;
	int ZadawanyDamage = 0;

	dynamiczne_projectile(float ox, float oy, bool bFriend, float velx, float vely, float duration, olcSprite* sprite, float tx, float ty);
	
	void Update(float fElapsedTime, dynamiczne* player = nullptr) override;

	void RenderSelf(olcConsoleGameEngineOOP* gfx, float ox, float oy) override;
	
};



class dynamiczne_Creature_player : public dynamiczne_creature
{
public:
	dynamiczne_Creature_player();


	void Attack_Perform() override;
	//void Show_textf(string sText, int x, int y);  // w przyszlosci..
};

class dynamiczne_Item : public dynamiczne
{
public:

	Przedmiot* item;
	bool _IsCollected = false;

	dynamiczne_Item(float x, float y, Przedmiot* item);
	void RenderSelf(olcConsoleGameEngineOOP* gfx, float ox, float oy) override;
	void OnInteract(dynamiczne* player = nullptr) override;

	
};