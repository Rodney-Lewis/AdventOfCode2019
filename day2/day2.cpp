// day2.cpp 
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;
int main()
{
	ifstream problemInputFile;
	string problemInputString;
	vector<int> seperatedInputValues;
	vector<int> seperatedInputValuesCopy;
	int inputValue = 0;
	int position = 0;

	problemInputFile.open("./problemInput.txt");
	if (!problemInputFile) {
		exit(1);
	}
	else {
		problemInputFile >> problemInputString;
	}

	//Write an appropriate split function for C++
	for (int i = 0; i < problemInputString.size(); i++) {
		if (problemInputString[i] == ',') {
			istringstream stringStream(problemInputString.substr(position, i - position));
			stringStream >> inputValue;
			seperatedInputValues.push_back(inputValue);
			seperatedInputValuesCopy.push_back(inputValue);
			position = i + 1;
		}
	}

	istringstream stringStream(problemInputString.substr(position, problemInputString.size() - position));
	stringStream >> inputValue;
	seperatedInputValues.push_back(inputValue);
	
	for (int k = 0; k < 100; k++) {
		for (int j = 0; j < 100; j++) {
			seperatedInputValues[1] = k;
			seperatedInputValues[2] = j;
	
			for (int i = 0; i < seperatedInputValues.size(); i = i + 4) {
				if (seperatedInputValues[i] == 1) {
					int temp = seperatedInputValues[seperatedInputValues[i + 1]] + seperatedInputValues[seperatedInputValues[i + 2]];
					seperatedInputValues[seperatedInputValues[i + 3]] = temp;
				}
				else if (seperatedInputValues[i] == 2) {
					int temp = seperatedInputValues[seperatedInputValues[i + 1]] * seperatedInputValues[seperatedInputValues[i + 2]];
					seperatedInputValues[seperatedInputValues[i + 3]] = temp;
				}
			}

			if (seperatedInputValues[0] == 19690720) {
				cout << k << " " << j;
			}

			seperatedInputValues = seperatedInputValuesCopy;
		}
	}
}