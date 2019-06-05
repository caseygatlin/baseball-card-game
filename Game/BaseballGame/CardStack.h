//
//  CardStack.h
//  BaseballGame
//
//  Created by Casey Gatlin on 6/5/19.
//  Copyright © 2019 Casey Gatlin. All rights reserved.
//


#ifndef CARDSTACK_H
#define CARDSTACK_H

#include "Card.h"
#include <random>
#include <chrono>

const int MAX_STACK_ELEMENTS = 30;
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

class CardStack
{
public:
    //Constructor
    CardStack();
    
    //Accessor
    int size();
    bool isEmpty();
    
    //Methods for adding / removing cards
	void push(Card &card);
	bool pop(Card &cardVar);
    
    //Shuffles the cards
    void shuffleStack(std::default_random_engine generator = std::default_random_engine(seed));

private:
	Card m_stack[MAX_STACK_ELEMENTS];
    int m_top;
};


#endif // !CARDSTACK_H
