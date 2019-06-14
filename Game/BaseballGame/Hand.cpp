//
//  Hand.cpp
//  BaseballGame
//
//  Created by Casey Gatlin on 6/6/19.
//  Copyright © 2019 Casey Gatlin. All rights reserved.
//

#include "Hand.h"
#include "Card.h"
#include "Globals.h"

int Hand::size()
{
    return m_cards.getNumElements();
}

void Hand::addCard(Card &cardToAdd)
{
    m_cards.insertCard(cardToAdd);
}

bool Hand::removeCard(CardName cardName, Card &cardVariable)
{
    return m_cards.removeCard(cardName, cardVariable);
}
