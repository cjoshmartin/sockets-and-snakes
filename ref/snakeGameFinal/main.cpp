//#include <iostream>
#include"Segment.h"
#include"Direction.h"
#include"Snake.h"
#include"Player.h"
#include"Board.h"
#include<signal.h>

void ctrl_c_handler(int signum);

using namespace std;

int main()
{
    signal(SIGINT,ctrl_c_handler);
	int answerInt=0;
	Board game;
	cout<<"How many players?(1/2): ";
	cin>>answerInt;

	if(answerInt==1){//single player game
		game.Start();
	}else if(answerInt==2){//multi player game
		game.Start2();
	}


    return 0;
}
void ctrl_c_handler(int signum)
    /*
     *  * purpose: called if SIGINT is detected
     *   *  action: reset tty and CLOSE FILE
     *    */
{
            clear();
            endwin();
            exit(2);
}
