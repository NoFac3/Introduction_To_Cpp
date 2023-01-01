//<If_Loops_and_Input_from_Data_File.cpp> --  C++ program that computes an assignment grade as a percentage from the student’s score and total points.
// uses studentData.txt

//Include statements
#include <iostream>
#include <string>
#include <iomanip>	// For floating-point format setprecision().
#include <fstream>	// For general file stream: read, write and create files. (ifstream and inFile)
#include <cmath>	// For math computations to complete the calculations. (ceil)

using namespace std;

//Global declarations: Constants and type definitions only -- no variables
//Function prototypes

int main()
{
	cout << "If Loop and Input from Data File" << endl << endl;

	//Variable declarations
	ifstream inFile;		// Declatation for inFile to read and get values from external text file.
	float score, total;		// Flaot variables for read values from external file.
	float grade;			// Floating-point variable for grade result

	//Program logic
	inFile.open("studentData.txt");		// Open and read external text file with student's score and total points.
	inFile >> score >> total;			// Format for recieveing read values from text file as the variables "score" and "total".
	grade = (score / total) * 100;		// Calculate the grade from external file. Multiply by 100 to convert decimal to percentage.
	grade = ceil(grade);				// New grade value: ceil for rounding the grade up to nearest whole value.

	//Output results to the screen.
	cout << " Student's score: " << score << endl;					// Print students assignment score from text file. 
	cout << "    Total points: " << total << endl << endl;			// Print total points possible for the assignment from text file.
	cout << fixed << showpoint << setprecision(5);					// Floating-point fixed format with precision to 5 decimal places.
	cout << "Assignment grade: " << grade << "%\n" << endl;			// Print assignment grade.

	//If else loop for grade comment.
	if (grade >= 90)
		cout << "Excellent\n" << endl;			// If the grade is greater than equal to 90%, print “Excellent”.
	if (grade >= 80 && grade < 90)
		cout << "Well Done\n" << endl;			// If the grade is 80% to less than 90%, print “Well Done”.
	if (grade >= 70 && grade < 80)
		cout << "Good\n" << endl;				// If the grade is 70% to less than 80%, print “Good”.
	if (grade >= 60 && grade < 70)
		cout << "Need Improvement\n" << endl;	// If the grade is 60% to less than 70%, print “Need Improvement”.
	if (grade < 60)
		cout << "Fail\n" << endl;				// If the grade is less than 60%, print “Fail”.

	inFile.close();					// Close external input file.
  
	//Closing program statements
	system("pause");
	return 0;
}
//Function definitions
