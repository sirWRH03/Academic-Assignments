#include <iostream>
#include <cstdlib>
#include "heart.h"

using namespace std;

Heart::Heart(int v) : RedCard::RedCard(v)
{
    Card::SetSuit('H');
}

string Heart::Description() const
{
    string d = RedCard::Description();
    d = d + ", Suit = H";
    return d;
}