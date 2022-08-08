#include "Queen.h"

Queen::Queen()
{
	Loc.Set(0, 0);
}

Queen::Queen(int x, int y, bool color):Piece(x, y, color), Name("Queen")
{	
}

int Queen::Black()
{
	return this->TotalBlack;
}

int Queen::White()
{
	return this->TotalWhite;
}

bool Queen::IsLegalMove(int x2, int y2, bool ptr, bool opt)
{
	int x = 0, y = 0;
	x = Loc.getX() - x2;
	y = Loc.getY() - y2;

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
	else if (x == y)
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

void Queen::move(int c, int r)
{
	this->Loc.Set(c, r);
}

void Queen::Draw()
{
	int b = (getmaxy() - 110) / 8;
	int X = Loc.getX();
	int Y = Loc.getY();
	
	if (color == 0)
	{
		readimagefile("QB.jpg", 15 + b * X, 15 + b * Y, 70 + b * X, 70 + b * Y);
	}
	if (color == 1)
	{
		readimagefile("QW.jpg", 15 + b * X, 15 + b * Y, 70 + b * X, 70 + b * Y);
	}
}

bool Queen::getColor()
{
	return this->color;
}

string Queen::GetName()
{
	return this->Name;
}

Queen::~Queen()
{
	if (color)
		this->TotalWhite--;
	else
		this->TotalBlack--;
	cout << "Queen terminated" << endl;
}
