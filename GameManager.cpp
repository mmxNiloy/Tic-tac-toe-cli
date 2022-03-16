#include "GameManager.h"

using namespace tictactoe;

// Default constructor
GameManager::GameManager() {
    // Initialization
    time = 0;
    bot = new GameBot();
    gameMenu = new Menu();
    gameBoard = new Board();
    gameState = GameState::menu;

    // TODO: Game logic and stuff...
}

// Destructor
GameManager::~GameManager() {
    // Free up memory
    delete gameMenu;
    delete gameBoard;
    delete bot;
}


void GameManager::start() {
    // Menu
    // Draw Welcome message
    gameMenu->drawWelcomeMessage();

    while (gameState == GameState::menu) {
        // Draw the menu
        gameMenu->drawUI();
        // Wait for user input
        gameMenu->input();
        // Process user input
        gameState = gameMenu->processInput();
    }

    while (gameState == GameState::play) gameStart();
}

void GameManager::gameStart() {
    // Get current time in milliseconds. If the number is even the player starts
    // Otherwise let the CPU start.
    auto now = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::milliseconds>(
        now.time_since_epoch()
        ).count();

    time = time & 1;    // Get the parity of the time
    // Set player and cpu symbol
    gameBoard->setPlayerSymbol(gameSymbols[time]);
    gameBoard->setCPUSymbol(gameSymbols[time ^ 1]);

    // Set up bot with current board
    bot->setBoardRef(gameBoard);

    char w;
    while (gameState == GameState::play) {
        w = gameBoard->checkWinner();

        gameBoard->drawBoard();
        if (w != '.') {
            gameState = GameState::gameover;
            continue;
        }

        if (time) bot->playBot();
        else gameBoard->playHuman();
        
        // Alternate between the player and the bot
        time ^= 1;
    }

    while (gameState == GameState::gameover) {
        // Announce the winner
        // Ask if the player wants to play again.
        gameBoard->printWinner();
        printPlayAgainMessage();
    }

    if (gameState == GameState::play) gameBoard->reset();
}

void tictactoe::GameManager::printPlayAgainMessage()
{
    char op;
    std::cout << "Play again? (y/N): ";
    std::cin >> op;
    if (op == 'y' || op == 'Y') gameState = GameState::play;
    else gameState = GameState::exit;
}