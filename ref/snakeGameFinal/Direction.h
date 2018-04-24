#ifndef DIRECTION_H_DEFINE
#define DIRECTION_H_DEFINE

using namespace std;
//this class represents the direction of the snake's head

class Direction{
    private:
        int x;
        int y;
    public:
        Direction();
        Direction(int x,int y);
        int getX();
        int getY();

        void setX(int x);
        void setY(int y);
};
#endif // DIRECTION_H_DEFINE
