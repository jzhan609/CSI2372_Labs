/*
 * File: myfile1.cpp
 * Author: Jacob Zhang
 * Description: Demonstrates data type sizes, number base conversions, and basic I/O in C++.
 * Date: 2025/09/24
 */

#include "myfile1.h"

// Takes an integer and returns its octal or hexadecimal string representation.
string convertInt(int value, bool toOctal) {
    string result;
    if (toOctal) {
        // Octal conversion
        if (value == 0) return "0";
        int temp = value;
        while (temp > 0) {
            result = to_string(temp % 8) + result;
            temp /= 8;
        }
    } else {
        // Hexadecimal conversion
        if (value == 0) return "0";
        int temp = value;
        const char* hexDigits = "0123456789abcdef";
        while (temp > 0) {
            result = hexDigits[temp % 16] + result;
            temp /= 16;
        }
    }
    return result;
}

// Main function demonstrating data type sizes, number base conversions, and I/O.
int main() {
    // Display sizes of various data types
    cout << "Size in bytes of a character: " << sizeof(char) << endl;
    cout << "Size in bytes of an Integer: " << sizeof(int) << endl;
    cout << "Size in bytes of a float: " << sizeof(float) << endl;
    cout << "Size in bytes of a double: " << sizeof(double) << endl;
    cout << "Size in bytes of a short Integer: " << sizeof(short) << endl;
    cout << "Size in bytes of an unsigned integer: " << sizeof(unsigned int) << endl;

    // Read an integer and display it in decimal, octal, and hexadecimal
    cout << "Enter an Integer: ";
    int input;
    cin >> input;
    cout << "Number in decimal: " << input << endl;
    cout << "Number in octal: " << oct << input << endl;
    cout << "Number in hexa: " << hex << input << endl;

    // Display octal and hexadecimal using custom conversion function
    string as_octal = convertInt(input, true);
    string as_hex = convertInt(input, false);
    cout << "Number in decimal: " << input << endl;
    cout << "Number in octal: " << as_octal << endl;
    cout << "Number in hexa: " << as_hex << endl;

    // Read and display a real number in normal and scientific notation
    cout << "Enter a real number: ";
    double real_input;
    cin >> real_input;
    cout << real_input << endl;  
    cout << scientific << real_input << endl;

    // Read and display a character and its ASCII value
    cout << "Enter a character: ";
    char char_input;
    cin >> char_input;
    cout << char_input << endl;
    cout << static_cast<int>(char_input) << endl;

    return 0;
}