
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>
// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"
#include "Entity.hpp"
#include <iostream>
#include "Player.hpp"
#include "Platform.hpp"
using namespace std;
using namespace sf;
int windowWidth = 1500;
int windowHeight = 1500;
//int halfWinHeight = windowHeight/2;
//int halfWinWidth = windowWidth/2;





/*
class platformClass{
public:
    float xPos;
    float yPos;
    float xVel;
    float yVel;
    float scale;
    float topSide;
    float bottomSide;
    float rightSide;
    float leftSide;
    Sprite image;
    platformClass(int initXPos, int initYPos, Sprite sprite){
        scale = 1;
        image = sprite;
        
        image.setPosition(initXPos, initYPos);
        image.setScale(scale, scale);
        leftSide = image.getPosition().x;
        rightSide = image.getPosition().x + (image.getLocalBounds().width * scale);
        topSide = image.getPosition().y;
        bottomSide = image.getPosition().y + (image.getLocalBounds().height * scale);
        
        
        
    }
};


class playerClass{
public:
    
    bool playerFaceRight;
    bool onGround;
    bool isCollide;
    float xpos;
    float ypos;
    float xvel;
    float yvel;
    float x;
    float y;
    float w;
    float h;
    float topSide;
    float bottomSide;
    float rightSide;
    float leftSide;
    int scale;
    Sprite image;
    
           
           
    playerClass(Sprite sprite){
        image = sprite;
        playerFaceRight = true;
        xpos = 0;
        ypos = 0;
        xvel = 0;
        yvel = 0;
       x=0;
       y=0;
       w=50;
       h=50;
        onGround = false;
        isCollide = false;
        scale = 2;
        image.setScale(scale, scale);
       
        
        
    }
 */
    /*
    void update(bool keyRight, bool keyLeft,bool keyUp, bool keyDown, platformClass platforms[5]){
        if(keyRight){
            playerFaceRight = true;
            
            xvel=1;
            x= -1;
        }
        if(keyLeft){
            playerFaceRight = false;
            xvel = -1;
            x+= 1;
           
        }
        if(keyUp){
            yvel = -1;
            y+= 0.003;
        }
        if(keyDown){
            yvel =1;
            y+= -1;
        }
        if(!(keyRight || keyLeft)){
            xvel = 0;
            x=0;
        }
        if(!(keyUp || keyDown)){
            yvel = 0;
            y=0;
        }
        if(onGround == true){
            yvel = 0;
        }
            
       
         
        image.move(Vector2f(xvel, 0));
        collision(xvel, 0, platforms);
         image.move(Vector2f(0, yvel));
        collision(0, yvel, platforms);
         
        
        xpos += xvel;
        ypos += yvel;
        cout << xpos << endl;
        cout << ypos << endl;
        cout << onGround <<endl;
        
    }
     */
    /*
    void collision(float xVelDelta, float yVelDelta, platformClass platforms[5]){
        for(int i = 0; i < 5; i++){
        if(image.getPosition().x + image.getLocalBounds().width * scale > platforms[i].leftSide && image.getPosition().x < platforms[i].rightSide &&
           image.getPosition().y + image.getLocalBounds().height * scale > platforms[i].topSide && image.getPosition().y < platforms[i].bottomSide){
           
            isCollide = true;
        }else{
            isCollide = false;
        }
        if(isCollide){
            
            if(xVelDelta >0){
                image.setPosition(Vector2f(platforms[i].leftSide - image.getLocalBounds().width * scale, image.getPosition().y));
            }
            if (xVelDelta <0){
                image.setPosition(Vector2f(platforms[i].rightSide, image.getPosition().y));
            }
            if (yVelDelta> 0){
                image.setPosition(Vector2f(image.getPosition().x, platforms[i].topSide - image.getLocalBounds().height * scale));
            }
            if (yVelDelta <0){
                image.setPosition(Vector2f(image.getPosition().x, platforms[i].bottomSide ));
            }
            
            
        }
        }
    }
    
    
    
    
    
    
};
*/


int main(int, char const**)
{
    
    bool canZoom = true;
    
    
    /*
    Texture texture;
    Texture textureSpriteMap;
    texture.loadFromFile("/Users/patrykpiwowarczyk/Desktop/STUDIA/FoCP/Sem2/KodowanieWłasne/platformerGame/platformerGame/images/ground.png");
    Sprite ground(texture);
    */
    
    
    
    
    // Create the main window
    RenderWindow window(VideoMode(windowWidth, windowHeight), "Project Flash");
    
    
    
    bool keyUp, keyDown, keyLeft, keyRight, keyW, keyS, keyA, keyD,keyUpLeft;
    
    
    int levelArray[10][10] = {  {1,0,0,0,0,0,0,0,0,1},
                                {0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,1,1,1,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0},
                                {1,0,0,0,0,0,0,0,0,1},
    };
    
    Platform level[100];
    
    int sizeOfLevel = 0;
    
    for(int i = 0; i < 10; i++){
        for(int j= 0; j< 10; j++){
            if(levelArray[i][j] == 1){
                level[sizeOfLevel].init("/Users/patrykpiwowarczyk/Desktop/STUDIA/FoCP/Sem2/KodowanieWłasne/platformerGame/platformerGame/images/block.png", j * 200, i * 200, 200,200);
                sizeOfLevel++;
            }
        }
               }
    
    
    /*
    
    Texture playerTexture1;
    playerTexture1.loadFromFile("/Users/patrykpiwowarczyk/Desktop/STUDIA/FoCP/Sem2/KodowanieWłasne/platformerGame/platformerGame/images/fly.png");
    Sprite playerSprite1(playerTexture1);
    
    
    Texture platformSpriteSheet;
    platformSpriteSheet.loadFromFile("/Users/patrykpiwowarczyk/Desktop/STUDIA/FoCP/Sem2/KodowanieWłasne/platformerGame/platformerGame/assets/images/ground.png");
    Sprite earthSprite1(platformSpriteSheet);
    earthSprite1.setTextureRect(IntRect(8,8,174,174));
*/
   // playerClass playerObject(playerSprite1);
    
    /*
   platformClass platforms[5] = {platformClass(100,1000,earthSprite1),platformClass(274,1000,earthSprite1),platformClass(448,1000,earthSprite1),platformClass(622,1000,earthSprite1),platformClass(796,1000,earthSprite1),};
    */
    
    Player player("/Users/patrykpiwowarczyk/Desktop/STUDIA/FoCP/Sem2/KodowanieWłasne/platformerGame/platformerGame/images/fly.png", 200, 200, 76, 86);
    
sf:View view(Vector2f(0.0f,0.0f), Vector2f(windowWidth, windowHeight));
    
    
    /*
    
    Texture backgroundTexture;
    backgroundTexture       .loadFromFile("/Users/patrykpiwowarczyk/Desktop/STUDIA/FoCP/Sem2/KodowanieWłasne/platformerGame/platformerGame/images/background.png");
    Sprite backgroundSprite(backgroundTexture);
    */
     
     /*
     
     
    Texture flyTexture;
    flyTexture.loadFromFile("/Users/patrykpiwowarczyk/Desktop/STUDIA/FoCP/Sem2/KodowanieWłasne/platformerGame/platformerGame/images/fly.png");
    Sprite flySprite(flyTexture);
   
    
    */
    // Set the Icon
    Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Load a sprite to display

    

    // Create a graphical text to display
    Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    
    /*
    Text text("Hello SFML", font, 50);
    text.setFillColor(sf::Color::Black);
*/
    // Load a music to play
    
    Music music;
    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
        return EXIT_FAILURE;
    }

    // Play the music
    //music.play();
    Clock gameClock;
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
        /*
        keyRight= sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
        keyLeft= sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
        keyUp= sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
        keyDown= sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
         keyUpLeft= sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&& sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
        */
        keyRight = event.type == Event::KeyPressed && event.key.code == sf::Keyboard::Right;
        keyLeft = event.type == Event::KeyPressed && event.key.code == sf::Keyboard::Left;
        keyUp = event.type == Event::KeyPressed && event.key.code == sf::Keyboard::Up;
        keyDown = event.type == Event::KeyPressed && event.key.code == sf::Keyboard::Down;
        keyUpLeft = event.type == Event::KeyPressed && event.key.code == sf::Keyboard::Left && event.type == Event::KeyPressed && event.key.code == sf::Keyboard::Up;
        
               keyW = event.type == Event::KeyPressed && event.key.code == sf::Keyboard::W;
               keyS = event.type == Event::KeyPressed && event.key.code == sf::Keyboard::S;
               keyA = event.type == Event::KeyPressed && event.key.code == sf::Keyboard::A;
               keyD = event.type == Event::KeyPressed && event.key.code == sf::Keyboard::D;
        
       
        /*
        if (event.type == Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
            keyRight = true;
        } else{
                       keyRight = false;
                   }
        if (event.type == Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
                   keyLeft = true;
               } else{
                              keyLeft = false;
                          }
        if (event.type == Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
            keyUp = true;
        } else{
                       keyUp = false;
                   }
        if (event.type == Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
            keyDown = true;
        } else{
                       keyDown = false;
                   }
        */
        player.update( keyUp,  keyDown,  keyRight,keyLeft, keyUpLeft);
        
        
        
        
        float fps = gameClock.getElapsedTime().asSeconds();
        gameClock.restart().asSeconds();
       /*
        if(canZoom){
        if (event.type == Event::KeyPressed && event.key.code == sf::Keyboard::Z) {
            zoomScale++;
            ground.scale(zoomScale, zoomScale);
            canZoom = false;
        }else {canZoom = true;}
        if (event.type == Event::KeyPressed && event.key.code == sf::Keyboard::X) {
            zoomScale--;
            ground.scale(zoomScale, zoomScale);
            canZoom = false;
        }else { canZoom = true;}}
        
        */
        
        
        
        
        
        
        
        
        
       
   // playerObject.update(keyRight, keyLeft, keyUp, keyDown, platforms);
        
        
        
        view.setCenter(sf::Vector2f(player.m_centrePos[0], player.m_centrePos[1]));
        
      //  view.setCenter(Vector2f(playerObject.image.getPosition().x + playerObject.image.getLocalBounds().width * playerObject.scale / 2.0f, playerObject.image.getPosition().y + playerObject.image.getLocalBounds().height *playerObject.scale / 2.0f));    TO JEST KOD NA STARE CENTROWANIE KAMERY.
        window.setView(view);
        // Clear screen
        window.clear(sf::Color(10,108,180));
        //window.draw(backgroundSprite);
        
        
         //window.draw(playerObject.image);

        
        
        window.draw(player);
        
        for(int i=0;i<sizeOfLevel;i++){
        window.draw(level[i]);
        }
        //window.draw(ground);
       
       
       
        
         /*
        window.draw(flySprite);
        flySprite.move(Vector2f(playerObject.xvel,playerObject.yvel));

        */
        // Draw the sprite
    
        
        
        
       // ground.move(Vector2f(playerObject.x /* *playerObject.fps*/ ,playerObject.y /* * playerObject.fps*/));
        
        // Draw the string
//   window.draw(text);

        // Update the window
        window.display();
        
 
        
    
       
    }

    return EXIT_SUCCESS;
}
