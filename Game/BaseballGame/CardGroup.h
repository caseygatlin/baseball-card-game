//
//  CardGroup.h
//  BaseballGame
//
//  Created by Casey Gatlin on 6/1/19.
//  Copyright © 2019 Casey Gatlin. All rights reserved.
//

#ifndef CardGroup_h
#define CardGroup_h

#include "Card.h"
#include "Globals.h"
#include "HashTable.h"

//The base class for all card groups in the game
//  (Pickup pile, discard, player's hand, batters, etc.)
//
// NOTE: Each player will have 1 of each CardGroup


class CardGroup
{
public:
    //Accessors
    int getSize();
    
    //Methods for moving cards around
    void addCard(Card &cardToAdd);
    virtual bool removeCard(CardName cardName, Card &cardVariable);
    
private:
    //The cards themselves in each CardGroup
    //An Array of Linked Lists
    HashTable m_cards;
    
};

#endif /* CardGroup_h */
