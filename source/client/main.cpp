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

// Global update flag to control the timing of the system. Set to "true"
//  by the alarm handler so that refresh does not occur more often than
//  once every 0.1 seconds.
bool drawFlag = true;

void handle(int signum);
void alarmHandle(int signum);
void UpdateBoard(BoardState& theBoard);

int main(void) {
	// Initialize board and draw borders
	// Initialize communication
	// Initialize players based on comms (which player I am, 1 or 2)
	// Set up alarm and stuff
	// Wait for input and update position accordingly

	// Install signal handlers: ^C and alarm
	signal(SIGINT, handle);
	signal(SIGALRM, alarmHandle);

	// Initialize board and current player according to initial communication
	SnakeBoard myBoard;
	myBoard.setCurrentPlayer(1);
	BoardState newBoard;
	int i = 20;

	// Set refresh rate
	set_ticker(10);

	while (i) {
		UpdateBoard(newBoard);
		myBoard.update(newBoard);
		while (!drawFlag) ;
		myBoard.draw();
		newBoard = myBoard.collectInput(newBoard);
	}

	// Update the board and draw
}

// Gets a new board state by socket communiation
void UpdateBoard(BoardState& theBoard) {
	theBoard.update();
	drawFlag = false;
}

// Sets the drawFlag to enforce a minimum refresh time
void alarmHandle(int signum) {
	signal(SIGALRM, alarmHandle);
	drawFlag = true;
}

// Control-c handler
void handle(int signum) {
	endwin();
	exit(1);
}
