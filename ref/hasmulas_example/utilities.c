#include "utilities.h"
#include "structs.h"

position generateTrophy()
{
	position pos;
	int cols = 50;
	int rows = 30;
	
    pos.x = rand() % (cols - 3) + 1;
    pos.y = rand() % (rows - 3) + 1;
    
	return pos;
}