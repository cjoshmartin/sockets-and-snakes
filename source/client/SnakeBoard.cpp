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
	timeout(1);
	//cbreak();
	//nodelay(stdscr, false);
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

	// Initial refresh with borders
	refresh();
}

// Destroy curses board
SnakeBoard::~SnakeBoard() {
	endwin();
}

// Update the local board given a BoardState (from the server)
BoardState SnakeBoard::update(BoardState& newState) {
	// Check for game over
	if (newState.game_on) {
		// Update player 1 and 2's snake heads
		player1.newHead(newState.player_1);
		player2.newHead(newState.player_2);

		// Check for death

		// New food posititon
		food = newState.snake_food;

		// Return updated state

	// Else, win has occurred.
	} else {
		// Win state
	}
}

// Sets the current player (i.e., which one is controlled by keypresses)
void SnakeBoard::setCurrentPlayer(int playerNum) {
	currentPlayer = playerNum;
}

// Draw the board on the screen according to the board's state
void SnakeBoard::draw(void) {
	// Draw both players
	player1.draw();
	player2.draw();

	// Draw the food
	mvaddch(food.getYPos(), food.getXPos(), FOODCHAR);
	refresh();
}

// Collect nonblocking terminal input from the user and return BoardState based
//  on this input. Also modifies the current player's head.
BoardState SnakeBoard::collectInput(BoardState oldState) {
	int newdir = -1;
	char ch;

	// Perform a nonblocking read from the terminal (crmode set)
	ch = getch();

	// Determine direction/action depending on character
	switch(ch) {
		case 'w': case 'W': case 'k': case 'K':
			newdir = Up;
			break;
		case 's': case 'S': case 'j': case 'J':
			newdir = Down;
			break;
		case 'a': case 'A': case 'h': case 'H':
			newdir = Left;
			break;
		case 'd': case 'D': case 'l': case 'L':
			newdir = Right;
			break;
		case 'q': case 'Q': case EOF:
			// Quit game
		default: // If unrecognized key or ERR, do nothing.
			newdir = -1;
	}

	// If direction was changed
	if (newdir != -1) {
		// Set direction for current player
		if (currentPlayer == 1)
			oldState.player_1.setDir(newdir);
		else
			oldState.player_2.setDir(newdir);
	}
	
	return oldState;
}
