/*
 * Defines the state of the snake board with information about the 
 *  heads of both the snakes and the position of the food.
 *  
 * Authors: Josh Martin and Nathaniel Cantwell
 */

#include "SnakeFood.h"
#include "SnakeHead.h"

class BoardState {
	private:
		int game_state; 	// Flag to determine if the game is still going on
		SnakeHead player_1;
		int player_1_score;
		SnakeHead player_2;
		int player_2_score;
		SnakeFood snake_food;

	public:
		BoardState();
		~BoardState();

		//void updateState();
};
