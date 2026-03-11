#ifndef PLAYER_H
#define PLAYER_H

#include "Memoarrr.h"
#include "Rubis.h"
#include <string>

/**
 * Player class represents a player in the Memoarrr! game
 * Stores player name, side position, active status, and ruby count
 */
class Player {
private:
    std::string name;           //Player's name
    Side side;                  //Position on board (top, bottom, left, right)
    bool active;                //Whether player is active in current round
    int rubiesCount;            //Total rubies collected
    bool endOfGameMode;         //Display mode flag

public:
    /**
     * Constructor for Player
     * @param playerName The name of the player
     * @param playerSide The side of the board for this player
     */
    Player(const std::string& playerName, Side playerSide);
    
    /**
     * Get the player's name
     * @return The player's name as a string
     */
    std::string getName() const;
    
    /**
     * Set the active status of the player
     * @param status True if player is active, false otherwise
     */
    void setActive(bool status);
    
    /**
     * Check if player is currently active
     * @return True if player is active, false otherwise
     */
    bool isActive() const;
    
    /**
     * Get the number of rubies the player has collected
     * @return The number of rubies
     */
    int getNRubies() const;
    
    /**
     * Add rubies to the player's collection
     * @param rubis The Rubis object to add
     */
    void addRubis(const Rubis& rubis);
    
    /**
     * Set the display mode for the player
     * @param endOfGame True if game has ended, false otherwise
     */
    void setDisplayMode(bool endOfGame);
    
    /**
     * Get the player's side on the board
     * @return The Side enum value
     */
    Side getSide() const;
    
    /**
     * Set the player's side on the board
     * @param newSide The new Side enum value
     */
    void setSide(Side newSide);
    
    /**
     * Output stream operator for printing Player information
     * @param os The output stream
     * @param player The player to print
     * @return The output stream
     */
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
};

#endif //PLAYER_H
