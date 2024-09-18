#include <iostream>
#include <new>
#include "stack.h"

using namespace std;

Stack::Stack(int n)
{
    array = new int[n];
    num = n;
    top = -1;
}

Stack::~Stack()
{
    delete array;
}

void Stack::Resize(int n)
{
    int NewArray[num];
    num = num * 2;

    for (int i = 0; i <= top; i++)
    {
        NewArray[i] = array[i];
    }

    array = new int[num];

    for (int i = 0; i < num; i++)
    {
        array[i] = NewArray[i];
    }

    Push(n);
}

void Stack::Push(int n)
{
    bool FullCheck = IsFull();

    switch (FullCheck)
    {
        case true:
            try
            {
                Resize(n);
            }
            catch ( std::bad_alloc )
            {
                throw StackFull();
            }
            break;

        case false:
            if (top == -1)
            {
                top = 0;
                array[top] = n;
            }
            else
            {
                top++;
                array[top] = n;
            }
            break;
    }
}

void Stack::Pop()
{
    bool EmptyCheck = IsEmpty();
    
    switch (EmptyCheck)
    {
        case true:
            throw StackEmpty();
            break;
        case false:
            top--;
            break;
    }
}

bool Stack::IsEmpty() const
{
    return (top == -1);
}

bool Stack::IsFull() const
{
    return (top == num-1);
}

void Stack::MakeEmpty()
{
    bool EmptyCheck = IsEmpty();
    
    switch (EmptyCheck)
    {
        case true:
            break;
        case false:
            array = new int[num];
            top = -1;
            break;
    }
}

int Stack::Top() const
{
    bool EmptyCheck = IsEmpty();

    switch (EmptyCheck)
    {
        case true:
            throw StackEmpty();
            break;
        case false:
            return array[top];
            break;
    }
}

int Stack::Size() const
{
    if (top == -1)
    {
        return 0;
    }
    else
    {
        return top + 1;
    }
}

int Stack::Max() const
{
    bool EmptyCheck = IsEmpty();
    
    switch (EmptyCheck)
    {
        case true:
            throw StackEmpty();
            break;
        case false:
            int Max;
            Max = array[0];
            
            for (int i = 1; i <= top; i++)
            {
                if (array[i] > Max)
                {
                    Max = array[i];
                }
            }

            return Max;
            break;
    }
}

int Stack::Min() const
{
    bool EmptyCheck = IsEmpty();
    
    switch (EmptyCheck)
    {
        case true:
            throw StackEmpty();
            break;
        case false:
            int Min;
            Min = array[0];
            
            for (int i = 1; i <= top; i++)
            {
                if (array[i] < Min)
                {
                    Min = array[i];
                }
            }   

            return Min;
            break;
    }
}

int Stack::Peek(unsigned int n) const
{
    if ((top == -1) or (n > top))
    {
        throw StackInvalidPeek();
    }
    else if (n == 0)
    {
        return Top();
    }
    else
    {
        return array[top-n];
    }
}

int Stack::Capacity() const
{
    return num;
}