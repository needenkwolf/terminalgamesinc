#include <stdlib.h>
#include "tictactoe.h"

void clearscreen()
{
#ifdef __unix__
	system("clear");
#endif
#ifdef _WIN32
	system("cls");
#endif
}
