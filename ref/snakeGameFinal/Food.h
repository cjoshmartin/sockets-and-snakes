//this is the class that defines the food on the board
//

#ifndef FOOD_H_HEADER
#define FOOD_H_HEADER
class Food
{
    public:

   //default constructor
    Food(void);

    void genRandFood(void);
    int x;
    int y;
};
#endif
