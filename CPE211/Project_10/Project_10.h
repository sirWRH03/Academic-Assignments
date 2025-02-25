// Header file for project 10
// Contains the class description
//
// Need guards to make sure this header file
// is included one time only
//
#ifndef P10_HEADER
#define P10_HEADER

#include <string>
#include <cstdlib>

using namespace std;


// Class declaration for Money

class Money
{
    private:        // private members accessed by helper functions
        int pennies;    // Number of pennies for the object
        int nickels;    // Number of nickels for the object
        int dimes;      // number of dimes for the object
        int quarters;   // number of quarters for the object

    protected:  // protected members here - none required

    public:     // public members here - helper functions

        // **********************************************
        // ************** CONSTRUCTORS ******************
        // **********************************************

        // default constructor -set coin totals to 0
        Money();             

        // parameterized constructor - use user provided values
        // for values not provided, the attribute is set to 0
        // order of parameters is pennies, nickels, dimes, quarters

        Money(int, int, int, int);   // all 4 coins   
        Money(int, int, int);      // pennies, nickels, dimes
        Money(int, int);      // pennies, nickels
        Money(int);      // pennies

        // **********************************************
        // **************  TRANSFORMERS  ****************
        // **********************************************
        
        void SetMoney(int, int, int, int);
		// order for add money is pennies, nickels, dimes and quarters
        void AddMoney(int, int, int, int);  // all 4
        void AddMoney(int, int, int);  // no quarters
		void AddMoney(int, int);  // no dimes or quarters
		void AddMoney(int);  // pennies only

        // **********************************************
        // **************  OBSERVERS  *******************
        // **********************************************

        // write out the number of each coin type 
        void WriteCoinTotals() const;

        // write out total dollar amount of the coins.
        void WriteDollarTotal() const;

};  // end of class Money
#endif
