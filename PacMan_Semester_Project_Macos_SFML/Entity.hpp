//
//  Entity.hpp
//  platformerGame
//
//  Created by Patryk Piwowarczyk on 09/05/2020.
//  Copyright © 2020 Patryk Piwowarczyk. All rights reserved.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "Hitbox.hpp"
#include <vector>

class Entity : public sf::Sprite{

public:
 
    sf::Vector2f velocity;
    sf::Vector2f size;
    sf::Vector2f frameSize;
    sf::Vector2f framesAmount;
    HitBox hitbox;
    std::vector<sf::IntRect> frames;
   
};


