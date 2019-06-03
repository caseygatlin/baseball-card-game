//
//  HashTable.h
//  BaseballGame
//
//  Created by Casey Gatlin on 6/3/19.
//  Copyright © 2019 Casey Gatlin. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h

#include "LinkedList.h"
#include "Card.h"
#include "Globals.h"

const int MAX_TABLE_ELEMENTS = 14;

struct HashElement
{
    LinkedList items;
    bool hasElement;
};

class HashTable
{
public:
    //Constructor
    HashTable();
    
    //Accessor
    int getNumElements();
    
    //Insert / Remove cards
    void insertCard(Card &cardToinsert);
    bool removeCard(CardName cardName, Card &cardVariable);
    
private:
    HashElement m_elements[MAX_TABLE_ELEMENTS];
    int m_numElements;
};

#endif /* HashTable_h */
