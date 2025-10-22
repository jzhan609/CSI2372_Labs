/*myFile2.h, Ex2 CSI2372A*/
/*
 * This class rep. a set of integers (no duplicate elements)
 * The array size is always the no. of elements
 */


#include <cstdlib> 
using namespace std;

class SetInt
{
public:
	SetInt() : elem(NULL), size(0) {};
	SetInt(int[], int);
	~SetInt();
	SetInt(const SetInt&);  // copy constructor
	void add(int);
	void remove(int);
	bool contains(int);
	int nbElem();
	int* tabElem();
private:
	int* elem;
	int size;
	bool containsIn(int n, int&);
};

/*
 * Parameters:
 *   arr - array of integers (int[])
 *   n - size of the array (int)
 * SetIn Constructor, Creates a set from array, excluding duplicate elements
 */
SetInt::SetInt(int arr[], int n) {
    elem = NULL;
    size = 0;
    
    //Add each element, will handle duplicates
    for (int i = 0; i < n; i++) {
        add(arr[i]);
    }
}

/*
 * Parameters: none
 * SetIn Destructor, Frees dynamically allocated memory for the element array
 */
SetInt::~SetInt() {
    if (elem != NULL) {
        delete[] elem;
    }
}

/*
 * Parameters:
 *   other - reference to another SetInt object (const SetInt&)
 * SetInt Copy Constructor, Creates deep copy of another SetInt object
 */
SetInt::SetInt(const SetInt& other) {
    size = other.size;
    
    if (size == 0) {
        elem = NULL;
    } else {
        elem = new int[size];
        for (int i = 0; i < size; i++) {
            elem[i] = other.elem[i];
        }
    }
}

/*
 * Parameters:
 *   n - integer to add (int)
 * Returns: void
 * Adds integer to the set if it's not present
 */
void SetInt::add(int n) {
    //Check if element already exists
    if (contains(n)) {
        return;  //Element already in set so don't add
    }
    
    //Create new array with size+1
    int* newElem = new int[size + 1];
    
    //Copy existing elements
    for (int i = 0; i < size; i++) {
        newElem[i] = elem[i];
    }
    
    //Add new element
    newElem[size] = n;
    
    //Delete old array & update
    if (elem != NULL) {
        delete[] elem;
    }
    elem = newElem;
    size++;
}

/*
 * Parameters:
 *   n - integer to remove (int)
 * Returns: void
 * Removes integer from set if it exists
 */
void SetInt::remove(int n) {
    int pos;
    
    //Check if element exists and get position
    if (!containsIn(n, pos)) {
        return;  //Element is not in set
    }
    
    //If only 1 element, delete array and set it to NULL
    if (size == 1) {
        delete[] elem;
        elem = NULL;
        size = 0;
        return;
    }
    
    //Create new array with size-1
    int* newElem = new int[size - 1];
    
    //Copy elements except the one at position pos
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (i != pos) {
            newElem[j] = elem[i];
            j++;
        }
    }
    
    //Delete old array and update
    delete[] elem;
    elem = newElem;
    size--;
}

/*
 * Parameters:
 *   n - integer to search for (int)
 * Returns: true: if element is in set, false otherwise (bool)
 * Checks if integer is present in set
 */
bool SetInt::contains(int n) {
    int pos;
    return containsIn(n, pos);
}

/*
 * Parameters: none
 * Returns: no. of elements in set (int)
 * Returns size of set
 */
int SetInt::nbElem() {
    return size;
}

/*
 * Parameters: none
 * Returns: pointer to dynamically allocated array containing set elements (int*)
 * Returns copy of elements array (NULL if set is empty)
 */
int* SetInt::tabElem() {
    if (size == 0) {
        return NULL;
    }
    
    //Create and return a copy of array
    int* copy = new int[size];
    for (int i = 0; i < size; i++) {
        copy[i] = elem[i];
    }
    
    return copy;
}

/*
 * Parameters:
 *   n - integer to search for (int)
 *   pos - reference to store position if found (int&)
 * Returns: true if element found, false otherwise (bool)
 * Searches for element and returns its position via reference parameter
 */
bool SetInt::containsIn(int n, int& pos) {
    for (int i = 0; i < size; i++) {
        if (elem[i] == n) {
            pos = i;
            return true;
        }
    }
    return false;
}

