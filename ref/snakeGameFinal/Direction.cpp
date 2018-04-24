#include"Direction.h"

using namespace std;
//this class represents the direction of the snake's head
//for snake to move, x and y in direction are added to snake's head
//and the other segments get the positions of the segments in front
//of them.

//variables names and methods names are self explanatory
Direction::Direction(){

}

Direction::Direction(int x, int y) {

}
int Direction::getX(){
	return this->x;
}
int Direction::getY(){
	return this->y;
}

void Direction::setX(int x){
	this->x = x;
}
void Direction::setY(int y){
	this->y = y;
}
