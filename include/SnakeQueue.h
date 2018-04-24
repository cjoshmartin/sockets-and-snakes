/*
 * Queue data structure to keep track of the snake tail/history
 */

#include "SnakeHead.h"
#include "TailSeg.h"

#define QUEUE_LEN 3600

// Snake_Queue: to enqueue/dequeue snake position history
class SnakeQueue {
	private:
		TailSeg queue_arr[QUEUE_LEN]; 	// Actual data container
		int head, tail; 			// "Pointers" to the beginning/end
		int length; 				// Positional difference between head/tail

	public:
		SnakeQueue();
		~SnakeQueue();

		void enqueue(TailSeg& segment);
		TailSeg dequeue(void);
};

