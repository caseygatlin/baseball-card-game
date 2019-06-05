//
//  CardStack.cpp
//  BaseballGame
//
//  Created by Casey Gatlin on 6/5/19.
//  Copyright © 2019 Casey Gatlin. All rights reserved.
//

#include "CardStack.h"
#include <random>
#include <chrono>

using namespace std;

CardStack::CardStack()
{
    m_top = 0;
}

int CardStack::size()
{
    return m_top;
}

bool CardStack::isEmpty()
{
    if (m_top == 0)
        return true;
    return false;
}

void CardStack::push(Card &card)
{
    m_stack[m_top] = card;
    m_top++;
}

bool CardStack::pop(Card &cardVar)
{
    if (m_top == 0)
        return false;
    
    m_top--;
    cardVar = m_stack[m_top];
    return true;
}

void CardStack::shuffleStack(default_random_engine generator)
{
    shuffle(m_stack, m_stack + MAX_STACK_ELEMENTS, generator);
}
