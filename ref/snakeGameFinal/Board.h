#ifndef BOARD_H_DEFINE
#define BOARD_H_DEFINE

#include "Segment.h"
#include "Direction.h"
#include "Snake.h"
#include "Player.h"
#include "Food.h"
#include "curses.h"

using namespace std;
//this class represents the board

class Board{

    public:
        Player players[4];
        Snake snakes[4];
        int boardArray[SIZEX][SIZEY];
        int speed;
        Food food;
        Board();
        ~Board();

        void Start();
        int  Start2();
        void initBoard();//will also initalize curses, must be called before display
        void printBoard();
        int wallCollision(Snake &snake);
        int foodCollision(Snake &snake);
        int snakeCollision(Snake &snake);
        void collision(Snake &snake);
        void display();//will diplsay the state of the board, must be called after initBoard
        void done_display();//will restore the TTY and de-initalize the display MUST BE CALLED WHEN DONE WITH Start()
        char translate_char( char input);//translate char for player 2
        
        void read();//will read for all players 
        
        int foodOverwriteCheck(Food &food);//added

        void ttysaver(int mode);//allows saving and restoring of TTY states 
                                //this will be called by init board and done_display
        void ttysetall();//this will manage setting the correct TTY settings for the board I/O

    private://helper methods used to write the the individual parts of the screen,
        void v_display_board();//incharge of writing the board 
        void v_display_snake();//incharge of writing the snake
        void v_display_food();//incharge of writing the food
};
#endif //SNAKE_H_DEFINE
