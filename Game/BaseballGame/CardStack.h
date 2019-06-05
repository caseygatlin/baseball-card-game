
#ifndef CARDSTACK_H
#define CARDSTACK_H

#include "Card.h"

const int MAX_STACK_ELEMENTS = 30;

class CardStack
{
public:

	void push(Card &card);
	Card pop();



private:
	Card m_stack[MAX_STACK_ELEMENTS];
};


#endif // !CARDSTACK_H
