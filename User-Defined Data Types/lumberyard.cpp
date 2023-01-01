//<User-Defined_Data_Types.cpp> -- C++ Program that collects order product information from customer input & prints as a reciept. 
// uses items.txt file

//Include statements
#include <iostream>		// Library for std functions.
#include <iomanip>		// Library for currency formatting in output statements: setprecision(2).
#include <fstream>		// Library for reading and writing to input and output file.

using namespace std;

//Global declarations: Constants and type definitions only -- no variables

//Function prototypes
bool validItem(char item);// Bool Function that takes user character input & returns whether the value is valid (P, F, C, M, O, & T).
bool validDimensions(int count, int width, int height, int length);// Bool function verifies the user dimension inputs are valid numbers.
double woodPricePerBoardFoot(char woodType);// Function that takes the type of wood & returns its assoiciated price per board foot.
double boardFeet(int width, int height, int length);// Function to calculate the board feet of each item from input (width, height, & length).
double itemCost(int count, double boardFeet, double woodPrice);	// Function to calculate the cost of each item from the number of boards, board feet, price of wood type.
bool OpenInputFile(ifstream& input, string filename);// Bool function that takes a file name & returns whether it sucessfully opened.

int main()
{
	cout << "User-Defined Data Types" << endl << endl;

	//Variable declarations
	ifstream inputFile;
	ofstream outputFile;
	outputFile.open("items.txt");	// Open the "items.txt" file:  used as read and write reference of the same file.
	char item;		// Character variable for customer wood type selection (P, F, C, M, O, & T).
	int count;		  // Integer variable for number of boards.
	int width, height, length;//   ''      ''     for board dimensions.
	double total = 0;        // Double variable to store total cost
	double cost = 0;	 //   ''		 ''    to store each items cost
	double boardSize, size;	 //   ''      ''    for the board dimensions.
	double woodPrice, price; //   ''      ''    for price of each item with respect to quantity & size of the board
	string woodType; // String variable for reading wood type from the "items.txt".

	//Program Logic
	cout << fixed << showpoint << setprecision(2);	// Print valus with currency formating with two places past decimal.
	cout << "Enter item: ";		// Initial statement for customer to input items (Outside loop - will be replaced inside loop). 

	while (true)		// While loop: Runs intill while value of character read is not 'T' 
	{
		cin >> item;	// Read user input: character for item [ Wood type('P','F','C','M','O') or Total('T') 
		bool correctItem = validItem(item);
		if (item != 'T')						// If user imput is not 'T': For entering items
		{
			// Read user input: board number & size.
			cin >> count;				// Number of boards
			cin >> width;				// Width of board
			cin >> height;				// Height of board
			cin >> length;				// Lenght of board
			if (correctItem == false || validDimensions(count, width, height, length) == false)
			{
				cin.ignore();																											// Ignore invalid input 
				cout << "\nInvalid character input: '" << item << "'" << endl;// Output: Error Message
				cout << "All items characters must be entered in capital letters:" << endl;// Error statement
				cout << "\t'P' for Pine\n\t'F' for Fir\n\t'C' for Cedar\n\t'M' for Maple\n\t'O' for Oak\n\t'T' for total\n" << endl;// Output: Character message
				cout << "Please Re-Enter item: ";																						// Prompt user to reenter item
			}
			else
			{
				price = woodPricePerBoardFoot(item);	// Call function to get price per board foot for Pine ($0.89)
				size = boardFeet(width, height, length);// Call function to compute board feet from the dimensions.
				cost = itemCost(count, size, price);	// Call function to computer the cost from board number, dimentions, & price per board foot.
				switch (item)			// Switch: Results based on wood type ('P', 'F', 'C', 'M', & 'O')
				{
				case 'P':																										// Pine
					cout << count << " " << width << "x" << height << "x" << length << " Pine at a cost of " << cost << endl;// Print to console output
					outputFile << count << " " << width << " " << height << " " << length << " Pine " << cost << endl;// Write to output file
					break;
				case 'F':																										// Fir
					cout << count << " " << width << "x" << height << "x" << length << " Fir at a cost of " << cost << endl;	
					outputFile << count << " " << width << " " << height << " " << length << " Fir " << cost << endl;			
					break;
				case 'C':																										// Cedar
					cout << count << " " << width << "x" << height << "x" << length << " Cedar at a cost of " << cost << endl;	
					outputFile << count << " " << width << " " << height << " " << length << " Cedar " << cost << endl;			
					break;
				case 'M':																										// Maple
					cout << count << " " << width << "x" << height << "x" << length << " Maple at a cost of " << cost << endl;	
					outputFile << count << " " << width << " " << height << " " << length << " Maple " << cost << endl;		
					break;
				case 'O':																										// Oak
					cout << count << " " << width << "x" << height << "x" << length << " Oak at a cost of " << cost << endl;	
					outputFile << count << " " << width << " " << height << " " << length << " Oak " << cost << endl;			
					break;
				}
				total += cost;													// Add cost to previous total stored as the new total cost.
				cout << "Enter another item (or press T for the total): ";		// New statement to prompt user input next loop. (Present option for printing total ('T') and ending program. 
			}
		}
		else if (item == 'T')	// If user input is 'T': print each item & the total cost of all items.
		{
			outputFile.close();			// Close "receipt.txt" file as output
			inputFile.open("items.txt");		// Open "receipt.txt" file as input
			cout << "The total for " << endl;	// Print initial statement for total cost.
			inputFile >> count >> width >> height >> length >> woodType >> cost;	// Priming input data.
			while (inputFile)	// While Loop: For reprinting items from "items.txt" file as input.
			{
				cout << count << " " << width << "x" << height << "x" << length << " ";	// Reprint item quantity & dimentions.
				cout << woodType << " at a cost of " << cost << endl;			//   ''     ''  type & cost.
				inputFile >> count >> width >> height >> length >> woodType >> cost;	// Priming input data for next loop.
			}
			cout << "is " << total << endl << endl;
			inputFile.close();
			break;
		}
	}
	//Closing program statements
	system("pause");
	return 0;
}

//Function Definitions

// Function that takes the user's initial character input and returns a bool value: (True = valid entry, False = invalid entry)
bool validItem(char item)
{
	switch (item)
	{
	case 'P':
	case 'F':
	case 'C':
	case 'M':
	case 'O':
	case 'T':
		return true;	// Character input is valid
	default:
		return false;	// Character input is invalid
	}
}

// Function that verifies the user dimension inputs are valid numbers.
bool validDimensions(int count, int width, int height, int length)// Takes number of boards, width, height, & length variables
{
	if (count > 0 && width > 0 && height > 0 && length > 0)
	{
		return true;	// Numerical inputs are valid
	}
	else
	{
		return false;	// Numerical inputs are invalid
	}
}

// Function that takes the character value of the referenced item and returns the associated wood type's price per board foot.
double woodPricePerBoardFoot(char woodType)
{
	double woodPrice=0;
	switch (woodType)
	{
	case 'P':			// Pine
		woodPrice = 0.89;	// Set wood price variable to 0.89
		break;
	case 'F':			// Fir
		woodPrice = 1.09;	// Set wood price variable to 1.09
		break;
	case 'C':			// Cedar
		woodPrice = 2.26;	// Set wood price variable to 2.26
		break;
	case 'M':			// Maple
		woodPrice = 4.50;	// Set wood price variable to 4.50
		break;
	case 'O':			// Oak
		woodPrice = 3.10;	// Set wood price variable to 3.10
		break;
	}
	return woodPrice;// Return associated wood type's pricer per board foot.
}

// Function that takes user's dimention inputs (width, height, length), then calculates & returns the converted board foot value.
double boardFeet(int width, int height, int length)
{
	double boardFoot = ((width * height * length) / 12.0);	// Convert volumetric dimensions to board feet
	return boardFoot;					// Return board foot value
}

// Function to calculate the cost of each item from their associated wood price, number of boards, & board dimentions.
double itemCost(int count, double boardFeet, double woodPrice)
{
	double woodCost = woodPrice * count * boardFeet;
	return woodCost;
}

// Function to verify that the input file ("items.txt") can be opened and returns associated bool values (True = sucessfully opened file or False = failed to open file).
bool OpenInputFile(ifstream& inputFile, string fileName)
{
	inputFile.open(fileName.c_str());
	if (!inputFile)
	{
		return false;	//File did not open sucessfully
	}
	else
	{
		return true;	// File opened sucessfully
	}
}
