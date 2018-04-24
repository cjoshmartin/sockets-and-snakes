#include "Headers.h"
#include "Food.h"
//this class represents food
Food::Food(){

    this -> y = (BORDERX2-BORDERX1)/2;
    this -> x = (BORDERY2-BORDERY1)/2;
}

void Food::genRandFood(){

    this -> y = rand()%(BORDERX2-2) + BORDERX1 + 1;//random y
    this -> x = rand()%(BORDERY2-2) + BORDERY1 + 1;//random x
}
