//
//  GameClasses.h
//  baseball-card-game
//
//  Created by Casey Gatlin on 9/24/18.
//  Copyright © 2018 Casey Gatlin. All rights reserved.
//

/*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*/
/*==*                     Working on Overwrite                     *==*/
/*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*/

#ifndef GameClasses_h
#define GameClasses_h

#include <iostream>
#include <vector>
#include <sstream>

class CardDeck
{
public:
    CardDeck();
    class Card
    {
    public:
        int value;
    };
    class CardSuit
    {
    public:
        CardSuit();
        Card ace;
        Card two;
        Card three;
        Card four;
        Card five;
        Card six;
        Card seven;
        Card eight;
        Card nine;
        Card ten;
        Card jack;
        Card queen;
        Card king;
    };
    CardSuit heart;
    CardSuit diamond;
    CardSuit spade;
    CardSuit club;
    Card joker1;
    Card joker2;
    void pushBackSuitP1(CardDeck::CardSuit suit);
    void pushBackSuitP2(CardDeck::CardSuit suit);
    void splitDeck();
    std::vector<CardDeck::Card> halfDeckP1;
    std::vector<CardDeck::Card> halfDeckP2;
};

class Player
{
public:
    void setStartingDeck(std::vector<CardDeck::Card> halfDeck);
    void removeJokerAndAces();
    void shuffleStartDeck();
    void pickUpCard();
    void setStartingAreas();
    void setIsBatting(bool tf);
    bool getIsBatting();
    
    void refreshPickup();
    void moveToNextBatter();
    int getLastBatterIndex();
    void refreshHand();
    void playCard();
    void decreasePitcherValue();
    void replacePitcher(int newPitcherHandIndex);
    CardDeck::Card getPlayFieldCard();
    CardDeck::Card getPitcher();
    CardDeck::Card getCurrentBatter();
    void cleanUp(); // erase card from playField, put to discard. Pick up new card.
    
private:
    std::vector<CardDeck::Card> hand;
    std::vector<CardDeck::Card> field;
    std::vector<CardDeck::Card> pickup;
    std::vector<CardDeck::Card> discard;
    std::vector<CardDeck::Card> pitcher;
    std::vector<CardDeck::Card> playField;
    std::vector<CardDeck::Card> startingDeck;
    std::vector<CardDeck::Card> removedFromPlay;
    int lastBatterIndex;
    bool isBatting;
    int pitcherStartValue;
    
};

class BoxScore
{
public:
    BoxScore();
    class Inning
    {
    public:
        Inning();
        int runs;
        int outs;
        int singles;
        int doubles;
        int triples;
        int homeRuns;
        int walks;
        int hits;
        int battersUp;
        int runner1Pos;
        int runner2Pos;
        int runner3Pos;
        int batterPos;
    };
    std::vector<Inning> game;
    int totalRuns;
    int totalSingles;
    int totalTriples;
    int totalHomeRuns;
    int totalDoubles;
    int totalHits;
    int totalWalks;
    int totalBattersUp;
};

class HitValues
{
public:
    std::vector<int> singles;
    std::vector<int> doubles;
    std::vector<int> triples;
    std::vector<int> homeRuns;
};

enum ResultType
{
    RUN,
    HIT,
    SINGLE_H,
    DOUBLE_H,
    TRIPLE_H,
    HOME_RUN_H,
    WALK,
    BATTER_UP
};

class Results
{
public:
    Results(int runs = 0,
            int hits = 0,
            int singles = 0,
            int doubles = 0,
            int triples = 0,
            int homeRuns = 0,
            int walks = 0,
            int blowouts = 0,
            int ties = 0,
            int RunDiff4 = 0,
            int RunDiff3 = 0,
            int RunDiff2 = 0,
            int RunDiff1 = 0,
            int numberOfGames = 0,
            int battersUp = 0);
    int getAllRuns();
    int getAllHits();
    int getAllSingles();
    int getAllDoubles();
    int getAllTriples();
    int getAllHomeRuns();
    int getAllWalks();
    int getBattersUp();
    void setNumberOfGames(int numberOfGames);
    void incrementResult(ResultType RESULT_TYPE, int valueToAdd);
    void calculateTotals(BoxScore boxScore);
    void displayResults();
private:
    int all_Runs;
    int all_Hits;
    int all_Singles;
    int all_Doubles;
    int all_Triples;
    int all_Home_Runs;
    int all_Walks;
    int all_Blowouts;
    int all_Ties;
    int all_4RunDiff;
    int all_3RunDiff;
    int all_2RunDiff;
    int all_1RunDiff;
    int all_BattersUp;
    int number_of_Games;
};

#endif /* GameClasses_h */
