//
//  LinkedList.h
//  BaseballGame
//
//  Created by Casey Gatlin on 6/3/19.
//  Copyright © 2019 Casey Gatlin. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include "Card.h"

struct Node
{
    Card card_n;
    Node * next;
};

class LinkedList
{
public:
    //Constructors, destructor, assignment operator
    LinkedList();
    LinkedList(const LinkedList& rhs);
    ~LinkedList();
    const LinkedList& operator=(const LinkedList& rhs);
    
    //Accessors
    bool isEmpty();
    int size();
    
    //Inserting/deleting
    void insertToRear(const Card &cardInstance);
    bool removeItem(Card &cardVariable);
    
private:
    Node * head;
    int m_size;
};

#endif /* LinkedList_h */
