#include "dynamiczne.h"
#include "Silnik_gry2.h"
#include "Glowny.h"


Glowny* dynamiczne::automator_engine = nullptr;

dynamiczne::dynamiczne(string n)
{
	_Nazwa = n;

	Hitbox_Vs_Map = true;
	Hitbox_Vs_DynObj = true;

	px = 0.0f;
	py = 0.0f;
	

	_isFriendly = true;

	vx = 0.0f;
	vy = 0.0f;
}

dynamiczne::~dynamiczne()
{

}

dynamiczne_creature::dynamiczne_creature(string name, olcSprite* sprite) : dynamiczne(name)
{
	
	_Timerr = 0.0f;
	AktualneHP = 10;
	MaxHp = 10;
	IsAlive = true;
	_Is_Facing_directionn = SOUTH;
	_Is_doing = STANDING;
	
	_spritesheet_graph_counter = 0;
	_IsAttackable = true;
	_Sprite_rend = sprite;
}

void dynamiczne_creature::Update(float fElapsedTime, dynamiczne* player)
{
	AktualnaRunda = 0;
	AktualnaRunda = RoundCounter/1000;

	if (AktualneHP > 1)
	{
						if (_Time_KnockBack > 0.0f)
					    {
								
								vy = _KnockBack_Coords_Y * 10.0f;
								_IsAttackable = false;
								vx = _KnockBack_Coords_X * 10.0f;
								_Time_KnockBack -= fElapsedTime;
								if (_Time_KnockBack <= 0.0f)
								{
									_IsAttackable = true;
									_StateTick = 0.0f;
									_Controlable = true;
									
								}

					    }
						else
					    {
								Hitbox_Vs_DynObj = true;
								_Timerr += fElapsedTime;
								if (_Timerr >= 0.2f)
								{
									_Timerr -= 0.15f;
									_spritesheet_graph_counter++;
									_spritesheet_graph_counter %= 4;
								}

								if (fabs(vx) > 0 || fabs(vy) > 0)
									_Is_doing = WALKING;
								else
									_Is_doing = STANDING;

								//if (AktualneHP <= 0)
									
								if (vy < -0.0f) _Is_Facing_directionn = NORTH;
								if (vx < 0.0f) _Is_Facing_directionn = WEST;
								
								
								if (vy > 0.0f) _Is_Facing_directionn = SOUTH;
								if (vx > 0.0f) _Is_Facing_directionn = EAST;
								EntityBehaviour(fElapsedTime, player);
						}
    }
	else
	{
		vx = 0;
		vy = 0;
		_Is_doing = DEAD;
	}


	
}

void dynamiczne_creature::RenderSelf(olcConsoleGameEngineOOP* gfx, float ox, float oy)
{
	int SpritesheetOffsetX = 0;
		int SpritesheetOffsetY = 0;





		switch (_Is_doing)
		{
		case STANDING:
			SpritesheetOffsetX = 4 * 16;
			break;

	

		case OTHER:
			SpritesheetOffsetX = 4 * 16;
			break;

		case WALKING:
			RoundCounter += 1;
			SpritesheetOffsetX = _Is_Facing_directionn * 16;
			SpritesheetOffsetY = _spritesheet_graph_counter * 32;

			break;
		case DEAD:
			SpritesheetOffsetX = 4 * 16;
				SpritesheetOffsetY = 1 * 32;
				break;



		}



		gfx->SpriteDraw_partial((px - ox) * 16.0f, (py - oy) * 16.0f, _Sprite_rend, SpritesheetOffsetX, SpritesheetOffsetY, 16, 32);
}




dynamiczne_Teleport::dynamiczne_Teleport(float x, float y, string mapName, float tx, float ty) : dynamiczne("Teleport")
{
	px = x;
	py = y;
	X_MapPos = tx;
	Y_MapPos = ty;
	_MapNamee = mapName;
	Hitbox_Vs_DynObj = false;
	Hitbox_Vs_Map = false;
}

void dynamiczne_Teleport::RenderSelf(olcConsoleGameEngineOOP* gfx, float ox, float oy)
{
	//nic
	//gfx->DrawCircle(((px + 0.5f) - ox) * 16.0f, ((py + 0.5f) - oy) * 16.0f, 0.5f * 16.0f); // do debuggu
}

void dynamiczne_Teleport::Update(float fElapsedTime, dynamiczne* player)
{
	//narazie nic
}

dynamiczne_Robot::dynamiczne_Robot() : dynamiczne_creature("przeciwnik", zawartosc::get().GetSprite("przeciwnik"))
{
	_isFriendly = false;
	AktualneHP = 10;
	MaxHp = 10;
	_StateTick = 2.0f;

	Weapon_Equiped = (_Weapon1*)zawartosc::get().GetItem("Basic Sword");


}

void dynamiczne_creature::EntityBehaviour(float fElapsedTime, dynamiczne* player)
{

}





dynamiczne_Creature_player::dynamiczne_Creature_player() : dynamiczne_creature("player", zawartosc::get().GetSprite("player"))
{
	_isFriendly = true;
	AktualneHP = 9;
	MaxHp = 10;
	_StateTick = 2.0f;
	Weapon_Equiped = (_Weapon1*)zawartosc::get().GetItem("Basic Sword");


}



void dynamiczne_Creature_player::Attack_Perform()
{
	if (Weapon_Equiped == nullptr)
		return;

	Weapon_Equiped->While_Used(this);

}





void dynamiczne_Robot::Attack_Perform()
{
	if (Weapon_Equiped == nullptr)
		return;

	Weapon_Equiped->While_Used(this);
}

void dynamiczne_creature::KnockBack(float dx, float dy, float dist)
{
	_KnockBack_Coords_X = dx;
	_KnockBack_Coords_Y = dy;
	_Time_KnockBack = dist;
	Hitbox_Vs_DynObj = false;
	_Controlable = false;
	_IsAttackable = false;
}



dynamiczne_projectile::dynamiczne_projectile(float ox, float oy, bool bFriend, float velx, float vely, float duration, olcSprite* sprite, float tx, float ty) : dynamiczne("projectile")
{
	_Sprite = sprite;
	_SpriteX_leng = tx;
	_SpriteY_leng = ty;
	_Durationn = duration;
	px = ox;
	py = oy;
	vx = velx;
	vy = vely;
	Hitbox_Vs_DynObj = false;
	Hitbox_Vs_Map = true;
	_isAprojectile = true;
	_IsAttackable = false;
	_isFriendly = bFriend;
}

void dynamiczne_projectile::RenderSelf(olcConsoleGameEngineOOP* gfx, float ox, float oy)
{
	gfx->SpriteDraw_partial((px - ox) * 16, (py - oy) * 20, _Sprite, _SpriteX_leng * 16, _SpriteY_leng * 16, 16, 16);





}


void dynamiczne_projectile::Update(float fElapsedTime, dynamiczne* player)
{
	_Durationn -= fElapsedTime;
	if (_Durationn <= 0.0f)
		_isRedundant = true;
}


dynamiczne_Item::dynamiczne_Item(float x, float y, Przedmiot* i) : dynamiczne("pickup")
{
	px = x;
	py = y;
	Hitbox_Vs_DynObj = false;
	Hitbox_Vs_Map = false;
	_isFriendly = true;
	_IsCollected = false;
	item = i;
}

void dynamiczne_Item::RenderSelf(olcConsoleGameEngineOOP* gfx, float ox, float oy)
{
	if (_IsCollected)
		return;

	gfx->SpriteDraw_partial((px - ox) * 16.0f, (py - oy) * 16.0f, item->_Sprite, 0, 0, 16, 16);
}

void dynamiczne_Item::OnInteract(dynamiczne* player)
{
	if (_IsCollected)
		return;

	if (item->OnInteract(player))
	{
		//dodaj przedmiot to schowka
		automator_engine->GiveItem(item);
	}

	_IsCollected = true;
}

void dynamiczne_Robot::EntityBehaviour(float fElapsedTime, dynamiczne* player)
{


	//AktualnaRunda = fElapsedTime;
	float X_Target_coord = player->px - px;
	float Y_Target_coord = player->py - py;
	float fDistance = sqrtf(X_Target_coord * X_Target_coord + Y_Target_coord * Y_Target_coord);
	_StateTick -= fElapsedTime;
	if (_StateTick <= 0.0f)
	{

		if (fDistance < 6.0f)
		{
			
			vy = (Y_Target_coord / fDistance) * 2.0f;
			vx = (X_Target_coord / fDistance) * 2.0f;
			if (fDistance < 1.5f)
				Attack_Perform();

		}
		else
		{
			
			vy = 0;
			vx = 0;
		}
		_StateTick += 1.0f;
	}
}