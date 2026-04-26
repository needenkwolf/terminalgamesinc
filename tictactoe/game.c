#include <stdio.h>
#include "tictactoe.h"

enum STATUS status;

int isxplaying = 1;
int nfreesquares = 9;

int printwinner(char winch)
{
	clearscreen();
	printtable();
	printf("Player %c WINS!\n", winch);
	return WINNER;
}

int getgamestatus()
{
	static int checkch;

	checkch = (checkch == 'X') ? 'O' : 'X';

	/* check horizontally, vertically and diagonally */

	for (int i = 0; i < NROWS; i++) {
		if (table[i][0] == checkch) 
			if (table[i][1] == checkch) 
				if (table[i][2] == checkch) 
					return printwinner(checkch);
	}
	for (int j = 0; j < NCOLS; j++) {
		if (table[0][j] == checkch)
			if (table[1][j] == checkch)
				if (table[2][j] == checkch)
					return printwinner(checkch);
	}

	if (table[0][0] == checkch)
		if (table[1][1] == checkch)
			if (table[2][2] == checkch)
				return printwinner(checkch);

	if (table[0][2] == checkch)
		if (table[1][1] == checkch)
			if (table[2][0] == checkch)
				return printwinner(checkch);

	/* no valid squares left? that's a tie */

	if (nfreesquares < 1) {
		printf("\nIt's a tie! Ending game...\n");
		return TIE;
	}

	return PLAYING;
}

void handleturn(int n)
{
	int row = (n - 1) / 3;
	int col = (n - 1) % 3;

	if (table[row][col] != 'X' && table[row][col] != 'O') {
		table[row][col] = (isxplaying) ? 'X' : 'O';
		nfreesquares--;
		isxplaying = !isxplaying;
	}
	else {
		printf("Square %d is already taken!\n", n);
		waitinput();
	}

}
