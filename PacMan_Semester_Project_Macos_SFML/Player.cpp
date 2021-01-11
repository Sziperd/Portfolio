//
//  Player.cpp
//  platformerGame
//
//  Created by Patryk Piwowarczyk on 09/05/2020.
//  Copyright © 2020 Patryk Piwowarczyk. All rights reserved.
//

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Platform.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "coin.hpp"
#include <math.h>
#include <vector>

using namespace std;

extern int levelArray[21][21];


Player::Player(float X,float Y,float W,float H, sf::Texture& t){
  
    speed = 2.f;
    jumpHeight = 8.f;
  
    size.x = W;
    size.y = H;
    
     
    
    
    idleFrames = 4;
    idleCounter = 0;
    
    walkFrames = 4;
    walkCounter = 0;
    
    walkUpCounter = 0;
    walkUpFrames = 4;
    
    walkDownFrames = 4;
    walkDownCounter=0;
    
    walkLeftCounter =0;
    walkLeftFrames=4;
    
    
    walkLeftSpeed=8;
    walkDownSpeed=8;
    walkSpeed = 8;
    idleSpeed = 32;
    walkUpSpeed = 8;
    
    
    frameSize.x= 128;
    frameSize.y=128;
    
   
    
    
    framesAmount.x = t.getSize().x / frameSize.x;
    framesAmount.y = t.getSize().y / frameSize.y;
    
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
    setPosition(128, 128);
    
   

}
void Player::update(bool &Right, bool &Left, bool &Up, bool &Down,  std::vector<Platform>& level,std::vector<Coin>& coinlevel)
{
    
    
    if(Up) {
        velocity.y = -1.f;
        walkUp();
        
    }
    if(Down) {
        velocity.y = 1.f;
        walkDown();
    }
    if(Left){
       velocity.x = -1.f;
        walkleft();
    }
    
    if(Right) {
        velocity.x = 1.f;
        walk();
    }
   
    if(!(Left or Right)) {
        velocity.x = 0.f;
        
    }
    if(!(Up or Down)){
        velocity.y = 0.f;
       
    }
    if(velocity.y ==0 && velocity.x == 0){
        idle();
    }
    
    move(velocity.x *speed, 0);
    collide(velocity.x , 0, level);
    
    
    
    
    
   
    
    move(0, velocity.y*speed);
    collide(0, velocity.y, level);
   
    
    
    
   
    
    
    }


void Player::collide(float xvel,float yvel, std::vector<Platform>& level){
    for(Platform& p : level)
   {
       cout << (int)getPosition().x/128 <<"  " <<(int)getPosition().y/128 << "  "<< levelArray[3][1]<<endl;
       
       
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

int Player::coinCollide(std::vector<Coin>& coinlevel, bool &deleteSprite){
    for(Coin& p : coinlevel)
   {
        if(getPosition().x + 0 < p.hitbox.rightHitbox &&
           getPosition().x + size.x - 0 > p.hitbox.leftHitbox &&
           getPosition().y + 0< p.hitbox.bottomHitbox &&
           getPosition().y + size.y - 0 > p.hitbox.topHitbox)
        {
            coincollision = true;
          
        }else
        {     coincollision = false;
          
            }
       if(coincollision)
       {
        deleteSprite = true;
          levelArray[(int)getPosition().y/128][(int)getPosition().x/128] = 2;
          
           
   }
       if (!coincollision){
         
          
       }
}
}





    
void Player::animate()
{
if(abs(velocity.x > 0))
{
    walk();
}
    else{
        idle();}


}
void Player::walkleft()
{
    
   for(int i =1; i <walkLeftFrames; i++)
     if(walkLeftCounter == (i+1) * walkLeftSpeed)
         setTextureRect(frames[i+walkFrames]);
     if(walkLeftCounter == walkLeftFrames * walkLeftSpeed)
         walkLeftCounter = 0;
    walkLeftCounter++;
}




void Player::walk()
{
    
    for(int i =0; i < walkFrames; i++)
     if(walkCounter == (i+1) * walkSpeed)
         setTextureRect(frames[i]);
     if(walkCounter == walkFrames * walkSpeed)
         walkCounter = 0;
     walkCounter++;
     
}


void Player::idle()
{
    for(int i =0; i <idleFrames; i++)
     if(idleCounter == (i+1) * idleSpeed)
         setTextureRect(frames[i+walkFrames+walkUpFrames+walkLeftFrames+idleFrames]);
     if(idleCounter == idleFrames * idleSpeed)
         idleCounter = 0;
    idleCounter++;
    
     
}

void Player::walkUp(){
    
    for(int i =0; i <walkUpFrames; i++)
        if(walkUpCounter == (i+1) * walkUpSpeed)
           setTextureRect(frames[i+walkFrames+idleFrames]);
       if(walkUpCounter == walkUpFrames * walkUpSpeed)
           walkUpCounter = 0;
     walkUpCounter++;
    
}


void Player::walkDown(){
    
    for(int i =0; i <walkDownFrames; i++)
        if(walkDownCounter == (i+1) * walkDownSpeed)
           setTextureRect(frames[i+walkFrames+idleFrames+walkUpFrames]);
       if(walkDownCounter == walkDownFrames * walkDownSpeed)
           walkDownCounter = 0;
     walkDownCounter++;
    
}
