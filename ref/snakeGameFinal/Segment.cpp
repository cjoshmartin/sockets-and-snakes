//#include<iostream>
#include"Segment.h"
using namespace std;
//this class represents a snake segment
//variables names and methods names are self explanatory
Segment::Segment(){
    positionX=-1;
    positionY=-1;
}
int Segment::getPositionX(){
    return this->positionX;
}
int Segment::getPositionY(){
    return this->positionY;
}
void Segment::setPositionX(int positionX){
    this->positionX=positionX;
}
void Segment::setPositionY(int positionY){
    this->positionY=positionY;
}
void Segment::updatePosition(int positionX, int positionY){
	this->positionX = positionX;
	this->positionY = positionY;
}

