/*
 * Snake class. Stores the snake's head and keeps track of the tail. Also checks
 *  for collisions with the wall.
 */

#ifndef _SNAKE_H
#define _SNAKE_H

#include "../include/SnakeHead.h"
#include <curses.h>

class Snake {
	private:
		bool alive;
		bool growflag;
		SnakeHead head;
		//SnakeTail tail;

	public:
		Snake();
		~Snake();

		void initPos(int xpos, int ypos);
		bool isAlive(void);
		void updatePos(int head_x, int head_y);
		void draw(void);
		//grow(void);
};

#endif
