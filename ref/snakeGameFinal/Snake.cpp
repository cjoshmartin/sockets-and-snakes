#include"Snake.h"
#include"Segment.h"
#include"Direction.h"

using namespace std;
//this class represents a snake
//variables names and methods names are self explanatory
Snake::Snake(){
    //default constructor
    //initializes properties
    this->id=-1;
    //this->stamina=5;
    this->FLAGGrow=0;
    this->isPlaying=0;
    this->length=1;
}

Snake::Snake(int id, char directionChar){
    //initializes properties
    this->id=id;
    //this->stamina=5;
    this->FLAGGrow=0;
    this->isPlaying=0;
    this->length=1;
    if (directionChar == 'w')
		this->setDirection(0, -1);
    else if (directionChar == 's')
		this->setDirection(0, 1);
	else if (directionChar == 'd')
		this -> setDirection(1, 0);
	else if (directionChar == 'a')
		this->setDirection(-1, 0);
}

Snake::~Snake(){
}
int Snake::getId(){
    	return this->id;
}

Direction Snake::getDirection(){
    	return this->direction;
}

void Snake::setId(int id){
    	this->id=id;
}

void Snake::setDirection(int x, int y) {
	this->direction.setX(x);
	this->direction.setY(y);
}

int Snake::updateDirection(char directionChar){
    int newX = this->direction.getX();
    int newY = this->direction.getY();
    if (directionChar == 'w'){
            newX=0;
            newY=-1;
    }else if (directionChar == 's'){
            newX=0;
            newY=1;
	}else if (directionChar == 'd'){
            newX=1;
            newY=0;
	}else if (directionChar == 'a'){
            newX=-1;
            newY=0;
	}
	//if snake is moving east, it cannot change to west and vice versa
    if(this->direction.getX()!=0&&newX!=0)
            return 0;
    //if snake is moving north, it cannot change to south and vice versa
    if (this->direction.getY()!=0&&newY!=0)
            return 0;

    this->setDirection(newX,newY);
    return 1;
}
int Snake::snakeLength(){
    int arrayLength=sizeof(this->snakeArray)/sizeof(this->snakeArray[0]);
    int i;
	for(i=0;i<arrayLength;i++){
            if(this->snakeArray[i].getPositionX()==-1&&this->snakeArray[i].getPositionY()==-1){
                    break;
            }
    }
    return i;
    //Segment snakeArray[100];
}
void Snake::snakeMove(){
	int snakeIndex=this->snakeLength()-1;
//-----------------------------------------------------------------------------------------------
    //if FLAGGrow is set, snake moves and then grows. FLAGGrow is set back to 0
    if(FLAGGrow){

            int tempX;
            int tempY;
            tempX=snakeArray[this->snakeLength()-1].getPositionX();
            tempY=snakeArray[this->snakeLength()-1].getPositionY();

            for(;snakeIndex>0;snakeIndex--){
                this->snakeArray[snakeIndex].updatePosition(this->snakeArray[snakeIndex-1].getPositionX(),
                                                    this->snakeArray[snakeIndex-1].getPositionY());
            }

        this->snakeArray[0].updatePosition(this->snakeArray[0].getPositionX()+this->direction.getX(),
                                        this->snakeArray[0].getPositionY()+this->direction.getY());

        this->snakeArray[this->snakeLength()].updatePosition(tempX,tempY);
        this->length++;
        FLAGGrow=0;
        return;
    }

//-----------------------------------------------------------------------------------------------
	//otherwise snake just moves normally
	for(;snakeIndex>0;snakeIndex--){
		this->snakeArray[snakeIndex].updatePosition(this->snakeArray[snakeIndex-1].getPositionX(),
                                                    this->snakeArray[snakeIndex-1].getPositionY());
	}
	this->snakeArray[0].updatePosition(this->snakeArray[0].getPositionX()+this->direction.getX(),
                                        this->snakeArray[0].getPositionY()+this->direction.getY());
}

void Snake::snakeGrow(){//FLAGGrow is activated. it grows next time it moves
    FLAGGrow=1;
}






