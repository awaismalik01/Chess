#pragma once
#include"Position.h"
#include<iostream>
#include<string.h>
#include "graphics.h"
using namespace std;
class Piece
{
protected:
	static int TotalBlack;
	static int TotalWhite;
	Position Loc;
	bool color;
public:
	Piece();
	Piece(int, int, bool);
	virtual int Black() = 0;
	virtual int White() = 0;
	virtual void IncBlack();
	virtual void IncWhite();
	virtual bool DidMove();
	virtual void Unmove();
	virtual bool PawnPromotion();
	virtual bool IsLegalMove(int, int, bool, bool) = 0;
	virtual void move(int, int) = 0;
	virtual void Draw() = 0;
	virtual bool getColor() = 0;
	virtual string GetName() = 0;
	virtual ~Piece() = 0;
};
