/*Ex2 - a3 CSI2372A*/
/*
 * Program Purpose: Implement a simple linked list for student evaluations
 * The program lets users add, remove, display student records and calculate averages
 */

#include "myLinkedList.h"

int main()
{
	// Global variables
	int choice;           //User menu choice
	Evaluation* first = nullptr;  //Pointer to the first element of the linked list
	int number = 0;       //Number of elements in our list
	
	do
	{
		cout << endl << endl << "1) Display of the complete linked list.\n";
		cout << "2) Insert an element\n";
		cout << "3) Remove an element.\n";
		cout << "4) Calculation of the class average.\n";
		cout << "5) Exit the program.\n" << endl << endl;
		cout << "Your choice ??:";
		cin >> choice;

		switch (choice)
		{
		case 1: display(first);
			break;
		case 2: first = add(first, number);
			break;
		case 3: first = remove(first, number);
			break;
		case 4: average(first, number);
			break;
		case 5: exit(0);
		default:
			break;
		}
	} while (1);
	return 0;
}



/**
 * Purpose: Add a new element to the linked list at a specified position
 * Parameters:
 *   - p: Evaluation* (pointer to the first element of the list)
 *   - number: int& (reference to the count of elements, will be incremented)
 * Returns:
 *   - Evaluation*: pointer to the first element of the updated list
 */
Evaluation* add(Evaluation* p, int& number)
{
	int position;
	cout << "After which element you want to insert ? (0 for start): ";
	cin >> position;
	
	//Validate position
	if (position < 0 || position > number) {
		cout << "Invalid position!" << endl;
		return p;
	}
	
	//Create a new node with memory allocation
	Evaluation* newNode = new Evaluation;
	
	cout << " Entering the item from the chained list." << endl;
	cout << "Enter the student: ";
	cin.ignore(); //Clear the input buffer
	cin.getline(newNode->student, capacity);
	
	cout << "Enter the grade: ";
	cin >> newNode->grade;
	
	//Case 1: Insert in beginning (position == 0)
	if (position == 0) {
		newNode->next = p;  //New node points to current first element
		number++;           //Increment element count
		return newNode;     //Return new node as the new first element
	}
	
	//Case 2: Insert after a specific element
	Evaluation* current = p;
	//Traverse to the element after which we want to insert
	for (int i = 1; i < position; i++) {
		current = current->next;
	}
	
	//Insert the new node
	newNode->next = current->next;  //New node points to next element
	current->next = newNode;        //Previous element points to new node
	number++;                       //Increment element count
	
	return p;  //Return pointer to first element (unchanged)
}

/**
 * Purpose: Removes an element from the linked list at a specified position
 * Parameters:
 *   - p: Evaluation* (pointer to the first element of the list)
 *   - number: int& (reference to the count of elements, will be decremented)
 * Returns:
 *   - Evaluation*: pointer to the first element of the updated list
 */
Evaluation* remove(Evaluation* p, int& number)
{
	if (p == nullptr) {
		cout << "The list is empty!" << endl;
		return p;
	}
	
	int position;
	cout << "what is the number of the element to delete ?: ";
	cin >> position;
	
	//Validate position
	if (position < 1 || position > number) {
		cout << "Invalid position!" << endl;
		return p;
	}
	
	//Case 1: Remove the first element
	if (position == 1) {
		Evaluation* temp = p;      //Save pointer to first element
		p = p->next;               //Move first pointer to next element
		delete temp;               //Free memory
		number--;                  //Decrement
		return p;                  //Return new first element
	}
	
	//Case 2: Remove an element in the middle or end
	Evaluation* current = p;
	//Traverse to the element before the one to delete
	for (int i = 1; i < position - 1; i++) {
		current = current->next;
	}
	
	Evaluation* temp = current->next;      //Save pointer to element to delete
	current->next = current->next->next;   //Bypass the element to delete
	delete temp;                           //Free memory
	number--;                              //Decrement element count
	
	return p;  //Return pointer to first element
}



/**
 * Purpose: Displays all elements in the linked list
 * Parameters:
 *   - p: Evaluation* (pointer to the first element of the list)
 * Returns: void
 */
void display(Evaluation* p)
{
	//Check if list is empty
	if (p == nullptr) {
		cout << "The list is empty!" << endl;
		return;
	}
	
	//Traverse list and display each element
	Evaluation* current = p;
	while (current != nullptr) {
		cout << "Student :" << current->student << endl;
		cout << "The grade is :" << current->grade << endl;
		current = current->next;  //Move to next element
	}
}



/**
 * Purpose: Calculates and displays the average grade of all students
 * Parameters:
 *   - p: Evaluation* (pointer to the first element of the list)
 *   - nbre: int const& (const reference to the number of elements)
 * Returns:
 *   - int: 1 if successful, 0 if list is empty
 */
int average(Evaluation* p, int const& nbre)
{
	//Check if list is empty
	if (p == nullptr || nbre == 0) {
		cout << "The list is empty! Cannot calculate average." << endl;
		return 0;
	}
	
	int sum = 0;
	Evaluation* current = p;
	
	//Traverse list and sum all grades
	while (current != nullptr) {
		sum += current->grade;
		current = current->next;
	}
	
	//Calculate and display the average
	int avg = sum / nbre;
	cout << "The average of the class is: " << avg << endl;
	
	return 1;  //Success!
}






