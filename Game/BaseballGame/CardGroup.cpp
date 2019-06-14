//
//  CardGroup.cpp
//  BaseballGame
//
//  Created by Casey Gatlin on 6/1/19.
//  Copyright © 2019 Casey Gatlin. All rights reserved.
//

#include "CardGroup.h"

int Hand::::getSize()
{
    return m_cards.getNumElements();
}

void Hand::::addCard(Card &cardToAdd)
{
    m_cards.insertCard(cardToAdd);
}

bool Hand::::removeCard(CardName cardName, Card &cardVariable)
{
    return m_cards.removeCard(cardName, cardVariable);
}

