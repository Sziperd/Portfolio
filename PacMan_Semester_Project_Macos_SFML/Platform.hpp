//
//  Platform.hpp
//  platformerGame
//
//  Created by Patryk Piwowarczyk on 10/05/2020.
//  Copyright © 2020 Patryk Piwowarczyk. All rights reserved.
//


#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.hpp"




class Platform : public Entity{

public:
   
    Platform( float X,float Y,float W,float H, sf::Texture& t);
    
  
};


class Background{
    
    Background(sf::Texture& g);
    
};
