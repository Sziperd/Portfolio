//
//  Enemy.hpp
//  PacManSemestraly
//
//  Created by Patryk Piwowarczyk on 24/05/2020.
//  Copyright © 2020 Patryk Piwowarczyk. All rights reserved.
//

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.hpp"
#include "Hitbox.hpp"
#include "Platform.hpp"
#include <vector>


class Enemy2 : public Entity{
private:
    float speed;
    bool collision;
    bool onGround;
    float acceleration;
    float jumpHeight;
    int walkCounter, idleCounter, animationCounter, walkFrames, idleFrames, walkSpeed, idleSpeed, walkUpSpeed, walkUpFrames, walkUpCounter, walkDownCounter, walkDownFrames, walkDownSpeed, walkLeftSpeed, walkLeftFrames, walkLeftCounter;
public:
    Enemy2(float X,float Y,float W,float H, sf::Texture& t);
    void update(bool &enemyRight, bool &enemyLeft,bool &enemyUp,bool &enemyDown,  std::vector<Platform>& level);
    void collide(float xvel, float yvel, std::vector<Platform>& level);
void animate();
    void walk();
    void idle();
    void walkleft();
    void walkUp();
    void walkDown();
    
};

