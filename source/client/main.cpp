/*
 * Main file for client to use. Runs the snake game, board, and all of the
 *  supporting socket communication with the server.
 */

#include "SnakeBoard.h"
#include <curses.h>
#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <cstdlib>
#include <signal.h>

void handle(int signum);
void UpdateBoard(BoardState& theBoard);

int main(void) {
	// Initialize board and draw borders
	// Initialize communication
	// Initialize players based on comms (which player I am, 1 or 2)
	// Set up alarm and stuff
	// Wait for input and update position accordingly
	signal(SIGINT, handle);
	SnakeBoard myBoard;
	myBoard.setCurrentPlayer(1);
	BoardState newBoard;
	while (1) {
		UpdateBoard(newBoard);
		myBoard.update(newBoard);
		myBoard.draw();
		newBoard = myBoard.collectInput();
	}

	// Update the board and draw
}

// Gets a new board state by socket communiation
void UpdateBoard(BoardState& theBoard) {
	theBoard.update();
	usleep(100000);
}

// Control-c handler
void handle(int signum) {
	endwin();
	exit(1);
}
