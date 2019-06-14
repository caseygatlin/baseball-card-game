//
//  Lineup.h
//  BaseballGame
//
//  Created by Casey Gatlin on 6/6/19.
//  Copyright © 2019 Casey Gatlin. All rights reserved.
//

#ifndef Lineup_h
#define Lineup_h

#include "Card.h"

class Lineup
{
public:
    //Constructor
    Lineup();
    
    //Accessor
    int getBatterPos();
    int getBatterVal();
    
    
private:
    Card m_lineup[9];
    int m_batterPos;
};

#endif /* Lineup_h */
