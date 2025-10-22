/*myFile1b.h, Ex1 a4 CSI2372A*/
/* 
This class rep. a student who can enroll in multiple courses and maintains
a list of courses and grades
*/

#include <iostream>
using namespace std;

class Student {
	int numID;
	int nbCourses;
	int maxCourses;
	int* List_grades;
	Course** List_courses;
public:
	Student(int, int); 	//constructor
	~Student(); 		//destructor
	double average();
	int totalHours();
	bool addCourse(Course*, int);
};


/*
 * id - student's registration number (int)
 * max - maximum number of courses student can take (int)
 * Initializes a Student object and allocates memory for course lists
 */
Student::Student(int id, int max) {
    numID = id;
    maxCourses = max;
    nbCourses = 0;  //Initially no courses
    
    //Allocate dynamic arrays for courses and grades
    List_courses = new Course*[maxCourses];
    List_grades = new int[maxCourses];
}

/*
 * Parameters: N/A
 * Purpose: Frees dynamically allocated memory for course and grade lists
 */
Student::~Student() {
    delete[] List_courses;
    delete[] List_grades;
}

/*
 * Parameters: N/A
 * Returns: average of grades (double)
 * Calculates and returns the student's average grade across all courses
 */
double Student::average() {
    if (nbCourses == 0) {
        return 0.0;  //If no courses, no average
    }
    
    double sum = 0.0;
    for (int i = 0; i < nbCourses; i++) {
        sum += List_grades[i];
    }
    
    return sum/nbCourses;
}

/*
 * Parameters: N/A
 * Returns: total number of course hours (int)
 * Calculates and returns the sum of hours from all enrolled courses
 */
int Student::totalHours() {
    int total = 0;
    for (int i = 0; i < nbCourses; i++) {
        total += List_courses[i]->getHours();
    }
    return total;
}

/*
 * course - pointer to a Course object (Course*)
 * grade - the grade obtained in this course (int)
 * Returns: true if course added successfully, false if maximum reached (bool)
 * Adds a course and its grade to the student's lists
 */
bool Student::addCourse(Course* course, int grade) {
    if (nbCourses >= maxCourses) {
        return false;  //Cannot add more courses
    }
    
    List_courses[nbCourses] = course;
    List_grades[nbCourses] = grade;
    nbCourses++;
    
    return true;
}

