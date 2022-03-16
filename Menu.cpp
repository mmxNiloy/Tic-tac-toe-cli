#include "Menu.h"

using namespace tictactoe;

// Draw welcome message
void const Menu::drawWelcomeMessage() {
    std::cout << std::string(21, '-') << '\n';
    std::cout << "|----- Welcome -----|\n"
        << "|------- TO --------|\n"
        << "|- Tic Tac Toe CLI -|\n";
    std::cout << std::string(21, '-') << '\n';
}

void const Menu::drawInstructions() {
    std::cout << std::string(21, '-') << '\n';
    std::cout << "|    How To Play    |\n";
    std::cout << std::string(21, '-') << '\n';
    std::cout << "1. Input the row number followed by the column number.\nThe row and columns are 1-indexed, in other words the first row is row number 1, the first column is column number 1 and vice versa.\n"
        << "\tEg: 2 1; stands for row = 2, column = 1\n"
        << "2. The first player is assigned to the symbol 'X' where the other player is assigned to the symbol 'O'\n"
        << "3. The first player to connect three symbols (\'X\' or \'O\') vertically, horizontally or diagonally wins.\n";
}

// Draw menu ui
const void Menu::drawUI() {
    std::cout << '\n';
    std::cout << std::string(21, '-') << '\n';
    std::cout << "|------- Menu ------|\n";
    std::cout << '|' << std::string(19, '-') << "|\n";
    std::cout << "|      1. Play      |\n"
        << "|   2. How to Play  |\n"
        << "|      3. Exit      |\n";
    std::cout << std::string(21, '-') << '\n';
    std::cout << "Select: ";
}

// Menu input
void Menu::input() {
    std::cin >> menuInput;
}

// Process the user input
const GameState Menu::processInput() {
    switch (menuInput)
    {
    case 1:
        return GameState::play;
        break;
    case 2:
        drawInstructions();
        return GameState::menu;
        break;
    default:
        return GameState::exit;
        break;
    }
}

// Constructor
Menu::Menu() {
    menuInput = 1;
}

// Destructor
Menu::~Menu() = default;