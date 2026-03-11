#ifndef CARD_H
#define CARD_H

#include "Memoarrr.h"
#include <string>

//Forward declaration
template<typename C> class DeckFactory;
class CardDeck;

/**
 * Card class represents a memory card with an animal and background color
 * Cards are 3x3 character grids displayed in the game
 */
class Card {
private:
    FaceAnimal animal;          //The animal on the card
    FaceBackground background;   //The background color
    
    /**
     * Private constructor - Cards can only be created by CardDeck
     * @param a The animal face
     * @param bg The background color
     */
    Card(FaceAnimal a, FaceBackground bg);
    
    //Allow CardDeck to create cards
    friend class CardDeck;
    friend class DeckFactory<Card>;

public:
    /**
     * Get the number of rows in the card display (always 3)
     * @return The number of rows
     */
    int getNRows() const { return 3; }
    
    /**
     * Get a specific row of the card as a string
     * @param row The row number (0-2)
     * @return The string representation of that row
     */
    std::string operator()(int row) const;
    
    /**
     * Conversion operator to FaceAnimal
     * @return The animal on this card
     */
    operator FaceAnimal() const;
    
    /**
     * Conversion operator to FaceBackground
     * @return The background color of this card
     */
    operator FaceBackground() const;
    
    /**
     * Get the animal on this card
     * @return The FaceAnimal enum value
     */
    FaceAnimal getAnimal() const { return animal; }
    
    /**
     * Get the background color of this card
     * @return The FaceBackground enum value
     */
    FaceBackground getBackground() const { return background; }
};

#endif //CARD_H
