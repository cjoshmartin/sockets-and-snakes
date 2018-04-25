/*
 * Data structucture to encode information about the head of the snake.
 *
 */

#ifndef _SNAKEHEAD_H
#define _SNAKEHEAD_H

#define X_SIZE 80
#define Y_SIZE 24

#define PLAYER_1_X 15
#define PLAYER_1_Y 7
#define PLAYER_2_X 64
#define PLAYER_2_Y 7

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

		void setPos(int xpos, int ypos);
		void setDir(int newdir);
		int getXPos();
		int getYPos();
		void addLength(void);
		bool updatePos();
		int getLength(void);
};

#endif
