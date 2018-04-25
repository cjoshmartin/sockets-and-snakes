/* bounce.h			*/

/* some settings for the game	*/

#define	BLANK		' '
#define	DFL_SYMBOL	'o'
#define	TOP_ROW		0
#define	BOT_ROW 	30
#define	LEFT_EDGE	0
#define	RIGHT_EDGE	80
#define	X_INIT		10		/* starting col		*/
#define	Y_INIT		10		/* starting row		*/
#define	TICKS_PER_SEC	50		/* affects speed	*/

#define	X_TTM		5
#define	Y_TTM		8

/** the ping pong ball **/

struct ppball {
		int	y_pos, x_pos,
			y_ttm, x_ttm, // Time to move ball
			y_ttg, x_ttg, // Time to get move
			y_dir, x_dir;
		char	symbol ;

	} ;
