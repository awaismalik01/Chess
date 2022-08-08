#include "Piece.h"

Piece::Piece():color(1)
{
}

int Piece::TotalBlack = 16;
int Piece::TotalWhite = 16;

Piece::Piece(int x, int y, bool color):color(color) 
{
	Loc.Set(x, y);
}

int Piece::Black()
{
	return this->TotalBlack;
}

int Piece::White()
{
	return this->TotalWhite;
}

void Piece::IncBlack()
{
	this->TotalBlack++;
}

void Piece::IncWhite()
{
	this->TotalWhite++;
}

bool Piece::DidMove()
{
	return false;
}

void Piece::Unmove()
{
}

bool Piece::PawnPromotion()
{
	return false;
}

bool Piece::IsLegalMove(int, int, bool, bool)
{
	return false;
}

void Piece::move(int, int)
{
}

void Piece::Draw()
{
}

bool Piece::getColor()
{
	return false;
}

string Piece::GetName()
{
	return string();
}

Piece::~Piece()
{
}
