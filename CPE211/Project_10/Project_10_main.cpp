// *************************************************************
// main function declaration to run the class funcitons
// DO NOT MODIFY THIS FILE
// **************************************************************

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Project_10.h" 

using namespace std;

int main()
{

    // construct 5 objects of the class - one using 
    // default values, and the others using paramertized constructors
    //
    cout << "Constructor Test\n";
    cout << "----------------\n";
    cout << "      Default Constructor\n";
    Money purse1;
    purse1.WriteCoinTotals();
    purse1.WriteDollarTotal();
    cout << string(40,'*') << endl << endl;

    cout << "      Parameterized Constructor(4 arguments)\n";
    Money purse2(6,5,4,3);
    purse2.WriteCoinTotals();
    purse2.WriteDollarTotal();
    cout << string(40,'*')  << endl << endl;

    cout << "      Parameterized Constructor(3 arguments)\n";
    Money purse3(16,15,14);
    purse3.WriteCoinTotals();
    purse3.WriteDollarTotal();
    cout << string(40,'*')  << endl << endl;

    cout << "      Parameterized Constructor(2 arguments)\n";
    Money purse4(26,76);
    purse4.WriteCoinTotals();
    purse4.WriteDollarTotal();
    cout << string(40,'*') << endl << endl;

    cout << "      Parameterized Constructor(1 argument)\n";
    Money purse5(90);
    purse5.WriteCoinTotals();
    purse5.WriteDollarTotal();
    cout << string(40,'*') << endl << endl;

    // verifying SetMoney function
    cout << string(40,'*') << endl;
    cout << "Set Money Test\n";
    cout << "-------------\n";
    purse1.SetMoney(0,6,20,10);
    purse1.WriteCoinTotals();
    purse1.WriteDollarTotal();
    cout << string(40,'*') << endl << endl;

    // Test the output for correct purse and month
    // formatting

    cout << string(40,'*') << endl << endl;
    cout << "Testing Add Money Methods\n";
    cout << "-------------------------\n";

    cout << "    Initial Amount\n";
    purse1.SetMoney(0,0,0,0);
    purse1.WriteCoinTotals();
    purse1.WriteDollarTotal();
    cout << string(40,'*') << endl;

    cout << "    add 10 pennies, 5 nickels, 7 dimes, 20 quarters\n";
    purse1.AddMoney(10,5,7,20);
    purse1.WriteCoinTotals();
    purse1.WriteDollarTotal();
    cout << string(40,'*') << endl;

    cout << "    add 15 pennies, 15 nickels, 27 dimes\n";
    purse1.AddMoney(15,15,27);
    purse1.WriteCoinTotals();
    purse1.WriteDollarTotal();
    cout << string(40,'*') << endl;

    cout << "    add 33 pennies, 22 nickels\n";
    purse1.AddMoney(33,22);
    purse1.WriteCoinTotals();
    purse1.WriteDollarTotal();
    cout << string(40,'*') << endl;

    cout << "    add 75 pennies\n";
    purse1.AddMoney(75);
    purse1.WriteCoinTotals();
    purse1.WriteDollarTotal();
    cout << string(40,'*') << endl;

    cout << "    add 0 pennies, 17 nickels, 0 dimes, 29 quarters\n";
    purse1.AddMoney(0,17,0,29);
    purse1.WriteCoinTotals();
    purse1.WriteDollarTotal();
    cout << string(40,'*') << endl;


    return 0;
}
