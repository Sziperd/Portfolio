#include "komendy.h"
#include "Glowny.h"
#include "Silnik_gry2.h"
#include "dynamiczne.h"


Glowny* komenda::automator_engine = nullptr;
extern clock_t TimeZero;
extern double deltaTime;

Procesor_Skryptu::Procesor_Skryptu()
{
	IsUserControlEnabled = true;
}

void Procesor_Skryptu::AddCommand(komenda* cmd)
{
	Lista_Komend.push_back(cmd);
}

void Procesor_Skryptu::ProcessCommands(float fElapsedTime)
{
	// jezeli komenda jest dostepna, odbierz graczowi mozliwosc ruchu
	IsUserControlEnabled = Lista_Komend.empty();

	if (!Lista_Komend.empty())
	{
		//komenda jest dostepna
		if (!Lista_Komend.front()->IsCompleted)
		{
			//komenda nie rozpoczela sie
			if (!Lista_Komend.front()->IsStarted)
			{
				Lista_Komend.front()->Start();
				Lista_Komend.front()->IsStarted = true;
			}
			else // komenda rozpoczela sie, zaaktualizuj
				Lista_Komend.front()->Update(fElapsedTime);
		}
		else
		{
			//komenda nie skonczyla sie jeszcze wiec
			delete Lista_Komend.front();
			Lista_Komend.pop_front();
		}
	}
}




// oznacza aktualnie aktywna komende jako skonczona
void Procesor_Skryptu::CompleteCommand()
{
	if (!Lista_Komend.empty())
	{
		Lista_Komend.front()->IsCompleted = true;
	}
}


komenda_AddMob::komenda_AddMob()
{

}



bool komenda_AddMob::AddMob(vector<dynamiczne*>& vecDyns)
{

	dynamiczne* g2 = new dynamiczne_Robot();
	vecDyns.push_back(g2);
	g2->px = rand() % 10 + 5.0f;
	g2->py = rand() % 10 + 5.0f;

	//delete(g2);

	return true;
}




komenda_DialogShowf::komenda_DialogShowf(vector<string> line)
{
	VectorLines = line;
}

void komenda_DialogShowf::Start()
{
	automator_engine->DialogShowf(VectorLines);
}


komenda_MapChangef::komenda_MapChangef(string mapName, float mapPosX, float mapPosY)
{
	_Nazwa_Mapy = mapName;
	//obvv
	_Map_PosX = mapPosX;



	_Map_PosY = mapPosY;
}


void komenda_MapChangef::Start()
{
	automator_engine->MapChangef(_Nazwa_Mapy, _Map_PosX, _Map_PosY);
	IsCompleted = true;
}

