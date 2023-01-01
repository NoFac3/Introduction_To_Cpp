//<While_Loops.cpp> -- C++ program reads song times from file (in seconds), converts to minutes & seconds, & writes to output file.
// uses songs.txt as input file

//Include statements
#include <iostream>
#include <string>
#include <fstream>			// Library for ifstream & ofstream: enables use of input and ouutput file commands.
#include <iomanip>			// Library for cout and output print spacing format: enables use of setw()

using namespace std;
//Global declarations: Constants and type definitions only -- no variables
//Function prototypes

int main()
{
	cout << "While Loops" << endl << endl;

	//Variable declarations
	ifstream inputFile;									// fstream variable for input file: read.
	ofstream outputFile;								// fstream variable for output file: write.
	float seconds, minutes, songSeconds, songMinutes;	// Conversion variables for time. (minutes and seconds)
	float totalSongSeconds = 0, totalSongMinutes = 0;	// Time variables for total seconds and minutes for songs.  
	int cdTotalMinutes = 80;							// CD capacity variables for total minutes and seconds conversion.  
	float  cdMinutesLeft, cdSecondsLeft;				// CD left over variables as a result of the compined size of songs. 
	int song = 1;										// First song number for while loop.
	int i = 4;											// If Statement variable in initial line space setw(i).
	
	//Program logic
	inputFile.open("songs.txt");	// Open read file, songs.txt.
	outputFile.open("CD.txt");		// Open/Create write file, CD.txt

	// Print data chart headings with spacing for alignment.
	cout << "  ______________________________________________" << endl;
	cout << " |        |                  |                  |" << endl;
	cout << " | Song   |    Song Time     |    Total Time    |" << endl;
	cout << " | Number | Minutes  Seconds | Minutes  Seconds |" << endl;
	cout << " |________|__________________|__________________|" << endl;
	// Write data chart headers to CD.txt file: 
	outputFile << "  ______________________________________________" << endl;
	outputFile << " |        |                  |                  |" << endl;
	outputFile << " | Song   |    Song Time     |    Total Time    |" << endl;
	outputFile << " | Number | Minutes  Seconds | Minutes  Seconds |" << endl;
	outputFile << " |________|__________________|__________________|" << endl;

	inputFile >> songSeconds;		//Priming read: Reads data from inputFile, "songs.txt".
	while (inputFile)				// While Loop: Read data from a text file using a while loop, calculates minutes & seconds for each song.
	{		
		songMinutes = songSeconds / 60;					// Convert each song's seconds to minutes with decimal remainder. (One minute = 60 seconds)
		minutes = static_cast<int>(songMinutes);		// Formats minutes to integer format.
		seconds = songSeconds - (minutes * 60);
    //seconds = ((songMinutes - minutes) * 60);		// Seconds: Subtract interger Minutes from minutes with decimals for remainder, multiplied by 60.

		//Calculate current total minutes and seconds of songs.
		totalSongMinutes = totalSongMinutes + minutes;			// Adds current song's minutes to the total minutes.
		totalSongSeconds = totalSongSeconds + seconds;			// Adds current song's seconds to the total seconds.

		//If statement for total song seconds greater than or equal to 60.
		if (totalSongSeconds >= 60)						
		{
			totalSongMinutes = totalSongMinutes + static_cast<int>(totalSongSeconds / 60);				 //Converts 60+ seconds to minutes. 
			totalSongSeconds = ((totalSongSeconds / 60) - static_cast<int>(totalSongSeconds / 60)) * 60; //Converts left over seconds to total seconds. 
		}
		//If statement for song with single digit numbers (songs 1 - 9).
		if (song < 10 && song > 0)
		{
			i = +i;		//Adds space at start of line for alignment to double digits (songs 10 & 11).
		}
		
		//Prints the numbered list of songs, the seconds and minutes for each song, the total minutes and seconds up to that song on the CD.
		cout << " |" << setw(i) << song << setw(5) << "|" << setw(6) << minutes << setw(8) << static_cast<int>(seconds+0.5) << setw(5) << "|" << setw(6) << totalSongMinutes << setw(8) << static_cast<int>(totalSongSeconds+0.5) << "    |" << endl;
		
		//Prints the output written on CD.txt file in the form of a table with columns and headings.			
		outputFile << " |" << setw(i) << song << setw(5) << "|" << setw(6) << minutes << setw(8) << static_cast<int>(seconds + 0.5) << setw(5) << "|" << setw(6) << totalSongMinutes << setw(8) << static_cast<int>(totalSongSeconds+0.5) << "    |" << endl;
		
		//Variable substitution for next loop.
		song++;									// Add 1 to song number for next loop.
		inputFile >> songSeconds;				// Gets next value from next row in song.txt file for the next loop.
	}
	// Calculated remaining space on CD after subtracting the total song times for size compatability. 
	cdMinutesLeft = ((cdTotalMinutes * 60) - ((totalSongMinutes*60) + totalSongSeconds))/60;
	cdSecondsLeft = (cdMinutesLeft - static_cast<int>(cdMinutesLeft))*60;

	//Prints the amount of time remaining available on the CD - Shows user how well the songs will fit to CD.
	cout << " |________|__________________|__________________|" << endl << endl;	//Output Table lower portion
	cout << "  There are " << int(cdMinutesLeft) << " minutes and " << cdSecondsLeft << " seconds of space left on the " << cdTotalMinutes << "-minute CD." << endl << endl;
	outputFile << " |________|__________________|__________________|" << endl << endl; //Output Table lower portion for CD.txt
	outputFile << "  There are " << int(cdMinutesLeft) << " minutes and " << cdSecondsLeft << " seconds of space left on the " << cdTotalMinutes << "-minute CD." << endl;

	//Closing program statements
	inputFile.close();				//Close input file: "songs.txt"
	outputFile.close();				//Close output file: "CD.txt"
	system("pause");
	return 0;
}
//Function definitions
