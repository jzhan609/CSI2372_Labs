#ifndef RULES_H
#define RULES_H

#include "Game.h"
#include "Player.h"

/**
 * Rules class checks game validity and manages game flow
 * Validates card matches and determines game/round end conditions
 */
class Rules {
private:
    bool expertMode;  // Whether expert rules are enabled
    
public:
    /**
     * Constructor
     * @param expert If true, use expert rules
     */
    Rules(bool expert = false);
    
    /**
     * Check if current card selection is valid
     * @param game The current game state
     * @return True if current card matches previous card's animal or background
     */
    bool isValid(const Game& game) const;
    
    /**
     * Check if the game is over (7 rounds completed)
     * @param game The current game state
     * @return True if 7 rounds have been played
     */
    bool gameOver(const Game& game) const;
    
    /**
     * Check if the current round is over
     * @param game The current game state
     * @return True if only one active player remains
     */
    bool roundOver(const Game& game) const;
    
    /**
     * Get the next player in turn order
     * @param game The current game state
     * @return Reference to the next active player
     */
    const Player& getNextPlayer(const Game& game) const;
    
    /**
     * Count number of active players
     * @param game The current game state
     * @return Number of active players
     */
    int countActivePlayers(const Game& game) const;
    
    /**
     * Get the last remaining active player
     * @param game The current game state
     * @return Pointer to the winning player of the round
     */
    Player* getWinningPlayer(const Game& game) const;
};

#endif //RULES_H
