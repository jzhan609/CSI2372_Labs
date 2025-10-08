/*Ex5.cpp : Ex5 a2 CSI2372A*/
/*
Purpose: String manipulation program with menu interface
*/

#include "Ex5.h"

int main()
{
	int i;
	char *chain[nb_ch];		//array of pointers on char
	char choice;			//variable for the choice entered in menu()

	cout << endl << "Enter the 5 character strings ending with a tab and a line return" << endl ;

	for (i=0;i<nb_ch;i++)
	{
		chain[i]=new char[size_ch];		//memory allocation
		cin.getline(chain[i],size_ch,'\t');	//seizure of the string
		cin.ignore(INT_MAX,'\n');		//clear the input buffer after reading the string
	}

	display(chain,nb_ch);					

	while(1)
	{
		choice=menu();
	
		switch(choice) 
		{
			case '1':	display(chain,nb_ch);  
				break;
			case '2':	replace(chain,nb_ch,size_ch);	
				break;
			case '3':	sort(chain,nb_ch);
				break;
			case '4':	
				// Clean up allocated memory before exit
				for(i=0; i<nb_ch; i++)
					delete[] chain[i];
				exit(0);
			default:	break;
		}
	}
}


/********************************************************************************/
/* Function menu which returns a character corresponding to the user's choice  */
/********************************************************************************/

char menu(void)
{
	char choice;

	cout << endl << endl << "\t\tMenu" << endl <<endl;
	cout << "1) Strings display." <<endl;
	cout << "2) Replacement of a string by an other one"<<endl;
	cout << "3) Sorting strings"<< endl;
	cout << "4) Exit of the program"<<endl<<endl;
	cout << "Your choice :";
	cin >> choice;

	return(choice);
}


/********************************************************************************/
/*Function display which displays the strings*/
/********************************************************************************/
void display(char* tab[], int const& nbre)
{
	cout << endl;
	for(int i = 0; i < nbre; i++)
	{
		cout << "The string " << i << " is : " << tab[i] << endl; //display each string
	}
}


/********************************************************************************
*
The replace function that replaces one string by another. 
It takes as arguments an array of pointers on the strings "tab", 
the number of elements of this array of pointers "nbre" and 
the maximum size of the strings "size" 
*
********************************************************************************/

void replace(char* tab[], int const& nbre, int const& size)
{
	int numero;		//the string to modify
	char newString[size_ch];	//temporary buffer for new string

	cout << endl << "Enter the string number to modify: ";
	cin >> numero;
	cin.ignore(INT_MAX,'\n');  // Clear the input buffer after reading the number

	//check if the number is valid
	if(numero >= 0 && numero < nbre)
	{
		cout << "Enter the new string: ";
		cin.getline(newString, size);
		
		//copy the new string to the array
		strcpy(tab[numero], newString);
	}
	else
	{
		cout << "Invalid string number!" << endl;
	}
}

/********************************************************************************/
/*Function sort to sort strings using insertion sort*/
/********************************************************************************/
void sort(char* tab[], int const& nbre)
{
	int i, j;
	char* temp;
	
	// Insertion sort algorithm
	for(i = 1; i < nbre; i++)
	{
		temp = tab[i];
		j = i - 1;
		
		//compare strings and shift them if needed
		while(j >= 0 && strcmp(tab[j], temp) > 0)
		{
			tab[j + 1] = tab[j]; //shift string to the right
			j = j - 1; //move to the previous string
		}
		tab[j + 1] = temp;
	}
}