// ****************************************
// Progam Title sample Header file
// Project File: Cpp_header.cpp
// Name: Will Humphrey
// Course Section: CPE-211-01
// Lab Section: 01
// Due Date: 01/28/22
// Program Description: Descripotion of
// what the program does.
// ****************************************
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string stockName;
int numOfShares;
float buyPrice;
float sellPrice;
float buyCom = .02;
float sellCom = .015;
float tax = .25;
float taxTotal;
float netGainOrLoss = 0;
float totalCost;
float buyComCost;
float sellComCost;
float income;
float totalReturn; 


int main()
{
	cout << "What is the name of the stock you wish to buy? ";
	cin >> stockName;
	cout << stockName << endl;
	
	cout << "How many shares would you like to buy? ";
	cin >> numOfShares;
	cout << numOfShares << endl;
	
	cout << "What is the buy price of the stock? ";
	cin >> buyPrice;
	cout << fixed << setprecision(2) << buyPrice << endl;
	
	cout << "What is the sell price of the stock? ";
	cin >> sellPrice;
	cout << fixed << setprecision(2) << sellPrice << endl;
	
	totalCost = buyPrice * numOfShares;
	buyComCost = totalCost * buyCom;
	totalCost += buyComCost;
	income = sellPrice * numOfShares;
	sellComCost = income * sellCom;
	totalReturn = income - sellComCost;
	netGainOrLoss = totalReturn - totalCost;
	taxTotal = netGainOrLoss * tax;
	
	cout << string(25, '*') << endl;
	cout << string(25, '*') << endl;
	
	cout << setfill('.');
	cout << setw(20) << "Stock: " << stockName << endl;
	cout << setw(20) << "Number of Shares: " << numOfShares << endl;
	cout << setw(20) << "Buy Commission: " << "$" << fixed << setprecision(2) << buyComCost << endl;
	cout << setw(20) << "Total Cost: " << "$" << fixed << setprecision(2) << totalCost << endl;	
	cout << setw(20) << "Sell Commission: " << "$" << fixed << setprecision(2) << sellComCost << endl;
	cout << setw(20) << "Total Return: " << "$" << fixed << setprecision(2) << totalReturn << endl;
	cout << setw(20) << "Net Profit: " << "$" << fixed << setprecision(2) << netGainOrLoss << endl;
	cout << setw(20) << "Tax on Profit: " << "$" << fixed << setprecision(2) << taxTotal << endl;
	
	cout << string(35, '-') << endl;
	return 0;
}