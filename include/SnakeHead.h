/*
 * Data structucture to encode information about the head of the snake.
 *
 */

class SnakeHead {
	private:
		int x_pos, y_pos; 	// The position of the snake head on the screen
		int dir; 			// Direction of the snake's movement (up, down, left, right)
		int length; 		// Length of the snake

	public:
		SnakeHead();
		~SnakeHead();
};
