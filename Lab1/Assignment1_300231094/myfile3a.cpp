/*
 * File: myfile3a.cpp
 * Author: Jacob Zhang
 * Description: This program reads an array of integers from the user, and sorts it in descending order using selection sort.
 * Date: 2025/09/24
 */

#include <iostream>
#include <vector>

using namespace std;

// Finds the index of the maximum value in the array up to the specified limit.
int searchIndex(vector<int> T, int imax) {
	if (T.size() < imax - 1) {
		cout << "Erreur ! Tableau trop petit ! " << endl;
		return -1;
	}
	int res = 0;
	for (int i = 1; i <= imax; i++)
		if (T[i] > T[res]) res = i;
	return res;
}

// Exchanges the values of two integers.
void exchange(int& a, int& b) {
	int c;
	c = a; a = b; b = c;
}

// Sorts the array in descending order using selection sort. 
vector<int> sort(vector<int> T) {
	int n = T.size();
	for (int i = n - 1; i > 0; i--) {
		int maxIdx = searchIndex(T, i);
		if (maxIdx != i) {
			exchange(T[maxIdx], T[i]);
		}
	}
	return T;
}

// Reads an array of integers from the user.
vector<int> arrayEntry() {
	int size;
	cout << " Enter the size of your array: ";
	cin >> size;
	vector<int> res(size, 0);
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
	vector<int> arraySorted;
	a = arrayEntry();

	// Display original array
	cout << "My array values are : ";
	for (int i = 0; i < a.size(); i++) {
		cout << "\n" << a[i];
	}
	cout << "\n";

	// Sort and display sorted array
	arraySorted = sort(a);
	cout << "\nMy sorted array values are : ";
	for (int i = 0; i < arraySorted.size(); i++) {
		cout << "\n" << arraySorted[i];
	}
	cout << "\n";
}
