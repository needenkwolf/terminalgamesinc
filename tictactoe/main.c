#include <stdio.h>

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
void turns(int n);
int gamehaswinner();
int winner(char winch);

int xplayer = 1;
int nfree = 9;

int main()
{
	int ntable = 0;
	int winnum = 0;

	printtable();

	do  {
		printf("[%c] It's your turn! N: ", (xplayer) ? 'X' : 'O');

		scanf("%d", &ntable);

		if (ntable < 0 || ntable >= 10) {
			printf("\n");
			printtable();
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

		printf("\n");
		printtable();
	} while (ntable != 0);

	if (ntable == 0)
		printf("Closing game...\n");

	printf("\n");
	
	return 0;
}

int winner(char winch)
{
	printf("\n");
	printtable();
	printf("\nPlayer %c WINS!\n", winch);
	return 1;
}

int gamehaswinner()
{
	int static checkch;

	checkch = (checkch == 'X') ? 'O' : 'X';

	if (nfree < 1) {
		return -1;
	}

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
