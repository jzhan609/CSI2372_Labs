/*Ex2.cpp : Ex2 a2 CSI2372A*/
/*
Purpose: To implement insertion sort algorithm
Parameters: int a[] : array to be sorted
			int size : number of elements in the array
*/
#include "Ex2.h"

int main() {
	int myArray[sizeArray] = { 2,4,88,20,3,55,87,134,2,5 };

	cout << "Displaying the unsorted array :" << endl;
	for (int i = 0; i < sizeArray; i++) {
		cout << myArray[i] << " ";
	}
	cout <<  endl << endl;
	sort(myArray, sizeArray);
	cout << "Displaying the sorted array :" << endl;
	for (int i = 0; i < sizeArray; i++) {
		cout << myArray[i] << " ";
	}
	cout << endl;
}

void sort(int a[], int size)
{
	//Insertion Sort algorithm
    for (int i = 0; i < size; i++) {
        int reference = a[i];
        int j = i + 1;
        
        //find smaller elements after position i
        while (j < size) {
            if (a[j] < reference) { //found a smaller element
                int temp = a[j]; 
                //shift elements to the right
                for (int k = j; k > i; k--) {  //shift elements to the right
                    a[k] = a[k - 1];
                }
                a[i] = temp; //insert the smaller element at position i
                reference = a[i];
            }
            j++; 
        }
    }
}