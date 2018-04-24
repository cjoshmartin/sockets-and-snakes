#include"Player.h"
#include"Board.h"
#include"Snake.h"
#include"Segment.h"
#include"Direction.h"
#include <string>

using namespace std;
//this class represents a player
//not used in this version
//will be used for multi terminal version
//variables names and methods names are self explanatory
Player::Player(int id, string pathName){
    this->id=id;
    this->pathName=pathName;
}
Player::Player(){
    this->id=-1;
}

Player::~Player(){
}

int Player::getId(){
    return this->id;
}

string Player::getPathName(){
    return this->pathName;
}
void Player::setId(int id){
    this->id=id;
}
void Player::setPathName(string pathName){
    this->pathName=pathName;
}
void Player::readMove(){

    //reads move made by player in client terminal
}
