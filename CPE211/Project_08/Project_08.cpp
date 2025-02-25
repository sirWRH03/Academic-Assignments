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
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

struct date
{
	int month;
	int day;
	int year;
};

struct customerData
{
	string firstName;
	string lastName;
	int custId;
	date joinDate;
};

void inFileOpener(ifstream&), customerDataRead(ifstream&, customerData&), customerOutput(customerData&);
bool custEqual(customerData&, customerData&), custLess(customerData&, customerData&), custGreater(customerData&, customerData&);


int main()
{
	ifstream inFile;
	customerData customer1, customer2;
	bool equal, less, greater;
	string outEqual, outLess, outGreater;
	
	inFileOpener(inFile);
	customerDataRead(inFile, customer1);
	if (inFile.eof() && inFile.fail())
	{
		cout << string(14, '*') << " Error: File Empty " << string(14, '*') << endl;
		cout << "==> Input file contains no customer data" << endl;
		cout << "==> Terminating program..." << endl << endl;
		return 1;
	}
	customerDataRead(inFile, customer2);
	
	cout << string(47, '*') << endl;
	cout << string(13, '*') << " Customer Comparison " << string(13, '*') << endl;
	cout << string(47, '*') << endl << endl;
	cout << "Customer 1 information:" << endl;
	customerOutput(customer1);
	cout << "Customer 2 information:" << endl;
	customerOutput(customer2);
	equal = custEqual(customer1, customer2);
	less = custLess(customer1, customer2);
	greater = custGreater(customer1, customer2);
	
	if (equal)
	{
		outEqual = "true";
	}
	else
	{
		outEqual = "false";
	}
	if (less)
	{
		outLess = "true";
	}
	else 
	{
		outLess = "false";
	}
	if (greater)
	{
		outGreater = "true";
	}
	else
	{
		outGreater = "false";
	}
	
	cout << "Customer 1 is greater than Customer 2:  " << outGreater << endl;
	cout << "Customer 1 is less than customer 2:     " << outLess << endl;
	cout << "Customer 1 is equal to customer 2:      " << outEqual << endl;
	
	return 0;
}

void inFileOpener(ifstream& inFile)
{
	string filename;
	
	cout << "Please type the name of the input file you wish to open: ";
	cin >> filename;
	cout << "Attempting to open: " << filename << endl;
	
	inFile.open(filename);
	if (inFile.fail())
	{
		while (inFile.fail())
		{
			cout << string(15, '*') << " File Open Error " << string(15, '*') << endl;
			cout << "==> Input file failed to open properly" << endl;
			cout << "==> Attempted to open file: " << filename << endl;
			cout << "==> Please enter reattempt to open a file" << endl;
			cout << string(47, '*') << endl << endl;
			inFile.clear();
			cout << "Please type the name of the input file you wish to open: ";
			cin >> filename;
			cout << "Attempting to open: " << filename << endl;
			inFile.open(filename);
		}
	}
}

void customerDataRead(ifstream& inFile, customerData& customer)
{
	getline(inFile, customer.firstName);
	getline(inFile, customer.lastName);
	inFile >> customer.custId;
	inFile.ignore(1);
	inFile >> customer.joinDate.month;
	inFile.ignore(1);
	inFile >> customer.joinDate.day;
	inFile.ignore(1);
	inFile >> customer.joinDate.year;
	inFile.ignore(1);
}

void customerOutput(customerData& customer)
{
	cout << string(23, '-') << endl;
	cout << "Name: " << customer.firstName << " " << customer.lastName << "(" << customer.custId << ")" << endl;
	cout << "Join: " << customer.joinDate.month << "/" << customer.joinDate.day << "/" << customer.joinDate.year << endl << endl;;
}

bool custEqual(customerData& cust1, customerData& cust2)
{
	if ((cust1.firstName == cust2.firstName) && (cust1.lastName == cust2.lastName) && (cust1.custId == cust2.custId) && (cust1.joinDate.year == cust2.joinDate.year) && (cust1.joinDate.month == cust2.joinDate.month) && (cust1.joinDate.day == cust2.joinDate.day))
	{
		return true;
	}
	else
	{
		return false;
	}
}
		
bool custLess(customerData& cust1, customerData& cust2)
{
	if (cust1.lastName < cust2.lastName)
	{
		return true;
	}
	else if ((cust1.lastName == cust2.lastName) && (cust1.firstName < cust2.firstName))
	{
		return true;
	}
	else if ((cust1.lastName == cust2.lastName) && (cust1.firstName == cust2.firstName) && (cust1.custId < cust2.custId))
	{
		return true;
	}
	else if ((cust1.lastName == cust2.lastName) && (cust1.firstName == cust2.firstName) && (cust1.custId == cust2.custId) && (cust1.joinDate.year < cust2.joinDate.year))
	{
		return true;
	}
	else if ((cust1.lastName == cust2.lastName) && (cust1.firstName == cust2.firstName) && (cust1.custId == cust2.custId) && (cust1.joinDate.year == cust2.joinDate.year) && (cust1.joinDate.month < cust2.joinDate.month))
	{
		return true;
	}
	else if ((cust1.lastName == cust2.lastName) && (cust1.firstName == cust2.firstName) && (cust1.custId == cust2.custId) && (cust1.joinDate.year == cust2.joinDate.year) && (cust1.joinDate.month == cust2.joinDate.month) && (cust1.joinDate.day < cust2.joinDate.day))
	{
		return true;
	}
	else
	{
		return false;
	}
}
		
bool custGreater(customerData& cust1, customerData& cust2)
{
	if (cust1.lastName > cust2.lastName)
	{
		return true;
	}
	else if ((cust1.lastName == cust2.lastName) && (cust1.firstName > cust2.firstName))
	{
		return true;
	}
	else if ((cust1.lastName == cust2.lastName) && (cust1.firstName == cust2.firstName) && (cust1.custId > cust2.custId))
	{
		return true;
	}
	else if ((cust1.lastName == cust2.lastName) && (cust1.firstName == cust2.firstName) && (cust1.custId == cust2.custId) && (cust1.joinDate.year > cust2.joinDate.year))
	{
		return true;
	}
	else if ((cust1.lastName == cust2.lastName) && (cust1.firstName == cust2.firstName) && (cust1.custId == cust2.custId) && (cust1.joinDate.year == cust2.joinDate.year) && (cust1.joinDate.month > cust2.joinDate.month))
	{
		return true;
	}
	else if ((cust1.lastName == cust2.lastName) && (cust1.firstName == cust2.firstName) && (cust1.custId == cust2.custId) && (cust1.joinDate.year == cust2.joinDate.year) && (cust1.joinDate.month == cust2.joinDate.month) && (cust1.joinDate.day > cust2.joinDate.day))
	{
		return true;
	}
	else
	{
		return false;
	}
}