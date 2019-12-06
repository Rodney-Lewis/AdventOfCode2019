// day3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Grid.cpp"

using namespace std;

vector<string> explode(string text, char delimiter) {

	int pos = 0; 
	string temp;
	vector<string> seperatedStrings;

	for (int i = 0; i < text.size(); i++) {
		if (text[i] == ',') {
			temp = (text.substr(pos, i - pos));
			seperatedStrings.push_back(temp);
			pos = i + 1;
		}
	}
	temp = (text.substr(pos, text.size()));
	seperatedStrings.push_back(temp);

	return seperatedStrings;
}

int main()
{
	ifstream problemInputFile;
	string problemInputString;
	vector<string> gridInput;
	vector<Grid> grids;

	problemInputFile.open("./problemInput.txt");
	if (!problemInputFile) {
		exit(1);
	}
	else {
		while (getline(problemInputFile, problemInputString)) {
			gridInput.push_back(problemInputString);
		}

		for (int i = 0; i < gridInput.size(); i++) {
			grids.push_back(Grid());
			grids[i].buildGrid(explode(gridInput[i], ';'));
		}
		grids[0].findIntersectionDistances(grids[1]);
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
