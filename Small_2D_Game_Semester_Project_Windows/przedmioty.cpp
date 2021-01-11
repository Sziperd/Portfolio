#include "przedmioty.h"

#include "Glowny.h"

Glowny* Przedmiot::automator_engine = nullptr;

Przedmiot::Przedmiot(string name, olcSprite* sprite, string desc)
{
	_Nazwa = name;
	//nazwa przedmiotu
	_Sprite = sprite;
	//nazwa grafiki
	_Description = desc;
	//opis przedmiotu
}


Przedmiot_Health::Przedmiot_Health() : Przedmiot("Health Potion", zawartosc::get().GetSprite("health"), "opis")
{
}








Przedmiot_HealthBoost::Przedmiot_HealthBoost() :
	Przedmiot("Health Up", zawartosc::get().GetSprite("healthboost"), "opis")
{}

bool Przedmiot_HealthBoost::OnInteract(dynamiczne* object)
{
	return true; // dodaj do schowka (ekwipunku)
}

bool Przedmiot_HealthBoost::While_Used(dynamiczne* object)
{
	if (object != nullptr)
	{
		dynamiczne_creature* dyn = (dynamiczne_creature*)object;
		dyn->MaxHp += 2;
		
	}

	return true; // usun ze schowka (ekwipunku)
}

_Weapon1::_Weapon1(string name, olcSprite* sprite, string desc, int dmg) : Przedmiot(name, sprite, desc)
{
	ZadawanyDamage = dmg;
}



bool _Weapon1::While_Used(dynamiczne* object)
{
	return false;
}




bool Przedmiot_Health::OnInteract(dynamiczne* object)
{
	While_Used(object);
	return false; // wtedy zaabsorbuj

}

bool _Melee_Weapon::While_Used(dynamiczne* object)
{
	//trzeba zapobiec atakowaniu przeciwnikow sie nawzajem

	//strona atakujacego
	dynamiczne_creature* Attacking_enemy = (dynamiczne_creature*)object;

	// detektujemy zrodlo ataku
	float x, y, vx, vy;
	if (Attacking_enemy->IsFacing() == 2) // gora
	{
		x = Attacking_enemy->px;
		y = Attacking_enemy->py - 1.0f;
		vx = 0.0f; vy = -1.0f;
	}
	if (Attacking_enemy->IsFacing() == 0) // dol
	{
		x = Attacking_enemy->px;
		y = Attacking_enemy->py + 1.0f;
		vx = 0.0f; vy = 1.0f;
	}
	if (Attacking_enemy->IsFacing() == 3) // prawo
	{
		x = Attacking_enemy->px + 1.0f;
		y = Attacking_enemy->py;
		vx = 1.0f; vy = 0.0f;
	}
	if (Attacking_enemy->IsFacing() == 1) //lewo
	{
		x = Attacking_enemy->px - 1.0f;
		y = Attacking_enemy->py;
		vx = -1.0f; vy = 0.0f;
	}

	

	

	if (Attacking_enemy->AktualneHP == Attacking_enemy->MaxHp)
	{
		// rzucanie mieczem
		dynamiczne_projectile* p = new dynamiczne_projectile(x, y, Attacking_enemy->_isFriendly, vx * 15.0f, vy * 15.0f, 1.0f, zawartosc::get().GetSprite("Basic Sword"), (Attacking_enemy->IsFacing() + 3) % 4 + 1, 1.0f);
		p->Hitbox_Vs_Map = true;
		p->ZadawanyDamage = 5;
		p->bOneHit = false;
		
		p->Hitbox_Vs_DynObj = false;
		automator_engine->AddProjectile(p);
	}

	dynamiczne_projectile* p = new dynamiczne_projectile(x, y, Attacking_enemy->_isFriendly, Attacking_enemy->vx, Attacking_enemy->vy, 0.1f, zawartosc::get().GetSprite("Basic Sword"), (Attacking_enemy->IsFacing() + 3) % 4 + 1, 0.0f);
	p->Hitbox_Vs_Map = false;
	p->bOneHit = true;
	p->ZadawanyDamage = 5;
	
	p->Hitbox_Vs_DynObj = false;
	automator_engine->AddProjectile(p);

	return false;
}
bool _Weapon1::OnInteract(dynamiczne* object)
{
	return false;
}

bool Przedmiot_Health::While_Used(dynamiczne* object)
{
	if (object != nullptr)
	{
		dynamiczne_creature* dyn = (dynamiczne_creature*)object;
		dyn->AktualneHP = min(dyn->AktualneHP + 1, dyn->MaxHp);
	}

	return true;
}

_Melee_Weapon::_Melee_Weapon() :
	_Weapon1("Basic Sword", zawartosc::get().GetSprite("Basic Sword")," desc", 5)
{

}