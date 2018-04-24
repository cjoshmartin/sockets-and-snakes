/*
 * Defines the state of the snake board with information about the 
 *  heads of both the snakes and the position of the food.
 *  
 * Authors: Josh Martin and Nathaniel Cantwell
 */

enum direction{
	Up,
	Down,
	Left,
	Right
};

// Snake_Head: defines the position and direction of the snake's head
class SnakeHead {
	int x_pos, y_pos; 	// The position of the snake head on the screen
	int dir; 			// Direction of the snake's movement (up, down, left, right)
	int length; 		// Length of the snake
};


// Tail_Seg: Snake tail piece structure
class TailSeg {
	int x_pos, y_pos;
};


// SnakeFood: snake food position structure
class SnakeFood {
	int x_pos, y_pos;
};


// Board_State: Board state, to be passed between client and server
class Board_State {
	int life_death; 	// Flag to determine if the game is still going on
	SnakeHead player_1;
	int player_1_score;
	SnakeHead player_2;
	int player_2_score;
	Food snake_food;
};