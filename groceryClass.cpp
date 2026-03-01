#include "grocery.h"

using namespace std;

// Display menu options 1-4
void Grocery::displayMenu()
{
    cout << "Press 1 to find an item" << endl;
    cout << "Press 2 to list items and quantities" << endl;
    cout << "Press 3 to print histogram" << endl;
    cout << "Press 4 to exit" << endl;
}

// Takes input stream and file name, attempts to open file and returns true if successful, false otherwise
bool Grocery::openInputFile(ifstream &inputFS, const string &fileName)
{
    inputFS.open(fileName);

    return inputFS.is_open();
}

// Takes output stream and file name, attempts to open file and returns true if successful, false otherwise
bool Grocery::openOutputFile(ofstream &outputFS, const string &fileName)
{
    outputFS.open(fileName);

    return outputFS.is_open();
}

// Takes input stream, reads and counts grocery items from file and returns item and quantity via a map
map<string, int> Grocery::readInputFile(ifstream &inputFS) {
    map<string, int> groceryList;
    string item;

    while (inputFS >> item) {
        groceryList[item]++;
    }

    return groceryList;
}

// Takes output stream and map of grocery items with quantity, and writes item and quantity to file with 1 pair per line
void Grocery::writeOutputFile(ofstream &outputFS, map<string, int> groceryList) {
    for (const auto &pair : groceryList) {
        outputFS << pair.first << " " << pair.second << endl;
    }
}


// Takes map of grocery items with quantity, prompts user to enter an item and displays its quantity if in map
void Grocery::findItem(map<string, int> groceryList) {
    string item;
    cout << "Enter item to find: ";
    cin >> item;
    if (groceryList.find(item) != groceryList.end()) {
        cout << item << " appears " << groceryList[item] << " times in the list" << endl;
    } else {
        cout << item << " not found in the list" << endl;
    }
}

// Lists all grocery items with its quantity from map
void Grocery::listItems(map<string, int> groceryList)
{
    for (const auto &pair : groceryList) {
        cout << pair.first << " " << pair.second << endl;
    }
    cout << endl;
}

// Prints all grocery items and displays quantity via asterisks in form of a histogram
void Grocery::printHistogram(map<string, int> groceryList) {
    for (const auto &pair : groceryList) {
        cout << pair.first << " " << string(pair.second, '*') << endl;
    }
    cout << endl;
}