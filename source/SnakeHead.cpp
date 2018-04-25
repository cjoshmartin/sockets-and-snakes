/*
 * Implementation file for SnakeHead class
 */

#include "include/SnakeHead.h"

// Default constructor
SnakeHead::SnakeHead() : x_pos(0), y_pos(0), dir(Up), length(0) {

}

// Destructor
SnakeHead::~SnakeHead() {

}

// Parameterized constructor
SnakeHead::SnakeHead(int xpos, int ypos) : x_pos(xpos), y_pos(ypos), dir(Up), length(0) {

}

// Update the position according to the direction
void SnakeHead::updatePos() {
	// Update position based on current direction
	switch (dir) {
		case Up:
			y_pos -= 1;
			break;
		case Down:
			y_pos += 1;
			break;
		case Left:
			x_pos -= 1;
			break;
		case Right:
			x_pos += 1;
			break;
		default:
			//Why????
	}
}

// Sets the direction of the snake

