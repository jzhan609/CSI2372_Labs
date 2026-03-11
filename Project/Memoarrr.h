#ifndef MEMOARRR_H
#define MEMOARRR_H

#include <string>
#include <iostream>

/**
 * Enumerations for game elements
 */
enum class FaceAnimal { Crab, Penguin, Octopus, Turtle, Walrus };
enum class FaceBackground { Red, Green, Purple, Blue, Yellow };
enum class Side { Top, Bottom, Left, Right };
enum class Letter { A, B, C, D, E };
enum class Number { One, Two, Three, Four, Five };

/**
 * Custom exception classes
 */
class OutOfRange : public std::exception {
private:
    std::string message;
public:
    OutOfRange(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

class NoMoreCards : public std::exception {
private:
    std::string message;
public:
    NoMoreCards(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

/**
 * Helper functions for enum conversions
 */
char animalToChar(FaceAnimal animal);
char backgroundToChar(FaceBackground bg);
std::string letterToString(Letter l);
std::string numberToString(Number n);
int numberToInt(Number n);
int letterToInt(Letter l);

#endif //MEMOARRR_H
