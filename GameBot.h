#pragma once
#include <vector>
#include <random>
#include "Board.h"

namespace tictactoe {
	class GameBot
	{
		public:
			void setBoardRef(Board*);							// Set the reference to the game board.
			GridCell findBestMove();							// Finds best available move for the bot following the minimax algorithm.
			void playBot();
			// Constructors
			GameBot();

			// Destructors
			~GameBot();

		private:
			Board* gameBoardRef;							// Reference to current game board
			int minimax(const int&, const bool&);		// Implements minimax algorithm
			int maximize(const int&);		// Maximizes score for bot
			int minimize(const int&);		// Minimizes score for the player
	};
}

