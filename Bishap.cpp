#include "Bishap.h"

Bishap::Bishap()
{
	Loc.Set(0, 0);
}

Bishap::Bishap(int x, int y, bool color):Piece(x, y, color), Name("Bishap")
{
}

int Bishap::Black()
{
	return this->TotalBlack;
}

int Bishap::White()
{
	return this->TotalWhite;
}

bool Bishap::IsLegalMove(int x2, int y2, bool ptr, bool opt)
{
	int x = 0, y = 0;
	x = Loc.getX() - x2;
	y = Loc.getY() - y2;
	cout << x << " "<<y << endl;
	if (x == y)
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
	else if (x == -y)
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
	else
		return false;
}

void Bishap::move(int c, int r)
{
	this->Loc.Set(c, r);
}

bool Bishap::getColor()
{
	return this->color;
}

void Bishap::Draw()
{
	int b = (getmaxy() - 110) / 8;
	int X = Loc.getX();
	int Y = Loc.getY();

	if (color == 0)
	{
		readimagefile("BB.jpg", 15 + b * X, 15 + b * Y, 70 + b * X, 70 + b * Y);
	}
	if (color == 1)
	{
		readimagefile("BW.jpg", 15 + b * X, 15 + b * Y, 70 + b * X, 70 + b * Y);
	}
}

string Bishap::GetName()
{
	return this->Name;
}

Bishap::~Bishap()
{
	if (color)
		this->TotalWhite--;
	else
		this->TotalBlack--;
	cout << "Bishap terminated" << endl;
}
