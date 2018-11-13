//
//  Game.cpp
//  baseball-card-game
//
//  Created by Casey Gatlin on 9/24/18.
//  Copyright © 2018 Casey Gatlin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "Game.h"
#include "GameClasses.h"
using namespace std;


HitValues assignHitValues(HitValues emptyHitValues)
{
    //            SINGLES
    emptyHitValues.singles.push_back(1);
    emptyHitValues.singles.push_back(2);
    emptyHitValues.singles.push_back(3);
    emptyHitValues.singles.push_back(7);
    emptyHitValues.singles.push_back(11);
    emptyHitValues.singles.push_back(13);
    emptyHitValues.singles.push_back(17);
    emptyHitValues.singles.push_back(19);
    emptyHitValues.singles.push_back(23);
    emptyHitValues.singles.push_back(25);
    
    //            DOUBLES
    emptyHitValues.doubles.push_back(4);
    emptyHitValues.doubles.push_back(6);
    emptyHitValues.doubles.push_back(10);
    emptyHitValues.doubles.push_back(14);
    emptyHitValues.doubles.push_back(18);
    emptyHitValues.doubles.push_back(22);
    emptyHitValues.doubles.push_back(26);
    
    //            TRIPLES
    emptyHitValues.triples.push_back(9);
    emptyHitValues.triples.push_back(15);
    emptyHitValues.triples.push_back(21);
    
    
    //            HOME RUNS
    emptyHitValues.homeRuns.push_back(5);
    emptyHitValues.homeRuns.push_back(8);
    emptyHitValues.homeRuns.push_back(12);
    emptyHitValues.homeRuns.push_back(16);
    emptyHitValues.homeRuns.push_back(20);
    emptyHitValues.homeRuns.push_back(24);
    
    return emptyHitValues;
}


BoxScore::Inning walkLogistics (BoxScore::Inning inning)
{
    BoxScore::Inning dummyInning = inning;
    
    dummyInning.walks++;
    
    if (dummyInning.runner3Pos == 3 &&
        dummyInning.runner2Pos == 2 &&
        dummyInning.runner1Pos == 1)
        dummyInning.runs++;
    
    else if (dummyInning.runner2Pos == 2 &&
             dummyInning.runner1Pos == 1)
        dummyInning.runner3Pos = 3;
    
    else if (dummyInning.runner1Pos == 1)
        dummyInning.runner2Pos = 2;
    
    else
        dummyInning.runner1Pos = 1;
    
    return dummyInning;
}

BoxScore::Inning hitBallLogistics (BoxScore::Inning inning, int hitType)
{
    BoxScore::Inning dummyInning = inning;
    int newRunPos1;
    int newRunPos2;
    int newRunPos3;
    int newBatPos = 0;
    
    dummyInning.hits++;
    
    if (hitType == 1)
        dummyInning.singles++;
    if (hitType == 2)
        dummyInning.doubles++;
    if (hitType == 3)
        dummyInning.triples++;
    if (hitType == 4)
        dummyInning.homeRuns++;
    
    /*
    if (hitType == 1)
        cout << "It's a single" << endl;
    if (hitType == 2)
        cout << "It's a double" << endl;
    if (hitType == 3)
        cout << "It's a triple" << endl;
    if (hitType == 4)
        cout << "It's a home run" << endl;
    cout << endl;
    */
    
    
    
    dummyInning.batterPos = hitType;
    dummyInning.runner1Pos += hitType;
    dummyInning.runner2Pos += hitType;
    dummyInning.runner3Pos += hitType;
    
    
    if (dummyInning.batterPos == 4)
    {
        dummyInning.runs++;
        dummyInning.batterPos = 0;
    }
    if (dummyInning.runner3Pos >= 4)
    {
        dummyInning.runs++;
        dummyInning.runner3Pos = 0;
    }
    if (dummyInning.runner2Pos >= 4)
    {
        dummyInning.runs++;
        dummyInning.runner2Pos = 0;
    }
    if (dummyInning.runner1Pos >= 4)
    {
        dummyInning.runs++;
        dummyInning.runner1Pos = 0;
    }
    
    if (dummyInning.batterPos == 3 ||
        dummyInning.runner1Pos == 3 ||
        dummyInning.runner2Pos == 3)
        newRunPos3 = 3;
    else
        newRunPos3 = 0;
    
    
    if (dummyInning.batterPos == 2 ||
        dummyInning.runner1Pos == 2)
        newRunPos2 = 2;
    else
        newRunPos2 = 0;
    
    
    if (dummyInning.batterPos == 1)
        newRunPos1 = 1;
    else
        newRunPos1 = 0;
    
    dummyInning.batterPos = newBatPos;
    dummyInning.runner1Pos = newRunPos1;
    dummyInning.runner2Pos = newRunPos2;
    dummyInning.runner3Pos = newRunPos3;
    
    return dummyInning;
    
}

/////////////////////////
/////////////////////////
//THIS IS THE MAIN LOOP//
/////////////////////////
/////////////////////////
void mainPlayLoop (BoxScore::Inning  &inning, Player &player1, Player &player2, HitValues hitValues)
{
    
    int currentOuts = inning.outs;
    // cout << "Outs: " << currentOuts << endl;
    int endOuts = currentOuts + 1;
    
    while (inning.outs < endOuts)
    {
        
        player1.playCard();
        player2.playCard();
        
        CardDeck::Card p1PlayedCard = player1.getPlayFieldCard();
        CardDeck::Card p2PlayedCard = player2.getPlayFieldCard();
        
        CardDeck::Card pitcher = player1.getPitcher();
        CardDeck::Card batter = player2.getCurrentBatter();
        
        
        int throwValue = p1PlayedCard.value + pitcher.value;
        int batValue = p2PlayedCard.value + batter.value;
        bool fiveInEffect = false;
        
        if (p1PlayedCard.value == 2)
            throwValue = pitcher.value * 2;
        
        if (p2PlayedCard.value == 2)
            batValue = batter.value * 2;
        
        if (p2PlayedCard.value == 5)
            fiveInEffect = true;
        
        if (batter.value == 5)
            fiveInEffect = true;
        
        
        /*
        cout << "Pitcher: " << pitcher.value << " + " << p1PlayedCard.value << " = " << throwValue << endl;
        cout << "Batter: " << batter.value << " + " << p2PlayedCard.value << " = " << batValue << endl;
        cout << endl;
        */
        
        
        /*
        if (p2PlayedCard.value == 1) //         IT'S A WALK     (ACE)
        {
            inning = walkLogistics(inning);
            
            player1.cleanUp();
            player2.cleanUp();
            player2.moveToNextBatter();
            
            inning.battersUp++;
            break;
        }
         */
        
        
        
        if (p1PlayedCard.value == 1) //    IT'S AN OUT     (ACE)
        {
            player1.cleanUp();
            player2.cleanUp();
            player2.moveToNextBatter();
            
            int player2BatIndex = player2.getLastBatterIndex();
            if (player2BatIndex == 0)
                player1.decreasePitcherValue();
            
            inning.battersUp++;
            inning.outs++;
            break;
        }
        
        else if (throwValue > batValue)
        {
            if (fiveInEffect && ((throwValue - batValue) < 5)) // IT'S A WALK
            {
                walkLogistics(inning);
                
                player1.cleanUp();
                player2.cleanUp();
                player2.moveToNextBatter();
                
                int player2BatIndex = player2.getLastBatterIndex();
                if (player2BatIndex == 0)
                    player1.decreasePitcherValue();
                
                inning.battersUp++;
                break;
            }
            
            else //                             IT'S AN OUT
            {
                player1.cleanUp();
                player2.cleanUp();
                player2.moveToNextBatter();
                
                int player2BatIndex = player2.getLastBatterIndex();
                if (player2BatIndex == 0)
                    player1.decreasePitcherValue();
                
                inning.battersUp++;
                inning.outs++;
                break;
            }
        }
        
        else if (batValue > throwValue) //      IT'S A HIT
        {
            int thisHitValue = batValue - throwValue;
            int hitType = 0;
            if (std::find(hitValues.singles.begin(), hitValues.singles.end(), thisHitValue) != hitValues.singles.end())
                hitType = 1;
            else if (std::find(hitValues.doubles.begin(), hitValues.doubles.end(), thisHitValue) != hitValues.doubles.end())
                hitType = 2;
            else if (std::find(hitValues.triples.begin(), hitValues.triples.end(), thisHitValue) != hitValues.triples.end())
                hitType = 3;
            else if (std::find(hitValues.homeRuns.begin(), hitValues.homeRuns.end(), thisHitValue) != hitValues.homeRuns.end())
                hitType = 4;
            else
            {
                std::cout << "ERROR: Hit value not found" << std::endl;
                break;
            }
            inning = hitBallLogistics(inning, hitType);
            
            player1.cleanUp();
            player2.cleanUp();
            player2.moveToNextBatter();
            
            int player2BatIndex = player2.getLastBatterIndex();
            if (player2BatIndex == 0)
                player1.decreasePitcherValue();
            
            inning.battersUp++;
        }
        else if (batValue == throwValue) //     IT'S A WALK
        {
            inning = walkLogistics(inning);
                
            player1.cleanUp();
            player2.cleanUp();
            player2.moveToNextBatter();
            
            int player2BatIndex = player2.getLastBatterIndex();
            if (player2BatIndex == 0)
                player1.decreasePitcherValue();
            
            inning.battersUp++;
        }
        else
        {
            std::cout << "ERROR: Main While Loop did not execute correctly" << std::endl;
            break;
        }
    }
}

BoxScore::Inning runInning (Player &player1, Player &player2, HitValues hitValues)
{
    BoxScore::Inning thisInning = BoxScore::Inning();
    player1.setIsBatting(false);
    player2.setIsBatting(true);
    
    while (thisInning.outs < 3)
        mainPlayLoop(thisInning, player1, player2, hitValues);
    
    return thisInning;
}


void playGame(Player &player1, Player &player2, BoxScore &boxScore)
{
    
    HitValues hitValues;
    hitValues = assignHitValues(hitValues);
    
    for (int inningCount = 1; inningCount <= 9; inningCount++)
    {
        boxScore.game.push_back(runInning(player1, player2, hitValues));
        boxScore.game.push_back(runInning(player2, player1, hitValues));
    }
    
    for (BoxScore::Inning inning : boxScore.game)
    {
        boxScore.totalHits += inning.hits;
        boxScore.totalRuns += inning.runs;
        boxScore.totalWalks += inning.walks;
        boxScore.totalSingles += inning.singles;
        boxScore.totalDoubles += inning.doubles;
        boxScore.totalTriples += inning.triples;
        boxScore.totalHomeRuns += inning.homeRuns;
        boxScore.totalBattersUp += inning.battersUp;
    }
    
}
