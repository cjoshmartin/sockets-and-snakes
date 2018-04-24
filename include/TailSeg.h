/*
 * Data structure to encode the tail segments of the snake on the board.
 */

class TailSeg {
	private:
		int x_pos, y_pos;

	public:
		TailSeg();
		~TailSeg();
		TailSeg(int xpos, int ypos);
};
