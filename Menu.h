#pragma once

#include <iostream>
#include "States.h"

namespace tictactoe {
    // Menu class. Renders menu and processes menu input
    class Menu {
        public:
            // Methods
            void input();                       // Takes an integer input.
            GameState const processInput();     // Processes the input
            void const drawUI();                // Draws the UI
            void const drawWelcomeMessage();    // Draws the welcome message
            void const drawInstructions();  // Draws the how to play instructions

            // Constructors and destructors
            Menu();
            ~Menu();
        private:
            int menuInput;          // Option input from the user.

    };
}

