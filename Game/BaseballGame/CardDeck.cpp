//
//  CardDeck.cpp
//  baseball-card-game
//
//  Created by Casey Gatlin on 10/15/18.
//  Copyright © 2018 Casey Gatlin. All rights reserved.
//

/*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*/
/*==*                     Working on Overwrite                     *==*/
/*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*/

#include "GameClasses.h"
using namespace std;

CardDeck::CardSuit::CardSuit()
{
    ace.value = 1;
    two.value = 2;
    three.value = 3;
    four.value = 4;
    five.value = 5;
    six.value = 6;
    seven.value = 7;
    eight.value = 8;
    nine.value = 9;
    ten.value = 10;
    jack.value = 11;
    queen.value = 12;
    king.value = 13;
}

CardDeck::CardDeck()
{
    club = CardSuit();
    diamond = CardSuit();
    spade = CardSuit();
    heart = CardSuit();
    joker1.value = 14;
    joker2.value = 14;
}

void CardDeck::pushBackSuitP1(CardDeck::CardSuit suit)
{
    halfDeckP1.push_back(suit.ace);
    halfDeckP1.push_back(suit.two);
    halfDeckP1.push_back(suit.three);
    halfDeckP1.push_back(suit.four);
    halfDeckP1.push_back(suit.five);
    halfDeckP1.push_back(suit.six);
    halfDeckP1.push_back(suit.seven);
    halfDeckP1.push_back(suit.eight);
    halfDeckP1.push_back(suit.nine);
    halfDeckP1.push_back(suit.ten);
    halfDeckP1.push_back(suit.jack);
    halfDeckP1.push_back(suit.queen);
    halfDeckP1.push_back(suit.king);
}

void CardDeck::pushBackSuitP2(CardDeck::CardSuit suit)
{
    halfDeckP2.push_back(suit.ace);
    halfDeckP2.push_back(suit.two);
    halfDeckP2.push_back(suit.three);
    halfDeckP2.push_back(suit.four);
    halfDeckP2.push_back(suit.five);
    halfDeckP2.push_back(suit.six);
    halfDeckP2.push_back(suit.seven);
    halfDeckP2.push_back(suit.eight);
    halfDeckP2.push_back(suit.nine);
    halfDeckP2.push_back(suit.ten);
    halfDeckP2.push_back(suit.jack);
    halfDeckP2.push_back(suit.queen);
    halfDeckP2.push_back(suit.king);
}

void CardDeck::splitDeck()
{
    pushBackSuitP1(heart);
    pushBackSuitP1(diamond);
    pushBackSuitP2(spade);
    pushBackSuitP2(club);
    
    halfDeckP1.push_back(joker1);
    halfDeckP2.push_back(joker2);
}
