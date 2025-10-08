/*Ex1.cpp : Ex1 a2 CSI2372A*/
/*
Purpose: Demonstrate pointer and array operations
Output: Displays the values as array elements are accessed and modified
*/

#include <iostream>
using namespace std;

int main(void) {
    int tab[10];
    int* p;
    
    for (int i = 0; i < 10; i++) {
        tab[i] = i * i;
    }
    
    //display tab[2] before any modification (value is 4)
    cout << tab[2] << endl;
    
    tab[2] = tab[1];
    cout << tab[2] << endl;  //display 1
    
    tab[2] = *(tab + 1);
    cout << tab[2] << endl;  //display 1
    
    *(tab + 2) = tab[1];
    cout << *(tab + 2) << endl;  //display 1
    
    *(tab + 2) = *(tab + 1);
    cout << *(tab + 2) << endl;  //display 1
    
    p = &tab[0];
    p = tab + 1;
    tab[4] = *p;
    cout << tab[4] << endl;  //display 1
    
    return 0;
}