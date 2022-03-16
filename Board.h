#pragma once

#include <vector>
#include <iostream>
#include "States.h"

namespace tictactoe {
    // Board class. Draws, validates, manages moves on the board
    class Board {
        public:
            // Methods
            void drawBoard();       // Draw the board
            void playHuman();       // PLayer's turn
            bool isEmptyCell(const int&, const int&);
            void setCellToCPU(const int&, const int&);
            void setCellToPlayer(const int&, const int&);
            void setCellToEmpty(const int&, const int&);
            char checkWinner();         // Check if there is a winner
            void printWinner();
            void reset();
            
            // Getter for symbols
            char getPlayerSymbol();
            char getBotSymbol();

            // Sets player symbol appropriately
            void setPlayerSymbol(const char&);
            void setCPUSymbol(const char&);
            
            // Constructors and destructors
            Board();
            ~Board();
        private:
            char playerSymbol;
            char botSymbol;
            std::vector<std::vector<char>> cells;           // Game Grid
            int inpRow;                                     // Input row number
            int inpCol;                                     // Input column number
            void input();                                   // Take row and column as input
            bool isValidCell();                             // Checks the validity of the selected cell
            void printSelectionError();                     // Prints an error message on invalid cell selection
    };
}


