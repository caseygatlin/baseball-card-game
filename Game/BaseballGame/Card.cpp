//
//  Card.cpp
//  BaseballGame
//
//  Created by Casey Gatlin on 6/1/19.
//  Copyright © 2019 Casey Gatlin. All rights reserved.
//

#include "Card.h"

// Card class implementation

// Constructors -------------
Card::Card()
{
    m_cardName = NONAME;
    m_cardValue = 0;
    m_cardSuit = NOSUIT;
}

Card::Card(Suit suit, CardName name)
{
    m_cardName = name;
    m_cardValue = name;
    m_cardSuit = suit;
}

// Accessors -------------
int Card::getValue()
{
    return m_cardValue;
}

Suit Card::getSuit()
{
    return m_cardSuit;
}

CardName Card::getName()
{
    return m_cardName;
}

// Mutators -------------

void Card::decreaseValue()
{
    m_cardValue--;
}
