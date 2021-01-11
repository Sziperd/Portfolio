#include "Glowny.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>



clock_t TimeZero; //dostep do clocka systemowego aby gra dzialala w takiej samej predkosci na szybszym jak i wolniejszym sprzecie oraz aby mozliwe bylo losowanie liczby (potrzebne do ruchow NPC)
double deltaTime = 0;

int main()
{


	_CrtDumpMemoryLeaks();
	
	Glowny game;
	if (game.ConstructConsole(128, 120, 5, 5))   
	//if (game.ConstructConsole(256, 240, 4, 4))
		game.Start();
	
	_CrtDumpMemoryLeaks();
	
	return 0;
}