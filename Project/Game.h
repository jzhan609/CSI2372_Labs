#ifndef GAME_H
#define GAME_H

#include "Memoarrr.h"
#include "Board.h"
#include "Player.h"
#include "Card.h"
#include <vector>
#include <iostream>

/**
 * Game class encapsulates the current state of the Memoarrr! game
 * Manages players, board, rounds, and card tracking
 */
class Game {
private:
    Board* board;                  //The game board
    std::vector<Player*> players;  //List of players
    int currentRound;              //Current round number (0-6)
    const Card* previousCard;      //Previously revealed card
    const Card* currentCard;       //Currently revealed card
    bool expertDisplayMode;        //Display mode flag
    bool expertRulesMode;          //Rules mode flag
    
public:
    /**
     * Constructor - creates a new game
     * @param expertDisplay If true, use expert display mode
     * @param expertRules If true, use expert rules mode
     */
    Game(bool expertDisplay = false, bool expertRules = false);
    
    /**
     * Destructor - cleans up dynamically allocated resources
     */
    ~Game();
    
    /**
     * Get the current round number (0-6)
     * @return The round number
     */
    int getRound() const;
    
    /**
     * Add a player to the game
     * @param player The player to add
     */
    void addPlayer(const Player& player);
    
    /**
     * Get a player by their side position
     * @param side The side to look for
     * @return Reference to the player
     */
    Player& getPlayer(Side side);
    
    /**
     * Get pointer to the previous card
     * @return Pointer to previous card or nullptr
     */
    const Card* getPreviousCard() const;
    
    /**
     * Get pointer to the current card
     * @return Pointer to current card or nullptr
     */
    const Card* getCurrentCard() const;
    
    /**
     * Set the current card
     * @param card Pointer to the card
     */
    void setCurrentCard(const Card* card);
    
    /**
     * Get card at board position
     * @param letter Row position
     * @param number Column position
     * @return Pointer to the card
     */
    Card* getCard(const Letter& letter, const Number& number);
    
    /**
     * Set card at board position
     * @param letter Row position
     * @param number Column position
     * @param card Pointer to the card
     */
    void setCard(const Letter& letter, const Number& number, Card* card);
    
    /**
     * Get the board
     * @return Pointer to the board
     */
    Board* getBoard() { return board; }
    
    /**
     * Get all players
     * @return Vector of player pointers
     */
    const std::vector<Player*>& getPlayers() const { return players; }
    
    /**
     * Increment to next round
     */
    void nextRound();
    
    /**
     * Check if expert rules mode is enabled
     * @return True if expert rules enabled
     */
    bool isExpertRules() const { return expertRulesMode; }
    
    /**
     * Update previous card with current card and reset current
     */
    void updateCards();
    
    /**
     * Output stream operator for printing game state
     * @param os The output stream
     * @param game The game to print
     * @return The output stream
     */
    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};

#endif //GAME_H
