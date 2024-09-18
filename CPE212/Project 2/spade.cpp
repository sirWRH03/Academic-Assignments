#include <iostream>
#include <cstdlib>
#include "spade.h"

using namespace std;

Spade::Spade(int v) : BlackCard::BlackCard(v)
{
    Card::SetSuit('S');
}

string Spade::Description() const
{
    string d = BlackCard::Description();
    d = d + ", Suit = S";
    return d;
}