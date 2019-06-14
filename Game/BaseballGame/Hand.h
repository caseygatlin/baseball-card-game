//
//  Hand.h
//  BaseballGame
//
//  Created by Casey Gatlin on 6/6/19.
//  Copyright © 2019 Casey Gatlin. All rights reserved.
//

#ifndef Hand_h
#define Hand_h

#include "HashTable.h"
#include "Card.h"
#include "Globals.h"

class Hand
{
public:
    //Accessors
    int size();
    
    //Methods for moving cards around
    void addCard(Card &cardToAdd);
    virtual bool removeCard(CardName cardName, Card &cardVariable);
    
private:
    //The cards themselves in each CardGroup
    //An Array of Linked Lists
    HashTable m_cards;
    
};

#endif /* Hand_h */
