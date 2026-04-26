#include <stdio.h>
#include "tictactoe.h"

char table[NROWS][NCOLS];

void resettable()
{
	int k = 0;
	for (int i = 1; i < NROWS + 1; i++) {
		for (int j = 1; j < NCOLS + 1; j++) {
			table[i - 1][j - 1] = j + k + '0';
		}
		k += NCOLS;
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
