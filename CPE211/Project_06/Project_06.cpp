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
	if(argc != 3)
		{
			cout << endl;
			cout << string(9, '*') << " Command Line Argument Error "
			     << string(9, '*') << endl;
			cout << "==> Incorrect number of Command Line Arguments!\n";
			cout << "==> Command for running the program is:\n";
			cout << "==> ./Project_06 inputFileName outputFileName\n";
			cout << string(47, '*') << endl << endl;
			return 1;
		}
		
		ifstream inFile;
		ofstream outFile;
		string inFilename, outFilename, firstName, lastName;
		int quizNum, hwNum, testNum, score, quizSum, hwSum, testSum, totalSum, keySum;
		int i; //iterate variables
    float average, classAverage;
		
		inFilename = argv[1];
		outFilename = argv[2];
		inFile.open(inFilename);
		
		if (inFile.fail())
		{
			while (inFile.fail())
			{
				inFile.clear();
				cout << string(15, '*') << " File Open Error " << string(15, '*') << endl;
				cout << "==> Input file failed to open properly!!\n";
				cout << "==> Attempted to open file: " << inFilename << endl;
				cout << "==> Please try again... ";
				cin >> inFilename;
				cout << "==> Attempting to open file: " << inFilename << endl;
				cout << string(47, '*') << endl;
				inFile.open(inFilename);
			}
		}
		
		cout << "Opening Input File: " << inFilename << endl << endl;
		outFile.open(outFilename);
		
		if (outFile.fail())
		{
			while (outFile.fail())
			{
				outFile.clear();
				cout << string(15, '*') << " File Open Error " << string(15, '*') << endl;
				cout << "==> Output file failed to open properly!!\n";
				cout << "==> Attempted to open file: " << outFilename << endl;
				cout << "==> Please try again... ";
				cin >> outFilename;
				cout << "==> Attempting to open file: " << outFilename << endl;
				cout << string(47, '*') << endl;
				outFile.open(outFilename);
			}
		}
		
		cout << "Opening Output File: " << outFilename << endl << endl;
		
		if (!inFile.fail() && !inFile.eof()) 
		{	
			inFile >> quizNum;
			if (inFile.fail() && inFile.eof())
			{
				cout << string(13, '*') << " Input File Is Empty " << string(13, '*') << endl;
				cout << "==> The input file is empty.\n";
				cout << "==> Terminating the program.\n";
				cout << string(47, '*') << endl;
				outFile << "Input file is empty.";
				inFile.close();
				outFile.close();
				return 1;
			}
			inFile.ignore(1);
			inFile >> hwNum;
			inFile.ignore(1);
			inFile >> testNum;
			inFile.ignore(1);
			
			outFile << left << setw(3) << "#" << setw(12) << "Last" << setw(7) << "First" 
				    	<< setw(6) << "Quiz" << setw(6) << "HW" << setw(6) << "Exam" 
				    	<< setw(7) << "Total" << setw(9) << "Average" << endl;
			outFile << left << setw(3) << "-" << setw(12) << "----------" << setw(7) << "-----" 
         			<< setw(6) << "----" << setw(6) << "---" << setw(6) << "----"  
         			<< setw(7) << "-----" << setw(9) << "-------" << endl;
			
      i = 1;
      
      while (!inFile.eof() && !inFile.fail())
			{
        quizSum = 0;
        hwSum = 0;
        testSum = 0;
        totalSum = 0;
        classAverage = 0;
				
        getline(inFile, lastName, ' ');
        //if (inFile.fail() && inFile.eof()) 
        //{
          //cout << "Input file did not contain any students.";
          //outFile << "Input file did not contain any students.";
          //return 1;
        //}
				getline(inFile, firstName, ' ');
        for (int k = 0; k<quizNum; k++)
        {
          inFile >> score;
          inFile.ignore(1);
          quizSum += score;
        }
        for (int j = 0; j<hwNum; j++)
        {
          inFile >> score;
          inFile.ignore(1);
          hwSum += score;
        }
        for (int l = 0; l<testNum; l++)
        {
          inFile >> score;
          inFile.ignore(1);
          testSum += score;
        }
        
        if (inFile.eof())
        {
          if ((firstName == "Max") || (firstName == "Key") || (firstName == "Solution"))
          {
            cout << "Input File did not contain any student data.\n";
            outFile << "Input file did not contain any student data.\n";
          }
          else
          {
            outFile << left << setw(3) << "-" << setw(12) << "----------" << setw(7) << "-----" 
         		  	    << setw(6) << "----" << setw(6) << "---" << setw(6) << "----"  
         			      << setw(7) << "-----" << setw(9) << "-------" << endl;
          }
        }
				else if ((lastName == "Max") || (lastName == "Key") || (lastName == "Solution"))
        {
          keySum = quizSum + hwSum + testSum;
          average = (float(keySum)/float(keySum))*100;
          outFile << left << setw(3) << " " << setw(12) << lastName << setw(7) << firstName 
				        	<< setw(6) << quizSum << setw(6) << hwSum << setw(6) << testSum 
				    	    << setw(7) << keySum << setw(9) << fixed << setprecision(2) << average << endl;
			    outFile << left << setw(3) << "-" << setw(12) << "----------" << setw(7) << "-----" 
         			    << setw(6) << "----" << setw(6) << "---" << setw(6) << "----"  
         			    << setw(7) << "-----" << setw(9) << "-------" << endl;
        } 
        else
        {
        
          totalSum = quizSum + hwSum + testSum;
          average = (float(totalSum)/float(keySum))*100;
          classAverage += average;
          outFile << left << setw(3) << i << setw(12) << lastName << setw(7) << firstName 
				         	<< setw(6) << quizSum << setw(6) << hwSum << setw(6) << testSum 
				          << setw(7) << totalSum << setw(9) << fixed << setprecision(2) <<average << endl;
          i++;
        }
			}
      classAverage = classAverage/float(i);
      outFile << "\nClass Average: " << classAverage << endl;
		}
			
	return 0;
}