/*myFile1a, Ex1 a4 CSI2372A*/
/*
This class rep. a course with a course number and number of hours
*/

#include <iostream>
using namespace std;

class Course {
    int num;
    int hours;
public:
    Course(int, int); 	//constructor
    int getNum();
    int getHours();
};

/*
 * Parameters:
 *   n - course number/code (int)
 *   h - number of course hours (int)
 * Initializes a Course object with the given number and hours
 */
Course::Course(int n, int h) {
    num = n;
    hours = h;
}

/*
 * Parameters: N/A
 * Returns: the course number (int)
 * Accessor method to retrieve the course number
 */
int Course::getNum() {
    return num;
}

/*
 * Parameters: N/A
 * Returns: the number of course hours (int)
 * Accessor method to retrieve the number of hours for this course
 */
int Course::getHours() {
    return hours;
}




