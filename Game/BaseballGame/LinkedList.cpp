//
//  LinkedList.cpp
//  BaseballGame
//
//  Created by Casey Gatlin on 6/3/19.
//  Copyright © 2019 Casey Gatlin. All rights reserved.
//

#include "LinkedList.h"

//---------------------------------------------------------------------
// Constructors, destructor, and assignment operator ------------------
//---------------------------------------------------------------------
LinkedList::LinkedList()
{
    head = nullptr;
    m_size = 0;
}

LinkedList::LinkedList(const LinkedList& rhs)
{
    //Copy the size of the other list
    m_size = rhs.m_size;
    
    //If the rhs is empty return an empty list
    head = nullptr;
    Node *srcP = rhs.head;
    if (rhs.head == nullptr)
        return;
    
    //If it's not empty, copy over the head
    head = new Node;
    Node *p = head;
    p->card_n = srcP->card_n;
    
    //Then continue copying until the end of the rhs list
    if (srcP->next != nullptr)
        srcP = srcP->next;
    
    while (srcP != nullptr)
    {
        Node *n = new Node;
        p->next= n;
        n->card_n = srcP->card_n;
        p = n;
        srcP = srcP->next;
    }
    p->next = nullptr;
}

LinkedList::~LinkedList()
{
    m_size = 0;
    
    //Move through the nodes, saving the next
    //node with 'n' and then deleting the current node.
    Node *p = head;
    while (p != nullptr)
    {
        Node *n = p->next;
        delete p;
        p = n;
    }
}

const LinkedList& LinkedList::operator=(const LinkedList& rhs)
{
    //Account for aliasing
    if (&rhs == this)
        return (*this);
    
    //Destructor code
    Node *p = head;
    while (p != nullptr)
    {
        Node *n = p->next;
        delete p;
        p = n;
    }
    
    //Copy constructor code
    m_size = rhs.m_size;
    
    head = nullptr;
    Node *srcP = rhs.head;
    if (rhs.head == nullptr)
        return (*this);
    
    head = new Node;
    p = head;
    p->card_n = srcP->card_n;
    
    if (srcP->next != nullptr)
        srcP = srcP->next;
    
    while (srcP != nullptr)
    {
        Node *n = new Node;
        p->next= n;
        n->card_n = srcP->card_n;
        p = n;
        srcP = srcP->next;
    }
    p->next = nullptr;
    return (*this);
}

//---------------------------------------------------------------------
// Accessors ----------------------------------------------------------
//---------------------------------------------------------------------
bool LinkedList::isEmpty()
{
    if (head == nullptr)
        return true;
    return false;
}

int LinkedList::size()
{
    return m_size;
}

//---------------------------------------------------------------------
// Inserting / Deleting -----------------------------------------------
//---------------------------------------------------------------------
void LinkedList::insertToRear(const Card &cardInstance)
{
    //Create the new node
    Node *newLast = new Node;
    newLast->card_n = cardInstance;
    newLast->next = nullptr;
    
    //If the list is empty, make the head the new node
    if (head == nullptr)
        head = newLast;
    
    //Otherwise traverse to the end and insert it there
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newLast;
    }
    
    //Increase size
    m_size++;
}

bool LinkedList::removeItem(Card &cardVariable)
{
    //Check if list is empty, if so, return failure
    if (head == nullptr)
        return false;
    
    //Point head to next node value
    Node * killMe = head;
    head = killMe->next;
    
    //Assign our removed item to cardVariable
    cardVariable = killMe->card_n;
    
    //Deallocate memory
    delete killMe;
    
    //Reduce size, return success
    m_size--;
    return true;
}
