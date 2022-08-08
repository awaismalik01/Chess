#include "Elephant.h"
#include"Board.h"
Elephant::Elephant()
{
	Loc.Set(0, 0);
}

Elephant::Elephant(int x, int y, bool color):Piece(x, y, color), Name("Elephant"), IsMove(false)
{
}

int Elephant::Black()
{
	return this->TotalBlack;
}

int Elephant::White()
{
	return this->TotalWhite;
}

bool Elephant::DidMove()
{
	return this->IsMove;
}

bool Elephant::IsLegalMove(int x2, int y2, bool ptr, bool opt)
{
	if (Loc.getX() == x2 && Loc.getY() != y2)
	{
		if (ptr)
		{
			if (this->color != opt)
				return true;
			else
				return false;
		}
		else
			return true;
	}
	else if (Loc.getY() == y2 && Loc.getX() != x2)
	{
		if (ptr)
		{
			if (this->color != opt)
				return true;
			else
				return false;
		}
		else
			return true;
	}
	return false;
}

bool Elephant::getColor()
{
	return this->color;
}

void Elephant::move(int c, int r)
{
	this->Loc.Set(c, r);
	if (this->IsMove == false)
		this->IsMove = true;
}

void Elephant::Draw()
{
	int b = (getmaxy() - 110) / 8;
	int X = Loc.getX();
	int Y = Loc.getY();

	if (color == 0)
	{
		readimagefile("EB.jpg", 15 + b * X, 15 + b * Y, 70 + b * X, 70 + b * Y);
	}
	if (color == 1)
	{
		readimagefile("EW.jpg", 15 + b * X, 15 + b * Y, 70 + b * X, 70 + b * Y);
	}
}

string Elephant::GetName()
{
	return this->Name;
}

Elephant::~Elephant()
{
	if (color)
		this->TotalWhite--;
	else
		this->TotalBlack--;
	cout << "Elephant terminated" << endl;
}
