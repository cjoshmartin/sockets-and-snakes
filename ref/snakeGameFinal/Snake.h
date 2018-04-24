
#ifndef SNAKE_H_DEFINE
#define SNAKE_H_DEFINE

#include "Segment.h"
#include "Direction.h"
using namespace std;
//this class represents a snake

class Snake{
    private:

    public:
        int id;
        Segment snakeArray[SIZEY*SIZEX];
        Direction direction;
        int length;
        //int stamina;
        //int hunger;
        int FLAGGrow;
        int isPlaying;
            Snake();
            Snake(int id,char directionChar);
            ~Snake();
            int getId();
            Direction getDirection();
            void setId(int id);
            void setDirection(int x, int y);
            int snakeLength();
            int updateDirection(char directionChar);
            void snakeMove();
            void snakeGrow();
};
#endif //SNAKE_H_DEFINE
