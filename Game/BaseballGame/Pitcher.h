//
//  Pitcher.h
//  BaseballGame
//
//  Created by Casey Gatlin on 6/1/19.
//  Copyright © 2019 Casey Gatlin. All rights reserved.
//

#ifndef Pitcher_h
#define Pitcher_h

#include "Globals.h"
#include "CardGroup.h"

// The Pitcher class
// Players can change pitchers, and pitchers can become
// fatigued (lose value) over time
class Pitcher : public CardGroup
{
public:
    //Constructor
    Pitcher();
    
    //Accessors
    int getInningsPitched();
    int getThroughLineup();
    int getPitcherVal();
    
    //Inserting / Deleting
    void addPitcher(Card &cardToAdd);
    
    //Mutators
    void goneThruLineup();
    void increaseInningCount();
    
private:
    int m_inningsPitched;
    int m_timesThroughLineup;
    CardName m_cardName;
    Suit m_suit;
    int m_val;
};

#endif /* Pitcher_h */
