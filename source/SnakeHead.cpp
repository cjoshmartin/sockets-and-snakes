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
bool SnakeHead::updatePos() {
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
	}

	// Check for collision with walls
	if (x_pos == 0 || x_pos == X_SIZE-1)
		return false;
	if (y_pos == 0 || y_pos == Y_SIZE-1)
		return false;
	return true;
}

// Sets the direction of the snake
void SnakeHead::setDir(int newdir) {
	if (dir == Up || dir == down || dir == left || dir == right)
		dir = newdir;
}

// Increases the length of the snake by 1
void SnakeHead::addLength(void) {
	length++;
}

// Returns the length of the snake
int SnakeHead::getLength(void) {
	return length;
}

// Sets the position of the snake's head
void SnakeHead::setPos(int xpos, int ypos) {
	x_pos = xpos;
	y_pos = ypos;
}
