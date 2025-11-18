# Makefile for Memoarrr! Game
# CSI2372A Project - Fall 2025

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Object files
OBJS = main.o Memoarrr.o Player.o Card.o Rubis.o CardDeck.o RubisDeck.o Board.o Game.o Rules.o

# Target executable
TARGET = memoarrr

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files to object files
main.o: main.cpp Game.h Rules.h Player.h RubisDeck.h Memoarrr.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Memoarrr.o: Memoarrr.cpp Memoarrr.h
	$(CXX) $(CXXFLAGS) -c Memoarrr.cpp

Player.o: Player.cpp Player.h Rubis.h Memoarrr.h
	$(CXX) $(CXXFLAGS) -c Player.cpp

Card.o: Card.cpp Card.h Memoarrr.h
	$(CXX) $(CXXFLAGS) -c Card.cpp

Rubis.o: Rubis.cpp Rubis.h
	$(CXX) $(CXXFLAGS) -c Rubis.cpp

CardDeck.o: CardDeck.cpp CardDeck.h DeckFactory.h Card.h
	$(CXX) $(CXXFLAGS) -c CardDeck.cpp

RubisDeck.o: RubisDeck.cpp RubisDeck.h DeckFactory.h Rubis.h
	$(CXX) $(CXXFLAGS) -c RubisDeck.cpp

Board.o: Board.cpp Board.h Card.h CardDeck.h Memoarrr.h
	$(CXX) $(CXXFLAGS) -c Board.cpp

Game.o: Game.cpp Game.h Board.h Player.h Card.h Memoarrr.h
	$(CXX) $(CXXFLAGS) -c Game.cpp

Rules.o: Rules.cpp Rules.h Game.h Player.h
	$(CXX) $(CXXFLAGS) -c Rules.cpp

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(TARGET)

# Rebuild everything
rebuild: clean all

.PHONY: all clean rebuild
