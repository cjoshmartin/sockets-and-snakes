/*
 * Board class to store the board state and update based on the player
 *  positions and history.
 * 
 * Responsible for interfacing with Curses and actually drawing stuff
 */

#ifndef _BOARD_H
#define _BOARD_H

#include <curses.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24
#define X_SIZE 78
#define Y_SIZE 22
#define BORDER_EDGE '-'
#define BORDER_CORNER '+'
#define BORDER_SIDE '|'

class SnakeBoard {
	private:
		Player player1;
		Player player2;

	public:
		SnakeBoard();
		~SnakeBoard();

		void initPlayers(void);
		update(Player& player1, Player& player2);
};

#endif
