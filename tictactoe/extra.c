#include <stdio.h>
#include "tictactoe.h"

void waitinput()
{
	/* clear buffer and wait for player input */
	while (getchar() != '\n');
	getchar();
}
