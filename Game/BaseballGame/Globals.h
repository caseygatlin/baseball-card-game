//
//  Globals.h
//  BaseballGame
//
//  Created by Casey Gatlin on 6/1/19.
//  Copyright © 2019 Casey Gatlin. All rights reserved.
//

#ifndef Globals_h
#define Globals_h

/*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*/
/*==*                            Enums                             *==*/
/*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*/

// Names for Suits
enum Suit
{
    NOSUIT,     // Used for default initialization
    HEART,
    DIAMOND,
    SPADE,
    CLUB,
    JOKER_SUIT
};

// Names and values of cards, Ace = 1, Two = 2, ..., Joker = 14
enum CardName
{
    NONAME,     // Used for default initialization
    ACE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    JOKER_CARD
};

#endif /* Globals_h */
