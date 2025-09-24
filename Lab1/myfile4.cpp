/*
 * File: myfile3b.cpp
 * Author: Jacob Zhang
 * Description: Reads an integer from the user and checks if it is an Armstrong number.
 * Date: 2025/09/24
 */

#include <iostream> // For input and output streams
#include <cmath>    // For pow() function

using namespace std;

// Checks if a number is an Armstrong number.
bool isAngstrom(int n) {
    int sum = 0, temp, remainder, digits = 0;
    temp = n;

    // Count the number of digits in n
    while (temp != 0) {
        digits++;
        temp /= 10;
    }

    temp = n;
    // Calculate the sum of each digit raised to the power of the number of digits
    while (temp != 0) {
        remainder = temp % 10;
        sum += pow(remainder, digits); // Use 'digits' instead of hardcoded 3
        temp /= 10;
    }

    // Return true if sum equals the original number
    return (sum == n);
}

// Main function to execute the program.
int main() {
    int input;
    cout << "Please, enter your number: ";
    cin >> input;

    if (isAngstrom(input)) {
        cout << "This is an Armstrong number" << endl;
    }
    else {
        cout << "This is not an Armstrong number" << endl;
    }

    return 0;
}