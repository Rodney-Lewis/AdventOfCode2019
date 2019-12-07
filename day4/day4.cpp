#include <iostream>
#include <sstream>

using namespace std;

bool pairCheck(string password) {

    int const size = 10;
    int arr[size] = {};
    int const ASCII_ZERO = 48;

    //48 starts ascii chars
    for (int i = 0; i < password.size(); i++) {
        for (int j = ASCII_ZERO; j < size + ASCII_ZERO; j++) {
            if (password[i] ==  j){
                arr[j - ASCII_ZERO]++;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] == 2) {
            return true;
        }
    }
    return false;
}

int main()
{
    int begin = 271973;
    int end = 785961;
    int part1totalPasswords = 0;
    int part2TotalPasswords = 0;
    string password;
    bool doubleDigit = false;
    bool sequence = false;

    for (int i = begin; i <= end; i++) {
        password = to_string(i);
        sequence = true;
        doubleDigit = false;

        for (int j = 1; j < password.size(); j++) {
            if (password[j - 1] <= password[j]) {
                if (password[j - 1] == password[j]) {
                    doubleDigit = true;
                }
            }
            else {
                sequence = false;
            }
        }

        if (doubleDigit == true && sequence == true) {
            part1totalPasswords++;
            if (pairCheck(password)) {
                part2TotalPasswords++;
            }
        }
      
    }

    cout << "Part 1 total passwords: " << part1totalPasswords << endl;
    cout << "Part 2 total passwords: " << part2TotalPasswords << endl;
};
