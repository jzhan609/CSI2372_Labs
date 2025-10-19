/*Ex1a - a3 CSI2372A*/
/*
* Program Purpose: This program creates an array of 32 distinct Card structures,
* which rep. a standard 32-card deck with 4 colors and 8 faces.
*/


#include <iostream>
using namespace std;

enum Color { club, diamond, spades, heart };
enum Face { seven, eight, nine, ten, jack, queen, king, ace };

struct Card{
	Color color;
	Face face;
};

int main(){

	//First, build deck of 32 cards + index to keep track of position in deck
	Card game[32];
	int index = 0;

	//Next, use nested loops to fill the deck with 32 distinct cards
	for (int c = club; c <= heart; c++) { //outer loop for colors
		for (int f = seven; f <= ace; f++) { //inner loop for faces
			//fill the deck with distinct cards
			game[index].color = static_cast<Color>(c);
			game[index].face = static_cast<Face>(f);
			index++;
		}
	}

	//Display the deck to verify if its correct
	cout << "Deck of 32 cards created" << endl;
	cout << "Total cards inside our deck: " << index << endl;
	
	//Display sample cards
	cout << "\nSample cards:" << endl;
	cout << "Card 0: Color=" << game[0].color << ", Face=" << game[0].face << endl;
	cout << "Card 10: Color=" << game[10].color << ", Face=" << game[10].face << endl;
	cout << "Card 25: Color=" << game[25].color << ", Face=" << game[25].face << endl;
	
	return 0;
}

