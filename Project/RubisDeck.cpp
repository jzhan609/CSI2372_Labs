#include "RubisDeck.h"

/**
 * Private constructor - creates ruby cards according to distribution
 * 3 cards with 1 ruby, 2 cards with 2 rubies, 1 card with 3 rubies, 1 card with 4 rubies
 */
RubisDeck::RubisDeck() : DeckFactory<Rubis>() {
    //3 cards with 1 ruby
    for (int i = 0; i < 3; i++) {
        deck.push_back(new Rubis(1));
    }
    
    //2 cards with 2 rubies
    for (int i = 0; i < 2; i++) {
        deck.push_back(new Rubis(2));
    }
    
    //1 card with 3 rubies
    deck.push_back(new Rubis(3));
    
    //1 card with 4 rubies
    deck.push_back(new Rubis(4));
}

/**
 * Get the singleton instance of RubisDeck
 * Implements singleton pattern using Meyer's singleton
 */
RubisDeck& RubisDeck::make_RubisDeck() {
    static RubisDeck instance;
    return instance;
}
