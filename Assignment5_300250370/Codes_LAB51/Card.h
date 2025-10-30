/*
* Card.h - definition of class Card
* Purpose: to represent a playing card with a color and a value
*/

#include <iostream>
using namespace std;
#include <cassert> //for assert()

enum color { club, diamond, heart, spade };

class Card {
public:
    Card(color c = club, int v = 1);
    int value() { return val; }
    void write();
private:
    color col;
    int val;
};

/*Constructor*/
Card::Card(color c, int v) {
    assert(v >= 1 && v <= 13); //we use a standard function void assert (int expression)
    //which indicates an error message if the expression is false.
    col = c;
    val = v;
}

/*
 * Purpose: Displays the card information. Prints the value and color of the card
 * Output format: "value of color"
 * Special cases: 1 = Ace, 11 = Jack, 12 = Queen, 13 = King
 */
void Card::write() {
    //Display the value
    if (val == 1) {
        cout << "Ace";
    } else if (val == 11) {
        cout << "Jack";
    } else if (val == 12) {
        cout << "Queen";
    } else if (val == 13) {
        cout << "King";
    } else {
        cout << val;
    }
    
    cout << " of ";
    
    //Display the color
    switch (col) {
        case club:
            cout << "Clubs";
            break;
        case diamond:
            cout << "Diamonds";
            break;
        case heart:
            cout << "Hearts";
            break;
        case spade:
            cout << "Spades";
            break;
    }
}

