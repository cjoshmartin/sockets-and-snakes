// Header file to define message structures for playing pingpong
//
// Author: Nathaniel Cantwell

#define BALL 'o'
//#define PADDLE 

// Message sent from the client encoding the key state
typedef struct {
	char key;
} Keystate;

// Message sent from server encoding state to draw the screen
typedef struct {
	int ball_x, ball_y;
	int leftpad_y, rightpad_y;
} Screenstate;
