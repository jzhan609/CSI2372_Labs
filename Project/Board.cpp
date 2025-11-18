#include "Board.h"
#include "CardDeck.h"

/**
 * Constructor - initializes board with cards from CardDeck
 * Creates a 5x5 board with center position (C3) empty
 */
Board::Board(bool expertDisplay) : expertDisplayMode(expertDisplay) {
    // Initialize all positions
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cards[i][j] = nullptr;
            faceUp[i][j] = false;
        }
    }
    
    // Get CardDeck instance
    CardDeck& deck = CardDeck::make_CardDeck();
    deck.shuffle();
    
    // Fill board with cards (except center position)
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            // Skip center position (row 2, col 2)
            if (i == 2 && j == 2) {
                continue;
            }
            
            Card* card = deck.getNext();
            if (card == nullptr) {
                throw NoMoreCards("Not enough cards to create board");
            }
            cards[i][j] = card;
        }
    }
}

/**
 * Helper to validate board position
 */
bool Board::isValidPosition(const Letter& letter, const Number& number) const {
    int row = letterToIndex(letter);
    int col = numberToIndex(number);
    
    // Check bounds
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        return false;
    }
    
    // Center position is never valid
    if (row == 2 && col == 2) {
        return false;
    }
    
    return true;
}

/**
 * Convert Letter enum to array index
 */
int Board::letterToIndex(const Letter& letter) const {
    return static_cast<int>(letter);
}

/**
 * Convert Number enum to array index
 */
int Board::numberToIndex(const Number& number) const {
    return static_cast<int>(number);
}

/**
 * Check if a card at given position is face up
 */
bool Board::isFaceUp(const Letter& letter, const Number& number) const {
    if (!isValidPosition(letter, number)) {
        throw OutOfRange("Invalid board position");
    }
    
    int row = letterToIndex(letter);
    int col = numberToIndex(number);
    return faceUp[row][col];
}

/**
 * Turn a card face up
 */
bool Board::turnFaceUp(const Letter& letter, const Number& number) {
    if (!isValidPosition(letter, number)) {
        throw OutOfRange("Invalid board position");
    }
    
    int row = letterToIndex(letter);
    int col = numberToIndex(number);
    
    if (faceUp[row][col]) {
        return false;  // Already face up
    }
    
    faceUp[row][col] = true;
    return true;
}

/**
 * Turn a card face down
 */
bool Board::turnFaceDown(const Letter& letter, const Number& number) {
    if (!isValidPosition(letter, number)) {
        throw OutOfRange("Invalid board position");
    }
    
    int row = letterToIndex(letter);
    int col = numberToIndex(number);
    
    if (!faceUp[row][col]) {
        return false;  // Already face down
    }
    
    faceUp[row][col] = false;
    return true;
}

/**
 * Get pointer to card at given position
 */
Card* Board::getCard(const Letter& letter, const Number& number) {
    if (!isValidPosition(letter, number)) {
        throw OutOfRange("Invalid board position");
    }
    
    int row = letterToIndex(letter);
    int col = numberToIndex(number);
    return cards[row][col];
}

/**
 * Set card at given position
 */
void Board::setCard(const Letter& letter, const Number& number, Card* card) {
    if (!isValidPosition(letter, number)) {
        throw OutOfRange("Invalid board position");
    }
    
    int row = letterToIndex(letter);
    int col = numberToIndex(number);
    cards[row][col] = card;
}

/**
 * Turn all cards face down
 */
void Board::allFacesDown() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            faceUp[i][j] = false;
        }
    }
}

/**
 * Set display mode
 */
void Board::setDisplayMode(bool expertMode) {
    expertDisplayMode = expertMode;
}

/**
 * Output stream operator for printing the board
 * Format depends on display mode:
 * - Normal: Full 19x19 grid with all cards
 * - Expert: Only face-up cards in a row with positions
 */
std::ostream& operator<<(std::ostream& os, const Board& board) {
    if (board.expertDisplayMode) {
        // Expert display mode: only show face-up cards
        bool first = true;
        for (int i = 0; i < Board::BOARD_SIZE; i++) {
            for (int j = 0; j < Board::BOARD_SIZE; j++) {
                if ((i == 2 && j == 2) || !board.faceUp[i][j]) {
                    continue;
                }
                
                if (!first) {
                    os << " ";
                }
                first = false;
                
                Card* card = board.cards[i][j];
                if (card) {
                    // Print card
                    for (int row = 0; row < 3; row++) {
                        os << (*card)(row);
                        if (row < 2) os << " ";
                    }
                }
            }
        }
        os << "\n";
        
        // Print positions
        first = true;
        for (int i = 0; i < Board::BOARD_SIZE; i++) {
            for (int j = 0; j < Board::BOARD_SIZE; j++) {
                if ((i == 2 && j == 2) || !board.faceUp[i][j]) {
                    continue;
                }
                
                if (!first) {
                    os << " ";
                }
                first = false;
                
                // Print position (e.g., "A1")
                os << char('A' + i) << (j + 1);
            }
        }
        os << "\n";
    } else {
        // Normal display mode: full grid
        for (int i = 0; i < Board::BOARD_SIZE; i++) {
            // Print 3 rows for each board row
            for (int cardRow = 0; cardRow < 3; cardRow++) {
                // Print row letter on first line
                if (cardRow == 1) {
                    os << char('A' + i) << " ";
                } else {
                    os << "  ";
                }
                
                for (int j = 0; j < Board::BOARD_SIZE; j++) {
                    // Center position is empty
                    if (i == 2 && j == 2) {
                        os << "   ";
                    } else if (board.faceUp[i][j] && board.cards[i][j]) {
                        // Show card
                        os << (*board.cards[i][j])(cardRow);
                    } else {
                        // Show back of card
                        os << "zzz";
                    }
                    
                    // Space between cards
                    if (j < Board::BOARD_SIZE - 1) {
                        os << " ";
                    }
                }
                os << "\n";
            }
            
            // Blank line between rows
            if (i < Board::BOARD_SIZE - 1) {
                os << "\n";
            }
        }
        
        // Print column numbers
        os << "  ";
        for (int j = 0; j < Board::BOARD_SIZE; j++) {
            os << (j + 1);
            if (j < Board::BOARD_SIZE - 1) {
                os << "   ";
            }
        }
        os << "\n";
    }
    
    return os;
}
