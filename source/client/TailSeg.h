/*
 * Data structure to encode the tail segments of the snake on the board.
 */

#ifndef _TAILSEG_H
#define _TAILSEG_H

class TailSeg {
	private:
		int x_pos, y_pos;

	public:
		TailSeg();
		~TailSeg();
		TailSeg(int xpos, int ypos);
		int getXPos();
		int getYPos();
};

#endif
