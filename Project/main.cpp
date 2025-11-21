#include "Game.h"
#include "Rules.h"
#include "Player.h"
#include "RubisDeck.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

/**
 * Helper function to convert string to uppercase
 */
std::string toUpper(std::string str) {
    for (char& c : str) {
        c = std::toupper(c);
    }
    return str;
}

/**
 * Helper function to parse position input (e.g., "A1" to Letter::A and Number::One)
 */
bool parsePosition(const std::string& input, Letter& letter, Number& number) {
    if (input.length() != 2) {
        return false;
    }
    
    char letterChar = std::toupper(input[0]);
    char numberChar = input[1];
    
    //Parse letter
    if (letterChar >= 'A' && letterChar <= 'E') {
        letter = static_cast<Letter>(letterChar - 'A');
    } else {
        return false;
    }
    
    //Parse number
    if (numberChar >= '1' && numberChar <= '5') {
        number = static_cast<Number>(numberChar - '1');
    } else {
        return false;
    }
    
    return true;
}

/**
 * Get positions in front of a player based on their side
 */
std::vector<std::pair<Letter, Number>> getPlayerViewPositions(Side side) {
    std::vector<std::pair<Letter, Number>> positions;
    
    switch (side) {
        case Side::Top:
            positions.push_back({Letter::A, Number::One});
            positions.push_back({Letter::A, Number::Two});
            positions.push_back({Letter::A, Number::Three});
            break;
        case Side::Bottom:
            positions.push_back({Letter::E, Number::Three});
            positions.push_back({Letter::E, Number::Four});
            positions.push_back({Letter::E, Number::Five});
            break;
        case Side::Left:
            positions.push_back({Letter::B, Number::One});
            positions.push_back({Letter::C, Number::One});
            positions.push_back({Letter::D, Number::One});
            break;
        case Side::Right:
            positions.push_back({Letter::B, Number::Five});
            positions.push_back({Letter::C, Number::Five});
            positions.push_back({Letter::D, Number::Five});
            break;
    }
    
    return positions;
}

/**
 * Main function - entry point of the program
 */
int main() {
    std::cout << "=== Welcome to Memoarrr! ===" << std::endl;
    std::cout << std::endl;
    
    //Choose game version
    std::cout << "Choose game version:" << std::endl;
    std::cout << "1. Base game" << std::endl;
    std::cout << "2. Expert display mode" << std::endl;
    std::cout << "3. Expert rules mode" << std::endl;
    std::cout << "4. Expert display + Expert rules" << std::endl;
    
    int version;
    std::cout << "Enter choice (1-4): ";
    std::cin >> version;
    
    bool expertDisplay = (version == 2 || version == 4);
    bool expertRules = (version == 3 || version == 4);
    
    //Number of players
    int numPlayers;
    do {
        std::cout << "Enter number of players (2-4): ";
        std::cin >> numPlayers;
    } while (numPlayers < 2 || numPlayers > 4);
    
    std::cin.ignore(); //Clear newline
    
    //Create game
    Game game(expertDisplay, expertRules);
    Rules rules(expertRules);
    
    //Create players
    Side sides[] = {Side::Top, Side::Right, Side::Bottom, Side::Left};
    for (int i = 0; i < numPlayers; i++) {
        std::string name;
        std::cout << "Enter name for Player " << (i + 1) << ": ";
        std::getline(std::cin, name);
        
        Player player(name, sides[i]);
        game.addPlayer(player);
    }
    
    std::cout << "\n=== Game Start ===" << std::endl;
    
    //Main game loop
    while (!rules.gameOver(game)) {
        std::cout << "\n=== Round " << (game.getRound() + 1) << " ===" << std::endl;
        
        //Reset cards face down
        game.getBoard()->allFacesDown();
        
        //Reset all players to active
        for (auto player : game.getPlayers()) {
            player->setActive(true);
        }
        
        //Let each player peek at their 3 cards
        for (auto player : game.getPlayers()) {
            std::cout << "\n" << player->getName() << ", press Enter to view your cards...";
            std::cin.get();
            
            auto positions = getPlayerViewPositions(player->getSide());
            std::cout << "Your cards:" << std::endl;
            for (const auto& pos : positions) {
                Card* card = game.getCard(pos.first, pos.second);
                if (card) {
                    std::cout << letterToString(pos.first) << numberToString(pos.second) << ": ";
                    for (int row = 0; row < 3; row++) {
                        std::cout << (*card)(row);
                        if (row < 2) std::cout << " ";
                    }
                    std::cout << std::endl;
                }
            }
            
            std::cout << "Press Enter to continue...";
            std::cin.get();
            std::cout << "\n\n"; //Clear screen effect
        }
        
        //Round play loop
        int currentPlayerIdx = 0;
        while (!rules.roundOver(game)) {
            //Get next active player
            Player* currentPlayer = nullptr;
            int attempts = 0;
            while (attempts < numPlayers) {
                Player* candidate = game.getPlayers()[currentPlayerIdx];
                if (candidate->isActive()) {
                    currentPlayer = candidate;
                    break;
                }
                currentPlayerIdx = (currentPlayerIdx + 1) % numPlayers;
                attempts++;
            }
            
            if (!currentPlayer) break;
            
            //Display game state
            std::cout << "\n" << game << std::endl;
            std::cout << "\n" << currentPlayer->getName() << "'s turn" << std::endl;
            
            //Get card selection
            std::string input;
            Letter letter;
            Number number;
            bool validInput = false;
            
            while (!validInput) {
                std::cout << "Enter position to reveal (e.g., A1): ";
                std::cin >> input;
                
                if (parsePosition(input, letter, number)) {
                    try {
                        //Check if card already face up
                        if (game.getBoard()->isFaceUp(letter, number)) {
                            std::cout << "Card already revealed! Choose another." << std::endl;
                        } else {
                            validInput = true;
                        }
                    } catch (const OutOfRange& e) {
                        std::cout << "Invalid position! " << e.what() << std::endl;
                    }
                } else {
                    std::cout << "Invalid format! Use format like A1, B3, etc." << std::endl;
                }
            }
            
            //Reveal card
            game.getBoard()->turnFaceUp(letter, number);
            Card* revealedCard = game.getCard(letter, number);
            game.setCurrentCard(revealedCard);
            
            //Check if valid move
            if (!rules.isValid(game)) {
                std::cout << "\nCard doesn't match! " << currentPlayer->getName() 
                          << " is out of this round." << std::endl;
                currentPlayer->setActive(false);
            }
            
            //Update for next turn
            game.updateCards();
            currentPlayerIdx = (currentPlayerIdx + 1) % numPlayers;
            
            std::cout << "Press Enter to continue...";
            std::cin.ignore();
            std::cin.get();
        }
        
        //Round over - award rubies to winner
        Player* winner = rules.getWinningPlayer(game);
        if (winner) {
            RubisDeck& rubisDeck = RubisDeck::make_RubisDeck();
            if (rubisDeck.isEmpty()) {
                rubisDeck.reset();
                rubisDeck.shuffle();
            }
            
            Rubis* rubis = rubisDeck.getNext();
            if (rubis) {
                winner->addRubis(*rubis);
                std::cout << "\n" << winner->getName() << " wins the round and receives " 
                          << *rubis << "!" << std::endl;
            }
        }
        
        game.nextRound();
        
        std::cout << "\nPress Enter to continue to next round...";
        std::cin.get();
    }
    
    //Game over - display final scores
    std::cout << "\n\n=== Game Over ===" << std::endl;
    std::cout << "\nFinal Scores:" << std::endl;
    
    //Sort players by rubies (least to most)
    std::vector<Player*> sortedPlayers = game.getPlayers();
    std::sort(sortedPlayers.begin(), sortedPlayers.end(),
              [](Player* a, Player* b) { return a->getNRubies() < b->getNRubies(); });
    
    for (auto player : sortedPlayers) {
        player->setDisplayMode(true);
        std::cout << *player << std::endl;
    }
    
    //Determine winner
    Player* winner = sortedPlayers.back();
    std::cout << "\n*** " << winner->getName() << " wins with " 
              << winner->getNRubies() << " rubies! ***" << std::endl;
    
    return 0;
}
