#include <iostream>
#include <cstdlib>
#include "redcard.h"

RedCard::RedCard(int v) : Card::Card(v)
{
    Card::SetColor("red"); // red card constructor
}

string RedCard::Description() const
{
    string d = Card::Description(); // use earlier Description function to get the first section of d
    int num; // number for switch statement
    string colorNum = Card::GetColor(); // getting the color of the card in a variable

    if (colorNum == "black") // sets number to zero if the color is black
    {
        num = 0;
    }
    else if (colorNum == "unknown") // sets number to 1 if the color is unknown
    {
        num = 1;
    }
    else if (colorNum == "red") // sets number to 2 if the color is red
    {
        num = 2;
    }

    d = d + ", Color = "; // setup for output statement

    switch (num) // switch statement to determine output based on previous if- eslse-if statement
    {
        case 0: d = d + "Black"; break;
        case 1: d = d + "Unknown"; break;
        case 2: d = d + "Red"; break;
    }

    return d;
}