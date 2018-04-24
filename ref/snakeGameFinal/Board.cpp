#include"Board.h"
#include"Snake.h"
#include"Segment.h"
#include"Direction.h"
#include "Food.h"

using namespace std;
//this class represents the board
//variables names and methods names are self explanatory
Board::Board(){
    this -> speed = 100000;
     for(int i=BORDERY1;i<BORDERY2;i++){
        for(int j=BORDERX1;j<BORDERX2;j++){
            //if(i==0||i==49||j==0||j==49){
                this->boardArray[i][j]=0;
            //}
        }
    }
}
Board::~Board(){
}
//checks if snake's head collided with a wall
int Board::wallCollision(Snake &snake){
    if(this->boardArray[snake.snakeArray[0].getPositionX()][snake.snakeArray[0].getPositionY()]==1){

        snake.isPlaying = 0;

        return 1;
    }
    return 0;
}
//checks if snake's head collided with food
int Board::foodCollision(Snake &snake){
    if(food.x==snake.snakeArray[0].getPositionX()&&food.y==snake.snakeArray[0].getPositionY()){
        snake.snakeGrow();
            if(this -> speed > 1000)
            {
                this -> speed = this -> speed - 1000;
            }

            //keeps generating food until food's location is not on top of any snake
            this->food.genRandFood();
            while(!this->foodOverwriteCheck(this->food))
            {
                this->food.genRandFood();
            }

        return 1;
    }
    return 0;
}
//checks if snake collided with other snakes or with itself
int Board::snakeCollision(Snake &snake){
        int seg;
        for(int index=0; index<4; index++){
            if(snake.isPlaying){
                //with other snakes
                if(snake.getId()!=this->snakes[index].getId()){
                    if(!snakes[index].isPlaying)
                        continue;
                    for(seg=0; seg<this->snakes[index].length; seg++){
                        if(snake.snakeArray[0].getPositionX() == snakes[index].snakeArray[seg].getPositionX()&&
                            snake.snakeArray[0].getPositionY() == snakes[index].snakeArray[seg].getPositionY()){
                              //  snake.isPlaying = 0;
                              //  return 1;
                        }
                    }
                }//endfor

                else{
                //with itself
                    if(snake.length>4){
                        for(seg=1; seg<snake.length; seg++){
                            if(snake.snakeArray[0].getPositionX() == snake.snakeArray[seg].getPositionX()&&
                                snake.snakeArray[0].getPositionY()== snake.snakeArray[seg].getPositionY()){
                                //if(){
                                    snake.isPlaying = 0;
                               //returnValue=1;
                                    return 1;
                            }
                        }//endfor
                    }//endif
                }//endelse

            }//endif
        //}//endif

        }//endfor
        //return returnValue;
        return 0;
}//end snakeCollision()

void Board::collision(Snake &snake){

}

void Board::initBoard(){
    srand(time(NULL));
    initscr();//will initalize the board
    clear();

    for(int i=BORDERY1;i<BORDERY2;i++){
        for(int j=BORDERX1;j<BORDERX2;j++){
            if(i==BORDERY1||i==BORDERY2-1||j==BORDERX1||j==BORDERX2-1){
                this->boardArray[i][j]=1;
            }
        }
    }
}

void Board::printBoard(){
    for(int i=BORDERY1;i<BORDERY2;i++){
        for(int j=BORDERX1;j<BORDERX2;j++){
            cout<<this->boardArray[i][j]<<"";
        }
        cout<<"\n";
    }
}
//uses the lcurses library to display the board state to the user.
//the curses MUST be initialized in main before the board.start() method, or have more board methods
void Board::display(){
    //clear screen
    clear();
    //write on the virtual board
    this->v_display_board();
    this->v_display_snake();
    this->v_display_food();

    //moves cursor out of the way
    move(LINES-1,0);

    //refresh screen
    refresh();
}

void Board::done_display()
{
    //clears and resets TTY
    clear();
    endwin();
}

void Board::v_display_food(void)
{
    move(this->food.y,this->food.x);
    addch('F');
}
void Board::v_display_snake(void)
{
    int i = 0;
    int k = 0;

    for( i = 0 ; i < 4 ; i++)
    {
        if( this->snakes[i].isPlaying )
        {

            move( this->snakes[i].snakeArray[0].getPositionY(),this->snakes[i].snakeArray[0].getPositionX() );
            addch('H');

            for( k = 1 ; k < this->snakes[i].length ; k++)
            {
                move( this->snakes[i].snakeArray[k].getPositionY() ,this->snakes[i].snakeArray[k].getPositionX() );
                addch('O');
            }

        }
    }
}
//writes to the virtual display
void Board::v_display_board(void)
{
    int k = 0;
    int i = 0;

    for( k = BORDERX1 ; k < BORDERX2 ; k++)
    {
        move(k,BORDERY1);//write down the column
        addch('X');
    }

    for( i = BORDERY1 ; i < BORDERY2 ; i++)
    {
        move(BORDERX1 , i);
        addch('X');

        move(BORDERX2 - 1 , i);
        addch('X');
    }

    for( k = BORDERX1 ; k < BORDERX2 ; k++)
    {
        move(k , BORDERY2 - 1);//write down the column
        addch('X');
    }
}

void Board::read()
{

    /*
    int i = 0;

    for( i = 0 ; i<4 ; i++ )
    {
        if( this -> players[i].id != -1)
        {
            this -> players[i].readMove(); //all active players movements read
        }
    }
    */
}

void Board::Start()
{
    char ch = 'a';

    this -> initBoard();
    this -> snakes[0].isPlaying = 1;
    this -> snakes[0].id = 0;
    this -> snakes[0].updateDirection('w');
    this -> snakes[0].snakeArray[0].updatePosition((BORDERY2-BORDERY1)/2,(BORDERX2-BORDERX1)/2);

    while(this->snakes[0].isPlaying)
    {

        this->ttysaver(0);
        this->ttysetall();

        ch = getchar();

        if(ch != EOF){//if we recieve charachter

            this->snakes[0].updateDirection(ch);
        }

        this->snakes[0].snakeMove();
        this->wallCollision(this->snakes[0]);

        this->foodCollision(this->snakes[0]);

        this->snakeCollision(this->snakes[0]);

        this->ttysaver(1);
        this->display();
        usleep(this -> speed);
    }

    this -> done_display();
	cout<<"You lost with "<<(this->snakes[0].length-1)*10<<" points."<<endl;
}

int Board::Start2()
{

    this -> initBoard();
    this -> snakes[0].isPlaying = 1;
    this -> snakes[0].id = 0;
    this -> snakes[0].updateDirection('d');
    this -> snakes[0].snakeArray[0].updatePosition((BORDERY2-BORDERY1)/4,(BORDERX2-BORDERX1)/2);

    this -> snakes[1].isPlaying = 1;
    this -> snakes[1].id = 1;
    this -> snakes[1].updateDirection('a');
    this -> snakes[1].snakeArray[0].updatePosition((BORDERY2-BORDERY1)/4+(BORDERY2-BORDERY1)/2,(BORDERX2-BORDERX1)/2);
    char ch = 'a';
    char ck = 'b';
    
    // Added code here...
    this -> snakes[0].snakeGrow();
    this -> snakes[0].snakeMove();
    
    this -> snakes[1].snakeGrow();
    this -> snakes[1].snakeMove();
    
    this -> snakes[0].snakeGrow();
    this -> snakes[0].snakeMove();
    
    this -> snakes[1].snakeGrow();
    this -> snakes[1].snakeMove();
    
    // Added code above...

    while(this->snakes[0].isPlaying && this->snakes[1].isPlaying)
    {

        this->ttysaver(0);
        this->ttysetall();

        ch = getchar();

        //ck = getchar();

        if(ch != EOF){//if we recieve charachter

            this->snakes[0].updateDirection(ch);

            this->snakes[1].updateDirection(this->translate_char(ch));
        }

        this->snakes[0].snakeMove();
        this->snakes[1].snakeMove();

        ch = getchar();

        //ck = getchar();

        if(ch != EOF){//if we recieve charachter

            this->snakes[0].updateDirection(ch);

            this->snakes[1].updateDirection(this->translate_char(ch));
        }

        this->wallCollision(this->snakes[0]);


        ch = getchar();

        //ck = getchar();

        if(ch != EOF){//if we recieve charachter

            this->snakes[0].updateDirection(ch);

            this->snakes[1].updateDirection(this->translate_char(ch));
        }
        this->foodCollision(this->snakes[0]);


        ch = getchar();

        //ck = getchar();

        if(ch != EOF){//if we recieve charachter

            this->snakes[0].updateDirection(ch);

            this->snakes[1].updateDirection(this->translate_char(ch));
        }
        this->snakeCollision(this->snakes[0]);



        ch = getchar();

        //ck = getchar();

        if(ch != EOF){//if we recieve charachter

            this->snakes[0].updateDirection(ch);

            this->snakes[1].updateDirection(this->translate_char(ch));
        }
        this->wallCollision(this->snakes[1]);


        ch = getchar();

        //ck = getchar();

        if(ch != EOF){//if we recieve charachter

            this->snakes[0].updateDirection(ch);

            this->snakes[1].updateDirection(this->translate_char(ch));
        }
        this->foodCollision(this->snakes[1]);


        ch = getchar();

        //ck = getchar();

        if(ch != EOF){//if we recieve charachter

            this->snakes[0].updateDirection(ch);

            this->snakes[1].updateDirection(this->translate_char(ch));
        }

        this->snakeCollision(this->snakes[1]);


        this->ttysaver(1);
        this->display();

        usleep(this -> speed);
    }

    if((this->snakes[0].snakeArray[0].getPositionX() == this->snakes[1].snakeArray[0].getPositionX()) &&
		(this->snakes[0].snakeArray[0].getPositionY()==this->snakes[1].snakeArray[0].getPositionY()))
    {
        this->done_display();
        cout << "It was a draw!" << endl;
        return -1;
    }else if(this->snakes[0].isPlaying)
    {

        this->done_display();
        cout << "Player 1 wins." << endl;
        return 0;
    }else
    {

        this->done_display();
        cout << "Player 2 wins." << endl;
        return 1;
	}
}

char Board::translate_char( char input)
{
    if(input == 'i')
    {
        return 'w';

    }else if(input == 'j')
    {
        return  'a';
    }else if(input == 'k')
    {
        return  's';
    }else if(input == 'l')
    {
        return 'd';
    }else
    {
        return 'p';//this is just a flase value
    }
}

int Board::foodOverwriteCheck(Food &food){
        int seg;
        for(int index=0; index<4; index++){
            if(!this->snakes[index].isPlaying)
                continue;

            for(seg=0; seg<this->snakes[index].length; seg++){
                if(this->food.x == snakes[index].snakeArray[seg].getPositionX()&&
                    this->food.y == snakes[index].snakeArray[seg].getPositionY()){
                            return 0;
                }
            }
        }//endfor
        return 1;
}//endmethod
//}

void Board::ttysaver(int how)
{//the mode value if 0, will save current tty settings, and if 1 will restore

   static struct termios original_mode;
   static int            original_flags;
   static int            stored = 0;

   if ( how == 0 ){
       tcgetattr(0, &original_mode);
       original_flags = fcntl(0, F_GETFL);
       stored = 1;
   }
   else if ( stored ) {
       tcsetattr(0, TCSANOW, &original_mode);
       fcntl( 0, F_SETFL, original_flags);
   }
}

void Board::ttysetall()
{
           struct termios ttystate;
           int  termflags;

           termflags = fcntl(0, F_GETFL);/* read curr. settings*/
           termflags |= O_NDELAY;/* flip on nodelay bit*/
           fcntl(0, F_SETFL, termflags);/* and install 'em*/
           tcgetattr( 0, &ttystate);/* read curr. setting*/
           ttystate.c_lflag    &= ~ICANON;/* no buffering*/
           ttystate.c_lflag    &= ~ECHO;/* no echo either*///ACTIVE
           ttystate.c_cc[VMIN]  =  1;/* get 1 char at a time*/
           tcsetattr( 0 , TCSANOW, &ttystate);/* install settings*/



           termflags = fcntl(0, F_GETFL);/* read curr. settings*/
           termflags |= O_NDELAY;/* flip on nodelay bit*/
           fcntl(0, F_SETFL, termflags);/* and install 'em*/
}
