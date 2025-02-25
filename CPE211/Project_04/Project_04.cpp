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
#include <cmath>
#include <fstream>
using namespace std;

int main()
{
	
	double gravity, timeHeight, timeDistance, distance, height, pi;
	string inputFile, objectTitle, velocity, alpha;
	ifstream InFile;
	ofstream OutFile;
	
	gravity = 9.80665;
	pi = 3.14159265;
	
	cout << string(30, '*') << endl;
	cout << string(5, '*') << " Projectile Motion\n";
	cout << string(30, '*') << endl;
	
	cout << "\nEnter the name of the input file: ";
	cin >> inputFile;
	cout << "File Opened: " << inputFile << endl;

	InFile.open(inputFile.c_str());
	
	if(InFile.fail())
	{
		cout << string(47, '*') << endl;
		cout << "==> Input file failed to open properly!\n";
		cout << "==> Name of file opened: " << inputFile << endl;
		cout << "==> Terminating Program!!!\n";
		cout << string(47,'*') << endl;
		return 1;
	}
	
	getline(InFile, objectTitle);
	getline(InFile, velocity);
	getline(InFile, alpha);
	
	cout << "\nCalculating values for " << objectTitle << " with:" << endl;
	cout << "Initial Velocity (in meters/sec): " << velocity << endl;
	cout << "Starting Angle (in degrees): " << alpha << endl;
	
	double alphaConvert = stod(alpha);
	double velocityConvert = stod(velocity);
	
	timeHeight = (velocityConvert*sin((alphaConvert*pi)/180))/gravity;
	timeDistance = (2*velocityConvert*sin((alphaConvert*pi)/180))/gravity;
	height = ((velocityConvert*velocityConvert)*(sin((alphaConvert*pi)/180)*sin((alphaConvert*pi)/180)))/(2*gravity);
	distance = velocityConvert*timeDistance*cos((alphaConvert*pi)/180);
	
	cout << "\nResults:" << endl;
	cout << "--------" << endl;
	cout << fixed << setprecision(3) << left << setw(25) << "Time to Max Height: " << timeHeight << " seconds" << endl;
	cout << fixed << setprecision(3) << left << setw(25) << "Time to Max Distance: " << timeDistance << " seconds" << endl;
	cout << fixed << setprecision(3) << left << setw(25) << "Maximum Height: " << height << " meters" << endl;
	cout << fixed << setprecision(3) << left << setw(25) << "Maximum Distance: " << distance << " meters" << endl;
	
	return 0;

}