#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int numberOfModules = 0;
    int moduleWeight = 0;
    int fuelWeightSum = 0;
    int calculatedFuelWeightForModule = 0;

    //9 is the minimum weight required for a module or fuel to ultimately effect the total fuel required.
    const int MIN_WEIGHT_REQUIREMENT = 9;

    cout << "Enter number of modules: ";
    cin >> numberOfModules;
    cout << endl << "Enter module weights:" << endl;

    for(int i = 0; i < numberOfModules; i++) {

        //Part 1
        cin >> moduleWeight;
        //Integer division handles the need to use "floor".
        calculatedFuelWeightForModule = ((moduleWeight/3)-2);
        if(calculatedFuelWeightForModule > 0) {
            fuelWeightSum += calculatedFuelWeightForModule;
        }

        //Part 2
        while(calculatedFuelWeightForModule >= MIN_WEIGHT_REQUIREMENT) {
            calculatedFuelWeightForModule = ((calculatedFuelWeightForModule/3)-2); 
            fuelWeightSum += calculatedFuelWeightForModule;
        }
    }
    cout << fuelWeightSum << endl;
}