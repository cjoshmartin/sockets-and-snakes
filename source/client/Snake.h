/*
 * Snake class. Stores the snake's head and keeps track of the tail. Also checks
 *  for collisions with the wall.
 */

#ifndef _SNAKE_H
#define _SNAKE_H

class Snake {
	private:
		bool alive;
		SnakeHead head;
		bool growflag;

	public:
		Snake();
		~Snake();

		bool isAlive(void);
		updatePos(int head_x, int head_y);
		//grow(void);
};

#endif
