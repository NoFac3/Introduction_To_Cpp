//<Simple Arrays> -- C++ program that calculates user's proportional weight on another planet.

//Include statements
#include <iostream> 
#include <string>
#include <fstream>    // Library for reading and writing to external txt files: ifstream & ofstream
using namespace std;
//Global declarations: Constants and type definitions only -- no variables
enum planetType { Mercury, Venus, Earth, Moon, Mars, Jupiter, Saturn, Uranus, Neptune, Pluto }; // Enumerator Type definition of the types of Planets with all planet names.

//Function prototypes
bool ValidPlanetName(string planetName, planetType& planet);        // Bool Function that verifies the user's input for planet name is valid.
void GetUserInput();                                                // Void Function that prompts and stores user input & calls ValidPlanetName() to validate planet name.
void ErrorMessageForInvalidInput(string planetName);                // Void Function that prints error message for invalid user input for planet name with guide and examples.
planetType ConvertInputToPlanetType(string planetName, planetType& planet); // Enum Function converts user input for planet name into its associated planetType value.
void OutputWeight(planetType planet, float weight);                 // Void Function calculates user weight conversion to chosen planet and prints solution.

int main()
{
    cout << "Simple Arrays" << endl << endl;

    //Variable declarations
    float weight;       // Float variable for storing users input for weight: In main function, this is used for passing variable from inputfile to called functions.
    string planetName;      // String variable for storing user input for planet name: In main function, this is used for passing variable from input file to called functions.
    planetType planet;      // Enumerator variable for storing PlanetType
    ifstream inputFile;     // fstream variable for reading "UserInput.txt" file where variables of user input is stored after GetUserInput() is called. 
    char redo = 'y';        // Character variable for user choice to run the program again

    //Program logic
    while (redo == 'y')     // While loop for main function. Will stop if user answers no (n) in redo prompt.
    {
        GetUserInput();                                             // Call void function, no return: prompts user input, validates planet name, & stores values in an outputFile "UserInput.txt".   
        inputFile.open("UserInput.txt");                    // Opens input file with stored user input, that was previous the outputFile for GetUserInput().
        inputFile >> weight >> planetName;                          // Priming data from input file to be distributed to call functions. 
        planet = ConvertInputToPlanetType(planetName, (planet));  // Call enum planetType Function: returns associated planets emun value.
        OutputWeight(planet, weight);                               // Call the OutputWeight function: takes user's weight & chosen planet, calculates their weight on the planet, & prints results to console. 
        inputFile.close();                                          // Close input file "UserInput.txt".
        cout << "Do you want to run the program again (y/n)? ";     // Prompt user if they want the program to preform another weight conversion 
        cin >> redo;                                                // Store user choice (y/n) for next loop
        cout << endl;
    }
    //Closing program statements
    system("pause");
    return 0;
}
//Function prototypes

// Bool Function that verifies the user's input for planet name is valid.
bool ValidPlanetName(string planetName, planetType& planet) //Function that validates that uses's input for planet name using if else statement & returns a bool value.
{
    if (planetName == "Mercury" || planetName == "Venus" || planetName == "Earth" || planetName == "Moon" || planetName == "Mars" || planetName == "Jupiter" || planetName == "Saturn" || planetName == "Uranus" || planetName == "Neptune" || planetName == "Pluto")  //If value for planet name matches properly formatted planet names
    {
        return true;  // Return true if user's input for planet name is valid
    }
    else
    {
        return false; // Returns false if the user's input for planet name does not match with the stored planet names.
    }
}
// Void Function that prompts and stores user input & calls ValidPlanetName() to validate planet name.
void GetUserInput()
{
    float weight;                               // Float variable for storing user input for their weight. 
    int flag = 0;                               // Integer Variable for error message in Do While loop.
    planetType planet;                          // Enum variable for storing PlanetType.
    string planetName;                          // String variable for storing users input for planet name.
    ofstream outputFile;                        // fstream variable declaration for use with output files.
    outputFile.open("UserInput.txt");   // Open write file to store user input.
    cout << "Enter your weight on Earth: ";     // Prompt user to enter their weight on Earth.
    cin >> weight;                              // Store users input to weight variable.
    do                                  //Do while planet name is valid. First planet name input wont include error message. Message will display when input is invalid and re-prompt user input.
    {
       if (flag != 0)                    // If: Prints an error message if flag isn't 0, when user input for planet is invalid via calling validPlanetName().
       {
          ErrorMessageForInvalidInput(planetName);    // Calls function that prints spelling and case error message.  
       }
       cout << "Enter a planet name: ";                    // Prompt user to input the name of the planet they want their weight converted to.
       cin >> planetName;                                  // Store user input for the name of the planet.
       flag++;                                             // Flag increment for next loop.
    } while (!(ValidPlanetName(planetName, (planet))));  // Do While user planet input is valid. Calls validInput function to validate planet name and return a bool value for true or false
    outputFile << weight << " " << planetName;             // Write user unput for weight and planet name to the output file.
    outputFile.close();                                    // Close output file "UserInput.txt"
    // No return for void function.
}
// Function that prints error message for invalid user input for planet name & prints guide for proper planet name input with examples.
void ErrorMessageForInvalidInput(string planetName)
{
    cout << "\nInvalid input for planet name: '" << planetName << "'" << endl << endl;                              // Error message with invalid input printed
    cout << "  The name of the planet must start with an upper case letter followed by lower case letters." << endl;// Input format guide: proper case (specific)
    cout << "  Below are the all of the planet name options with correct spelling and case format." << endl << endl;// Input format guide: proper spelling (general)& indicates lower examples
    cout << "  Please match the case and spelling of one of the following: " << endl << endl;                       // Input format guide: reiterates previous statements
    cout << "\tMercury\t\tVenus\t\tEarth\t\tMoon\t\tMars" << endl << endl;                                          // Planet name examples: row 1
    cout << "\tJupiter\t\tSaturn\t\tUranus\t\tNeptune\t\tPluto" << endl << endl;                                    // Planet name examples: row 2 (all options are printed)
    // No return for void function
}
// Enum Function converts user input for planet name into its associated planetType value.
planetType ConvertInputToPlanetType(string planetName, planetType& planet)
{
    if (planetName == "Mercury")    // If planet name is Mercury
    {
        planet = Mercury;           // Stores correct planet variable for planetType enumerator. 
    }
    else if (planetName == "Venus")   // If planet name is Venus
    {
        planet = Venus;             // Stores correct planet variable for planetType enumerator.
    }
    else if (planetName == "Earth")   // If planet name is Earth
    {
        planet = Earth;             // Stores correct planet variable for planetType enumerator.
    }
    else if (planetName == "Moon")    // If planet name is Moon
    {
        planet = Moon;              // Stores correct planet variable for planetType enumerator.
    }
    else if (planetName == "Mars")    // If planet name is Mars
    {
        planet = Mars;              // Stores correct planet variable for planetType enumerator.
    }
    else if (planetName == "Jupiter") // If planet name is Jupiter
    {
        planet = Jupiter;           // Stores correct planet variable for planetType enumerator.
    }
    else if (planetName == "Saturn")  // If planet name is Saturn
    {
        planet = Saturn;            // Stores correct planet variable for planetType enumerator.
    }
    else if (planetName == "Uranus")  // If planet name is Uranus
    {
        planet = Uranus;            // Stores correct planet variable for planetType enumerator.
    }
    else if (planetName == "Neptune") // If planet name is Neptune
    {
        planet = Neptune;           // Stores correct planet variable for planetType enumerator.
    }
    else if (planetName == "Pluto")   // If planet name is Pluto
    {
        planet = Pluto;             // Stores correct planet variable for planetType enumerator.
    }
    return planet;      // Returns converted planetType variable 
}
// Void Function calculates user weight conversion to chosen planet and prints solution
void OutputWeight(planetType planet, float weight)  // Function calculates user weight based on planet value & prints users converted weight to console.    
{
    double planetWeight = 0;    // Variable for storing the value for the users converted weight.
    cout << "Your weight on ";    // First part of final statement for output of users converted weight on selected planet.
    switch (planet)         // Switch for planet enumerator variable
    {
    case Mercury:                       // Mercury
        planetWeight = weight * 0.4155; // Converted weight
        cout << "Mercury";              // Print planet name "Mercury" to console (between first and second part of final statement).
        break;
    case Venus:                         // Venus
        planetWeight = weight * 0.8975; // Converted weight
        cout << "Venus";                // Print planet name "Venus" to console ('').
        break;
    case Earth:                         // Earth
        planetWeight = weight * 1.0;    // Converted weight 
        cout << "Earth";                // Print planet name "Earth" to console ('').
        break;
    case Moon:                          // Moon
        planetWeight = weight * 0.166;  // Converted weight 
        cout << "the Moon";             // Print planet name "the Moon" to console (''). Addition of "the " for correct grammatical phrasing.
        break;
    case Mars:                          // Mars
        planetWeight = weight * 0.3507; // Converted weight
        cout << "Mars";                 // Print planet name "Mars" to console ('').
        break;
    case Jupiter:                       // Jupiter
        planetWeight = weight * 2.5374; // Converted weight 
        cout << "Jupiter";              // Print planet name "Jupiter" to console ('').
        break;
    case Saturn:                        // Saturn
        planetWeight = weight * 1.0677; // Converted weight: 
        cout << "Saturn";               // Print planet name "Saturn" to console ('').
        break;
    case Uranus:                        // Uranus
        planetWeight = weight * 0.8947; // Converted weight: 
        cout << "Uranus";               // Print planet name "Uranus" to console ('').
        break;
    case Neptune:                       // Neptune
        planetWeight = weight * 1.1794; // Converted weight 
        cout << "Neptune";              // Print planet name "Neptune" to console ('').
        break;
    case Pluto:                         // Pluto
        planetWeight = weight * 0.0899; // Converted weight 
        cout << "Pluto";                // Print planet name "Pluto" to console ('').
        break;
    }
    cout << " would be " << planetWeight << endl << endl; //Second part of final statement: Print user converted weight on the chosen planet.
    //no return for void function 
}
