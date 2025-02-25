// **************************************************************
// **************************************************************
//
// **********  DO NOT MODIFY ANYTHING IN THIS SECTION
//
// solution cpp file for project 10
// all helper function definitions go in this file

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Project_10.h"

using namespace std;

// **************************************************************
// **********  DO NOT MODIFY ANYTHING ABOVE THIS LINE
// **************************************************************

// **************************************************************
// **********   PUT ALL FUNCTION DEFINITIONS BELOW THIS COMMENT
// **************************************************************

// Function definitions start here. 

// *****************************************
// ************** CONTRUCTORS **************
// *****************************************

Money::Money()
{
	pennies = 0;
	nickels = 0;
	dimes = 0;
	quarters = 0;
}

Money::Money(int pennyNum, int nickelNum, int dimeNum, int quarterNum)
{
	pennies = pennyNum;
	nickels = nickelNum;
	dimes = dimeNum;
	quarters = quarterNum;
}

Money::Money(int pennyNum, int nickelNum, int dimeNum)
{
	pennies = pennyNum;
	nickels = nickelNum;
	dimes = dimeNum;
	quarters = 0;
}

Money::Money(int pennyNum, int nickelNum)
{
	pennies = pennyNum;
	nickels = nickelNum;
	dimes = 0;
	quarters = 0;
}

Money::Money(int pennyNum)
{
	pennies = pennyNum;
	nickels = 0;
	dimes = 0;
	quarters = 0;
}


// *****************************************
// ************** TRANSFORMERS **************
// *****************************************

void Money::SetMoney(int penNum, int nicNum, int dimNum, int quaNum)
{
	pennies = penNum;
	nickels = nicNum;
	dimes = dimNum;
	quarters = quaNum;
}


void Money::AddMoney(int penNum, int nicNum, int dimNum, int quaNum)
{
	pennies += penNum;
	nickels += nicNum;
	dimes += dimNum;
	quarters += quaNum;
}

void Money::AddMoney(int penNum, int nicNum, int dimNum)
{
	pennies += penNum;
	nickels += nicNum;
	dimes += dimNum;
}

void Money::AddMoney(int penNum, int nicNum)
{
	pennies += penNum;
	nickels += nicNum;
}

void Money::AddMoney(int penNum)
{
	pennies += penNum;
}

// *****************************************
// ************** OBSERVERS *******************
// *****************************************

void Money::WriteCoinTotals() const
{
	cout << "Number of Pennies: " << pennies << endl;
	cout << "Number of Nickels: " << nickels << endl;
	cout << "Number of Dimes: " << dimes << endl;
	cout << "Number of Quarters: " << quarters << endl;
}

void Money::WriteDollarTotal() const
{
	float dollarAmount;
	dollarAmount = (pennies*.01) + (nickels*.05) + (dimes*.10) + (quarters*.25);
	cout << "The dollar amount of the coins is : " << fixed << setprecision(2) << dollarAmount << endl;
}