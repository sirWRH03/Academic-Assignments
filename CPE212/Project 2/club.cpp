#include <iostream>
#include <cstdlib>
#include "club.h"

using namespace std;

Club::Club(int v) : BlackCard::BlackCard(v)
{
    Card::SetSuit('C');
}

string Club::Description() const
{
    string d = BlackCard::Description();
    d = d + ", Suit = C";
    return d;
}