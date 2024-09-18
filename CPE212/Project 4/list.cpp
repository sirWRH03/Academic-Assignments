#include <iostream>
#include <new>
#include "list.h"

using namespace std;

List::List()
{
    head = NULL;
    num = 0;
}

List::~List()
{
    Node* tempPtr;
    while (head != NULL)
    {
        tempPtr = head;
        head = head->next;
        delete tempPtr;
    }
}

void List::Append(string newword)
{
    try
    {
        if (num == 0)
        {
            Node* tempPtr = new Node;
            tempPtr->word = newword;
            head = tempPtr;
            num++;
        }
        else
        {
            Node* tempPtr;
            tempPtr = head;
            Node* tempNode = new Node;
            tempNode->word = newword;

            while (tempPtr->next != NULL)
            {
                tempPtr = tempPtr->next;
            }

            tempPtr->next = tempNode;
            tempNode->next = NULL;
            num++;
        }
    }
    catch ( std::bad_alloc )
    {
        throw ( ListFull() );
    }
}

void List::InsertAt(int pos, string newword)
{
    try
    {
        Node* tempPtr;
        Node* tempPtr2;
        Node* tempNode = new Node;

        tempPtr = head;
        tempNode->word = newword;

        if (pos > num || pos < 0)
        {
            throw ( ListBadPosition() );
        }
        else if (pos == num)
        {
            List::Append(newword);
        }
        else
        {
            for (int i = 0; i < pos; i++)
            {
                tempPtr2 = tempPtr;
                tempPtr = tempPtr->next;
            }
            
            tempNode->next = tempPtr;
        
            if (tempPtr == head)
            {
                head = tempNode;
            }
            else
            {
                tempPtr2->next = tempNode;
            }
            
            num++;
        }
    }
    catch( std::bad_alloc )
    {
        throw ( ListFull() );
    }
}

void List::Delete(string someword)
{
    if (List::Find(someword))
    {
        Node* tempPtr;
        tempPtr = head;
        Node* tempPtr2;
        Node* tempPtr3;

        if (head->word == someword)
        {
            //tempPtr2 = head;
            head = head->next;
            //delete tempPtr2;
        }
        else
        {
            while (tempPtr->next != NULL)
            {
                tempPtr3 = tempPtr;
                tempPtr = tempPtr->next;
                if (tempPtr->word == someword)
                {
                    tempPtr2 = tempPtr;
                    tempPtr2 = tempPtr->next;
                    tempPtr3->next = tempPtr2;
                    delete tempPtr;
                }
            }
        }
    }
    else
    {
        throw ( ListNotFound() );
    }
}

void List::Replace(string oldword, string newword)
{
    if (Find(oldword))
    {
        Node* tempPtr;
        if (head->word == oldword)
        {
            head->word = newword;
        }
        else
        {
            tempPtr = head;

            while (tempPtr->next != NULL)
            {
                tempPtr = tempPtr->next;
                if (tempPtr->word == oldword)
                {
                    tempPtr->word = newword;
                }
            }
        }
    }
    else
    {
        throw ( ListNotFound() );
    }
}

int List::Length() const
{
    return num;
}

bool List::Find(string someword) const
{
    Node* tempPtr = head;

    if (head->word == someword)
    {
        return true;
    }
    else if (head == NULL)
    {
        return false;
    }

    while (tempPtr->next != NULL)
    {
        tempPtr = tempPtr->next;
        if (tempPtr->word == someword)
        {
            return true;
        }

        if (tempPtr->next == NULL)
        {
            return false;
        }
    }
}