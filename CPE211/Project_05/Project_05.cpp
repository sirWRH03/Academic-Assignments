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
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char *argv[ ])
{
	//if (argv != 2)
	//{
		//cout << endl;
		//cout << string(9, '*') << " Command Line Argument Error "
		//	 << string(9, '*') << endl;
		//cout << "==> Incorrect number of Command Line Arguments!\n";
		//cout << "==> Command for running the program is:\n";
		//cout << "==> ./Project_05 inputFileName\n";
		//cout << string(47, '*') << endl << endl;
		//return 1;
	//}
	
	ifstream inFile;
	ofstream outFile;
	string filename = argv[1];
	string line1, line2, line3, line4, guess, type;
	char c1;
	double a, b, c, s, area, perimeter;
	
	
	inFile.open(filename);	
	
	if (inFile.fail())
	{
		cout << string(15, '*') << " File Open Error "	
			 << string(15, '*') << endl;
		cout << "==> Input file failed to open properly!!\n";
		cout << "==> Attempted to open file: " << filename << endl;
		cout << "==> Terminating program!!!\n";
		cout << string(47, '*') << endl << endl;
		return 1;
	}
	
	cout << string(60, '*') << endl << string(20, '*')
		 << "  Triangle Checker  " << string(20, '*') << endl
		 << string(60, '*') << endl << endl;
	cout << "Input File Opened: " << filename << endl << endl;
	cout << "Reading Values From Input File..." << endl << endl;
	
	int i = 0;
	while (i<4)
	{
		c1 = inFile.get(); 
		if (c1 == 'a') 
		{
			inFile.ignore(1);
			inFile >> a;
			inFile.ignore(1);
		}
		else if (c1 == 'b')
		{
			inFile.ignore(1);
			inFile >> b;
			inFile.ignore(1);
		}
		else if (c1 == 'c')
		{
			inFile.ignore(1);
			inFile >> c;
			inFile.ignore(1);
		}
		else if (c1 == '?')
		{
			inFile.ignore(1);
			getline(inFile, guess);
			inFile.ignore(1);
		}
		i += 1;
	}
		
	if (inFile.fail()) 
	{
		cout << string(15, '*') << " File Read Error "
			 << string(15, '*') << endl;
		cout << "==> Error reading data form input file.\n";
		cout << "==> Terminating program now..." << endl;
		cout << string(47, '*') << endl << endl;
		return 1;
	}
	
	if (a < 0 || b < 0 || c < 0)
	{
		cout << string (15, '*') << " File Data Error " 
			 << string (15, '*') << endl;
		cout << "==> Error: One or more side lengths are negative." << endl;
		cout << "==> Terminating program now..." << endl;
		cout << string(47, '*') << endl << endl;
		return 1;
	}
	
	cout << "Summary of Data Read..." << endl;
	cout << "Side A = " << fixed << setprecision(2) << a << endl;
	cout << "Side B = " << fixed << setprecision(2) << b << endl;
	cout << "Side c = " << fixed << setprecision(2) << c << endl;
	cout << "Guess  = " << guess << endl;
	cout << string(60, '*') << endl;
	
	if (!(a < b + c && b < a + c && c < a + b))
	{
		type = "not-triangle";
	}		
	else if (a == b && b == c)
	{
		type = "equilateral";
	}
	else if (a == b || a == c || b == c)
	{
		type = "isosceles";
	}
	else
	{
		type = "scalene";
	}
	
	perimeter = a + b + c;
	s = perimeter/2;
	area = sqrt(s*(s-a)*(s-b)*(s-c));
	
	cout << "Results From Data Read:" << endl;
	cout << left << setw(13) << setfill('.') << "Type:" << type << endl;
	if (type != "not-triangle")
	{
		cout << left << setw(13) << setfill('.') << "Area:" << fixed << setprecision(2) << area << endl;
		cout << left << setw(13) << setfill('.') << "Perimeter:" << fixed << setprecision(2) << perimeter << endl << endl;
	}
	else
	{
		cout << endl;
	}
		
	if (guess == type)
	{
		cout << "Congratulations! Triangle specified is correct" << endl;
	}
	else
	{
		cout << "Sorry! Triangle specified is incorrect" << endl;
	}	
	cout << string(60, '*') << endl;
	
	return 0;
}