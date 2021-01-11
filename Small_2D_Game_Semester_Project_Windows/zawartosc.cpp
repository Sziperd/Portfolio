#include "zawartosc.h"
#include "Mapa_gry.h"
#include "przedmioty.h"

zawartosc::zawartosc()
{

}

zawartosc::~zawartosc()
{

}

void zawartosc::LoadSprites()
{
	auto load = [&](string _Nazwa, wstring sFileName) // tak zwana lambda function czyli definicja anonimowego objektu funkcji w którym jest wywo³ywana lub przenoszona jako argument do funkcji
	{ // auto oznacza typ zwracany...
		olcSprite* s = new olcSprite(sFileName); // tworzymy grafike 
		container_Sprites[_Nazwa] = s;  // storujemy mape 
		
	};


	// dzieki powyzszej funkcji latwo zaladujemy zawartosc do naszego programu

	load("player", L"Tekstury/walking_animation_final.png.spr");
	load("przeciwnik", L"Tekstury/robotanimationsfinal.png.spr");
	
	load("startroom", L"Tekstury/start_room.png.spr");
	



	load("font", L"Tekstury/nesfont8x8.spr");
	load("village", L"Tekstury/Test_wyglad1.png.spr");
	

	load("sword", L"Tekstury/Swordd.png.spr");


	load("health", L"Tekstury/health.png.spr");
	load("healthboost", L"Tekstury/max_up.png.spr");

	load("Basic Sword", L"Tekstury/weapon_sword.png.spr");

}

void zawartosc::LoadMaps()
{
	auto load = [&](Mapa_gry* m)
	{
		container_Maps[m->_Nazwa] = m;
	};

    load(new Mapa11());
	load(new Mapa22());
	
}

void zawartosc::LoadItems()
{
	auto load = [&](Przedmiot* i)
	{
		container_Items[i->_Nazwa] = i;
	};

	load(new Przedmiot_Health());
	load(new Przedmiot_HealthBoost());

	load(new _Melee_Weapon());
}