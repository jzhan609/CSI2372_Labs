/*Ex1b - a3 CSI2372A*/
/*
* Program Purpose: This program defines a function to test if a hand of 5 cards contains at least one pair.
*/

#include <iostream>
using namespace std;

enum Color { club, diamond, spades, heart };
enum Face { seven, eight, nine, ten, jack, queen, king, ace };

struct Card
{
	Color color;
	Face face;
};

typedef Card Hand[5];

/**
 * Purpose: Test if a hand contains at least one pair of cards with the same face
 * Parameters:
 *   - h: const Hand& (reference a hand of 5 cards)
 * Returns:
 *   - bool: true if at least one pair is found and false otherwise
 */
bool testPair(const Hand& h)
{
	//Nested loop to compare each card with every other card
	//Iterate through cards 0 to 3 (no need to check last card)
	for (int i = 0; i < 4; i++) {
		//Compare current card with all subsequent cards
		for (int j = i + 1; j < 5; j++) {
			if (h[i].face == h[j].face) { //Check if faces are the same
				return true; //Pair found
			}
		}
	}
	return false; //No pair found
}


/*Example of main()*/
int main()
{
	bool testPair(const Hand&);
	Hand myHand = { {club,nine}, {diamond, eight}, {spades, ace}, {spades, jack}, {club, ace} };
	cout << "\nI have at least: " << testPair(myHand) << " pair" << endl;
	return 0;
}



