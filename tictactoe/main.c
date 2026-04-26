#include <stdio.h>
#include "tictactoe.h"

int main()
{
	int ntable = -1;

	resettable();

	clearscreen();

	do  {
		printtable();
		printf("[%c] It's your turn! N: ", (isxplaying) ? 'X' : 'O');

		if ((scanf("%d", &ntable)) < 1 ||
				(ntable < 0 || ntable >= 10)) {
			printf("Valid numbers: (1-9). Number [0] to exit.\n");

			waitinput();

			clearscreen();
			continue; 
		}

		handleturn(ntable);

		if (getgamestatus() != PLAYING) {
			waitinput();
			int c;
			do {
				printf("Would you like to keep on playing? (y/n)\n");
				c = getchar();
				if (c == 'y') {
					resettable();
					nfreesquares = 9;
					ntable = -1;
					isxplaying = 1;
					break;
				} else if (c == 'n') {
					ntable = 0;
					break;
				} else {
					printf("Valid options: (y/n).\n");
				}
			} while (c != 'y' || c != 'n');
		}

		clearscreen();
	} while (ntable != 0);

	if (ntable == 0) {
		printf("Closing game...\n");
	}

	printf("\n");
	
	return 0;
}
