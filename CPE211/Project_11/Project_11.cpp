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
#include <fstream>
#include <cmath>
using namespace std;

const double pi = 3.14159265;

void inputFileOpen(ifstream&), inputFileRead(ifstream);

int main()
{
	ifstream in;
	
	inputFileOpen(in);
	
	return 0;
}

void inputFileOpen(ifstream& in)
{
	string filename;
	cout << "Please enter the name of the file you wish to open: ";
	cin >> filename;
	cout << filename;
	in.open(filename);
	if (in.fail())
	{
		while (in.fail())
		{	
			cout << string(15, '*') << " File Open Error " << string (15, '*') << endl;
			cout << "==> Input File could not be opened" << endl;
			cout << "==> Attempted to open file: " << filename << endl;
			cout << "==> Please try again..." << endl;
			cout << string(47, '*') << endl;
			in.clear();
			cout << endl << "Please enter the name of the file you wish to open: ";
			cin >> filename;
			cout << filename << endl;
		}
	}
}

void inputFileRead(ifstream& in)
{
	
}