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
	curs_set(0);

	// Top row border
	mvaddch(0, 0, BORDER_CORNER);
	mvaddch(0, SCREEN_WIDTH-1, BORDER_CORNER);
	for (int i = 1; i < SCREEN_WIDTH-1; i++) {
		mvaddch(0, i, BORDER_EDGE);
	}

	// Bottom border
	mvaddch(SCREEN_HEIGHT-1, 0, BORDER_CORNER);
	mvaddch(SCREEN_HEIGHT-1, SCREEN_WIDTH-1, BORDER_CORNER);
	for (int i = 1; i < SCREEN_WIDTH-1; i++) {
		mvaddch(SCREEN_HEIGHT-1, i, BORDER_EDGE);
	}

	// Sides border
	for (int i = 1; i < SCREEN_HEIGHT-1; i++) {
		mvaddch(i, 0, BORDER_SIDE);
		mvaddch(i, SCREEN_WIDTH-1, BORDER_SIDE);
	}

	// Initial refresh
	refresh();
}

// Destroy curses board
SnakeBoard::~SnakeBoard() {
	endwin();
}
