#include "Rules.h"

/**
 * Constructor
 */
Rules::Rules(bool expert) : expertMode(expert) {
}

/**
 * Check if current card selection is valid
 * Valid if current card matches previous card's animal OR background
 * First card of round is always valid (no previous card)
 */
bool Rules::isValid(const Game& game) const {
    const Card* previous = game.getPreviousCard();
    const Card* current = game.getCurrentCard();
    
    //First card is always valid
    if (previous == nullptr || current == nullptr) {
        return true;
    }
    
    //Check if animal or background matches
    FaceAnimal prevAnimal = static_cast<FaceAnimal>(*previous);
    FaceBackground prevBg = static_cast<FaceBackground>(*previous);
    FaceAnimal currAnimal = static_cast<FaceAnimal>(*current);
    FaceBackground currBg = static_cast<FaceBackground>(*current);
    
    return (prevAnimal == currAnimal) || (prevBg == currBg);
}

/**
 * Check if the game is over (7 rounds completed)
 */
bool Rules::gameOver(const Game& game) const {
    return game.getRound() >= 7;
}

/**
 * Check if the current round is over
 * Round is over when only one active player remains
 */
bool Rules::roundOver(const Game& game) const {
    return countActivePlayers(game) <= 1;
}

/**
 * Get the next player in turn order
 * Returns next active player in clockwise order
 */
const Player& Rules::getNextPlayer(const Game& game) const {
    const std::vector<Player*>& players = game.getPlayers();
    
    if (players.empty()) {
        throw std::runtime_error("No players in game");
    }
    
    //Find current active player and get next one
    //In a turn-based system, we cycle through players
    for (size_t i = 0; i < players.size(); i++) {
        if (players[i]->isActive()) {
            //Look for next active player
            for (size_t j = 1; j <= players.size(); j++) {
                size_t nextIdx = (i + j) % players.size();
                if (players[nextIdx]->isActive()) {
                    return *players[nextIdx];
                }
            }
            //If no other active player, return current
            return *players[i];
        }
    }
    
    //If no active player found, return first player
    return *players[0];
}

/**
 * Count number of active players
 */
int Rules::countActivePlayers(const Game& game) const {
    int count = 0;
    const std::vector<Player*>& players = game.getPlayers();
    
    for (const auto& player : players) {
        if (player->isActive()) {
            count++;
        }
    }
    
    return count;
}

/**
 * Get the last remaining active player
 */
Player* Rules::getWinningPlayer(const Game& game) const {
    const std::vector<Player*>& players = game.getPlayers();
    
    for (auto player : players) {
        if (player->isActive()) {
            return player;
        }
    }
    
    return nullptr;
}
