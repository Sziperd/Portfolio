//
//  Enemy.cpp
//  PacManSemestraly
//
//  Created by Patryk Piwowarczyk on 24/05/2020.
//  Copyright © 2020 Patryk Piwowarczyk. All rights reserved.
//


//opis kodu znajdowac sie bedzie tylko w tym pliku, poniewaz reszta "enemies" posiada bardzo podobny kod.



#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Platform.hpp"
#include "Entity.hpp"
#include "Enemy.hpp"
#include <math.h>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


extern clock_t TimeZero;
extern double deltaTime;
extern int iRand;
Enemy::Enemy(float X,float Y,float W,float H, sf::Texture& t){
  //ustalanie parametrow przeciwnikow oraz ich  poprawnych "hitbox'ów " zgodnie z wielkoscia grafiki
    speed = 3.f;
    jumpHeight = 8.f;
  
    size.x = W;
    size.y = H;
    
     
    //tutaj kod pozwalajacy na okreslenie ilosci klatek danych animacji
    
    idleFrames = 0;
    idleCounter = 0;
    
    walkFrames = 1;
    walkCounter = 0;
    
    walkUpCounter = 0;
    walkUpFrames = 1;
    
    walkDownFrames = 1;
    walkDownCounter=0;
    
    walkLeftCounter =0;
    walkLeftFrames=1;
    
    
    walkLeftSpeed=8;
    walkDownSpeed=8;
    walkSpeed = 8;
    idleSpeed = 32;
    walkUpSpeed = 8;
    
    
    frameSize.x= 128;
    frameSize.y=128;
    
    
    framesAmount.x = t.getSize().x / frameSize.x;
    framesAmount.y = t.getSize().y / frameSize.y;
    
    //petla pozwalajaca puszczanie klatek animacji w odpowiedniej kolejnosci
    
    for(int y=0; y< framesAmount.y; y++)
        {
        for(int x = 0; x< framesAmount.x; x++)
        {
            sf::IntRect frame(x* frameSize.x, y*frameSize.y, frameSize.x, frameSize.y);
            frames.push_back(frame);
        }
        }
    setTextureRect(frames[0]);
    setTexture(t);
    setPosition(2432, 2432);

}
void Enemy::update(bool &enemyRight, bool &enemyLeft, bool &enemyUp, bool &enemyDown,  std::vector<Platform>& level)
{
    //ponizej funkcja programujaca sposob poruszania sie NPC (dziala on na zasadzie losowania liczb z uzyciem seeda stworzonego z czasu systemowego.

    float secondsToDelay = 1;

        deltaTime = (clock() - TimeZero) / (CLOCKS_PER_SEC/4);

    if(deltaTime > secondsToDelay)
    {
    iRand = (rand() % 4)+1;
        
               
                TimeZero = clock();
      
    
    
    }

    if(iRand == 1) {
        velocity.y = -1;
         //velocity.x = 0;
        walkUp();
    }
        
        
    
    if(iRand == 2) {
        velocity.y = 1;
        //velocity.x = 0;
        walkDown();
    }
    if(iRand == 3){
       velocity.x = -1;
        //velocity.y = 0;
        walkleft();
    }
    
    if(iRand == 4) {
        velocity.x = 1;
        //velocity.y = 0;
        walk();
    }
/*
    if(!(enemyLeft or enemyRight)) {
        velocity.x = 0.f;
        
    }
    if(!(enemyUp or enemyDown)){
        velocity.y = 0.f;
       
    }
   */
  //funkcja zapobiegajaca jednoczesnemu ruszaniu sie w dwie strony naraz
    
    if(velocity.y ==0 && velocity.x == 0){
        idle();
        
        
         
        
    }
    
    move(velocity.x *speed, 0);
    collide(velocity.x , 0, level);
    
    
    
    
   
    
     move(0, velocity.y*speed);
    collide(0, velocity.y, level);
  
   
    
    }

// funckcja programujaca "hitbox" grafiki, zapobiegajaca przechodzeniu przez sciany.
void Enemy::collide(float xvel,float yvel, std::vector<Platform>& level){
    for(Platform& p : level)
   {
        if(getPosition().x + 0 < p.hitbox.rightHitbox &&
           getPosition().x + size.x - 0 > p.hitbox.leftHitbox &&
           getPosition().y + 0< p.hitbox.bottomHitbox &&
           getPosition().y + size.y - 0 > p.hitbox.topHitbox)
        {
            collision = true;
            
        }else
        {     collision = false;
            }
      
                
              if(collision)
              {
           
           
           if(xvel > 0)
            {
            
                setPosition(p.hitbox.leftHitbox - size.x + 0, getPosition().y);
                velocity.x = 0.f;
            
            }
           if(xvel <0 )
            {
            
                setPosition(p.hitbox.rightHitbox - 0, getPosition().y);
                velocity.x = 0.f;
                         
            }
           if(yvel > 0)
            {
   
                setPosition(getPosition().x,p.hitbox.topHitbox - size.y + 0);
                velocity.y = 0.f;
                onGround = true;
            }
            if(yvel <0 )
            {
            
                setPosition(getPosition().x,p.hitbox.bottomHitbox - 0);
                velocity.y = 0.f;
            }
   }
}
}
    //funkcje wywolujace dana animacje 
void Enemy::animate()
{
if(abs(velocity.x > 0))
{
    walk();
}
    else{
        idle();}


}
void Enemy::walkleft()
{
    
   for(int i =1; i <walkLeftFrames; i++)
     if(walkLeftCounter == (i+1) * walkLeftSpeed)
         setTextureRect(frames[i+walkFrames]);
     if(walkLeftCounter == walkLeftFrames * walkLeftSpeed)
         walkLeftCounter = 0;
    walkLeftCounter++;
}




void Enemy::walk()
{
    
    for(int i =0; i < walkFrames; i++)
     if(walkCounter == (i+1) * walkSpeed)
         setTextureRect(frames[i]);
     if(walkCounter == walkFrames * walkSpeed)
         walkCounter = 0;
     walkCounter++;
     
}


void Enemy::idle()
{
    for(int i =0; i <idleFrames; i++)
     if(idleCounter == (i+1) * idleSpeed)
         setTextureRect(frames[i+walkFrames+walkUpFrames+walkLeftFrames+idleFrames]);
     if(idleCounter == idleFrames * idleSpeed)
         idleCounter = 0;
    idleCounter++;
    
     
}

void Enemy::walkUp(){
    
    for(int i =0; i <walkUpFrames; i++)
        if(walkUpCounter == (i+1) * walkUpSpeed)
           setTextureRect(frames[i+walkFrames+idleFrames]);
       if(walkUpCounter == walkUpFrames * walkUpSpeed)
           walkUpCounter = 0;
     walkUpCounter++;
    
}


void Enemy::walkDown(){
    
    for(int i =0; i <walkDownFrames; i++)
        if(walkDownCounter == (i+1) * walkDownSpeed)
           setTextureRect(frames[i+walkFrames+idleFrames+walkUpFrames]);
       if(walkDownCounter == walkDownFrames * walkDownSpeed)
           walkDownCounter = 0;
     walkDownCounter++;
    
}

