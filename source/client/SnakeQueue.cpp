/*
 * Snake_Queue.cpp:
 * 	Implementation file for the snake tail piece queue.
 */

#include "SnakeQueue.h"

// Default constructor
SnakeQueue::SnakeQueue() {
	// Initialize head/tail queue pointers
	head = 0;
	tail = 0;
	length = 0;
}

// Destructor
SnakeQueue::~SnakeQueue() {

}

// Enqueue a
