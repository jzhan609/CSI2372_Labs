/*Ex4.cpp : Ex4 a2 CSI2372A*/
/*
Purpose: Implement flexible sorting using function pointers
*/

#include <iostream>
using namespace std;

//This function returns true if a < b for the ascending order
bool increasing(int a, int b) {
	return a < b;
}

//This function returns true if a > b for the descending order
bool decreasing(int a, int b) {
	return a > b;
}

//Sorting function using function pointer for comparison
// Parameters: int tab[] - array to sort
//            int nb - size of array
//            bool (*compare)(int, int) - comparison function
void sorting(int tab[], int nb, bool (*compare)(int, int)) {
    int i, j, min, tmp;
    
    for (i = 0; i < nb; i++) {
        min = i;
        for (j = i + 1; j < nb; j++) {
            //use the comparison function pointer
            if (compare(tab[j], tab[min])) {
                min = j;
            }
        }
        //swap elements
        tmp = tab[min];
        tab[min] = tab[i];
        tab[i] = tmp;
    }
}
 
int main()
{

	int a1[6] = { 12,234,-35,1234,0, 51 };
	int a2[10] = { 1,24,5,124, -14, 0, -55, 51, 10, 33 };

	cout << "My first array a1 sorted in ascending order:" << endl;
	sorting(a1, 6, increasing);
    for (int i = 0; i < 6; i++) {
        cout << a1[i] << " ";
    }
    cout << endl;

	cout << "My second array a2 sorted in descending order:" << endl;
	sorting(a2, 10, decreasing);
    for (int i = 0; i < 10; i++) {
        cout << a2[i] << " ";
    }
    cout << endl;

	return 0;
}