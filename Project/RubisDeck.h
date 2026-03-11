#ifndef RUBISDECK_H
#define RUBISDECK_H

#include "DeckFactory.h"
#include "Rubis.h"

/**
 * RubisDeck class - Singleton deck of ruby reward cards
 * Derived from DeckFactory<Rubis>
 * Creates: 3 cards with 1 ruby, 2 cards with 2 rubies, 
 *          1 card with 3 rubies, 1 card with 4 rubies
 */
class RubisDeck : public DeckFactory<Rubis> {
private:
    /**
     * Private constructor - creates ruby cards according to distribution
     * Singleton pattern ensures only one deck exists
     */
    RubisDeck();
    
    //Prevent copying
    RubisDeck(const RubisDeck&) = delete;
    RubisDeck& operator=(const RubisDeck&) = delete;

public:
    /**
     * Get the singleton instance of RubisDeck
     * @return Reference to the single RubisDeck instance
     */
    static RubisDeck& make_RubisDeck();
    
    /**
     * Destructor
     */
    ~RubisDeck() override = default;
};

#endif //RUBISDECK_H
