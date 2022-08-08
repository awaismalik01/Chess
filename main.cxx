#include "graphics.h"
#include <math.h>
#include <stdlib.h>                     // Provides exit
#include <ctype.h>                      // Provides toupper
#include"ChessGame.h"
int main()
{
	initwindow(700, 800, "First Sample");
	ChessGame Game;
	Game.StartGame();
	return 0;
}