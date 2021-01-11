#include "Mapa_gry.h"
#include <fstream> /
#include "komendy.h"
#include <time.h>
#include <chrono>
#include <ctime>
using namespace std;

extern clock_t TimeZero;
extern double deltaTime;


Procesor_Skryptu* Mapa_gry::Procesor_skryptu = nullptr;



Mapa_gry::Mapa_gry()
{

	_Solids = nullptr; // defaultowe wartosci startowe dla zmiennych;
	_Sprite = nullptr; // defaultowe wartosci startowe dla zmiennych;
	
	_Width = 0;
	_Height = 0;
	_Indices = nullptr;// defaultowe wartosci startowe dla zmiennych;
	
	g2 = nullptr;


}

Mapa_gry::~Mapa_gry()
{
	delete[] _Solids; // funckcje usuwajace wczesniej stworzone arraye
	delete[] _Indices; // funckcje usuwajace wczesniej stworzone arraye
	delete[] g2;



}



int Mapa_gry::GetIndex(int x, int y) // funkcja ta sprawdza czy poproszone koordynaty s¹ w zasiegu wielkosci mapy i zwraca odpowiedni indeks do arraya.
{
	if (x >= 0 && x < _Width && y >= 0 && y < _Height)
		return _Indices[y * _Width + x];
	else
		return 0; // to nie tylko zapobiega przed dostepem do pamieci do ktorej nie ma prawa a rowniez pomoze w rozwojowi programu (jesli cos bedzie nie tak to wyrenderuje sie kafelka z indeksem 0 co bedzie ostrzezeniem
}

bool Mapa_gry::GetSolid(int x, int y) // robi to samo co funkcja wyzej, tylko dla innego arraya
{
	if (x >= 0 && x < _Width && y >= 0 && y < _Height)
		return _Solids[y * _Width + x];
	else
		return true;
}


bool Mapa_gry::Create(string fileData, olcSprite* sprite, string name)
{

	_Nazwa = name; //lokalnie storowana nazwa oraz pointer do grafiki wiec teraz sa czescia klasy 'mapa_gry'
	_Sprite = sprite; // ^
	ifstream data(fileData, ios::in | ios::binary); //funckja ladujaca plik zawierajacy rozlozenie plytek na mapie i ich kolizyjnosc
	if (data.is_open())  // sprawdzanie czy plik zostal otwarty prawidlowo
	{
		data >> _Width >> _Height; // pokolei czytane sa liczby pierwsza to szerokosc druga to wysokosc stworzonej mapy
		_Solids = new bool[_Width * _Height]; // dwa arraye zawierajace informacje o kafelkach
		_Indices = new int[_Width * _Height];

		for (int i = 0; i < _Width * _Height; i++) // iterowanie przez plik z liczbami 
		{
			data >> _Indices[i]; // czytanie odpowiednich liczb do odpowiednich arrayow
			data >> _Solids[i];
		}

		return true;
	}
	//delete (data);
	return false;
}


Mapa22::Mapa22()
{

	Create("Mapy/start_room.lvl", zawartosc::get().GetSprite("startroom"), "home"); // "" getujemy""  jedna instacje, sprite o danej nazwie oraz rozlozenie kafelek o danej nazwie.
}




bool Mapa22::PopulatingMapf(vector<dynamiczne*>& vecDyns)
{

	vecDyns.push_back(new dynamiczne_Teleport(2.0f, 12.0f, "mainroom", 17.0f, 17.0f));
	//vecDyns.push_back(new dynamiczne_Teleport(2.0f, 14.0f, "mainroom", 17.0f, 17.0f));


	return true;
}

bool Mapa22::OnInteraction(vector<dynamiczne*>& vecDynobs, dynamiczne* target, ActionsATM ActionsATM)
{
	if (target->_Nazwa == "Teleport")
		Procesor_skryptu->AddCommand(new komenda_MapChangef(
			((dynamiczne_Teleport*)target)->_MapNamee,
			((dynamiczne_Teleport*)target)->X_MapPos,
			((dynamiczne_Teleport*)target)->Y_MapPos));

	return false;
}

Mapa11::Mapa11()
{                                                                                       
	Create("Mapy/vilage111.lvl", zawartosc::get().GetSprite("village"), "mainroom");  //wywolujemy funkcje,  "" getujemy""  jedna instacje, sprite o danej nazwie oraz rozlozenie kafelek o danej nazwie.
}


bool Mapa11::PopulatingMapf(vector<dynamiczne*>& vecDyns)
{
	// Nie chcemy mozliwosci powrotu do spawna
	//vecDyns.push_back(new dynamiczne_Teleport(16.0f, 14.0f, "home", 5.0f, 12.0f));
	//vecDyns.push_back(new dynamiczne_Teleport(16.0f, 13.0f, "home", 5.0f, 12.0f));

	

	for (int i = 0; i < 1; i++)
	{
		dynamiczne* g3 = new dynamiczne_Item(10, 10, zawartosc::get().GetItem("Health Up"));
		vecDyns.push_back(g3);
		g3->px = rand() % 11 + 11.0f;  // koordynaty x beda modulo losowej liczby dzielonej przez 8 dodac statyczne 5
		g3->py = rand() % 11 + 11.0f; // koordynaty y beda modulo losowej liczby dzielonej przez 8 dodac statyczne 5
	}


	for (int i = 0; i < 1; i++)
	{
		dynamiczne* g2 = new dynamiczne_Item(10, 10, zawartosc::get().GetItem("Health Potion"));
		vecDyns.push_back(g2);
		g2->px = rand() % 11 + 15.0f; // koordynaty x beda modulo losowej liczby dzielonej przez 8 dodac statyczne 5
		g2->py = rand() % 11 + 15.0f; // koordynaty y beda modulo losowej liczby dzielonej przez 8 dodac statyczne 5
		//delete[] g2;
	}

	for (int i = 0; i < 1; i++)
	{

		dynamiczne* g1 = new dynamiczne_Robot();
		vecDyns.push_back(g1);
		g1->px = rand() % 8 +	15.0f; // koordynaty x beda modulo losowej liczby dzielonej przez 8 dodac statyczne 5
		g1->py = rand() % 8 + 15.0f; // koordynaty y beda modulo losowej liczby dzielonej przez 8 dodac statyczne 5
	}
	
	float secondsToDelay = 1;
	deltaTime = (clock() - TimeZero) / (CLOCKS_PER_SEC / 24);
	if (deltaTime > secondsToDelay)
	{


		dynamiczne* g2 = new dynamiczne_Robot();
		vecDyns.push_back(g2);
		g2->px = rand() % 10 + 5.0f;
		g2->py = rand() % 10 + 5.0f;
		
		TimeZero = clock();
	}
	/*else if (deltaTime > 10)
	{
		delete[] (g2);
	}
	*/

	return true;


	
	

}

bool Mapa11::OnInteraction(vector<dynamiczne*>& vecDynobs, dynamiczne* target, ActionsATM ActionsATM)
{
	if (target->_Nazwa == "Teleport")
		Procesor_skryptu->AddCommand(new komenda_MapChangef(
			((dynamiczne_Teleport*)target)->_MapNamee,
			((dynamiczne_Teleport*)target)->X_MapPos,
			((dynamiczne_Teleport*)target)->Y_MapPos));

	return false;
}

