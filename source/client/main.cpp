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

        int playerNum = 1;
        bool playing;

	// Initialize board and current player according to initial communication
	SnakeBoard gameBoard;
	BoardState boardState;

	// Initialize communication
        //playerNum = initCommuniation()

        // Set local player number
	gameBoard.setCurrentPlayer(playerNum);

	// Install ^C handler
	signal(SIGINT, killHandle);

        // Loop until win
        playing = true;
	while (playing) {
		// Start timing loop
		gettimeofday(&start, NULL);

		// Update the board from the server
		UpdateBoard(boardState); // get from client side

		// Update the graphical board from the state
		playing = gameBoard.update(boardState);

		// Draw the board on the screen
		gameBoard.draw();

		// Collect input from the board and update the state
		boardState = gameBoard.collectInput(boardState);

		// Send new state to the server
		//SendState(boardState); // Send from client side
		
		// Enforce minimum elapsed time of 80 ms by waiting for that time
		double diff;
		do {
			gettimeofday(&end, NULL);
		} while (timedif(start, end) < 80000);
	}

	// Print winner/loser and wait for keypress
}

// Gets a new board state by socket communiation
void UpdateBoard(BoardState& theBoard) {
	theBoard.update();
}

