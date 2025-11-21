========================================
     Memoarrr! Memory Card Game
========================================

Student Name: Rahul Atre, Jacob Zhang
Student Number: 300250370, 300231094
Course Code: CSI2372A
Semester: Fall 2025

========================================
DESCRIPTION 
========================================

This project implements the Memoarrr memory card game as a console application in C++.
The game features 25 unique cards (5 animals × 5 background colors) arranged in a 5×5 grid
w/ the center position empty.

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
- Player.cpp      - Player class 
- Card.cpp        - Card class 
- Rubis.cpp       - Rubis class 
- CardDeck.cpp    - Card deck 
- RubisDeck.cpp   - Rubis deck 
- Board.cpp       - Board 
- Game.cpp        - Game Implementation
- Rules.cpp       - Rules of game Implementation
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
COMPILATION INSTRUCTIONS (IF ABOVE FAILS)
========================================

USING TERMINAL, type these two in order: 

1. g++ -std=c++17 -o memoarrr.exe main.cpp Memoarrr.cpp Player.cpp Card.cpp Rubis.cpp CardDeck.cpp RubisDeck.cpp Board.cpp Game.cpp Rules.cpp
2. ./memoarrr.exe

