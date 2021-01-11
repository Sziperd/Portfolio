#include "Glowny.h"


#include <iostream>
#include <string>
using namespace std;
extern clock_t TimeZero;
extern double deltaTime;
#include "dynamiczne.h"
#include "Glowny.h"
#include "Silnik_gry2.h"


	Glowny::Glowny()
	{
		m_sAppName = L"Projekt Semestralny CP";
	}

	

	void Glowny::Show_textf(string sText, int x, int y) // funkcja wyswietlajaca grafiki liter (szczytujaca je z pliku graficznego)
	{
		//grafika czcionki zostala ulozona 8x8 pix na litere  tak aby lokacja indeksu grafiki laczyla sie z lokalizacja ASCII
		int i = 0;
		for (auto c : sText)
		{
			int sx = ((c - 32) % 16) * 8; // wiec podozajac za ustwieniem pojedynczych grafik na tak zwanym sprite sheet 
			int sy = ((c - 32) / 16) * 8; // ustalam koordynaty poszczegolnych indeksow w pliku graficznym wzgledem pixeli 
			SpriteDraw_partial(x + i * 8, y, _TextFont, sx, sy, 8, 8); // funkcja rysujaca litery w okreslonych koordynatach x i y 
			i++;                                                      // ta funkcja jest zawarta w silniku gry.
		}

	}

	bool Glowny::While_UsedrCreate()


	{
		
		komenda::automator_engine = this;
		Mapa_gry::Procesor_skryptu = &_Skrypty;
		
		dynamiczne::automator_engine = this;
		Przedmiot::automator_engine = this;
	
        zawartosc::get().LoadSprites(); // metody directly zaaplikowane do klasy
		zawartosc::get().LoadMaps();  // cala grafika mapy itemy zostaja zaladowane do gry naraz.
		zawartosc::get().LoadItems(); // poniewaz gra jest mala to mozemy zaladowac wszystko naraz przy wlaczaniu gry.
		// gdyby byla wieksza zastanawialbym sie nad procedurami ladowania danych grafik map etc.
		
		
		
		_TextFont = zawartosc::get().GetSprite("font");

		_Player_1 = new dynamiczne_Creature_player();

		_ItemList.push_back(zawartosc::get().GetItem("Basic Sword"));


		MapChangef("home", 5, 5); // miejsce spawnu gracze

		return true;
	}

	  bool Glowny::While_UsedrUpdate(float fElapsedTime)
	  {
		switch (_GameMode)
		{
		
		case _ACTUAL_MAP_MODE:
			return UpdateLocalMap(fElapsedTime);
			
		case _INVENTORY_MODE:
			return UpdateInventory(fElapsedTime);
			
		}

		return true;
	   }


	bool Glowny::UpdateLocalMap(float fElapsedTime)
	{
		float secondsToDelay = 10;
		deltaTime = (clock() - TimeZero) / (CLOCKS_PER_SEC / 4);
		if (deltaTime > secondsToDelay)
		{


			_CurrentLoadedMap->PopulatingMapf(_vectorDynamics);

			TimeZero = clock();
		}
		
		_Skrypty.ProcessCommands(fElapsedTime);


		// Erase and delete redundant projectiles	
		_vectorProjectiles.erase(
			remove_if(_vectorProjectiles.begin(), _vectorProjectiles.end(),
				[](const dynamiczne* d) {return ((dynamiczne_projectile*)d)->_isRedundant; }), _vectorProjectiles.end());

		


		if (_Skrypty.IsUserControlEnabled) // if sprawdzajacy czy postac w ogole moze sie ruszac, jesli tak to:
		{

			_Player_1->vx = 0.0f; // tak zwane velocity x i y czyli predkosc gracza bazowo gdy nic sie nie dzieje ustawiam na 0
			_Player_1->vy = 0.0f;
			if (!_Dialog_Show && _Player_1->_Controlable)
			{

				// input
				if (IsFocused())
				{
					if (GetKey(VK_UP).bHeld)
					{
						_Player_1->vy = -4.0f;
					}

					if (GetKey(VK_DOWN).bHeld)
					{
						_Player_1->vy = 4.0f;
					}

					if (GetKey(VK_LEFT).bHeld)
					{
						_Player_1->vx = -4.0f;
					}

					if (GetKey(VK_RIGHT).bHeld)
					{
						_Player_1->vx = 4.0f;
					}

					if (GetKey(L'E').IsReleased)
						_GameMode = _INVENTORY_MODE;

					if (GetKey(VK_SPACE).IsReleased) //jesli interakcja zostala zrequestowana
					{
						//sprawdzanie interakcji wzgledem strony odwrocenia gracza										
						float fTestX, fTestY;

						if (_Player_1->IsFacing() == 0) // dol
						{
							fTestX = _Player_1->px + 0.5f;
							fTestY = _Player_1->py + 1.5f;
						}

						if (_Player_1->IsFacing() == 1) // lewo
						{
							fTestX = _Player_1->px - 0.5f;
							fTestY = _Player_1->py + 0.5f;
						}

						if (_Player_1->IsFacing() == 2) // gora
						{
							fTestX = _Player_1->px + 0.5f;
							fTestY = _Player_1->py - 0.5f;
						}

						if (_Player_1->IsFacing() == 3) // prawo
						{
							fTestX = _Player_1->px + 1.5f;
							fTestY = _Player_1->py + 0.5f;
						}

						//sprawdzanie czy zostalo uderzone cos
						bool _IsHittingAnything = false;

						for (auto dyns : _vectorDynamics)
						{//hitboxy uderzenia
							if (fTestX > dyns->px && fTestX < (dyns->px + 1.0f) && fTestY > dyns->py && fTestY < (dyns->py + 1.0f))
							{
								if (dyns->_isFriendly)
								{
									_IsHittingAnything = true;

									
									// interakcje dynamicznych rzeczy z graczem
									dyns->OnInteract(_Player_1);

									//sprawdzanie czy odnosi sie do mapy
									_CurrentLoadedMap->OnInteraction(_vectorDynamics, dyns, Mapa_gry::IsIdle);
								}
								else
								{
									//interakcja z czyms co nie jest friendly oznacza atak.
									_Player_1->Attack_Perform();
								}
							}
						}

						if (!_IsHittingAnything) // atak
						{
							_Player_1->Attack_Perform();
						}

				
					}
					if (GetKey(L'P').IsReleased)
					{
						
						return false;
						

					}


					if (GetKey(L'M').IsReleased)
					{
						
						_CurrentLoadedMap->PopulatingMapf(_vectorDynamics);
						
					}

				}
			}
		}
		else
		{
			// System skryptu kontroluje
			if (_Dialog_Show)
			{ // to jest zabezpieczenie, jesli istnieje dialog to moze zostac pominiety nacisnieciem spacji .
				if (GetKey(VK_SPACE).IsReleased)
				{
					_Dialog_Show = false;
					_Skrypty.CompleteCommand();
				}
			}
		}




		bool Works_with_Projectile = false;
		for (auto& source : { &_vectorDynamics, &_vectorProjectiles })
		{

		for (auto& object : *source)
		{

			float New_Obj_PosX = object->px + object->vx * fElapsedTime;
			float New_Obj_PosY = object->py + object->vy * fElapsedTime;


			
			bool HasMapCollision = false;

			// Kolizja
			if (object->vx <= 0)
			{
				if (_CurrentLoadedMap->GetSolid(New_Obj_PosX + 0.0f, object->py + 0.0f) || _CurrentLoadedMap->GetSolid(New_Obj_PosX + 0.0f, object->py + 0.9f))
				{
					New_Obj_PosX = (int)New_Obj_PosX + 1;
					object->vx = 0;
					HasMapCollision = true;
				}
			}
			else
			{
				if (_CurrentLoadedMap->GetSolid(New_Obj_PosX + 1.0f, object->py + 0.0f) || _CurrentLoadedMap->GetSolid(New_Obj_PosX + 1.0f, object->py + 0.9f))
				{
					New_Obj_PosX = (int)New_Obj_PosX;
					object->vx = 0;
					HasMapCollision = true;

				}
			}

			if (object->vy <= 0)
			{
				if (_CurrentLoadedMap->GetSolid(New_Obj_PosX + 0.0f, New_Obj_PosY) || _CurrentLoadedMap->GetSolid(New_Obj_PosX + 0.9f, New_Obj_PosY))
				{
					New_Obj_PosY = (int)New_Obj_PosY + 1;
					object->vy = 0;
					HasMapCollision = true;
				}
			}
			else
			{
				if (_CurrentLoadedMap->GetSolid(New_Obj_PosX + 0.0f, New_Obj_PosY + 1.0f) || _CurrentLoadedMap->GetSolid(New_Obj_PosX + 0.9f, New_Obj_PosY + 1.0f))
				{
					New_Obj_PosY = (int)New_Obj_PosY;
					object->vy = 0;
					HasMapCollision = true;
				}
			}


			if (object->_isAprojectile && HasMapCollision)
			{
				object->_isRedundant = true;
			}

			float X_Pos_Of_DynObj = New_Obj_PosX;
			float Y_Pos_Of_DynObj = New_Obj_PosY;



			for (auto& dyn : _vectorDynamics)
			{
				if (dyn != object)
				{
					//jesli objekt ma hitbox to gracz nie moze na niego nachodzic
					if (dyn->Hitbox_Vs_DynObj && object->Hitbox_Vs_DynObj)
					{
						// sprawdzam czy ograniczajace prostokaty nachodza na siebie
						if (X_Pos_Of_DynObj < (dyn->px + 1.0f) && (X_Pos_Of_DynObj + 1.0f) > dyn->px &&
							object->py < (dyn->py + 1.0f) && (object->py + 1.0f) > dyn->py)
						{
							// Sprawdzam  horyzontalnie w lewo
							if (object->vx <= 0)
								X_Pos_Of_DynObj = dyn->px + 1.0f;
							else
								X_Pos_Of_DynObj = dyn->px - 1.0f;
						}

						if (X_Pos_Of_DynObj < (dyn->px + 1.0f) && (X_Pos_Of_DynObj + 1.0f) > dyn->px &&
							Y_Pos_Of_DynObj < (dyn->py + 1.0f) && (Y_Pos_Of_DynObj + 1.0f) > dyn->py)
						{

							// Sprawdzam wertykalnie w lewo
							if (object->vy <= 0)
								Y_Pos_Of_DynObj = dyn->py + 1.0f;
							else
								Y_Pos_Of_DynObj = dyn->py - 1.0f;
						}

					}
					else
					{
						if (object == _vectorDynamics[0])
						{
							// gracz jest obiektem i moze interakcjonowac z rzeczami, tutaj sa hitboxy interakcji
							if (X_Pos_Of_DynObj < (dyn->px + 1.0f) && (X_Pos_Of_DynObj + 1.0f) > dyn->px &&
								object->py < (dyn->py + 1.0f) && (object->py + 1.0f) > dyn->py)
							{


								// jezeli to interakcja z mapa, sprawdz:
								_CurrentLoadedMap->OnInteraction(_vectorDynamics, dyn, Mapa_gry::IsWalking);

								
								//sprawdzanie czy objekt interakcjonuje
								dyn->OnInteract(object);

							}
						}
						else
						{
							if (Works_with_Projectile)
							{ //pozycjonowanie
								if (X_Pos_Of_DynObj < (dyn->px + 1.0f) && (X_Pos_Of_DynObj + 1.0f) > dyn->px &&

									Y_Pos_Of_DynObj < (dyn->py + 1.0f) && (Y_Pos_Of_DynObj + 1.0f) > dyn->py)
								{
									if (dyn->_isFriendly != object->_isFriendly)
									{
										//objektem jest wystrzelona rzecz											
										if (dyn->_IsAttackable)//sprawdzamy czy wystrzelona rzecz (dyn) najechala na coœ
										{ //w skrocie jesli dyn nachodzi na cos = robi DMG
											
											Damage((dynamiczne_projectile*)object, (dynamiczne_creature*)dyn); //przeciwnik jest dynamicznym obiektem
										}
									}
								}
							}


						}

					}
				}
			}



			object->px = X_Pos_Of_DynObj;
			object->py = Y_Pos_Of_DynObj;

			
		}

		Works_with_Projectile = true;
	


      }



	   for (auto& source : { &_vectorDynamics, &_vectorProjectiles })
		for (auto& dyns : *source)
			dyns->Update(fElapsedTime, _Player_1);

		//lockowanie kamery na graczu
		_CameraPosX = _Player_1->px;
		_CameraPosY = _Player_1->py;

		// rysowanie poziomu
		int _Width_Tile = 16;
		int _Height_Tile = 16;
		int X_Tiles_Visible = Scree_Width() / _Width_Tile;
		int Y_Tiles_Visible = Scree_Height() / _Height_Tile;

		// kalkulacja offsetu
		float X_Offset = _CameraPosX - (float)X_Tiles_Visible / 2.0f;
		float Y_Offset = _CameraPosY - (float)Y_Tiles_Visible / 2.0f;

		// lockowanie kamery 
		if (X_Offset < 0) X_Offset = 0;
		if (Y_Offset < 0) Y_Offset = 0;
		if (X_Offset > _CurrentLoadedMap->_Width - X_Tiles_Visible) X_Offset = _CurrentLoadedMap->_Width - X_Tiles_Visible;
		if (Y_Offset > _CurrentLoadedMap->_Height - Y_Tiles_Visible) Y_Offset = _CurrentLoadedMap->_Height - Y_Tiles_Visible;

		// offsety dla movementu
		float X_Tiles_Offset = (X_Offset - (int)X_Offset) * _Width_Tile;
		float Y_Tiles_Offset = (Y_Offset - (int)Y_Offset) * _Height_Tile;

		// rysuje mape zlozona z TILESOW
		for (int x = -1; x < X_Tiles_Visible + 1; x++)
		{
			for (int y = -1; y < Y_Tiles_Visible + 1; y++)
			{
				int idx = _CurrentLoadedMap->GetIndex(x + X_Offset, y + Y_Offset);
				int sx = idx % 10;
				int sy = idx / 10;

				SpriteDraw_partial(x * _Width_Tile - X_Tiles_Offset, y * _Height_Tile - Y_Tiles_Offset, _CurrentLoadedMap->_Sprite, sx * _Width_Tile, sy * _Height_Tile, _Width_Tile, _Height_Tile);



			}
		}

		
		// rysowanie obiektu
		for (auto& source : { &_vectorDynamics, &_vectorProjectiles })
			for (auto& dyns : *source)
			dyns->RenderSelf(this, X_Offset, Y_Offset + 1); //TUTAJ HITBOX PLAYERA ZMIENILEM dodajac +1

		_Player_1->RenderSelf(this, X_Offset, Y_Offset + 1);
		
		string sHealth = "HP: " + to_string(_Player_1->AktualneHP) + "/" + to_string(_Player_1->MaxHp);
		string RoundCount = "Round:" + to_string(_Player_1->AktualnaRunda);
		string RoundCountDead1 = "You lived:"; 
		string RoundCountDead2 = to_string(_Player_1->AktualnaRunda) + " rounds";
		DialogDisplayf({ RoundCount }, 70, 3);
		DialogDisplayf({ sHealth }, 3, 3);
		string quit = "Press'P'to quit";


		if (_Player_1->AktualneHP < 1)
		{
			Show_textf("You died", 30, 40);
			Show_textf("Game over gamer", 5, 70);
			DialogDisplayf({ RoundCountDead1}, 25, 85);
			DialogDisplayf({ RoundCountDead2 }, 30, 100);
			//Show_textf("press P to quit", 5, 110);
			DialogDisplayf({ quit }, 3, 3);

			if (GetKey(L'P').IsReleased)
			{

				return false;


			}
		}
		if (_Dialog_Show)
			DialogDisplayf(_vectorDialogShowf, 10, 10);


		
		return true;
	}



	void Glowny::DialogShowf(vector<string> VectorLines)
	{
		_vectorDialogShowf = VectorLines;
		_Dialog_Show = true;

	}
	
	void Glowny::DialogDisplayf(vector<string> vecText, int x, int y)
	{
		int _LineLengthMax = 0;
		int Box_Lines = vecText.size();

		for (auto l : vecText)	if (l.size() > _LineLengthMax) _LineLengthMax = l.size();

		// rysuje boxa 
		Fill(x - 1, y - 1, x + _LineLengthMax * 8 + 1, y + Box_Lines * 8 + 1, PIXEL_SOLID, FG_DARK_BLUE);//kolor tla
		//rysowanie obramowan tekstu
		LineDrawf(x - 2, y - 2, x - 2, y + Box_Lines * 8 + 1);
		//linie beda tak dlugie jak napisany tekst
		LineDrawf(x + _LineLengthMax * 8 + 1, y - 2, x + _LineLengthMax * 8 + 1, y + Box_Lines * 8 + 1);
		//f 22 8
		LineDrawf(x - 2, y - 2, x + _LineLengthMax * 8 + 1, y - 2);
		LineDrawf(x - 2, y + Box_Lines * 8 + 1, x + _LineLengthMax * 8 + 1, y + Box_Lines * 8 + 1);

		for (int l = 0; l < vecText.size(); l++)
			Show_textf(vecText[l], x, y + l * 8);
	}
	


	void Glowny::MapChangef(string _MapNamee, float x, float y)
	{
		//czysci wszystki dynamiczne rzeczy
		_vectorDynamics.clear();
		_vectorDynamics.push_back(_Player_1);

		//ustawia aktualna mape
		_CurrentLoadedMap = zawartosc::get().GetMap(_MapNamee);

		// Odswiezanie lokalizacji gracza
		_Player_1->px = x;
		_Player_1->py = y;

		
		_CurrentLoadedMap->PopulatingMapf(_vectorDynamics);// Place'uje dynamiczne rzeczy z map (Teleporty, potiony etc.)

	
	}
	

	

	bool Glowny::TakeItem(Przedmiot* item)
	{
		if (item != nullptr)
		{
			_ItemList.erase(find(_ItemList.begin(), _ItemList.end(), item));
			return true;
		}
		else
			return false;
	}

	bool Glowny::GiveItem(Przedmiot* item)
	{

		_ItemList.push_back(item);
		return true;
	}

	bool Glowny::HasItem(Przedmiot* item)
	{
		if (item != nullptr)
			return find(_ItemList.begin(), _ItemList.end(), item) != _ItemList.end();
		else
			return false;
	}




	bool Glowny::UpdateInventory(float fElapsedTime)
	{
		Fill(0, 0, Scree_Width(), Scree_Height(), L' ');
		Show_textf("ITEMS", 4, 4);


		int i = 0;
		Przedmiot* _Podswietlony = nullptr;

		
		for (auto& item : _ItemList) // Rysuje rzeczy do podniesienia
		{
			int x = i % 4;
			int y = i / 4;
			i++;

			SpriteDraw_partial(8 + x * 20, 20 + y * 20, item->_Sprite, 0, 0, 16, 16);

			if (_Inventory_X == x && _Inventory_Y == y)
				_Podswietlony = item;
		}

		// Rysowanie grida wyboru itemow
		//
		LineDrawf(6 + (_Inventory_X) * 20, 18 + (_Inventory_Y) * 20, 6 + (_Inventory_X + 1) * 20, 18 + (_Inventory_Y) * 20);
		LineDrawf(6 + (_Inventory_X) * 20, 18 + (_Inventory_Y + 1) * 20, 6 + (_Inventory_X + 1) * 20, 18 + (_Inventory_Y + 1) * 20);
		LineDrawf(6 + (_Inventory_X) * 20, 18 + (_Inventory_Y) * 20, 6 + (_Inventory_X) * 20, 18 + (_Inventory_Y + 1) * 20);
		LineDrawf(6 + (_Inventory_X + 1) * 20, 18 + (_Inventory_Y) * 20, 6 + (_Inventory_X + 1) * 20, 18 + (_Inventory_Y + 1) * 20);
		
		
		if (GetKey(VK_UP).IsReleased)	_Inventory_Y--;
		if (GetKey(VK_LEFT).IsReleased)	_Inventory_X--;
		
		if (GetKey(VK_DOWN).IsReleased)	_Inventory_Y++;
		if (GetKey(VK_RIGHT).IsReleased)	_Inventory_X++;


		if (_Inventory_Y >= 4) _Inventory_Y = 0;
		if (_Inventory_X >= 4) _Inventory_X = 0;
		if (_Inventory_Y < 0) _Inventory_Y = 3;
		
		if (_Inventory_X < 0) _Inventory_X = 3;
		if (GetKey(L'E').IsReleased)
			//naciskamy e zeby wyjsc tez
			_GameMode = _ACTUAL_MAP_MODE;

	

		if (_Podswietlony != nullptr)
		{
		
			if (GetKey(VK_SPACE).IsReleased)
			{
				// Uzyj podswietlonego (wybranego) itemu
				if (!_Podswietlony->PodswietlonyItem)
				{
					if (_Podswietlony->While_Used(_Player_1))//co sie dzieje kiedy uzyje itema
					{
						
						TakeItem(_Podswietlony); //usuwanie uzytego itema
					}
				}
				else
				{
					//nic
				}
			}
		}
		return true;
	}

	void Glowny::Attack(dynamiczne_creature* Attacking_enemy, _Weapon1* weapon)
	{
		weapon->While_Used(Attacking_enemy);
	}




	void Glowny::Damage(dynamiczne_projectile* projectile, dynamiczne_creature* _ofiara)
	{
		if (_ofiara != nullptr)
		{
			
			_ofiara->AktualneHP -= projectile->ZadawanyDamage; //atakowanie ofiary dmg


			// knockback po uderzeniu
			float tx = _ofiara->px - projectile->px;
			float ty = _ofiara->py - projectile->py;
			float d = sqrtf(tx * tx + ty * ty);
			if (d < 1) d = 1.0f;

			_ofiara->KnockBack(tx / d, ty / d, 0.2f);

			if (_ofiara != _Player_1)
			{
				_ofiara->OnInteract(_Player_1);
			}
			else
			{
				_ofiara->Hitbox_Vs_DynObj = true; //funkcja zapobiegajaca wyrzuceniu poza mape (czy stale objekty po prostu)
			}


			if (projectile->bOneHit)
				projectile->_isRedundant = true;
		}
	}

	void Glowny::AddProjectile(dynamiczne_projectile* proj)
	{
		_vectorProjectiles.push_back(proj);
	}