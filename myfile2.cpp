/* Header file: myfile2.h */
#include <iostream>
#include <iomanip>
#include <process.h>
using namespace std;

const double Pi = 3.14159;
char menu(void);
float surface(double radius);
float volume(double radius, double height);

float surface(double radius){
    static int count = 0;
    count++;
    cout << "The Surface is: " << Pi * radius * radius << endl;
    return count;    
}

float volume(double radius, double height){
    static int count = 0;
    count++;
    cout << "The Volume is: " << Pi * radius * radius * height << endl;
    return count;
}

/* menu Function: displays an option menu and returns the chosen option*/
char menu(void) {
char choice;
cout << "What do you want to do?:" << endl << endl;
cout << "\t-Calculate the area of a disk from a radius (Press 1)" << endl
<< endl;
cout << "\t-Calculate the volume of a cylinder from a radius and a height (Press 2)" << endl << endl;
cout << "\t-Exit the program (press 3)" << endl << endl;
cout << "Your choice:";
cin >> choice;
return (choice);
cout << endl;
}

/* main Function */
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