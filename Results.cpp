//
//  Results.cpp
//  baseball-card-game
//
//  Created by Casey on 10/11/18.
//  Copyright © 2018 Casey Gatlin. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include "GameClasses.h"
using namespace std;

Results::Results(int runs,
                 int hits,
                 int singles,
                 int doubles,
                 int triples,
                 int homeRuns,
                 int walks,
                 int blowouts,
                 int ties,
                 int RunDiff4,
                 int RunDiff3,
                 int RunDiff2,
                 int RunDiff1,
                 int numberOfGames,
                 int battersUp)
{
    all_Runs = runs;
    all_Hits = hits;
    all_Singles = singles;
    all_Doubles = doubles;
    all_Triples = triples;
    all_Home_Runs = homeRuns;
    all_Walks = walks;
    all_BattersUp = battersUp;
    all_Blowouts = blowouts;
    all_Ties = ties;
    all_4RunDiff = RunDiff4;
    all_3RunDiff = RunDiff3;
    all_2RunDiff = RunDiff2;
    all_1RunDiff = RunDiff1;
    number_of_Games = numberOfGames;
}

int Results::getAllRuns()
{
    return all_Runs;
}

int Results::getAllHits()
{
    return all_Hits;
}

int Results::getAllSingles()
{
    return all_Singles;
}

int Results::getAllDoubles()
{
    return all_Doubles;
}

int Results::getAllTriples()
{
    return all_Triples;
}

int Results::getAllHomeRuns()
{
    return all_Home_Runs;
}

int Results::getAllWalks()
{
    return all_Walks;
}

int Results::getBattersUp()
{
    return all_BattersUp;
}

void Results::setNumberOfGames(int numberOfGames)
{
    number_of_Games = numberOfGames;
}

void Results::incrementResult(ResultType RESULT_TYPE, int valueToAdd)
{
    switch (RESULT_TYPE)
    {
        case HIT:
            all_Hits += valueToAdd;
            break;
        case RUN:
            all_Runs += valueToAdd;
            break;
        case SINGLE_H:
            all_Singles += valueToAdd;
            break;
        case DOUBLE_H:
            all_Doubles += valueToAdd;
            break;
        case TRIPLE_H:
            all_Triples += valueToAdd;
            break;
        case HOME_RUN_H:
            all_Home_Runs += valueToAdd;
            break;
        case WALK:
            all_Walks += valueToAdd;
            break;
        case BATTER_UP:
            all_BattersUp += valueToAdd;
        default:
            break;
    }
}

void Results::calculateTotals(BoxScore boxScore)
{
    //Increments all major result types
    incrementResult(HIT, boxScore.totalHits);
    incrementResult(RUN, boxScore.totalRuns);
    incrementResult(SINGLE_H, boxScore.totalSingles);
    incrementResult(DOUBLE_H, boxScore.totalDoubles);
    incrementResult(TRIPLE_H, boxScore.totalTriples);
    incrementResult(HOME_RUN_H, boxScore.totalHomeRuns);
    incrementResult(WALK, boxScore.totalWalks);
    incrementResult(BATTER_UP, boxScore.totalBattersUp);
    
    
    // Calculates and increments blowouts
    int runsP1 = 0;
    int runsP2 = 0;
    for (int inningIndex = 0; inningIndex < boxScore.game.size(); inningIndex++)
    {
        if ((inningIndex % 2) == 0)
            runsP2 += boxScore.game[inningIndex].runs;
        else
            runsP1 += boxScore.game[inningIndex].runs;
    }
    
    int runDiff = abs(runsP1 - runsP2);
    switch (runDiff)
    {
        case (0):
            all_Ties++;
            break;
        case (1):
            all_1RunDiff++;
            break;
        case (2):
            all_2RunDiff++;
            break;
        case (3):
            all_3RunDiff++;
        case (4):
            all_4RunDiff++;
        case (5):
            break;
            
        default:
            all_Blowouts++;
            break;
    }
}

void Results::displayResults()
{
    // Calculates per-game statistics
    double hitsPerGame = static_cast<double>(all_Hits)/static_cast<double>(number_of_Games);
    double walksPerGame = static_cast<double>(all_Walks)/static_cast<double>(number_of_Games);
    double singlesPerGame = static_cast<double>(all_Singles)/static_cast<double>(number_of_Games);
    double doublesPerGame = static_cast<double>(all_Doubles)/static_cast<double>(number_of_Games);
    double triplesPerGame = static_cast<double>(all_Triples)/static_cast<double>(number_of_Games);
    double homeRunsPerGame = static_cast<double>(all_Home_Runs)/static_cast<double>(number_of_Games);
    double runsPerGame = static_cast<double>(all_Runs)/static_cast<double>(number_of_Games);
    double battersPerGame = static_cast<double>(all_BattersUp)/static_cast<double>(number_of_Games);
    
    
    // Displays totals and per-game statistics
    int width;
    if (number_of_Games <= 500)
        width = 5;
    else
        width = 7;
    
    cout << endl;
    cout << "NUMBER OF GAMES: " << number_of_Games << endl;
    cout << endl;
    cout << "-----Totals--And--Per--Game-----" << endl;
    cout << "Hits: " << "\t" << "\t" << setfill('_') << setw(width) << all_Hits;
    cout << "\t" << "\t" << "Hits per game: " << "\t" << "\t" << "\t" << hitsPerGame << endl;
    cout << "Runs: " << "\t" << "\t" << setfill('_') << setw(width) << all_Runs;
    cout << "\t" << "\t" << "Runs per game: " << "\t" << "\t" << "\t" << runsPerGame << endl;
    cout << "Singles: " << "\t" << setfill('_') << setw(width) << all_Singles;
    cout << "\t" << "\t" << "Singles per game: " << "\t" << "\t" << singlesPerGame << endl;
    cout << "Doubles: " << "\t" << setfill('_') << setw(width) << all_Doubles;
    cout << "\t" << "\t" << "Doubles per game: " << "\t" << "\t" << doublesPerGame << endl;
    cout << "Triples: " << "\t" << setfill('_') << setw(width) << all_Triples;
    cout << "\t" << "\t" << "Triples per game: " << "\t" << "\t" << triplesPerGame << endl;
    cout << "Home Runs: " << "\t" << setfill('_') << setw(width) << all_Home_Runs;
    cout << "\t" << "\t" << "Home runs per game: " << "\t" << homeRunsPerGame << endl;
    cout << "Walks: " << "\t" << "\t" << setfill('_') << setw(width) << all_Walks;
    cout << "\t" << "\t" << "Walks per game: " << "\t" << "\t" << walksPerGame << endl;
    cout << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "Batters Per Game: " << "\t" << "\t" << battersPerGame << endl;
    cout << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "Batters Per Inning: " << "\t" << battersPerGame/18 << endl;
    cout << endl;
    
    
    // Calculates overall percentages of hits and blowouts
    double percSingles = static_cast<double>(all_Singles)/static_cast<double>(all_Hits) * 100;
    double percDoubles = static_cast<double>(all_Doubles)/static_cast<double>(all_Hits) * 100;
    double percTriples = static_cast<double>(all_Triples)/static_cast<double>(all_Hits) * 100;
    double percHomeRuns = static_cast<double>(all_Home_Runs)/static_cast<double>(all_Hits) * 100;
    double percBlowouts = static_cast<double>(all_Blowouts)/static_cast<double>(number_of_Games) * 100;
    double percTies = static_cast<double>(all_Ties)/static_cast<double>(number_of_Games) * 100;
    double perc1Run = static_cast<double>(all_1RunDiff)/static_cast<double>(number_of_Games) * 100;
    double perc2Run = static_cast<double>(all_2RunDiff)/static_cast<double>(number_of_Games) * 100;
    double perc3Run = static_cast<double>(all_3RunDiff)/static_cast<double>(number_of_Games) * 100;
    double perc4Run = static_cast<double>(all_4RunDiff)/static_cast<double>(number_of_Games) * 100;
    
    
    // Displays overall percentages of hits and blowouts
    cout << "-----Percentages--Overall-----" << endl;
    cout << "Singles: " << "\t" << percSingles << "%" << endl;
    cout << "Doubles: " << "\t" << percDoubles << "%" << endl;
    cout << "Triples: " << "\t" << percTriples << "%" << endl;
    cout << "Home Runs: " << "\t" << percHomeRuns << "%" << endl;
    cout << "-----" << endl;
    cout << "> 5 Runs: " << "\t" << percBlowouts << "%" << endl;
    cout << "4 Runs: " << "\t" << perc4Run << "%" << endl;
    cout << "3 Runs: " << "\t" << perc3Run << "%" << endl;
    cout << "2 Runs: " << "\t" << perc2Run << "%" << endl;
    cout << "1 Run: " << "\t" << "\t" << perc1Run << "%" << endl;
    cout << "Ties: " << "\t" << "\t" << percTies << "%" << endl;
    cout << "------------------------------" << endl;
    cout << endl;
    
}
