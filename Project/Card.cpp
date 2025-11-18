#include "Card.h"

/**
 * Private constructor - Cards can only be created by CardDeck
 */
Card::Card(FaceAnimal a, FaceBackground bg)
    : animal(a), background(bg) {
}

/**
 * Get a specific row of the card as a string
 * Creates a 3x3 grid with background color and animal letter
 * Format:
 *   bbb
 *   bAb  (where b = background char, A = animal char)
 *   bbb
 */
std::string Card::operator()(int row) const {
    char bgChar = backgroundToChar(background);
    char animalChar = animalToChar(animal);
    
    std::string result;
    
    if (row == 0 || row == 2) {
        // Top or bottom row: all background
        result = std::string(3, bgChar);
    } else if (row == 1) {
        // Middle row: background, animal, background
        result = bgChar + std::string(1, animalChar) + bgChar;
    } else {
        result = "???";
    }
    
    return result;
}

/**
 * Conversion operator to FaceAnimal
 */
Card::operator FaceAnimal() const {
    return animal;
}

/**
 * Conversion operator to FaceBackground
 */
Card::operator FaceBackground() const {
    return background;
}
