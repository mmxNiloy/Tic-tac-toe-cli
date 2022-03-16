#pragma once

#include "Board.h"
#include "Menu.h"
#include "GameBot.h"
#include "States.h"
#include <chrono>
#include <iostream>

namespace tictactoe {
    // Game manager class
    class GameManager {
        public:
            // Methods
            void start();               // Entry point for the game loop

            void gameStart();           // Start the game
            // Constructor(s)
            GameManager();
            // TODO: Implement save states and load state
            // GameManager(const ifstream& state)

            // Destructor(s)
            ~GameManager();
        private:
            Board* gameBoard;        // Game Board Manager
            Menu* gameMenu;          // Game Menu Manager
            GameState gameState;     // Game State Manager
            GameBot* bot;            // Game Bot, controls CPU moves
            int64_t time;                // Stores curret time in ms

            void printPlayAgainMessage();
    };
}


