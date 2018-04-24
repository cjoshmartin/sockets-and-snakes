#ifndef PLAYER_H_DEFINE
#define PLAYER_H_DEFINE

#include "Segment.h"
#include "Direction.h"
#include "Snake.h"
//#include <string>
#include "Headers.h"
using namespace std;
//this class represents a player

class Player{
    private:

    public:
        int id;
        string pathName;
        //char keyPressed;
        Player(int id, string pathName);
        Player();
        ~Player();
        int getId();
        string getPathName();
        void setId(int id);
        void setPathName(string pathName);
        void readMove();
};
#endif //SNAKE_H_DEFINE
