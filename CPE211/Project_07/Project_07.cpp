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
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

void printMenu(), inFileOpener(ifstream&), outFileOpener(ofstream&), compress(ifstream&, ofstream&), decompress(ifstream&, ofstream&);
int numInput();



void printMenu()
{
	cout << string(10, '*') << "  Compression Menu  " << string(10,'*') << endl;
	cout << "0. Exit Program\n1. Compress File\n2. Decompress File" << endl;
	cout << string(40, '*') << endl;
}

int numInput()
{
	double userChoice;
	cin >> userChoice;
	cout << "User choice is " << userChoice << endl;
	return userChoice;
}

void inFileOpener(ifstream& inFilestream)
{
	string filename;
	cout << "Please Enter a input file name: ";
	cin >> filename;
	cout << "Attempting to open input file: " << filename << endl;
	inFilestream.open(filename);
	if (inFilestream.fail())
	{
		cout << string(15, '*') << " File Open Error " << string(15, '*') << endl;
		cout << "==> Input file failed to open properly!!" << endl;
		cout << "==> Attempted to open file: " << filename << endl;
		cout << "==> Selected operation has been canceled" << endl;
		cout << string(47, '*') << endl;
	}
}

void outFileOpener(ofstream& outFilestream)
{
	string filename;
	cout << "Please enter an output file name: ";
	cin >> filename;
	cout << "Attempting to open output file: " << filename << endl;
	outFilestream.open(filename);
}

void compress(ifstream& inFilestream, ofstream& outFilestream)
{
	char prev, next;
	int count;
	inFilestream.get(prev);
	if ((inFilestream.eof()) && (inFilestream.fail()))
	{
		cout << string(15, '*') << " Empty Input File " << string(15, '*') << endl;
		cout << "==> Empty file for Compression\n" << "==> Nothing written to output file" << endl;
		cout << string(47, '*') << endl;
	}
	else
	{
		while ((!inFilestream.eof()) && (!inFilestream.fail()))	
		{
			count = 1;
			inFilestream.get(next);
			if (prev == next)
			{
			count += 1;
			}
			else 
			{
			outFilestream << count << prev;
			}
		}
	}	
}

void decompress(ifstream& inFilestream, ofstream& outFilestream)
{
	int charNum;
	char c1;
	
	inFilestream >> charNum;
	
	if ((inFilestream.eof()) && (inFilestream.fail()))
	{
		cout << string(15, '*') << " Empty Input File " << string(15, '*') << endl;
		cout << "==> Empty file for Decompression\n" << "==> Nothing written to output file" << endl;
		cout << string(47, '*') << endl;
	}
	else
	{
		while ((!inFilestream.eof()) && (!inFilestream.fail()))
		{
			inFilestream.get(c1);
			for (int i=0; i<charNum; i++)
			{
				outFilestream << c1;
			}
			inFilestream >> charNum;
		}
	}
}

int main()
{
	//int choice;
	bool status;
	ifstream inFile;
	ofstream outFile;
	
	printMenu();
	//choice = numInput();
	
	while ((numInput() != 0) || (numInput() != 1) || (numInput() != 2))
	{
		cout << string(14, '*') << " Invalid Selection " << string(14, '*') << endl;
		cout << "==> Invalid integer value entered\n";
		cout << "==> Please enter 0, 1 or 2\n";
		cout << string(47, '*') << endl << endl;
		printMenu();
		numInput();
	}
	
	inFileOpener(inFile);
	if (inFile.fail())
	{
		return 0;
	}
	outFileOpener(outFile);
	
	if (!inFile.fail())
	{
		if (numInput() == int(0))
		{
			return 0;
		}
		if (numInput() == int(1))
		{
			compress(inFile, outFile);
		}
		if (numInput() == int(2))
		{
			decompress(inFile, outFile);
		}
		return 0;
	}
	else
	{
		return 0;
	}
}
