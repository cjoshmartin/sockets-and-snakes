/*
 * Data structure to define the information about the snake food
 */

#ifndef _SNAKEFOOD_H
#define _SNAKEFOOD_H

#define X_SIZE 78
#define Y_SIZE 38

#include <math.h>

class SnakeFood {
	private:
		int x_pos, y_pos;

	public:
		SnakeFood();
		~SnakeFood();
		SnakeFood(int xpos, int ypos);

		int getXPos();
		int getYPos();
		randPos();
};

#endif
