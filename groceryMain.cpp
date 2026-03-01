/*
* Jonathan Martinez
* Project Three Grocery
* 2/18/26
* CS-210
* This program reads grocery data from a file and allows the user to see the frequency of
* each produce item in either a list or a histogram. They may also look for a specific item and its quantity.
*/
#include "grocery.h"

/*
* These are defined in grocery.h so no need to do in main
* #include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>
*/

using namespace std;

int getInteger(int, int, string);
string printStars(int);
void pause(string = "Press enter to continue ");
void cls();

const string INPUT_FILE = "CS210_Project_Three_Input_File.txt";
const string OUTPUT_FILE = "frequency.txt";


int main() {

	Grocery myGrocery;

	ifstream inputFile;
	ofstream outputFile;
	string item = "";
	map<string, int> grocList;  // Map contains grocery item and its quantity
	int selection = 0;

	// Attempt to open input file via Grocery function
	if (myGrocery.openInputFile(inputFile, INPUT_FILE)) {
		cout << "Input File Opened " << endl;
	}
	else {
		cerr << "Error in file " << endl;
		return EXIT_FAILURE;
	}

	// Attempt to open output file via Grocery function
	if (myGrocery.openOutputFile(outputFile, OUTPUT_FILE)) {
		cout << "Output File Opened " << endl;
	}
	else {
		cerr << "Error in file " << endl;
		return EXIT_FAILURE;
	}

	pause("Press enter to read the file ");
	cls();
	grocList = myGrocery.readInputFile(inputFile);      // Reads grocery items and their count to a map
	myGrocery.writeOutputFile(outputFile, grocList);  // Writes grocery item and its quantity to frequency.txt

	// Loop to display menu and perform actions to display grocery data until user selects option 4
	do {
		myGrocery.displayMenu();
		selection = getInteger(1, 4, "Please select menu option between");

		switch (selection) {
		case 1:  // Find item and output its quantity
			myGrocery.findItem(grocList);
			cls();
			break;
		case 2:  // List all grocery items and their quantity
			myGrocery.listItems(grocList);
			break;
		case 3:  // Print histogram of grocery item counts
			myGrocery.printHistogram(grocList);
			break;
		case 4:  // Close program
			break;
		default:
			cout << "Opps we should never get here ...." << endl;
			break;
		}
	} while (selection != 4);

	// Close input and output files
	inputFile.close();
	outputFile.close();

	return 0;

} //main

int getInteger(int lowest, int highest, string prompt)
{
	/*
	* This function will get a string input for a number and will call the function isNumber to make sure the user typed in only digits.
	* If the function isNumber returns false the user will be notified and asked to reinput.
	* In addition to the overloaded plain getInteger, this function will also check for low and high constraints
	*/
	int number = 0;
	bool needNumber = true;
	//string prompt = "";

	prompt = prompt + to_string(lowest) + " and " + to_string(highest) + " ";
	do {
		cout << prompt;
		cin >> number;
		if (cin.fail()) {
			cout << "Must be a number " << endl;
			cin.clear();
			cin.ignore(MAX_INTEGER, char(10));  // '\n'
			continue;
		}
		cin.ignore(MAX_INTEGER, '\n');
		needNumber = ((number < lowest) || (number > highest)); //check if in bounds
		if (needNumber) {
			cout << "\a Invalid number - please enter" << endl;
		}
	} while (needNumber);

	//cin.ignore(100, '\n');

	return number;
} //getInteger

string printStars(int numStars)
{
	//string stars(numStars, '*');

	return string(numStars, '*');
}

void pause(string prompt)
{
	cout << prompt;
	cin.get();


}

void cls()
{
	std::cout << "\x1B[2J\x1B[H";  // ANSI escape codes to clear screen and move cursor to top-left
	cout << endl;
	std::cout.flush();
}
