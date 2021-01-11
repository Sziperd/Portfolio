#pragma once


#include "Silnik_gry2.h"
#include <map>

class Mapa_gry;
class Przedmiot;



class zawartosc
{
public:
	static zawartosc& get() // ta funkcja bedzie zwracac sie sama 
	{
		static zawartosc me;
		return me;
	}

	//Generalnie jest to singleton czyli cos co ogranicza maksymalna ilosc instancji obiektu .

	zawartosc(zawartosc const&) = delete; //pozbywam sie defaultowego copy konstruktora tworzonego przez compiler aby uniknac reloadowania grafik (zawartosci) w kolko. Tylko raz na starcie programu.
	void operator=(zawartosc const&) = delete; // to samo ^^ tylko dla load operatora. Chcemy zeby grafiki ladowaly sie raz

	Przedmiot* GetItem(string name)
	{
		return container_Items[name];
	}
	olcSprite* GetSprite(string name)
		{
		return container_Sprites[name];
		}

	Mapa_gry* GetMap(string name)
	{
		return container_Maps[name];
	}
	


	void LoadSprites(); // ladujemy grafiki
	void LoadMaps(); // ladujemy ulozenie map
	void LoadItems(); // ladujemy ulozenie itemow

private:

	zawartosc(); // sa prywatne aby uzytkownik nie mogl directly stworzyc kopii singletona 
	~zawartosc();



	// tak zwany container na wszystkie grafiki mapy oraz przedmioty.
	map<string, olcSprite*> container_Sprites;  // mapy to troche jak arraye, zamiast uzywac liczb na indeksowanie miejsca w arrayu mozemy uzywac innych objektow.  
	map<string, Mapa_gry*> container_Maps;    // w tym przypadku mozemy pokusic sie na uzywanie map zamiast arrayow poniewaz dostep do grafik nie jest czesty, raczej jednorazowy wiec 
	map<string, Przedmiot*> container_Items;  // nie obnizy to wydajnosci programu / komputera. Benefitem uzywania map bedzie przyjazne nazewnictwo w calym programie. 
};   // wiec generalnie w przyszlosci bedziemy uzywac nazw jako indeksu mapy zamiast liczb.

