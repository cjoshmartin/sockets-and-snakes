/*
 * Snake class. Stores the snake's head and keeps track of the tail. Also checks
 *  for collisions with the wall.
 */

#ifndef _SNAKE_H
#define _SNAKE_H

class Snake {
	private:
		bool alive;
		bool growflag;
		SnakeHead head;
		//SnakeTail tail;

	public:
		Snake();
		~Snake();

		void initPos(int xposk, int ypos);
		bool isAlive(void);
		updatePos(int head_x, int head_y);
		//grow(void);
};

#endif
