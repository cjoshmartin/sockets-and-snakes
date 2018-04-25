/*
 * Implementation file for Snake class. Responsible for keeping track of
 *  the snake, its body/tail, and its life/death.
 */

#include "Snake.h"

// Default constructor
Snake::Snake() : alive(true), growflag(false) {

}

// Destructor
Snake::~Snake() {

}

// Sets the head position of the snake
void Snake::initPos(int xpos, int ypos) {
	head.setPos(xpos, ypos);
}

// Updates the position of the snake given a new head position
void Snake::updatePos(int head_x, int head_y) {
	
}

// Draws the snake on the screen according to the position
void Snake::draw(void) {
	mvaddch(head.getYPos(), head.getXPos(), SNAKECHAR);
}

// Update the head of the snake given a head
void Snake::newHead(SnakeHead& newSnakeHead) {
	head = newSnakeHead;
}