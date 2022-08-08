#pragma once
#include "graphics.h"
#include"Piece.h"
#include"King.h"
#include"Queen.h"
#include"Horse.h"
#include"Elephant.h"
#include"Bishap.h"
#include"Soldier.h"

class Board
{
protected:
	Piece* B[8][8];
	Position old;
	Position now;
	bool UNDO;
	int b;
	bool Played;
public:
	Board();
	void move(int, int, int, int);
	bool DidMove();
	void Undo();
	bool DidUndo();
	bool PathClear(int, int, int, int);
	bool DecideTurn(int, int, bool);
	bool CorrectSpot(int, int);
	void HighLightSource(int, int);
	void HighLightDestination(int, int);
	int GetBlack();
	int GetWhite();
	void Draw();
	~Board();
};

