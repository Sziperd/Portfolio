//
//  coin.cpp
//  PacManSemestraly
//
//  Created by Patryk Piwowarczyk on 04/06/2020.
//  Copyright © 2020 Patryk Piwowarczyk. All rights reserved.
//

#include "coin.hpp"
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Entity.hpp"

using namespace std;


Coin::Coin(float X,float  Y,float  W,float  H, sf::Texture& t){

    size.x = W;
    size.y = H;
       
    
       hitbox.leftHitbox = X + 0.f;
       hitbox.rightHitbox = X + size.x - 0.f;
       hitbox.topHitbox = Y + 0.f;
       hitbox.bottomHitbox = Y + size.y - 0.f;
      
     
    setTexture(t);
    
    setPosition(X,Y);
    
}
