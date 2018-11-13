//
//  Player.cpp
//  baseball-card-game
//
//  Created by Casey Gatlin on 10/15/18.
//  Copyright © 2018 Casey Gatlin. All rights reserved.
//

#include "GameClasses.h"
#include <vector>
#include <random>
#include <chrono>
#include <iostream>
using namespace std;

void Player::setStartingDeck(vector<CardDeck::Card> halfDeck)
{
    for (CardDeck::Card card : halfDeck)
    {
        startingDeck.push_back(card);
    }
}

void Player::removeJokerAndAces()
{
    for (int index = 0; index < startingDeck.size(); index++)
        if (startingDeck[index].value == 14 || startingDeck[index].value == 1)
            removedFromPlay.push_back(startingDeck.at(index));
    
    for (int index = 0; index < startingDeck.size(); index++)
        if (startingDeck[index].value == 14)
            startingDeck.erase(startingDeck.begin() + index);
    
    for (int index = 0; index < startingDeck.size(); index++)
        if (startingDeck[index].value == 1)
            startingDeck.erase(startingDeck.begin() + index);
    
    for (int index = 0; index < startingDeck.size(); index++)
        if (startingDeck[index].value == 1)
            startingDeck.erase(startingDeck.begin() + index);
}

void Player::shuffleStartDeck()
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(startingDeck.begin(), startingDeck.end(), default_random_engine(seed));
}

void Player::pickUpCard()
{
    if (pickup.size() <= 1)
        refreshPickup();
    
    hand.push_back(pickup.at(0));
    pickup.erase(pickup.begin());
}

void Player::setStartingAreas()
{
    
    // Draws 12 cards from the top of the deck
    for (int deckIndex = 0; deckIndex < 12; deckIndex++)
        field.push_back(startingDeck.at(deckIndex));
    for (int deckIndex = 0; deckIndex < 12; deckIndex++)
        startingDeck.erase(startingDeck.begin());
    
    //Puts the rest of the cards from the deck into the pickup pile
    for (int deckIndex_2 = 0; deckIndex_2 < startingDeck.size(); deckIndex_2++)
        pickup.push_back(startingDeck.at(deckIndex_2));
    for (int deckIndex_2 = 0; deckIndex_2 < startingDeck.size(); deckIndex_2++)
        startingDeck.erase(startingDeck.begin());
    
    // Puts the Aces and Joker into the pickup pile
    for (int remFromPlayIndex = 0; remFromPlayIndex < removedFromPlay.size(); remFromPlayIndex++)
        pickup.push_back(removedFromPlay.at(remFromPlayIndex));
    for (int remFromPlayIndex = 0; remFromPlayIndex < removedFromPlay.size(); remFromPlayIndex++)
        removedFromPlay.erase(removedFromPlay.begin());
    
    
    // Assigns the pitcher from the 12 cards drawn                                      PITCHER ASSIGNED
    int max = 0;
    int maxIndex = 0;
    
    for (int fieldIndex = 0; fieldIndex < field.size(); fieldIndex++)
    {
        if (field[fieldIndex].value > max)
        {
            max = field[fieldIndex].value;
            maxIndex = fieldIndex;
        }
    }
    
    pitcher.push_back(field.at(maxIndex));
    field.erase(field.begin() + maxIndex);
    
    pitcherStartValue = pitcher.at(0).value;

    
    // Takes out the lowest card from the field, leaving 10
    int min = 14;
    int minIndex = 0;
    
    for (int fieldIndex_2 = 0; fieldIndex_2 < field.size(); fieldIndex_2++)
    {
        if (field[fieldIndex_2].value < min)
        {
            min = field[fieldIndex_2].value;
            minIndex = fieldIndex_2;
        }
    }
    
    pickup.push_back(field.at(minIndex));
    field.erase(field.begin() + minIndex);
    
    
    // Takes out the next lowest card from the field, leaving 9                         FIELD ASSIGNED
    int min_2 = 14;
    int minIndex_2 = 0;
    
    for (int fieldIndex_3 = 0; fieldIndex_3 < field.size(); fieldIndex_3++)
    {
        if (field[fieldIndex_3].value < min_2)
        {
            min = field[fieldIndex_3].value;
            minIndex_2 = fieldIndex_3;
        }
    }
    
    pickup.push_back(field.at(minIndex_2));
    field.erase(field.begin() + minIndex_2);
    
    
    // Shuffles the pickup pile
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(pickup.begin(), pickup.end(), default_random_engine(seed));
    
    
    // Picks up 3 cards and puts them in the player's hand                              HAND ASSIGNED
    for ( int numberOfCards = 1; numberOfCards <= 3; numberOfCards++)
    {
        pickUpCard();
    }
    
    
    // Makes the first card in the field the first batter
    lastBatterIndex = 0;
}


void Player::setIsBatting(bool tf)
{
    isBatting = tf;
}


bool Player::getIsBatting()
{
    return isBatting;
}

void Player::refreshPickup()
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(discard.begin(), discard.end(), default_random_engine(seed));
    
    for (int discardIndex = 0; discardIndex < discard.size(); discardIndex++)
        pickup.push_back(discard.at(discardIndex));
    for (int discardIndex = 0; discardIndex < discard.size(); discardIndex++)
        discard.erase(discard.begin());
}

void Player::moveToNextBatter()
{
    lastBatterIndex++;
    
    if (lastBatterIndex > 8)
        lastBatterIndex = 0;
}

int Player::getLastBatterIndex()
{
    return lastBatterIndex;
}

void Player::refreshHand()
{
    // Discard current hand
    for ( int numCardsInHand = 1; numCardsInHand <= 3; numCardsInHand++)
    {
        discard.push_back(hand.at(0));
        hand.erase(hand.begin());
    }
    
    // Pick up three new cards
    for ( int numberOfCards = 1; numberOfCards <= 3; numberOfCards++)
    {
        pickUpCard();
    }
}

void Player::playCard()
{
    int playCardIndex = 0;
    bool cardNotChosen = true;
    while (cardNotChosen)
    {
        
        int defaultIndex = 5;
        int max = 0;
        int aceIndex, twoIndex, threeIndex, fiveIndex, newPitcherIndex, maxIndex;
        aceIndex = twoIndex = threeIndex = fiveIndex = newPitcherIndex = maxIndex = defaultIndex; // Assign a default hand index value that will not work
        
        for (int handIndex = 0; handIndex < hand.size(); handIndex++)
        {
            if (hand[handIndex].value == 1)
                aceIndex = handIndex;
            if (hand[handIndex].value == 2)
                twoIndex = handIndex;
            if (hand[handIndex].value == 3)
                threeIndex = handIndex;
            if (hand[handIndex].value == 5)
                fiveIndex = handIndex;
            if (hand[handIndex].value > max)
            {
                max = hand[handIndex].value;
                maxIndex = handIndex;
            }
        }
        
        if (max >= 10)
            newPitcherIndex = maxIndex;
        
        int batterVal = field.at(lastBatterIndex).value;
        
        // If the player has a 10 or higher and needs to replace their pitcher
        if (newPitcherIndex != defaultIndex && (pitcherStartValue - pitcher.at(0).value) >= 2)
            replacePitcher(newPitcherIndex);
    
        // If the player has an Ace and is pitching
        else if (aceIndex != defaultIndex && !isBatting)
        {
            playCardIndex = aceIndex;
            cardNotChosen = false;
        }
        
        // If the player has a Two, is batting, and batter is 9 or higher
        else if (twoIndex != defaultIndex && isBatting && batterVal > 8)
        {
            playCardIndex = twoIndex;
            cardNotChosen = false;
        }
        
        // If the player has a Two, and is pitching
        else if (twoIndex != defaultIndex && !isBatting)
        {
            playCardIndex = twoIndex;
            cardNotChosen = false;
        }
        
        // If the player is batting, has a Five, and batter is 10 or above
        else if (fiveIndex != defaultIndex && isBatting && batterVal >= 10)
        {
            playCardIndex = fiveIndex;
            cardNotChosen = false;
        }
        
        // If the current batter is a Three and player doesn't have a two or an ace or any cards higher than 7
        else if (isBatting && batterVal == 3 && max < 8 && twoIndex == defaultIndex && aceIndex == defaultIndex)
            refreshHand();
        
        // If the player has a Three, doesn't have a two or an ace or any cards higher than 7
        else if (threeIndex != defaultIndex && max < 8 && twoIndex == defaultIndex && aceIndex == defaultIndex)
            refreshHand();
        
        
        // If the player doesn't have any 5's, 3's, 2's, or Aces they can use wisely
        else
        {
            playCardIndex = maxIndex;
            cardNotChosen = false;
        }
    }
        
    
    playField.push_back(hand.at(playCardIndex));
    hand.erase(hand.begin() + playCardIndex);
    
}

void Player::decreasePitcherValue()
{
    pitcher.at(0).value--;
}

void Player::replacePitcher(int newPitcherHandIndex)
{
    removedFromPlay.push_back(pitcher.at(0));
    pitcher.erase(pitcher.begin());
    
    pitcher.push_back(hand.at(newPitcherHandIndex));
    hand.erase(hand.begin() + newPitcherHandIndex);
    
    pitcherStartValue = pitcher.at(0).value;
    
    pickUpCard();
}

void Player::cleanUp()
{
    for (int playfieldIndex = 0; playfieldIndex < playField.size(); playfieldIndex++)
        discard.push_back(playField.at(playfieldIndex));
    for (int playfieldIndex = 0; playfieldIndex < playField.size(); playfieldIndex++)
        playField.erase(playField.begin());
    
    while (hand.size() < 3)
        pickUpCard();
}

CardDeck::Card Player::getPlayFieldCard()
{
    return playField.at(0);
}

CardDeck::Card Player::getPitcher()
{
    return pitcher.at(0);
}

CardDeck::Card Player::getCurrentBatter()
{
    return field.at(lastBatterIndex);
}
