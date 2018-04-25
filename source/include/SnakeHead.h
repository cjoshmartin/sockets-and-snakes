/*
 * Data structucture to encode information about the head of the snake.
 *
 */

#ifndef _SNAKEHEAD_H
#define _SNAKEHEAD_H

enum Direction{
	Up,
	Right,
	Down,
	Left
};

class SnakeHead {
	private:
		int x_pos, y_pos; 	// The position of the snake head on the screen
		int dir; 			// Direction of the snake's movement (up, down, left, right)
		int length; 		// Length of the snake

	public:
		SnakeHead();
		~SnakeHead();

		void updatePos();
		void setDir(int newdir);
		int getXPos();
		int getYPos();
};

#endif
