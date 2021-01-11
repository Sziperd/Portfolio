//
//  Player.hpp
//  platformerGame
//
//  Created by Patryk Piwowarczyk on 09/05/2020.
//  Copyright © 2020 Patryk Piwowarczyk. All rights reserved.
//


#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.hpp"
#include "Hitbox.hpp"
#include "Platform.hpp"
#include <vector>
#include "coin.hpp"

class Player : public Entity{
private:
    float speed;
    bool collision;
    bool coincollision;
    bool onGround;
    
    float acceleration;
    float jumpHeight;
    int walkCounter, idleCounter, animationCounter, walkFrames, idleFrames, walkSpeed, idleSpeed, walkUpSpeed, walkUpFrames, walkUpCounter, walkDownCounter, walkDownFrames, walkDownSpeed, walkLeftSpeed, walkLeftFrames, walkLeftCounter;
public:
    
    Player(float X,float Y,float W,float H, sf::Texture& t);
    void update(bool &Right, bool &Left,bool &Up,bool &Down,  std::vector<Platform>& level,std::vector<Coin>& coinlevel);
    void collide(float xvel, float yvel, std::vector<Platform>& level);
  
    int coinCollide(std::vector<Coin>& coinlevel, bool &deleteSprite);
void animate();
    void walk();
    void idle();
    void walkleft();
    void walkUp();
    void walkDown();
    
};

