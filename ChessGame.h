#pragma once
#include"Board.h"
class ChessGame
{
	Board ChessBoard;
	bool turn;
public:
	ChessGame();
	void StartGame();
	~ChessGame();
};

