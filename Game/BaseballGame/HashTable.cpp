//
//  HashTable.cpp
//  BaseballGame
//
//  Created by Casey Gatlin on 6/3/19.
//  Copyright © 2019 Casey Gatlin. All rights reserved.
//

#include "HashTable.h"
#include "Card.h"

HashTable::HashTable()
{
    m_numElements = 0;
    
    for (int i = 0; i < MAX_TABLE_ELEMENTS; i++)
        m_elements[i].hasElement = false;
}

int HashTable::getNumElements()
{
    return m_numElements;
}

void HashTable::insertCard(Card &cardToinsert)
{
    int index = cardToinsert.getValue() - 1;
    m_elements[index].items.insertToRear(cardToinsert);
    m_elements[index].hasElement = true;
    m_numElements++;
}

bool HashTable::removeCard(CardName cardName, Card &cardVariable)
{
    int index = cardName - 1;
    
    if (!m_elements[index].hasElement)
        return false;
    
    m_elements[index].items.removeItem(cardVariable);
    m_numElements--;
    return true;
}
