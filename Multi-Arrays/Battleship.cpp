//<Battleship.cpp> -- C++ program that utilizes array's to simulate the game of Battleship. It takes user coordinate input to sink fleet ships.
// uses BattleshipGameBoard.txt file

//Include statements
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
//Global declarations: Constants and type definitions only -- no variables
const int boardWidth = 25;      // Constant integer variable for game board width (X coordinate)
const int boardHeight = 25;     // Constant integer variable for game board height (Y coordinate)

//Function prototypes
void Fire(const int boardWidth, const int boardHeight, int X, int Y, char gameBoard[][25]);                     // Function that determines if user coordinate input hit a ship
void FleetSunk(const int boardWidth, const int boardHeight, int X, int Y, char gameBoard[][25], bool& gameOver);// Function that determines if player has sunk all the fleet

int main()
{
    cout << "Multi-Array: Battleship" << endl << endl;

    //Variable declarations
    ifstream inputFile;                         // ifstream variable to read input file
    char gameBoard[boardWidth][boardHeight];    // Character variable for game board array
    bool gameOver;                              // Boolean variable to initiate the conclusion of the game
    int X;                                      // Integer Variable for X coordinate (board width)
    int Y;                                      // Integer Variable for Y coordinate (board height)

    //Program logic
    inputFile.open("BattleshipGameBoard.txt"); // Open game board file  
    // For loop for reading board game text file and writing to gameboard array
    for (int i = 0; i < 25; i++)            // For rows from 0 - 24 (1-25) & priming i for next row
    {
        for (int j = 0; j < 25; j++)        // For colums from 0-24 (1-25) & priming j for next colum
            inputFile >> gameBoard[i][j];   // Input data red and saved to array variable for game board
    }
    cout << "                                   ___  # #  (*)                       " << endl;      
    cout << "                                  |ooo|,#_#___|__,                     " << endl;
    cout << "      |))                    ___  |ooo||_________|  ___                " << endl;
    cout << "      |            ___  ====|   | |   ||.........| |   |=== ___         " << endl;
    cout << "      |     ======|   |_____'---'.|   ||_________|.'---'___|   |====      " << endl;
    cout << "    %-----------------------------'---''---------'-------------------/" << endl;
    cout << "     %                ******** BATTLESHIP ********                  / " << endl;                   //Print game title to console
    cout << "~~~~~~%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/~~~~~~" << endl;
    cout << "Enter target coordinates for your torpedos until you've sunk all of the enemy's fleet." << endl;  // Print initial game instructions to console
    cout << "Enter X and Y coordinate values from 1 to 25." << endl << endl;
    gameOver = false;   // Set game state to active for start of game
    while (!gameOver)   // While game is still active (not all fleet ships are sunk)
    {
        cout << "Enter X coordinate: ";// Prompt user to input X coordinate
        cin >> X;                                   // Store user input for X coordinate to integer variable X
        //cout << endl;
        cout << "Enter Y coordinate: ";// Prompt user to input Y coordinate
        cin >> Y;                                   // Store user input for Y coordinate to integer value Y
        cout << endl;
        X--;                                        // Convert X input to real X coordinate
        Y--;                                        // Convert Y input to real Y coordinate
        Fire(boardHeight, boardWidth, X, Y, gameBoard);                 // Calls function that takes player input an gameboard data and determins hit or miss
        FleetSunk(boardHeight, boardWidth, X, Y, gameBoard, gameOver);// Calls function that determines if player has sunk all the ships
    }
    //Closing program statements
    inputFile.close();              // Close board game file
    system("pause");
    return 0;
}
//Function declarations

// Function that takes player coordinate input, determines if it matches one of the fleet coordinates, prints coordinate result, & changes game board array value.
void Fire(const int boardWidth, const int boardHeight, int X, int Y, char gameBoard[][25])
{
    char hit = 'H';                             // Character variable for a sucessful Hit
    char miss = 'M';                            // Character variable for a miss
    if (gameBoard[X][Y] == '#')                 // If player's coordinates sucessfully hit a section of the fleet (#)
    {
        cout << "HIT" << endl << endl;          // Print "Hit" to console for the sucessful hit of the fleet ship
        gameBoard[X][Y] = hit;                  // Change game board array value to 'H' indicating a sucessful hit
    }
    else if (gameBoard[X][Y] == 'H')            // If the player's coordinates match a fleet coordinate but have already been input
    {
        cout << "HIT AGAIN" << endl << endl;    // Print "Hit again" to console if player's coordinates hit fleet position they have already hit
    }
    else//If the player doesn't match one of the fleet ships
    {
        cout << "MISS" << endl << endl;         // Print "Miss" to console if the player's coordinates are not one of the fleets
        gameBoard[X][Y] = miss;                 // Change game board array variable to 'M' indicating a miss
    }
}
//Function that determines if all ships in the fleet have been sunk. If they have, it prints a concluding statement and the game board results
void FleetSunk(const int boardWidth, const int boardHeight, int X, int Y, char gameBoard[][25], bool& gameOver)
{
    bool fleetDestroyed = false;            // Bool variable for storing wheither the fleet is destroyed or not.
    for (int i = 0; i < 25; i++)            // For board height. Coordinate values between 0-24 & priming i for next row value
    {
        for (int j = 0; j < 25; j++)        // For board width. Coordinate values between 0-24, & priming j for next colum value
            if (gameBoard[i][j] != '#' )    // If there are not any '#' in the array, then the fleet is destroyed
                fleetDestroyed = true;      // Set fleet destroyed to true for final results printed in while loop
            else
            {
                fleetDestroyed = false;     // If there are still '#' in array, the fleet is still there
                break;
            }
        if (fleetDestroyed == false)        // If user hasn't input all the fleet coordinates, continue the game
            break;
    }
    if (fleetDestroyed == true)             // If user has inputed all the battleship coordinates
    {
        gameOver = true;
        cout << "\tThe fleet was destroyed!" << endl << endl;   // Print to console to notify user they have completed the game.
        int i = 0;
        // While loop to print game array results to console, showing all Hits and Misses
        while (i<25)                    //While i (x coordinate) is the first row to the last row. 
        {
            int j = 0;                  // Reset columb value to 0 for next loop
            cout << "\t";
            while (j < 25)              // While loop for printing all the colum values to the current row (i)
            {
                cout << gameBoard[i][j];//Print game board coordinate value
                j++;                    //Priming j (colum) value for next loop 
            }
            cout << endl;               // Print new line for next row
            i++;                        // Priming i (row) for next loop
        }
        cout << endl << endl;
    }
}
