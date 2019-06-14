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
#include "Card.h"

// The Pitcher class
// Players can change pitchers, and pitchers can become
// fatigued (lose value) over time
class Pitcher
{
public:
    //Constructor
    Pitcher();
    
    //Accessors
    int getInningsPitched();
    int getThroughLineup();
    int getPitcherVal();
    bool hasPitcher();
    
    //Inserting / Deleting
    void addPitcher(Card &cardToAdd);
    bool removePitcher(Card &cardVar);
    
    //Mutators
    void goneThruLineup();
    void increaseInningCount();
    
private:
    int m_inningsPitched;
    int m_timesThroughLineup;
    Card m_pitcherCard[1];
    bool m_hasPitcher;
};

#endif /* Pitcher_h */
