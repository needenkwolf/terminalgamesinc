#ifndef TICTACTOE_H
#define TICTACTOE_H

#define NROWS 3
#define NCOLS 3

#define DIVCH '*'
#define NDIV  18

extern char table[NROWS][NCOLS];

enum STATUS {
	TIE = -1,
	PLAYING,
	WINNER
};
extern enum STATUS status;

extern int isxplaying;
extern int nfreesquares;

void printtable();
void resettable();

void clearscreen();

void waitinput();

void handleturn(int n);
int getgamestatus();
int printwinner(char winch);

#endif
