//
//  platform.cpp
//  platformerGame
//
//  Created by Patryk Piwowarczyk on 10/05/2020.
//  Copyright © 2020 Patryk Piwowarczyk. All rights reserved.
//


#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Entity.hpp"
#include "Platform.hpp"
using namespace std;


Platform::Platform(float X,float  Y,float  W,float  H, sf::Texture& t){

    size.x = W;
    size.y = H;
       
    
       hitbox.leftHitbox = X + 0.f;
       hitbox.rightHitbox = X + size.x - 0.f;
       hitbox.topHitbox = Y + 0.f;
       hitbox.bottomHitbox = Y + size.y - 0.f;
      
     
    setTexture(t);
    
    setPosition(X,Y);
    
}

