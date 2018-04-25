/*
 * Defines the state of the snake board with information about the 
 *  heads of both the snakes and the position of the food.
 *  
 * Authors: Josh Martin and Nathaniel Cantwell
 */

#ifndef _BOARDSTATE_H
#define _BOARDSTATE_H

#define DRAW 0 		// No winner is 0. Else, 1 or 2 (which player)

#include "SnakeFood.h"
#include "SnakeHead.h"

class BoardState {
	public:
		int winner;
		bool game_on; 	// Flag to determine if the game is still going on
		bool player1_alive, player2_alive;
		SnakeHead player_1;
		SnakeHead player_2;
		SnakeFood snake_food;

		BoardState();
		~BoardState();

		void update();
};

#endif
