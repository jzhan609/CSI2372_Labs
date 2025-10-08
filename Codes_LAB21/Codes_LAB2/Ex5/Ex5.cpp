/*Ex5.cpp : Ex5 a2 CSI2372A*/
/*
Purpose: String manipulation program with menu interface
*/

#include "Ex5.h"

int main()
{
    int i;
    char* chain[nb_ch];     //array of pointers to char
    char choice;            //variable for choice entered inside menu()

    cout << endl << "Enter the 5 character strings ending with a tab and a line return" << endl;

    for (i = 0; i < nb_ch; i++)
    {
        chain[i] = new char[size_ch];              //memory allocation
        cin.getline(chain[i], size_ch, '\t');      //input the string up until TAB
        cin.ignore(INT_MAX, '\n');                 //ignore remaining line (line return)
    }

    display(chain, nb_ch);

    while (1)
    {
        choice = menu();

        switch (choice)
        {
        case '1':
            display(chain, nb_ch);
            break;

        case '2':
            replace(chain, nb_ch, size_ch);
            break;

        case '3':
            sort(chain, nb_ch);
            break;

        case '4':
            //free our allocated memory before exiting
            for (i = 0; i < nb_ch; ++i) delete[] chain[i];
            exit(0);

        default:
            //if unknown choice -> just loop again to show the menu
            break;
        }
    }

    return 0;
}

/********************************************************************************/
/* Function menu which returns a character corresponding to the user's choice    */
/********************************************************************************/
char menu(void)
{
    char choice;

    cout << endl << endl << "\t\tMenu" << endl << endl;
    cout << "1) Strings display." << endl;
    cout << "2) Replacement of a string by an other one" << endl;
    cout << "3) Sorting strings" << endl;
    cout << "4) Exit of the program" << endl << endl;
    cout << "Your choice :";
    cin >> choice;

    return choice;
}

/********************************************************************************/
/* Function display which displays the strings                                   */
/********************************************************************************/
void display(char* tab[], int const& nbre)
{
    for (int i = 0; i < nbre; ++i)
    {
        cout << "The string " << i << " is : " << tab[i] << endl;
    }
}

/********************************************************************************
 * replace: replaces one string by another.
 * Arguments:
 *   - tab  : array of pointers to C-strings
 *   - nbre : number of elements in 'tab'
 *   - size : maximum size of each string (buffer size)
 ********************************************************************************/
void replace(char* tab[], int const& nbre, int const& size)
{
    int numero; // the string index to modify

    cout << endl << "Enter the string number to modify: ";

    // Clear any leftover newline from previous formatted input,
    // then read the index.
    cin.ignore(INT_MAX, '\n');
    cin >> numero;

    if (numero < 0 || numero >= nbre)
    {
        cout << "Invalid index. Must be between 0 and " << (nbre - 1) << "." << endl;
        return;
    }

    cout << "Enter the new string: ";
    cin.ignore(INT_MAX, '\n');           //flush newline after reading 'numero'
    cin.getline(tab[numero], size);      //read the replacement line (up to size-1 chars)

    //tab[numero] already points to an allocated buffer; getline writes directly into it.
}

/********************************************************************************/
/* Function sort to sort strings (insertion sort, lexicographic ascending)      */
/********************************************************************************/
void sort(char* tab[], int const& nbre)
{
    //insertion sort by rearranging pointers (no string copies needed here)
    for (int i = 1; i < nbre; ++i)
    {
        char* key = tab[i];
        int j = i - 1;

        //Move elements that are > key one position ahead
        while (j >= 0 && strcmp(tab[j], key) > 0)
        {
            tab[j + 1] = tab[j];
            --j;
        }
        tab[j + 1] = key;
    }
}
