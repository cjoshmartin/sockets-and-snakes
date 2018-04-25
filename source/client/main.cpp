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

// Global update flag to control the timing of the system. Set to "true"
//  by the alarm handler so that refresh does not occur more often than
//  once every 0.1 seconds.
bool drawFlag = true;

void handle(int signum);
void alarmHandle(int signum);
void UpdateBoard(BoardState& theBoard);
int timedif(struct timeval start, struct timeval end);

int main(void) {
	// Initialize board and draw borders
	// Initialize communication
	// Initialize players based on comms (which player I am, 1 or 2)
	// Set up alarm and stuff
	// Wait for input and update position accordingly

	// Time-storing variables to enforce minimum refresh time
	struct timeval start, end;

	// Install signal handlers: ^C and alarm
	signal(SIGINT, handle);

	// Initialize board and current player according to initial communication
	SnakeBoard myBoard;
	myBoard.setCurrentPlayer(1);
	BoardState newBoard;
	int i = 20;

	// Set refresh rate
	//set_ticker(100);

	drawFlag = true;
	while (i) {
		gettimeofday(&start, NULL);
		UpdateBoard(newBoard);
		myBoard.update(newBoard);
		myBoard.draw();
		newBoard = myBoard.collectInput(newBoard);
		
		// Enforce minimum elapsed time of 100 ms
		double diff;
		do {
			gettimeofday(&end, NULL);
		} while (timedif(start, end) < 70000);
	}

	// Update the board and draw
}

// Gets a new board state by socket communiation
void UpdateBoard(BoardState& theBoard) {
	theBoard.update();
}

// Control-c handler
void handle(int signum) {
	endwin();
	exit(1);
}

// Calculates the time difference between two different struct timeval structures. Returns the number of milliseconds
int timedif(struct timeval start, struct timeval end) {
	return (end.tv_sec*1000000 + end.tv_usec) - (start.tv_sec*1000000 + start.tv_usec);
}
