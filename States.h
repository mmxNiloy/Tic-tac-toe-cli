#pragma once

namespace tictactoe {
    // Game states
    enum class GameState {
        play,
        menu,
        gameover,
        exit
    };

    // Player symbol
    const char gameSymbols[] = { 'X', 'O' };

    // Auxilary data structure for row column pair
    struct GridCell {
        int row;
        int col;

        GridCell() : row(0), col(0) {  }
        GridCell(const int& _row, const int& _col) : row(_row), col(_col) {  }
    };
}