#include "GameBot.h"

using namespace tictactoe;

void GameBot::setBoardRef(Board* gameBoardReference) {
	gameBoardRef = gameBoardReference;
}

void GameBot::playBot() {
	std::cout << "CPU's turn.\n";
	GridCell cell = findBestMove();
	std::cout << "CPU picks row = " << cell.row + 1 << " column = " << cell.col + 1 << '\n';
	if(gameBoardRef -> isEmptyCell(cell.row, cell.col))
		gameBoardRef->setCellToCPU(cell.row, cell.col);
}

GridCell GameBot::findBestMove() {
	int bestScore = 0x8000'0000;
	int score = 0;
	int row = 0;
	int col = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (gameBoardRef->isEmptyCell(i, j)) {
				gameBoardRef->setCellToCPU(i, j);
				score = minimax(0, false);
				gameBoardRef->setCellToEmpty(i, j);

				if (score > bestScore) {
					bestScore = score;
					row = i;
					col = j;
				}
			}
		}
	}

	return GridCell(row, col);
}

int GameBot::minimax(const int& depth, const bool& isMaximizing) {
	char w = gameBoardRef->checkWinner();
	
	// To give players a chance at winning the algorithm will have a 10% chance of making a false positive decision
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, 100);

	if (w == 't') return 0;
	else if (w == gameBoardRef->getPlayerSymbol()) return -1 + (dist(gen) < 11 ? 2 : 0);
	else if (w == gameBoardRef->getBotSymbol()) return 1;

	switch (isMaximizing) {
	case true:
		return maximize(depth);
	default:
		return minimize(depth);
	}
}

int GameBot::maximize(const int& depth) {
	int bestScore = 0x8000'0000;
	int recur = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (gameBoardRef->isEmptyCell(i, j)) {
				gameBoardRef->setCellToCPU(i, j);
				recur = minimax(depth + 1, false);
				if (recur > bestScore) bestScore = recur;
				gameBoardRef->setCellToEmpty(i, j);
			}
		}
	}

	return bestScore;
}

int GameBot::minimize(const int& depth) {
	int worstScore = 0x7fff'ffff;
	int recur = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (gameBoardRef->isEmptyCell(i, j)) {
				gameBoardRef->setCellToPlayer(i, j);
				recur = minimax(depth + 1, true);
				if (recur < worstScore) worstScore = recur;
				gameBoardRef->setCellToEmpty(i, j);
			}
		}
	}

	return worstScore;
}

// Constructor
GameBot::GameBot() {
	gameBoardRef = NULL;
}

// Destructor
GameBot::~GameBot() = default;
