/*
 * Data structure to define the information about the snake food
 */

class SnakeFood {
	private:
		int x_pos, y_pos;

	public:
		SnakeFood();
		~SnakeFood();
		SnakeFood(int xpos, int ypos);

		int getXPos();
		int getYPos();
};
