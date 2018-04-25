/*
 * Main file for client to use. Runs the snake game, board, and all of the
 *  supporting socket communication with the server.
 */

#include "Utils.h"
#include "SnakeBoard.h"
#include <curses.h>
#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <cstdlib>
#include <signal.h>
#include <string.h>
#include <sys/time.h>

void UpdateBoard(BoardState& theBoard);

int main(void) {
	// Initialize communication
	// Initialize players based on comms (which player I am, 1 or 2)
	// Wait for input and update position accordingly

	// Time-storing variables to enforce minimum refresh time
	struct timeval start, end;

	// Initialize communication

	// Initialize board and current player according to initial communication
	SnakeBoard gameBoard;
	gameBoard.setCurrentPlayer(1);
	BoardState boardState;

	// Install ^C handler
	signal(SIGINT, killHandle);

	while (1) {
		// Start timing loop
		gettimeofday(&start, NULL);

		// Update the board from the server
		UpdateBoard(boardState);

		// Update the graphical board from the state
		gameBoard.update(boardState);

		// Draw the board on the screen
		gameBoard.draw();

		// Collect input from the board and update the state
		boardState = gameBoard.collectInput(boardState);

		// Send new state to the server
		//SendState(boardState);
		
		// Enforce minimum elapsed time of 80 ms by waiting for that time
		double diff;
		do {
			gettimeofday(&end, NULL);
		} while (timedif(start, end) < 80000);
	}

	// Update the board and draw
}

// Gets a new board state by socket communiation
void UpdateBoard(BoardState& theBoard) {
	theBoard.update();
}

