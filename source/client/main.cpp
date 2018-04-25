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

void UpdateBoard(BoardState& theBoard);

int main(void) {
	// Initialize board and draw borders
	// Initialize communication
	// Initialize players based on comms (which player I am, 1 or 2)
	// Set up alarm and stuff
	// Wait for input and update position accordingly
	SnakeBoard myBoard;
	sleep(1);
	BoardState newBoard;
	myBoard.update(newBoard);
	myBoard.draw();
	sleep(1);

	// Update the board and draw
	UpdateBoard(newBoard);
	newBoard = myBoard.update(newBoard);
	myBoard.draw();
	sleep(1);
}

// Gets a new board state by socket communiation
void UpdateBoard(BoardState& theBoard) {
	theBoard.update();
}
