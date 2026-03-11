/*
 * File: myfile3b.cpp
 * Author: Jacob Zhang
 * Description:  This program reads an array of integers from the user, and sorts it in ascending order using selection sort.
 * Date: 2025/09/24
 */

#include <iostream>
#include <vector>

using namespace std;

// Finds the index of the maximum value in the array up to the specified limit.
int searchIndex(vector<int> T, int imax) {
	// Check if the vector is large enough for the search
	if (T.size() < imax - 1) {
		cout << "Erreur ! Tableau trop petit ! " << endl;
		return -1;
	}
	int res = 0;
	// Loop from 1 to imax to find the index of the maximum value
	for (int i = 1; i <= imax; i++)
		if (T[i] > T[res]) res = i;
	return res;
}

// Exchanges the values of two integers.
void exchange(int& a, int& b) {
	int c;
	c = a; a = b; b = c;
}

// Sorts the array in ascending order using selection sort.
void sort(vector<int>& T) {
	int n = T.size();
	// Loop from the end of the vector to the beginning
	for (int i = n - 1; i > 0; --i) {
		// Find the index of the maximum value in T[0..i]
		int idx = searchIndex(T, i);
		// Swap the maximum value with the value at position i
		if (idx != i) {
			exchange(T[i], T[idx]);
		}
	}
}

// Prompts the user to enter the size and values of an integer array.
vector<int> arrayEntry() {
	int size;
	// Prompt user for array size
	cout << " Enter the size of your array: ";
	cin >> size;
	vector<int> res(size, 0);
	// Prompt user for each value in the array
	cout << " Enter the values ​​of your array: \n";
	for (int i = 0; i < size; i++) {
		cout << " val[ " << i << "] =";
		cin >> res[i];
	}
	cout << "\n";
	return res;
}

// Main function to execute the program.
int main() {
	vector<int> a;
	// Get array input from user
	a = arrayEntry();

	// Display the original array
	cout << "My array values are : ";
	for (int i = 0; i < a.size(); i++) {
		cout << "\n" << a[i];
	}
	cout << "\n";

	// Sort the array
	sort(a);

	// Display the sorted array
	cout << "\nMy sorted array values are : ";
	for (int i = 0; i < a.size(); i++) {
		cout << "\n" << a[i];
	}
	cout << "\n";
}
