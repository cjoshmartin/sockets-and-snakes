/*
 * Implementation for SnakeBoard class. Interfaces with Curses and calls
 *  necessary functions to use the library.
 */

#include "SnakeBoard.h"

// Initialize curses environment, draw border, initialize player positions based
//  on initial values
SnakeBoard::SnakeBoard() {
	// Initialize curses environment
	initscr();
	noecho();
	crmode();

	// Draw border

	// Top row:
	for (int i = 0; i < SCREEN_WIDTH; i++) {
		mvaddch(0, i, BORDERSYM);
	}

	// Initial refresh
	refresh();
}

// Destroy curses board
SnakeBoard::~SnakeBoard() {
	endwin();
}
