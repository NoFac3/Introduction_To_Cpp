//<User-Defined_Functions.cpp> -- C++ Program that reads data from input file and & sends it to 3 functions that calculate & print the students last name, percent grade, decimal grade, & a preformance remark.  
// uses studentScores.txt as input file

//Include statements
#include <iostream>
#include <string>
#include <iomanip>  // For floating-point format setprecision().
#include <fstream>  // For general file stream: read, write and create files. (ifstream and inFile)
#include <cmath>    // For math computations to complete the calculations. (ceil)

using namespace std;
//Global declarations: Constants and type definitions only -- no variables

//Function prototypes
string names(string name);							// Function for printing the students last name.
float grades(float score, float totalPoints);		// Function for calculating & printing grade percentage & decimal value. 
string remarks(float score, float totalPoints);		// Function for determining a remark for the students associated grade.

int main()
{
	//In cout statement below SUBSTITUTE your name and lab number
	cout << "User-Defined Functions" << endl << endl;

	//Variable declarations
	string name;
	ifstream inputFile;
	float score;			// Students total points earned.
	float totalPoints;		// Assignments total points possible.
	int student = 0;		// Variable for while loop for reading each line.
	
	//Program logic
	inputFile.open("studentScores.txt");			// Open input file		
	inputFile >> name >> score >> totalPoints;		// Priming data. Reads data from an input file.  The data file includes 10 students. 
	
	while (inputFile)		// While loop for reading input file data & call the functions that calculate grade percentage, decimal grade value & the associated remarks & passing appropriate arguments to functions.
	{
		names(name);								// Function call: sends last name from input data to the names function that prints the last name.
		grades(score, totalPoints);					// Function call: sends the student's score and the assignments possible points to the grade function that prints the percentage and decimal values.  
		remarks(score, totalPoints);				// Function call: sends the student's score and the assignments possible points to the grade function that prints corresponding remark.
		inputFile >> name >> score >> totalPoints;	// Priming data for next loop
	}
	cout << endl;

	//Closing program statements
	inputFile.close();				// Closes the input file, "studentScores.txt"
	system("pause");
	return 0;
}
//Function definitions

string names(string name)		//Function 1: Print the last name of the student.
{
	string lastName = name;
	cout << " " << lastName << " ";	// Prints last name followed by a space.
	return lastName;
}

float grades(float score, float totalPoints)			// Function 2: compute and print decimal and percent grade.
{
	float decimalGrade = score / totalPoints;						// Calculates the studen't grade as a decimal value, dividing their score by the total points possible.
	float percentGrade = ceil(decimalGrade * 100);					// Calculates the student's grade as a percentage from the decimal grade with ceil function to round up to nearest whole value.
	cout << percentGrade << "% ";									// Prints grade in the percentage format with "%".
	// If statements for decimal grade & leading 0's.
	if (decimalGrade < 1)								//If statement: for grades less than 100%. Prints decimal grade without leading zero before decimal point.
	{
		decimalGrade = decimalGrade * 100000;			// Converts decimal number to five numbers before decimal
		decimalGrade = ceil(decimalGrade);				// Rounds up converted decimal to a whole number removing numbers past decimal.
		cout << "." << decimalGrade << " ";				// Prints "." before converted decimal. Display's as floating point result up to 5 decimal places.
	}
	else												//Else: grade is 100% or greater. Prints without leading ".", allowing for "1"
	{
		cout << fixed << showpoint << setprecision(5);	// Print format: display's floating point result up to 5 decimal places
		cout << decimalGrade << " ";					// Prints decimal grade.
		cout << noshowpoint << setprecision(0);			// Print format: removes the decimal point and removes decimal places for the next loop.
	}
	return 0;
}

string remarks(float score, float totalPoints)			// Function 3: print remarks with corresponding grade.
{
	string remark;
	float percentGrade = (score / totalPoints)*100;		// Calculates the percentage grade from the score divided by total points.
	percentGrade = ceil(percentGrade);					// Using ceil function to round up to nearest whole number
	if (percentGrade >= 90)
	{
		remark = "Excellent";		  // If the grade is 90 to 100%, print “Excellent”.
	}
	else if (percentGrade >= 80)
	{
		remark = "Well Done";		  // If the grade is 80 to less than 90%, print “Well Done”.
	}
	else if (percentGrade >= 70)
	{
		remark = "Good";			  // If the grade is 70 to less than 80%, print “Good”.
	}	
	else if (percentGrade >= 60)
	{
		remark = "Need Improvement";  // If the grade is 60 to less than 70%, print “Need Improvement”.
	}
	else if (percentGrade < 60)
	{
		remark = "Fail";			  // If the grade is less than 60, print “Fail”.
	}
	cout << remark << endl;			  // Print remark.
	return remark;
}
