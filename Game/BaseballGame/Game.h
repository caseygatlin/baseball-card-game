//
//  Game.h
//  baseball-card-game
//
//  Created by Casey Gatlin on 9/24/18.
//  Copyright © 2018 Casey Gatlin. All rights reserved.
//

/*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*/
/*==*                     Working on Overwrite                     *==*/
/*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*/

#ifndef Game_h
#define Game_h

#include <iostream>
#include "GameClasses.h"

HitValues assignHitValues(HitValues emptyHitValues);

BoxScore::Inning walkLogistics (BoxScore::Inning inning);

BoxScore::Inning hitBallLogistics (BoxScore::Inning inning, int hitType);

void mainPlayLoop (BoxScore::Inning  &inning, Player &player1, Player &player2, HitValues hitValues);

BoxScore::Inning runInning (Player &player1, Player &player2, HitValues hitValues);

void playGame(Player &player1, Player &player2, BoxScore &boxScore);

#endif /* Game_h */
