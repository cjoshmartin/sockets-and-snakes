#ifndef SEGMENT_H_DEFINE
#define SEGMENT_H_DEFINE

#include "Headers.h"

using namespace std;
//this class represents a snake segment

class Segment;
class Segment{
    private:
        int positionX;
        int positionY;

    public:
        Segment();
        int getPositionX();
        int getPositionY();

        void setPositionX(int positionX);
        void setPositionY(int positionY);
		void updatePosition(int x, int y);
};
#endif // SEGMENT_H_DEFINE
