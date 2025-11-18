#ifndef DECKFACTORY_H
#define DECKFACTORY_H

#include <vector>
#include <algorithm>
#include <random>

/**
 * DeckFactory template class - Abstract factory for creating decks
 * Template parameter C can be Card or Rubis
 */
template<typename C>
class DeckFactory {
protected:
    std::vector<C*> deck;      // The deck of cards or rubis
    size_t currentIndex;        // Current position in the deck
    
    /**
     * Protected constructor
     */
    DeckFactory() : currentIndex(0) {}
    
    /**
     * Virtual destructor to clean up dynamically allocated objects
     */
    virtual ~DeckFactory() {
        for (auto item : deck) {
            delete item;
        }
        deck.clear();
    }

public:
    /**
     * Shuffle the deck using std::random_shuffle
     */
    void shuffle() {
        static std::random_device rd;
        static std::mt19937 g(rd());
        std::shuffle(deck.begin(), deck.end(), g);
        currentIndex = 0;
    }
    
    /**
     * Get the next card or rubis from the deck
     * @return Pointer to the next item, or nullptr if deck is empty
     */
    C* getNext() {
        if (isEmpty()) {
            return nullptr;
        }
        return deck[currentIndex++];
    }
    
    /**
     * Check if the deck is empty
     * @return True if no more items available, false otherwise
     */
    bool isEmpty() const {
        return currentIndex >= deck.size();
    }
    
    /**
     * Reset the deck to start from beginning
     */
    void reset() {
        currentIndex = 0;
    }
};

#endif // DECKFACTORY_H
