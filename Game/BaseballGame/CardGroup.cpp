//
//  CardGroup.cpp
//  BaseballGame
//
//  Created by Casey Gatlin on 6/1/19.
//  Copyright © 2019 Casey Gatlin. All rights reserved.
//

#include "CardGroup.h"

int CardGroup::getSize()
{
    return m_cards.getNumElements();
}

void CardGroup::addCard(Card &cardToAdd)
{
    m_cards.insertCard(cardToAdd);
}

bool CardGroup::removeCard(CardName cardName, Card &cardVariable)
{
    return m_cards.removeCard(cardName, cardVariable);
}

