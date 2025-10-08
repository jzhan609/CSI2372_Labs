/*Ex3.cpp : Ex3 a2 CSI2372A*/

#include <iostream>
using namespace std;

/*
Purpose: Create Pascal's triangle as a lower triangular matrix 
Parameters	: int n : number of rows in the triangle
Returns		: int** : pointer to the triangular matrix
*/

int** triangleInf(int n)
{
	//allocate array of row pointers
    int** triangle = new int*[n];
    
    // Allocate and fill each row
    for (int i = 0; i < n; i++) {
        triangle[i] = new int[i + 1];  //row i has i+1 elements
        
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                //first and last elements are always 1
                triangle[i][j] = 1;
            }
            else {
                //sum of two elements from previous row
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
        }
    }
    
    return triangle;
}

int main() {
	int** tab;
	const int size = 10;
	tab = triangleInf(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <= i; j++)
			cout << tab[i][j] << " ";
		cout << endl;
	}

	//clean up memory
    for (int i = 0; i < size; i++) {
        delete[] tab[i];
    }
    delete[] tab;
    
    return 0;
}