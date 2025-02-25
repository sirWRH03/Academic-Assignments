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

typedef int bitArray[10][10];
typedef int decimalArray[10];

struct resultsArrays {
	bitArray orArray;
	bitArray andArray;
	bitArray xorArray;
	decimalArray orDec;
	decimalArray andDec;
	decimalArray xorDec;
	int rows;
	int cols;
};

void openInputFile(ifstream&); 
void readInputData(ifstream&, resultsArrays&, bitArray&, bitArray&); 
void inputArrayPrint(resultsArrays&, bitArray&, bitArray&);
void arrayCalc(resultsArrays&, bitArray&, bitArray&);
void outputArrayPrint(resultsArrays&);
void decimalCalc(resultsArrays&);
void decimalOutput(resultsArrays&);

int main()
{
	ifstream inFile;
	bitArray array1;
	bitArray array2;
	resultsArrays results;
	
	openInputFile(inFile);
	inFile >> results.rows;
	if (inFile.eof() && inFile.fail())
	{
		cout << string(47, '*') << endl;
		cout << string(14, '*') << " Error: Empty File " << string(14, '*') << endl;
		cout << "==> File did not contain any input data" << endl;
		cout << "==> Terminating Program..." << endl;
		cout << string(47, '*') << endl;
		return 1;
	}
	readInputData(inFile, results, array1, array2);
	inputArrayPrint(results, array1, array2);
	arrayCalc(results, array1, array2);
	outputArrayPrint(results);
	decimalCalc(results);
	decimalOutput(results);
	
	return 0;
}

void openInputFile(ifstream& in)
{
	string filename;

	cout << "Please enter the name of the file you'd like to open (ctrl-c to exit): ";
	cin >> filename;
	cout << "Attempting to open: " << filename << endl;

	in.open(filename);
	if (in.fail())
	{
		while (in.fail())
		{
			cout << string(47, '*') << endl;
			cout << string(15, '*') << " File Open Error " << string (15, '*') << endl;
			cout << "==> Input file failed to open properly" << endl;
			cout << "==> Attempted to open file: " << filename << endl;
			cout << "==> Please reattempt to open a file or exit with ctrl-c" << endl;
			cout << string(47, '*') << endl;
			in.close();
			in.clear();
			cout << "Please type the name of the input file you wish to open: ";
			cin >> filename;
			cout << "Attempting to open: " << filename << endl;
			in.open(filename);
		}
	}
}

void readInputData(ifstream& in, resultsArrays& results, bitArray& array1, bitArray& array2)
{
	in.ignore(100, '\n');
	in >> results.cols;
	in.ignore(100, '\n');
	in.ignore(1);
	for (int i = 0; i < results.rows; i++)
	{
		for (int j = 0; j < results.cols; j++)
		{
			in >> array1[i][j];
			in.ignore(1);
		}
	}
	in.ignore(1);
	for (int i = 0; i < results.rows; i++)
	{
		for (int j = 0; j < results.cols; j++)
		{
			in>> array2[i][j];
			in.ignore(1);
		}
	}
}

void inputArrayPrint(resultsArrays& results, bitArray& array1, bitArray& array2)
{
	int rowNum, colNum;
	
	rowNum = results.rows;
	colNum = results.cols;
	cout << "Initial values of the arrays processed" << endl;
	cout << "--------------------------------------" << endl;
	cout << setw(colNum*2) << left << "Array 1" << "    " << setw(colNum*2) << left << "Array 2" << endl;
	cout << setw(colNum*2) << left << "-------" << "    " << setw(colNum*2) << left << "-------" << endl;
	for (int i = 0; i < results.rows; i++)
	{
		for (int j = 0; j < results.cols; j++)
		{
			cout << left << array1[i][j] << " ";
		}
		cout << "    ";
		for (int j = 0; j < results.cols; j++)
		{
			cout << left << array2[i][j] << " ";
		}
	cout << endl;
	}
	cout << endl;
}

void arrayCalc(resultsArrays& results, bitArray& array1, bitArray& array2)
{
	for (int i = 0; i < results.rows; i++)
	{
		for (int j = 0; j < results.cols; j++)
		{
			//or array
			if ((array1[i][j] == 1) || (array2[i][j] == 1))
			{
				results.orArray[i][j] = 1;
			}
			else 
			{
				results.orArray[i][j] = 0;
			}
			//and array
			if ((array1[i][j] == 1) && (array2[i][j] == 1))
			{
				results.andArray[i][j] = 1;
			}
			else
			{
				results.andArray[i][j] = 0;
			}
			//xor array
			if (((array1[i][j] == 1) && (array2[i][j] == 0)) || ((array1[i][j] == 0) && (array2[i][j] == 1)))
			{
				results.xorArray[i][j] = 1;
			}
			else
			{
				results.xorArray[i][j] = 0;
			}
		}
	}
}

void outputArrayPrint(resultsArrays& results)
{
	int rowNum, colNum;
	
	rowNum = results.rows;
	colNum = results.cols;
	
	cout << "OR, AND, and XOR results" << endl;
	cout << "------------------------" << endl;
	cout << setw(2*colNum) << left << "OR Array" << "    " << setw(2*colNum) << left << "AND Array" << "    " << setw(2*colNum) << left << "XOR Array" << endl;
	cout << setw(2*colNum) << left << "--------" << "    " << setw(2*colNum) << left << "---------" << "    " << setw(2*colNum) << left << "---------" << endl;
	for (int i = 0; i < results.rows; i++)
	{
		for (int j = 0; j < results.cols; j++)
		{
			cout << left << results.orArray[i][j] << " ";
		}
		cout << "    ";
		for (int j = 0; j < results.cols; j++)
		{
			cout << left << results.andArray[i][j] << " ";
		}
		cout << "    ";
		for (int j = 0; j < results.cols; j++)
		{
			cout << left << results.xorArray[i][j] << " ";
		}
	cout << endl;
	}
	cout << endl << endl;
}

void decimalCalc(resultsArrays& results)
{
	int rowNum, colNum, base, rowSum;
	
	rowNum = results.rows;
	colNum = results.cols;
	base = 1;
	rowSum = 0;
	
	for (int row = 0; row < rowNum; row++)
	{
		rowSum = 0;
		base = 1;
		for (int col = (colNum - 1); col >= 0; col--)
		{
			rowSum += (base*results.orArray[row][col]);
			base *= 2;
		}
		results.orDec[row] = rowSum;
		rowSum = 0;
		base = 1;
		for (int col = (colNum - 1); col >=0; col--)
		{
			rowSum += (base*results.andArray[row][col]);
			base *= 2;
		}
		results.andDec[row] = rowSum;
		rowSum = 0;
		base = 1;
		for (int col = (colNum - 1); col >=0; col--)
		{
			rowSum += (base*results.xorArray[row][col]);
			base *= 2;
		}
		results.xorDec[row] = rowSum;
	}
}

void decimalOutput(resultsArrays& results)
{
	cout << "Integer Equivalents for the rows" << endl << "of the OR, AND, and XOR arrays" << endl;
	cout << "--------------------------------" << endl;
	cout << setw(8) << left << "OR" << setw(8) << left << "AND" << setw(8) << left << "XOR" << endl;
	cout << setw(8) << left << "--" << setw(8) << left << "---" << setw(8) << left << "---" << endl;
	for (int i = 0; i < results.rows; i++)
	{
		cout << setw(8) << left << results.orDec[i] << setw(8) << left << results.andDec[i] << setw(8) << left << results.xorDec[i] << endl;
	}
}