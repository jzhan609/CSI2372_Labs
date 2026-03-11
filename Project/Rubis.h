#ifndef RUBIS_H
#define RUBIS_H

#include <iostream>

//Forward declarations
template<typename C> class DeckFactory;
class RubisDeck;

/**
 * Rubis class represents a ruby reward card
 * Can have values from 1 to 4 rubies
 */
class Rubis {
private:
    int value;  // Number of rubies (1-4)
    
    /**
     * Private constructor - Rubis can only be created by RubisDeck
     * @param val The number of rubies (1-4)
     */
    Rubis(int val);
    
    //Allow RubisDeck to create rubis
    friend class RubisDeck;
    friend class DeckFactory<Rubis>;

public:
    /**
     * Conversion operator to int
     * @return The number of rubies
     */
    operator int() const;
    
    /**
     * Get the number of rubies
     * @return The value (1-4)
     */
    int getValue() const { return value; }
    
    /**
     * Output stream operator for printing Rubis information
     * @param os The output stream
     * @param rubis The rubis to print
     * @return The output stream
     */
    friend std::ostream& operator<<(std::ostream& os, const Rubis& rubis);
};

#endif //RUBIS_H
