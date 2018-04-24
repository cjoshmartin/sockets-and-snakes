/*
 * Queue data structure to keep track of the snake tail/history
 */

#include "SnakeState.h"

#define QUEUE_LEN 3600

// Snake_Queue: to enqueue/dequeue snake position history
class Snake_Queue {
	private:
		Tail queue_arr[QUEUE_LEN]; 	// Actual data container
		int head, tail; 			// "Pointers" to the beginning/end
		int length; 				// Positional difference between head/tail

	public:
		Snake();
		~Snake();
};

void init_queue(Snake_Queue* the_queue);
void enqueue(Snake_Queue* the_queue, item);
void dequeue(Snake_Queue* the_queue, item);
