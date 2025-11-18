========================================
     Memoarrr! Memory Card Game
========================================

Student Name: [Your Name Here]
Student Number: [Your Student Number]
Course Code: CSI2372A
Semester: Fall 2025

========================================
PROJECT DESCRIPTION
========================================

This project implements the Memoarrr! memory card game as a console application in C++.
The game features 25 unique cards (5 animals × 5 background colors) arranged in a 5×5 grid
with the center position empty.

GAME RULES:
- 2-4 players take turns revealing cards
- Each revealed card must match the previous card's animal OR background color
- If a card doesn't match, the player is eliminated from the current round
- The last player standing wins the round and receives 1-4 rubies randomly
- After 7 rounds, the player with the most rubies wins

========================================
IMPLEMENTED FEATURES
========================================

BASE GAME (19 marks):
✓ Player class - manages player information and ruby count
✓ Card class - represents memory cards with animals and backgrounds
✓ Rubis class - represents ruby rewards (1-4 rubies)
✓ DeckFactory template - abstract factory for decks
✓ CardDeck - singleton deck of 25 cards
✓ RubisDeck - singleton deck of ruby rewards
✓ Board class - manages 5×5 game board
✓ Game class - encapsulates game state
✓ Rules class - validates moves and determines game flow
✓ Main game loop with full gameplay implementation

EXPERT DISPLAY MODE (2 marks):
✓ Alternative display showing only face-up cards with positions

EXPERT RULES MODE (3 marks):
⚠ Partially implemented - basic framework in place
  (Full implementation would include special abilities for each animal)

========================================
FILE STRUCTURE
========================================

Header Files (.h):
- Memoarrr.h      - Common enumerations and helper functions
- Player.h        - Player class declaration
- Card.h          - Card class declaration
- Rubis.h         - Rubis class declaration
- DeckFactory.h   - Template factory class
- CardDeck.h      - Card deck singleton
- RubisDeck.h     - Rubis deck singleton
- Board.h         - Game board class
- Game.h          - Game state manager
- Rules.h         - Game rules validator

Implementation Files (.cpp):
- Memoarrr.cpp    - Helper function implementations
- Player.cpp      - Player class implementation
- Card.cpp        - Card class implementation
- Rubis.cpp       - Rubis class implementation
- CardDeck.cpp    - Card deck implementation
- RubisDeck.cpp   - Rubis deck implementation
- Board.cpp       - Board implementation
- Game.cpp        - Game implementation
- Rules.cpp       - Rules implementation
- main.cpp        - Main game loop and user interface

Build Files:
- Makefile        - Compilation instructions
- README.txt      - This file

========================================
COMPILATION INSTRUCTIONS
========================================

To compile the project:
    make

To run the game:
    ./memoarrr

To clean build files:
    make clean

To rebuild from scratch:
    make rebuild

========================================
USAGE INSTRUCTIONS
========================================

1. Run the executable: ./memoarrr
2. Choose game version (1-4)
3. Enter number of players (2-4)
4. Enter player names
5. Each player will peek at their 3 cards at the start of each round
6. Players take turns revealing cards by entering positions (e.g., "A1", "C3")
7. If a card doesn't match, the player is eliminated from that round
8. The last player standing wins rubies
9. After 7 rounds, final scores are displayed

========================================
DESIGN DECISIONS
========================================

1. SINGLETON PATTERN: CardDeck and RubisDeck use Meyer's singleton to ensure only
   one instance exists throughout the game.

2. FACTORY PATTERN: DeckFactory template provides a common interface for both
   card and rubis deck creation.

3. ENCAPSULATION: Card and Rubis have private constructors with friend classes,
   ensuring they can only be created through their respective decks.

4. CONST CORRECTNESS: Extensive use of const qualifiers to prevent unintended
   modifications and improve code safety.

5. EXCEPTION HANDLING: Custom exceptions (OutOfRange, NoMoreCards) for error
   handling with meaningful error messages.

6. OPERATOR OVERLOADING: << operators for easy printing of game objects,
   () operator for card row access, and conversion operators for type safety.

7. TEMPLATE PROGRAMMING: DeckFactory template allows code reuse between
   CardDeck and RubisDeck.

8. STL USAGE: Vector for dynamic collections, array for fixed-size board,
   random_shuffle for deck shuffling.

========================================
KNOWN LIMITATIONS
========================================

1. Expert Rules Mode is not fully implemented. Special animal abilities
   (Octopus swap, Penguin flip, Walrus block, Crab double-turn, Turtle skip)
   are defined but not fully integrated into gameplay.

2. No save/load game functionality.

3. Console-based interface only (no GUI).

4. Limited input validation for some edge cases.

========================================
FUTURE ENHANCEMENTS
========================================

1. Complete implementation of all expert rule abilities
2. Add AI players for single-player mode
3. Implement undo/redo functionality
4. Add game statistics tracking
5. Create graphical user interface
6. Network multiplayer support

========================================
ACADEMIC INTEGRITY
========================================

This code was developed following the University of Ottawa's academic integrity
policies. All code is original work created specifically for this assignment.

References consulted:
- C++ Standard Library documentation
- Course lecture notes and lab materials
- "Effective C++" by Scott Meyers
- cppreference.com for STL documentation

========================================
