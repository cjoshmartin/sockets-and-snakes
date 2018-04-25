/*
 * Snake_Queue.cpp:
 * 	Implementation file for the snake tail piece queue.
 */

#include "../../include/SnakeQueue.h"

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

// Enqueue a tail segment into the queue at the head pointer location
void SnakeQueue::enqueue(TailSeg& segment) {
	if (head != tail) {
		queue_arr[head++] = segment;
		length++;
	}
}

// Dequeue the last tail segment from the queue
TailSeg SnakeQueue::dequeue(void) {
	if (head != tail) {
		length--;
		return queue_arr[tail++];
	}
}
