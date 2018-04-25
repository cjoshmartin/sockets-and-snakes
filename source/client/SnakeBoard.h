/*
 * Board class to store the board state and update based on the player
 *  positions and history.
 * 
 * Responsible for interfacing with Curses and actually drawing stuff
 */

#ifndef _BOARD_H
#define _BOARD_H

#include "Snake.h"
#include "../include/SnakeFood.h"
#include "../include/BoardState.h"
#include <curses.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24
#define BORDER_EDGE '-'
#define BORDER_CORNER '+'
#define BORDER_SIDE '|'

class SnakeBoard {
	private:
		int currentPlayer;
		Snake player1;
		Snake player2;
		SnakeFood food;

	public:
		SnakeBoard();
		~SnakeBoard();

		void setCurrentPlayer(int playerNum);
		BoardState update(BoardState& state);
		BoardState collectInput(BoardState oldState);
		void draw(void);
};

#endif
