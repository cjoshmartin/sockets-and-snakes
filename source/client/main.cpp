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

// Global update flag to control the timing of the system. Set to "true"
//  by the alarm handler so that refresh does not occur more often than
//  once every 0.1 seconds.
bool updateFlag = true;

void handle(int signum);
//void updateHandler(int signum);
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
	int i = 20;
	while (i) {
		UpdateBoard(newBoard);
		myBoard.update(newBoard);
		myBoard.draw();
		newBoard = myBoard.collectInput(newBoard);
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
