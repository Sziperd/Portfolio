
//Projekt Semestraly, Patryk Piwowarczyk Makrokierunek sem2, PACMAN
// Disclaimer:
// ----------
//
//
// Włączając grę na systemie macos trzeba uprzednio dać jej uprawnienia do korzystania z klawiatury.  Ustawienia -> Ochrona i prywatność -> monitorowanie wprowadzania -> Pacman Semestralny
//
//

// Możliwe jest, że potrzebne będzie ustalenie własnych ścieżek dla obrazków (grafik) elementów znajdujacych sie w grze. (tak naprawde sciezka moze sie roznic jej poczatkiem tylko.
//
//
//
//
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>

#include "ResourcePath.hpp"
#include "Entity.hpp"
#include <iostream>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Enemy2.hpp"
#include "Enemy3.hpp"
#include "Enemy4.hpp"
#include "Enemy5.hpp"
#include "Enemy6.hpp"
#include "Platform.hpp"
#include <vector>
#include "coin.hpp"
using namespace std;
using namespace sf;
const int windowWidth = 1500;
const int windowHeight = 1500;  //rozmiary okienka w którym wyświetlana będzie gra.

bool deleteSprite;

float accelGravity= 0.2f; // wartość przyspieszenia
float maxGravity= 5.f; //wartość grawitacji

clock_t TimeZero; //dostep do clocka systemowego aby gra dzialala w takiej samej predkosci na szybszym jak i wolniejszym sprzecie oraz aby mozliwe bylo losowanie liczby (potrzebne do ruchow NPC)
double deltaTime = 0;
 int iRand;


int levelArray[21][21] = {  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                               {1,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,1},
                               {1,2,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1},
                               {1,0,1,1,1,0,1,0,0,0,0,0,0,0,1,0,1,1,1,0,1},
                               {1,0,1,1,1,0,1,0,1,1,0,1,1,0,1,0,1,1,1,0,1},
                               {1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1},
                               {1,0,1,0,1,0,1,1,1,1,0,1,1,1,1,0,1,0,1,0,1},   // Miejsca w których znaleźć sie maja sciany w siatce
                               {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                               {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
                               {1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1},
                               {1,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,1},
                               {1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1},
                               {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                               {1,0,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1},
                               {1,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,1},
                               {1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1},
                               {1,0,1,1,1,0,1,0,0,0,0,0,0,0,1,0,1,1,1,0,1},
                               {1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1},
                               {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                               {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};



int main(int, char const**)
{
    
    srand(time(0));
    TimeZero = clock();
    
    RenderWindow window(VideoMode(windowWidth, windowHeight), "Project PACMAN Semestralny");
   
    window.setFramerateLimit(144); // limit klatek (aby niepotrzebnie nie obciazac komputera)
    
    bool keyUp, keyDown, keyLeft, keyRight;

    bool Right, Left, Up ,Down;
    
    bool enemyRight, enemyLeft, enemyUp, enemyDown;
    
    
    // ładowanie tekstur z pliku
  
    sf::Texture backgroundTex;
    backgroundTex.loadFromFile("/Users/patrykpiwowarczyk/Desktop/STUDIA/FoCP/Sem2/KodowanieWłasne/PacManProjektSem/PacManSemestraly/PacManSemestraly/textures/background1.JPG");
    sf::Sprite background(backgroundTex);
    
    
    sf::Texture enemy1Tex;
    sf::Texture enemy2Tex;
    sf::Texture enemy3Tex;
    sf::Texture enemy4Tex;
    sf::Texture enemy5Tex;
    sf::Texture enemy6Tex;
    
    sf::Texture coinTex;
    
    sf::Texture playerTex;
    sf::Texture platformsTex;
    playerTex.loadFromFile("/Users/patrykpiwowarczyk/Desktop/STUDIA/FoCP/Sem2/KodowanieWłasne/PacManProjektSem/PacManSemestraly/PacManSemestraly/textures/playersprite5.png");
   
    platformsTex.loadFromFile("/Users/patrykpiwowarczyk/Desktop/STUDIA/FoCP/Sem2/KodowanieWłasne/PacManProjektSem/PacManSemestraly/PacManSemestraly/textures/wall.png");
   
    
    enemy1Tex.loadFromFile("/Users/patrykpiwowarczyk/Desktop/STUDIA/FoCP/Sem2/KodowanieWłasne/PacManProjektSem/PacManSemestraly/PacManSemestraly/textures/enemy1sprite.png");
    enemy2Tex.loadFromFile("/Users/patrykpiwowarczyk/Desktop/STUDIA/FoCP/Sem2/KodowanieWłasne/PacManProjektSem/PacManSemestraly/PacManSemestraly/textures/enemy2sprite.png");
    enemy3Tex.loadFromFile("/Users/patrykpiwowarczyk/Desktop/STUDIA/FoCP/Sem2/KodowanieWłasne/PacManProjektSem/PacManSemestraly/PacManSemestraly/textures/enemy3sprite.png");
    enemy4Tex.loadFromFile("/Users/patrykpiwowarczyk/Desktop/STUDIA/FoCP/Sem2/KodowanieWłasne/PacManProjektSem/PacManSemestraly/PacManSemestraly/textures/enemy4sprite.png");
    enemy5Tex.loadFromFile("/Users/patrykpiwowarczyk/Desktop/STUDIA/FoCP/Sem2/KodowanieWłasne/PacManProjektSem/PacManSemestraly/PacManSemestraly/textures/enemy5sprite.png");
    enemy6Tex.loadFromFile("/Users/patrykpiwowarczyk/Desktop/STUDIA/FoCP/Sem2/KodowanieWłasne/PacManProjektSem/PacManSemestraly/PacManSemestraly/textures/enemy6sprite.png");
   
    
    
    coinTex.loadFromFile("/Users/patrykpiwowarczyk/Desktop/STUDIA/FoCP/Sem2/KodowanieWłasne/PacManProjektSem/PacManSemestraly/PacManSemestraly/textures/coinTex.png");
    
   
    
    
    
   
    
    
    
    
    

    
    
    
    
    
    
    
    std::vector<Coin>coinlevel;
    std::vector<Platform>level;
   
    
    
    // poniżej funkcja generujaca sciany oraz rozkładajaca monety według mapy zawartej wyżej
    int sizeOfLevel = 0;
    
    for(int i = 0; i < 21; i++){
        for(int j= 0; j< 21; j++){
            if(levelArray[i][j] == 1){
               Platform p(j * 128, i * 128, 128,128, platformsTex);
                level.push_back(p);
            }
            
            
                if(levelArray[i][j] == 0){
                    Coin p(j * 128, i * 128, 50, 50, coinTex);
                    coinlevel.push_back(p);
                }
 
                sizeOfLevel++;
            }
        }
    
    
    
    
    Player player(128, 128, 128, 128, playerTex);
    Enemy enemy(128, 128, 128, 128, enemy1Tex);
    Enemy2 enemy2(128, 128, 128, 128, enemy2Tex);
    Enemy3 enemy3(128, 128, 128, 128, enemy3Tex);
    Enemy4 enemy4(128, 128, 128, 128, enemy4Tex);
    Enemy5 enemy5(128, 128, 128, 128, enemy5Tex);
    Enemy6 enemy6(128, 128, 128, 128, enemy6Tex);
    

    
  
    
   
    
    
sf:View view(Vector2f(0.0f,0.0f), Vector2f(windowWidth, windowHeight));
    
 
    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == Event::Closed) {
                window.close();
                
            }

            // Escape pressed: exit
            if (event.type == Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
           
        }
        
       Up= sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
         
       Left= sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
         
       Down= sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
         
       Right= sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
         
        
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        /*
        mouseX = (player.getPosition().x + player.size.x /2) +mousePos.x / gameScale - halfWinWidth / gameScale;
        mouseY = (player.getPosition().y + player.size.y /2) +mousePos.y / gameScale - halfWinWidth / gameScale;
        
        
        std::cout << mouseX << " , " << mouseY << std::endl;
        
        */
      
        /*
       Right = event.type == Event::KeyPressed && event.key.code == sf::Keyboard::Right;
        Left = event.type == Event::KeyPressed && event.key.code == sf::Keyboard::Left;
        Up = event.type == Event::KeyPressed && event.key.code == sf::Keyboard::Up;
        Down = event.type == Event::KeyPressed && event.key.code == sf::Keyboard::Down;
       */
        /*
               W = event.type == Event::KeyPressed && event.key.code == sf::Keyboard::W;
               A = event.type == Event::KeyPressed && event.key.code == sf::Keyboard::A;
               S = event.type == Event::KeyPressed && event.key.code == sf::Keyboard::S;
               D = event.type == Event::KeyPressed && event.key.code == sf::Keyboard::D;
        
       */
        player.update( Right, Left, Up, Down, level, coinlevel);
        enemy.update(enemyRight, enemyLeft, enemyUp, enemyDown, level);
        enemy2.update(enemyRight, enemyLeft, enemyUp, enemyDown, level);
        enemy3.update(enemyRight, enemyLeft, enemyUp, enemyDown, level);
        enemy4.update(enemyRight, enemyLeft, enemyUp, enemyDown, level);
        enemy5.update(enemyRight, enemyLeft, enemyUp, enemyDown, level);
        enemy6.update(enemyRight, enemyLeft, enemyUp, enemyDown, level);
        player.coinCollide(coinlevel,deleteSprite);
        
      
        view.setCenter(player.getPosition().x + player.size.x /2,player.getPosition().y + player.size.y /2 );
     

        window.setView(view);
        // Clear screen
        //window.clear(sf::Color(10,108,180));
        window.clear();
    
    
        
        
       
        window.draw(background);
        
        
        
        for(Coin& p : coinlevel){
           
        window.draw(p);
            }
        
       
     window.draw(player);
     window.draw(enemy);
     window.draw(enemy2);
     window.draw(enemy3);
     window.draw(enemy4);
     window.draw(enemy5);
     window.draw(enemy6);
        
        
        for(Platform& p : level){
               window.draw(p);
               }
        window.display();
        
 
    
       
    }

    return EXIT_SUCCESS;
}
