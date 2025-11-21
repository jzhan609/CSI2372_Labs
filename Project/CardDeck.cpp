#include "CardDeck.h"

/**
 * Private constructor - creates all 25 cards
 * One card for each combination of 5 animals and 5 backgrounds
 */
CardDeck::CardDeck() : DeckFactory<Card>() {
    //Create all combinations of animals and backgrounds
    FaceAnimal animals[] = {
        FaceAnimal::Crab,
        FaceAnimal::Penguin,
        FaceAnimal::Octopus,
        FaceAnimal::Turtle,
        FaceAnimal::Walrus
    };
    
    FaceBackground backgrounds[] = {
        FaceBackground::Red,
        FaceBackground::Green,
        FaceBackground::Purple,
        FaceBackground::Blue,
        FaceBackground::Yellow
    };
    
    //Create 25 cards (5 animals × 5 backgrounds)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            deck.push_back(new Card(animals[i], backgrounds[j]));
        }
    }
}

/**
 * Get the singleton instance of CardDeck
 * Implements singleton pattern using Meyer's singleton
 */
CardDeck& CardDeck::make_CardDeck() {
    static CardDeck instance;
    return instance;
}
