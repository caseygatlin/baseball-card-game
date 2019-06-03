//
//  Pitcher.cpp
//  BaseballGame
//
//  Created by Casey Gatlin on 6/1/19.
//  Copyright © 2019 Casey Gatlin. All rights reserved.
//

#include "Pitcher.h"

// Constructor -----------
Pitcher::Pitcher() : CardGroup(), m_inningsPitched(0), m_timesThroughLineup(0),
m_cardName(NONAME), m_suit(NOSUIT), m_val(0)
{
}

// Accessors -------------
int Pitcher::getInningsPitched()
{
    return m_inningsPitched;
}

int Pitcher::getThroughLineup()
{
    return m_timesThroughLineup;
}

int Pitcher::getPitcherVal()
{
    return m_val;
}

void Pitcher::addPitcher(Card &cardToAdd)
{
    addCard(cardToAdd);
    m_cardName = cardToAdd.getName();
    m_suit = cardToAdd.getSuit();
    m_val = cardToAdd.getValue();
}

// Mutators -------------
void Pitcher::goneThruLineup()
{
    m_val--;
    m_timesThroughLineup++;
}

void Pitcher::increaseInningCount()
{
    m_inningsPitched++;
}
