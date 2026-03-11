/*
 * File: myfile2.cpp
 * Author: Jacob Zhang
 * Description: This program provides a menu to calculate the surface area of a disk and the volume of a cylinder.
 * Date: 2025/09/24
 */

#include "myfile2.h"

// Displays an option menu to the user and returns the chosen option.
char menu(void) {
    char choice;
    cout << "What do you want to do?:" << endl << endl;
    cout << "\t-Calculate the area of a disk from a radius (Press 1)" << endl << endl;
    cout << "\t-Calculate the volume of a cylinder from a radius and a height (Press 2)" << endl << endl;
    cout << "\t-Exit the program (press 3)" << endl << endl;
    cout << "Your choice:";
    cin >> choice;
    return (choice);
    cout << endl; // This line is unreachable, but left for completeness
}


// Calculates and displays the surface area of a disk given its radius.
float surface(double radius) {
    static int count = 0;
    count++;
    cout << "The Surface is: " << Pi * radius * radius << endl;
    return count;
}

// Calculates and displays the volume of a cylinder given its radius and height.
float volume(double radius, double height) {
    static int count = 0;
    count++;
    cout << "The Volume is: " << Pi * radius * radius * height << endl;
    return count;
}

// Main program loop. Displays the menu, processes user input, and calls the appropriate calculation functions.
int main() {
    char choice;
    int nvolume = 0;   // number of times the volume function has been executed
    int nsurface = 0;  // number of times the surface function has been executed
    double radius, height;

    while (1) {
        choice = menu();
        switch (choice) {
            case '1':
                cout << endl << "Surface calculation" << endl;
                cout << "Enter the radius: ";
                cin >> radius;
                nsurface = surface(radius);
                break;
            case '2':
                cout << endl << "Volume calculation" << endl;
                cout << "Enter the radius: ";
                cin >> radius;
                cout << "Enter the height: ";
                cin >> height;
                nvolume = volume(radius, height);
                break;
            case '3':
                cout << endl << "Exit the program" << endl;
                cout << "The volume function has been executed " << nvolume << " times" << endl;
                cout << "The surface function has been executed " << nsurface << " times" << endl;
                exit(0);
            default:
                break;
        }
    }
}