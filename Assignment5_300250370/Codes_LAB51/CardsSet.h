/*
* CardSet.h - definition of class CardsSet
* Purpose: to represent a set of playing cards (e.g., a deck or a player's hand)
*/

class CardsSet {
public:
    CardsSet() : number(0) {}
    void novSet();
    void shuffle();
    int numCards() { return number; }
    Card take();
    void put(Card k);
    Card lookIn(int no);
    void empty() { number = 0; }
private:
    Card set[52];
    int number;
};

/*
 * Initializes the set with all 52 standard playing cards
 * Result: set contains all cards (4 suits × 13 values), number = 52
 */
void CardsSet::novSet() {
    number = 0;
    // Create all 52 cards: 4 colors × 13 values
    // Nested loops for colors and values
    for (int c = club; c <= spade; c++) {
        for (int v = 1; v <= 13; v++) {
            set[number] = Card(static_cast<color>(c), v);
            number++;
        }
    }
}

/*
 * Randomly rearranges the cards in the set
 * Fisher-Yates shuffle: swap each card with a random card
 */
void CardsSet::shuffle() {
    //Initialize random seed
    srand(time(0));
    
    //Fisher-Yates shuffle algorithm
    for (int i = number - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        //Swap set[i] and set[j]
        Card temp = set[i];
        set[i] = set[j];
        set[j] = temp;
    }
}

/*
 * Takes a card from the top of the set 
 * Returns: The top card (last card in the array)
 * Side effect: Decrements number (removes card from set)
 */
Card CardsSet::take() {
    assert(number > 0); //Ensure there's cards to take
    number--;
    return set[number];
}

/*
 * Adds a card to the set
 * Parameters: k (Card) - the card to add
 * Adds a card to top of set
 * Side effect: Increments number (adds card to set)
 */
void CardsSet::put(Card k) {
    assert(number < 52); //Ensure array bounds aren't exceeded
    set[number] = k;
    number++;
}

/*
 * Returns the card at position no
 * Parameters: no (int) - position to look at (1 = top of set)
 * Returns: The card at specified position
 */
Card CardsSet::lookIn(int no) {
    assert(no >= 1 && no <= number); // Validate position
    // Position 1 is the top (last card), position number is the bottom (first card)
    return set[number - no];

    //Note: Position 1 is the top (last card in array)
}
