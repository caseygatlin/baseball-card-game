//
//  Card.h
//  BaseballGame
//
//  Created by Casey Gatlin on 6/1/19.
//  Copyright © 2019 Casey Gatlin. All rights reserved.
//

#ifndef Card_h
#define Card_h

#include "Globals.h"

//Defines the attributes and methods for the cards themselves
class Card
{
public:
    //Constructors
    Card(); //Default initialized to NOSUIT and NONAME
    Card(Suit suit, CardName name);
    
    //Accessors
    int getValue();
    Suit getSuit();
    CardName getName();
    
    //Mutators
    void decreaseValue();
    
private:
    int m_cardValue;
    CardName m_cardName;
    Suit m_cardSuit;
};

#endif /* Card_h */
