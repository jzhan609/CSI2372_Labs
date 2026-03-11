#include "Player.h"

/**
 * Constructor for Player
 * Initializes a player with name and side, starting inactive with no rubies
 */
Player::Player(const std::string& playerName, Side playerSide)
    : name(playerName), side(playerSide), active(false), rubiesCount(0), endOfGameMode(false) {
}

/**
 * Get the player's name
 */
std::string Player::getName() const {
    return name;
}

/**
 * Set the active status of the player
 */
void Player::setActive(bool status) {
    active = status;
}

/**
 * Check if player is currently active
 */
bool Player::isActive() const {
    return active;
}

/**
 * Get the number of rubies the player has collected
 */
int Player::getNRubies() const {
    return rubiesCount;
}

/**
 * Add rubies to the player's collection
 */
void Player::addRubis(const Rubis& rubis) {
    rubiesCount += static_cast<int>(rubis);
}

/**
 * Set the display mode for the player
 */
void Player::setDisplayMode(bool endOfGame) {
    endOfGameMode = endOfGame;
}

/**
 * Get the player's side on the board
 */
Side Player::getSide() const {
    return side;
}

/**
 * Set the player's side on the board
 */
void Player::setSide(Side newSide) {
    side = newSide;
}

/**
 * Output stream operator for printing Player information
 * Format depends on endOfGameMode:
 * - During game: "Name: side (active/inactive)"
 * - End of game: "Name: X rubies"
 */
std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << player.name << ": ";
    
    if (player.endOfGameMode) {
        os << player.rubiesCount << " rubies";
    } else {
        //Print side
        switch (player.side) {
            case Side::Top: os << "top"; break;
            case Side::Bottom: os << "bottom"; break;
            case Side::Left: os << "left"; break;
            case Side::Right: os << "right"; break;
        }
        os << " (" << (player.active ? "active" : "inactive") << ")";
    }
    
    return os;
}
