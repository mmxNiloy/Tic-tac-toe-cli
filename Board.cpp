#include "Board.h"

using namespace tictactoe;

// Draw the board
void Board::drawBoard() {
    std::cout << "\n\n";
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            std::cout << '.' << cells[row][col] << '.';
            if (col < 2) std::cout << "|";
        }
        std::cout << '\n';
        for (int col = 0; col < 11 && row < 2; col++) std::cout << "_";
        std::cout << '\n';
    }
    std::cout << "\n\n";
}

// Check the validity of a player selected cell
bool Board::isValidCell() {
    if (inpRow > 3 || inpCol > 3 || inpRow < 0 || inpCol < 0) return false;
    inpRow--;
    inpCol--;

    if (cells[inpRow][inpCol] != '.') return false;

    return true;
}

// Check if there is a winner
char Board::checkWinner() {
    for (int i = 0; i < 3; i++) {
        // Check the rows
        if (
            cells[i][0] == cells[i][1] &&
            cells[i][1] == cells[i][2] &&
            cells[i][0] != '.'
            ) return cells[i][0];
        
        // Check the columns
        if (
            cells[0][i] == cells[1][i] &&
            cells[0][i] == cells[2][i] &&
            cells[0][i] != '.'
            ) return cells[0][i];
    }

    // Check main diagonal
    if (
        cells[0][0] == cells[1][1] &&
        cells[1][1] == cells[2][2] &&
        cells[0][0] != '.'
        ) return cells[0][0];

    // Check the other diagonal
    if (
        cells[0][2] == cells[1][1] &&
        cells[2][0] == cells[1][1] &&
        cells[1][1] != '.'
        ) return cells[1][1];

    // Check for an empty cell
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (cells[i][j] == '.') return '.';
        }
    }

    // Other wise the game has tied.
    return 't';
}

void tictactoe::Board::printWinner()
{
    char w = checkWinner();
    if (w == playerSymbol) {
        std::cout << "Well played! You have won.\n";
    }
    else if (w == botSymbol) {
        std::cout << "Tough luck! CPU wins.\n";
    }
    else std::cout << "The game has tied.\n";
}

void tictactoe::Board::reset()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cells[i][j] = '.';
        }
    }
}

char tictactoe::Board::getPlayerSymbol()
{
    return playerSymbol;
}

char tictactoe::Board::getBotSymbol()
{
    return botSymbol;
}

// Print invalid selection error message
void Board::printSelectionError() {
    std::cout << "Invalid cell selected. The cell is either occupied or out of bounds.\n";
}

void Board::playHuman() {
    input();
    if (!isValidCell()) {
        printSelectionError();
        playHuman();
    } else cells[inpRow][inpCol] = playerSymbol;
}

bool Board::isEmptyCell(const int& row, const int& col)
{
    if (row < 0 || col < 0 || row > 2 || col > 2) return false;
    return cells[row][col] == '.';
}

void tictactoe::Board::setCellToCPU(const int& row, const int& col)
{
    if (row < 0 || col < 0 || row > 2 || col > 2) return;
    cells[row][col] = botSymbol;
}

void tictactoe::Board::setCellToPlayer(const int& row, const int& col)
{
    if (row < 0 || col < 0 || row > 2 || col > 2) return;
    cells[row][col] = playerSymbol;
}

void tictactoe::Board::setCellToEmpty(const int& row, const int& col)
{
    if (row < 0 || col < 0 || row > 2 || col > 2) return;
    cells[row][col] = '.';
}

void Board::setPlayerSymbol(const char& c) {
    playerSymbol = c;
}

void Board::setCPUSymbol(const char& c) {
    botSymbol = c;
}

// Take player input
void Board::input() {
    std::cout << "Your turn. Enter row and column number: ";
    std::cin >> inpRow >> inpCol;
}

// Default constructor
Board::Board() {
    inpRow = -1;
    inpCol = -1;

    // Create the grid with all empty cells
    cells.reserve(3);
    for (int i = 0; i < 3; i++) {
        cells.emplace_back(std::vector<char>(3, '.'));
    }
}

// Destructor
Board::~Board() = default;