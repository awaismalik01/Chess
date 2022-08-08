#include "Horse.h"

Horse::Horse()
{
	Loc.Set(0, 0);
}

Horse::Horse(int x, int y, bool color):Piece(x, y, color), Name("Horse")
{
	
}

int Horse::Black()
{
	return this->TotalBlack;
}

int Horse::White()
{
	return this->TotalWhite;
}

bool Horse::IsLegalMove(int x2, int y2, bool ptr, bool opt)
{

	if ((((Loc.getX() == x2 - 1 || Loc.getX() == x2 + 1) && (this->Loc.getY() == y2 + 2 || this->Loc.getY() == y2 - 2)) || ((Loc.getX() == x2 - 2 || Loc.getX() == x2 + 2) && (this->Loc.getY() == y2 + 1 || this->Loc.getY() == y2 - 1))))
	{
		if (ptr == true)
		{
			if (this->color != opt)
				return true;
			else
				return false;
		}
		else
			return true;

	}
	else
		return false;
}

void Horse::move(int c, int r)
{
	this->Loc.Set(c, r);
}

bool Horse::getColor()
{
	return this->color;
}

void Horse::Draw()
{
	int b = (getmaxy() - 110) / 8;
	int X = Loc.getX();
	int Y = Loc.getY();

	if (color == 0)
	{
		readimagefile("HB.jpg", 15 + b * X, 15 + b * Y, 70 + b * X, 70 + b * Y);
	}
	if (color == 1)
	{
		readimagefile("HW.jpg", 15 + b * X, 15 + b * Y, 70 + b * X, 70 + b * Y);
	}
}

string Horse::GetName()
{
	return this->Name;
}

Horse::~Horse()
{
	if (color)
		this->TotalWhite--;
	else
		this->TotalBlack--;
	cout << "Horse terminated" << endl;
}
