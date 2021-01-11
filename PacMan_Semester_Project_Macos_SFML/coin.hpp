//
//  coin.hpp
//  PacManSemestraly
//
//  Created by Patryk Piwowarczyk on 04/06/2020.
//  Copyright © 2020 Patryk Piwowarczyk. All rights reserved.
//

#ifndef coin_hpp
#define coin_hpp

#include <stdio.h>

#endif /* coin_hpp */
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.hpp"




class Coin : public Entity{

public:
   
    Coin( float X,float Y,float W,float H, sf::Texture& t);
    
  
};


class coinBackground{
    
    coinBackground(sf::Texture& g);
    
};
