//
//  BoxScore.cpp
//  baseball-card-game
//
//  Created by Casey Gatlin on 10/15/18.
//  Copyright © 2018 Casey Gatlin. All rights reserved.
//

#include <iostream>
#include "GameClasses.h"

BoxScore::BoxScore()
{
    totalRuns = totalSingles = totalTriples = totalHomeRuns = totalDoubles = totalHits = totalWalks = totalBattersUp = 0;
}

BoxScore::Inning::Inning()
{
    runs = outs = singles = doubles = triples = homeRuns = walks = hits = runner1Pos = runner2Pos = runner3Pos = batterPos = battersUp = 0;
}
