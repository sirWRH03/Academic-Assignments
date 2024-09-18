/*
Author: William Humphrey
Date of Development: 22 August 2022
Activity: Programming Activity 1.1
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
  int n;
  
  cout << "Please input a number: ";
  cin >> n;
  
  if ((n % 2) == 0)
  {
    cout <<"\nThe number you chose, " << n << ", is even." << endl;
  }
  else
  {
    cout << "\nThe number you chose, " << n << ", is odd." << endl;
  }
  return 0;
}
