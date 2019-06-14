//
//  Pitcher.cpp
//  BaseballGame
//
//  Created by Casey Gatlin on 6/1/19.
//  Copyright © 2019 Casey Gatlin. All rights reserved.
//

#include "Pitcher.h"

// Constructor -----------
Pitcher::Pitcher()
{
    m_inningsPitched = m_timesThroughLineup = 0;
    m_hasPitcher = false;
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
    return m_pitcherCard[0].getValue();
}

bool Pitcher::hasPitcher()
{
    return m_hasPitcher;
}

void Pitcher::addPitcher(Card &cardToAdd)
{
    if (m_hasPitcher)
        return; //Note: implement assert
    
    m_pitcherCard[0] = cardToAdd;
    m_hasPitcher = true;
}

bool Pitcher::removePitcher(Card &cardVar)
{
    if (!m_hasPitcher)
        return false;
    
    cardVar = m_pitcherCard[0];
    m_hasPitcher = false;
    return true;
}

// Mutators -------------
void Pitcher::goneThruLineup()
{
    m_pitcherCard[0].decreaseValue();
    m_timesThroughLineup++;
}

void Pitcher::increaseInningCount()
{
    m_inningsPitched++;
}
