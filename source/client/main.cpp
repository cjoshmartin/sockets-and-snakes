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

int main(int ac, char* av[]) {
	// Time-storing variables to enforce minimum refresh time
	struct timeval start, end;

	// Is the game still going?
	bool playing;

	// Initialize board and current player according to initial communication
	SnakeBoard gameBoard;
	BoardState boardState;

	// Connection parameters
	char* hostname;
	int portnum;

	
	// Check command-line arguments
	if (ac < 3) {
		printf("Usage: %s [hostname] [portnum]\n", av[0]);
		exit(1);
	}

	// Get hostname and port number from command line arguments
	portnum = atoi(av[2]);
	hostname = av[1];

	// Initialize the connection with the server and set the player number
	gameBoard.initConnection(hostname, portnum);

	gameBoard.getState(); // get from client side
	printf("Success!\n");
	exit(0);

	// Install ^C handler
	signal(SIGINT, killHandle);

	// Initialize Curses
	gameBoard.initScreen();

	// Loop until win
	playing = true;
	while (playing) {
		// Start timing loop
		gettimeofday(&start, NULL);

		// Update the board from the server
		gameBoard.getState(); // get from client side

		// Update the graphical board from the state
		playing = gameBoard.update();

		// Draw the board on the screen
		gameBoard.draw();

		// Collect input from the board and update the state
		gameBoard.collectInput();

		// Send new state to the server
		gameBoard.sendState(); // Send from client side
		
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

