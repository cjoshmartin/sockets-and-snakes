/*
 * Queue data structure to keep track of the snake tail/history
 */

#include "SnakeState.h"

#define QUEUE_LEN 3600

typedef struct {
	Tail queue_arr[QUEUE_LEN];
	int head, tail;
} Snake_Queue

void init_queue(Snake_Queue& the_queue);
void enqueue(Snake_Queue& the_queue, item);
