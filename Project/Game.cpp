#include "Game.h"

/**
 * Constructor - creates a new game
 */
Game::Game(bool expertDisplay, bool expertRules)
    : board(nullptr), currentRound(0), previousCard(nullptr), currentCard(nullptr),
      expertDisplayMode(expertDisplay), expertRulesMode(expertRules) {
    board = new Board(expertDisplay);
}

/**
 * Destructor - cleans up dynamically allocated resources
 */
Game::~Game() {
    delete board;
    for (auto player : players) {
        delete player;
    }
}

/**
 * Get the current round number (0-6)
 */
int Game::getRound() const {
    return currentRound;
}

/**
 * Add a player to the game
 */
void Game::addPlayer(const Player& player) {
    players.push_back(new Player(player));
}

/**
 * Get a player by their side position
 */
Player& Game::getPlayer(Side side) {
    for (auto player : players) {
        if (player->getSide() == side) {
            return *player;
        }
    }
    // Should never reach here in valid game
    return *players[0];
}

/**
 * Get pointer to the previous card
 */
const Card* Game::getPreviousCard() const {
    return previousCard;
}

/**
 * Get pointer to the current card
 */
const Card* Game::getCurrentCard() const {
    return currentCard;
}

/**
 * Set the current card
 */
void Game::setCurrentCard(const Card* card) {
    currentCard = card;
}

/**
 * Get card at board position
 */
Card* Game::getCard(const Letter& letter, const Number& number) {
    return board->getCard(letter, number);
}

/**
 * Set card at board position
 */
void Game::setCard(const Letter& letter, const Number& number, Card* card) {
    board->setCard(letter, number, card);
}

/**
 * Increment to next round
 */
void Game::nextRound() {
    currentRound++;
}

/**
 * Update previous card with current card and reset current
 */
void Game::updateCards() {
    previousCard = currentCard;
    currentCard = nullptr;
}

/**
 * Output stream operator for printing game state
 * Displays board and all players
 */
std::ostream& operator<<(std::ostream& os, const Game& game) {
    // Print the board
    os << *game.board << "\n";
    
    // Print all players
    for (size_t i = 0; i < game.players.size(); i++) {
        os << *game.players[i];
        if (i < game.players.size() - 1) {
            os << "\n";
        }
    }
    
    return os;
}
