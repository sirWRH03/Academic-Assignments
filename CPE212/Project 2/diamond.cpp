#include <iostream>
#include <cstdlib>
#include "diamond.h"

using namespace std;

Diamond::Diamond(int v) : RedCard::RedCard(v)
{
    Card::SetSuit('D');
}

string Diamond::Description() const
{
    string d = RedCard::Description();
    d = d + ", Suit = D";
    return d;
}