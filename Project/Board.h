#ifndef BOARD_H
#define BOARD_H

#include "Memoarrr.h"
#include "Card.h"
#include <array>
#include <iostream>

/**
 * Board class represents the 5x5 game board
 * Manages card positions and face-up/face-down states
 * Center position (C3) is always empty
 */
class Board {
private:
    static const int BOARD_SIZE = 5;
    std::array<std::array<Card*, BOARD_SIZE>, BOARD_SIZE> cards;  //5x5 grid of card pointers
    std::array<std::array<bool, BOARD_SIZE>, BOARD_SIZE> faceUp;  //Track face-up state
    bool expertDisplayMode;  //Display mode flag
    
    /**
     * Helper to validate board position
     * @param letter Row position
     * @param number Column position
     * @return True if valid position and not center
     */
    bool isValidPosition(const Letter& letter, const Number& number) const;
    
    /**
     * Convert Letter enum to array index
     * @param letter The letter
     * @return Array index (0-4)
     */
    int letterToIndex(const Letter& letter) const;
    
    /**
     * Convert Number enum to array index
     * @param number The number
     * @return Array index (0-4)
     */
    int numberToIndex(const Number& number) const;

public:
    /**
     * Constructor - initializes board with cards from CardDeck
     * @param expertDisplay If true, use expert display mode
     * @throws NoMoreCards if not enough cards available
     */
    Board(bool expertDisplay = false);
    
    /**
     * Destructor - cards are owned by CardDeck, not deleted here
     */
    ~Board() = default;
    
    /**
     * Check if a card at given position is face up
     * @param letter Row position
     * @param number Column position
     * @return True if card is face up
     * @throws OutOfRange if invalid position
     */
    bool isFaceUp(const Letter& letter, const Number& number) const;
    
    /**
     * Turn a card face up
     * @param letter Row position
     * @param number Column position
     * @return False if card was already face up, true otherwise
     * @throws OutOfRange if invalid position
     */
    bool turnFaceUp(const Letter& letter, const Number& number);
    
    /**
     * Turn a card face down
     * @param letter Row position
     * @param number Column position
     * @return False if card was already face down, true otherwise
     * @throws OutOfRange if invalid position
     */
    bool turnFaceDown(const Letter& letter, const Number& number);
    
    /**
     * Get pointer to card at given position
     * @param letter Row position
     * @param number Column position
     * @return Pointer to the card
     * @throws OutOfRange if invalid position
     */
    Card* getCard(const Letter& letter, const Number& number);
    
    /**
     * Set card at given position
     * @param letter Row position
     * @param number Column position
     * @param card Pointer to the card
     * @throws OutOfRange if invalid position
     */
    void setCard(const Letter& letter, const Number& number, Card* card);
    
    /**
     * Turn all cards face down
     */
    void allFacesDown();
    
    /**
     * Set display mode
     * @param expertMode True for expert display mode
     */
    void setDisplayMode(bool expertMode);
    
    /**
     * Output stream operator for printing the board
     * @param os The output stream
     * @param board The board to print
     * @return The output stream
     */
    friend std::ostream& operator<<(std::ostream& os, const Board& board);
};

#endif //BOARD_H
