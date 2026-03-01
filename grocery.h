#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>
#include <limits>
#include <filesystem>


using namespace std;
const int MAX_INTEGER = numeric_limits<int>::max();


class Grocery {

public:
	static void displayMenu();
	bool openInputFile(ifstream&, const string&);
	bool openOutputFile(ofstream&, const string&);
	map<string, int> readInputFile(ifstream&);
	void writeOutputFile(ofstream&, map<string, int>);
	void findItem(map<string, int>);
	void listItems(map<string, int>);
	void printHistogram(map<string, int>);

};