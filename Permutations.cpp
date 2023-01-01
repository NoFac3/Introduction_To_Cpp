//<Permutations.cpp> -- This is a program that uses two variables, number of students and members per team, to calculate the possible number of permutations for team arrangements and the steps to derive this solution. 

//Include statements
#include <iostream>
#include <string>
#include <cmath>	//Math Library: use with mathematical operations: power function [pow(x,y) = x^y], exponent [exp(x) = e^x], squareroot [sqrt(x) = √x]. Function Call.

using namespace std;

//Global declarations: Constants and type definitions only -- no variables
const double PI = 3.1416;		//constant variable for pi that can handle decimal values (double). 

//Function prototypes

int main()
{
	//In cout statement below SUBSTITUTE your name and lab number
	cout << "Permtation Example" << endl << endl;

	//Variable declarations
	int n = 18; //Number of people (students)
	int r = 3;	//Items taken (members per team)
	int teams = n / r; // For use in output. This identifies the possible teams of r members in n set of people.
	double n_factorial, r_factorial, n_minus_r_factorial; //Variable representation of the factorial solution values: n!, r!, and (n-r)!
	double potentialTeamArangements; //Variable representation for all of the possible team arrangement permutations.

	char squareRoot = 251, divide = 47, pi = 227, negative = 45, power = 94; //For use with output (cout), allowing the printed output to include mathematical symbols and operations for user's methodolical comprehension. 

	//Program logic
	//Primary equation for factorial approxmation: x! = e^(-x)*(x^x)*√(2πx). Equation will utilize exp(x) for e^(x), pow(x,x) for x^x, and sqrt(2πx) for √(2πx). Constant PI substituted for π.
	n_factorial = exp(-n) * pow(n, n) * sqrt(2 * PI * n);		// n! = e^(−n) * (n^n) * √(2*π*n)
	r_factorial = exp(-r) * pow(r, r) * sqrt(2 * PI * r);		// r! = e^(−r) * (r^r) * √(2*π*r)
	n_minus_r_factorial = exp(-(n - r)) * pow((n - r), (n - r)) * sqrt(2 * PI * (n - r));	// (n-r)! = e^[−(n-r)] * [(n-r)^(n-r)] * √[2*π*(n-r)]
	potentialTeamArangements = (n_factorial / (r_factorial * n_minus_r_factorial));		// Solution in decimal form: The number of probable arrangements: P = n! ∕ [r! * (n−r)!]. Double variable type will be used at end of output to indicate the process of rounding down to find the integer solution for total number of complete permutations.

	// Output for user interface: 
	cout << "There are " << n << " people in your class and you want to divide the class into programming teams of " << r << " members. " << endl << endl; //Output problem statement for user introduction, with substituted values for n and r. 
	cout << "Given variables: \n Number of people, n = " << n << "\n Members per team, r = " << r << endl << endl; //Output: Given statement. Separation with newline escape sequence (\n) and indentation with (\t)
	cout << "The number of different team arangements, or permutations, can be found with the formula below: " << endl << endl; //Output: Introduce user to initial equation. 
	cout << "\t P(n,r) = n!" << divide << "[r!(n" << negative << "r)!]." << endl << endl; // Output: Using P(n,r) a proibability equation and "divide" character for the " / " symbol.
	cout << "To Determine the approximate values of n!, r!, and (n - r)!, use the following formula: " << endl << endl; //Output indicating the repetition of the formula for all subsequent factorials.
	
  	//Factorial
	cout << "\t x! = e^(-x) * x^(x) * " << squareRoot << "(2" << pi << "x)" << endl << endl; //Output for factorial equation with x as the base value that will be substituted for n, r, and (n-r)
	
  	// Solve for n!
	cout << " Substitute x with n.\n\t  n! = " << n << "!" << endl; //Output substituted n, for (x)! lined up with prior equation for with tab sequences (\t), for mathematical formatting.
	cout << "\t " << n << "! = e^(" << -n << ") * " << n << power << "(" << n << ") * " << squareRoot << "[(2)(" << PI << ")(" << n << ")]" << endl; //Output substituted formula with n, for (x)!,char symbol operators (/,^) ."
	cout << "\t " << n << "! = " << n_factorial << endl << endl; //Output of n!.
	
 	// Solve for r!
	cout << " Substitute x with r.\n\t r! = " << r << "!" << endl;
	cout << "\t " << r << "! = e^(" << -r << ") * " << r << power << "(" << r << ") * " << squareRoot << "[(2)(" << PI << ")(" << r << ")]" << endl; //Output substitute x for r.
	cout << "\t " << r << "! = " << r_factorial << endl << endl; //Output solution of r!.
	
  	// Solve for (n-r)!
	cout << " Substitute x with (n-r).\n      (n-r)! = (" << n << negative << r << ")! = " << (n - r) << "!" << endl; //Output simplification of (n-r) for (n-r)! Solution to (n-r)! factorial starting with the simplification of the internal operation, (n-r), which will be subtituted into the formula. Use of char negative as the minus sign in (n-r)!, avoiding redundancy.
	cout << "\t " << (n - r) << "! = e^(" << -(n - r) << ") * " << (n - r) << power << "(" << (n - r) << ") * " << squareRoot << "[(2)(" << PI << ")(" << (n - r) << ")]" << endl; //Output substitute x with (n-r).
	cout << "\t " << (n - r) << "! = " << n_minus_r_factorial << endl << endl; //Output solution for (n-r)!
	
  	// Solve for P(n,r)
	cout << "Now, substitute the values for n!, r!, and (n-r)! into the initial formula for P(n,r): " << endl; //Output statemtent for substurtion of factorial values into initial equation.
	cout << "\n P(n,r) = n! " << divide << " [r!(n-r)!]\n";	//Output equation for P(n,r)
	cout << "\t = " << n << "! " << divide << " [" << r << "!(" << (n - r) << ")!]\n";	//Output equation variable substitution.
	cout << "\t = " << n_factorial << " " << divide << " [(" << r_factorial << ")(" << n_minus_r_factorial << ")]\n";	//Output equation simplification via factorials. 
	cout << "\t = " << n_factorial << " " << divide << " " << r_factorial * n_minus_r_factorial << "\n";	//Output equation further simplification via denomenator multiplication.
	cout << "\t = " << n_factorial / (r_factorial * n_minus_r_factorial) << endl << endl;	//Output equation solution with unrounded, decimal value.
	
  	//Solution: Concluding statements
	cout << "The floor of " << potentialTeamArangements << ", or rounding down to the nearest integer, will give the number of permutations.\n" << endl;//Output satement for rounding to the nearest whole number
	cout << "The total number of team arrangements with " << r << " members: " << int(potentialTeamArangements) << " permutations." << endl << endl; //Output solution with nearest whole integer of possible permutations.

	//Closing program statements 
	system("pause");
	return 0;
}
//Function definitions
