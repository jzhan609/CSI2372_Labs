#ifndef CARDDECK_H
#define CARDDECK_H

#include "DeckFactory.h"
#include "Card.h"

/**
 * CardDeck class - Singleton deck of memory cards
 * Derived from DeckFactory<Card>
 * Creates all 25 possible combinations of animals and backgrounds
 */
class CardDeck : public DeckFactory<Card> {
private:
    /**
     * Private constructor - creates all 25 cards
     * Singleton pattern ensures only one deck exists
     */
    CardDeck();
    
    // Prevent copying
    CardDeck(const CardDeck&) = delete;
    CardDeck& operator=(const CardDeck&) = delete;

public:
    /**
     * Get the singleton instance of CardDeck
     * @return Reference to the single CardDeck instance
     */
    static CardDeck& make_CardDeck();
    
    /**
     * Destructor
     */
    ~CardDeck() override = default;
};

#endif // CARDDECK_H
