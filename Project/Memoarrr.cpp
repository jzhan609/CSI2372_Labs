#include "Memoarrr.h"

/**
 * Convert FaceAnimal enum to character representation
 * @param animal The animal enum value
 * @return Character representing the animal (C, P, O, T, W)
 */
char animalToChar(FaceAnimal animal) {
    switch (animal) {
        case FaceAnimal::Crab: return 'C';
        case FaceAnimal::Penguin: return 'P';
        case FaceAnimal::Octopus: return 'O';
        case FaceAnimal::Turtle: return 'T';
        case FaceAnimal::Walrus: return 'W';
        default: return '?';
    }
}

/**
 * Convert FaceBackground enum to character representation
 * @param bg The background enum value
 * @return Character representing the background color (r, g, p, b, y)
 */
char backgroundToChar(FaceBackground bg) {
    switch (bg) {
        case FaceBackground::Red: return 'r';
        case FaceBackground::Green: return 'g';
        case FaceBackground::Purple: return 'p';
        case FaceBackground::Blue: return 'b';
        case FaceBackground::Yellow: return 'y';
        default: return '?';
    }
}

/**
 * Convert Letter enum to string representation
 * @param l The letter enum value
 * @return String representation (A-E)
 */
std::string letterToString(Letter l) {
    switch (l) {
        case Letter::A: return "A";
        case Letter::B: return "B";
        case Letter::C: return "C";
        case Letter::D: return "D";
        case Letter::E: return "E";
        default: return "?";
    }
}

/**
 * Convert Number enum to string representation
 * @param n The number enum value
 * @return String representation (1-5)
 */
std::string numberToString(Number n) {
    switch (n) {
        case Number::One: return "1";
        case Number::Two: return "2";
        case Number::Three: return "3";
        case Number::Four: return "4";
        case Number::Five: return "5";
        default: return "?";
    }
}

/**
 * Convert Number enum to integer
 * @param n The number enum value
 * @return Integer value (1-5)
 */
int numberToInt(Number n) {
    switch (n) {
        case Number::One: return 1;
        case Number::Two: return 2;
        case Number::Three: return 3;
        case Number::Four: return 4;
        case Number::Five: return 5;
        default: return 0;
    }
}

/**
 * Convert Letter enum to integer
 * @param l The letter enum value
 * @return Integer value (0-4)
 */
int letterToInt(Letter l) {
    switch (l) {
        case Letter::A: return 0;
        case Letter::B: return 1;
        case Letter::C: return 2;
        case Letter::D: return 3;
        case Letter::E: return 4;
        default: return -1;
    }
}
