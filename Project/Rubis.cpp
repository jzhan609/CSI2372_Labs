#include "Rubis.h"

/**
 * Private constructor - Rubis can only be created by RubisDeck
 */
Rubis::Rubis(int val) : value(val) {
    if (val < 1 || val > 4) {
        value = 1; // Default to 1 if invalid
    }
}

/**
 * Conversion operator to int
 * Returns the number of rubies
 */
Rubis::operator int() const {
    return value;
}

/**
 * Output stream operator for printing Rubis information
 * Format: "X rubies" or "1 ruby" for singular
 */
std::ostream& operator<<(std::ostream& os, const Rubis& rubis) {
    os << rubis.value << " " << (rubis.value == 1 ? "ruby" : "rubies");
    return os;
}
