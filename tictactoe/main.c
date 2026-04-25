#include <stdio.h>
#include <stdlib.h>

#define NROWS 3
#define NCOLS 3

#define DIVCH '*'
#define NDIV  18

char table[NROWS][NCOLS] = {
	{'1', '2', '3'},
	{'4', '5', '6'},
	{'7', '8', '9'}
};

void printtable();
void clearscreen();

void turns(int n);

int gamehaswinner();
int winner(char winch);

int xplayer = 1;
int nfree = 9;

int main()
{
	int ntable = 0;
	int winnum = 0;

	clearscreen();

	do  {
		printtable();
		printf("[%c] It's your turn! N: ", (xplayer) ? 'X' : 'O');

		scanf("%d", &ntable);

		if (ntable < 0 || ntable >= 10) {
			printf("Valid numbers: (1-9). Number [0] to exit.\n");

			/* clear buffer and wait for player input */
			while (getchar() != '\n');
			getchar();

			clearscreen();
			continue; 
		}

		turns(ntable);

		if ((winnum = gamehaswinner()) > 0) {
			break;
		}
		else if (winnum < 0) {
			printf("\nIt's a tie! Ending game...\n");
			break;
		}

		clearscreen();
	} while (ntable != 0);

	if (ntable == 0)
		printf("Closing game...\n");

	printf("\n");
	
	return 0;
}

void clearscreen()
{
#ifdef __unix__
	system("clear");
#endif
#ifdef _WIN32
	system("cls");
#endif
}

int winner(char winch)
{
	clearscreen();
	printtable();
	printf("Player %c WINS!\n", winch);
	return 1;
}

int gamehaswinner()
{
	int static checkch;

	checkch = (checkch == 'X') ? 'O' : 'X';

	/* check horizontally, vertically and diagonally */

	for (int i = 0; i < NROWS; i++) {
		if (table[i][0] == checkch) 
			if (table[i][1] == checkch) 
				if (table[i][2] == checkch) 
					return winner(checkch);
	}
	for (int j = 0; j < NCOLS; j++) {
		if (table[0][j] == checkch)
			if (table[1][j] == checkch)
				if (table[2][j] == checkch)
					return winner(checkch);
	}

	if (table[0][0] == checkch)
		if (table[1][1] == checkch)
			if (table[2][2] == checkch)
				return winner(checkch);

	if (table[0][2] == checkch)
		if (table[1][1] == checkch)
			if (table[2][0] == checkch)
				return winner(checkch);

	/* no valid squares left? that's a tie */

	if (nfree < 1) {
		return -1;
	}

	return 0;
}

void turns(int n)
{
	int row = (n - 1) / 3;
	int col = (n - 1) % 3;

	if (table[row][col] != 'X' && table[row][col] != 'O') {
		table[row][col] = (xplayer) ? 'X' : 'O';
		nfree--;
		xplayer = !xplayer;
	}
	else {
		printf("Square %d is already taken!\n", n);
		/* clear buffer and wait for player input */
		while (getchar() != '\n');
		getchar();
	}

}

void printtable()
{
	for (int i = 0; i < NDIV; i++)
		putchar(DIVCH);
	printf("\n");
	for (int i = 0; i < NROWS; i++) {
		for (int j = 0; j < NCOLS; j++) {
			printf("%c\t", table[i][j]);
		}
		printf("\n\n");
	}
}
