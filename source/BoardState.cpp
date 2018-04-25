/*
 * Implementation file for the board state. To be passed between server and
 *  client to synchronize board states in clients.
 */

// Default constructor
BoardState::BoardState() : game_on(true), player1_alive(true), player2_alive(true), winner(-1) {
	player_1.setPos(PLAYER_1_X, PLAYER_1_Y);
	player_2.setPos(PLAYER_2_X, PLAYER_2_Y);
	snake_food.randPos();
}

// Destructor
BoardState::~BoardState() {

}

// Update state based on each snake head's position and direction
void BoardState::update() {
	// Update snake head position and end game if collision occurs
	if (!player_1.updatePos()) {
		game_on = false;
		winner = 2;
	}
	if (!player_2.updatePos()) {
		game_on = false;
		winner = 1;
	}

	// Check for head collision
	if (player_1.getXPos() == player_2.getXPos() && player_1.getYPos() == player_2.getYPos()) {
		game_on = false;
		winner = DRAW;
	}

	// Check if a snake ate the food

}
