#include "King.h"

King::King()
{
	Loc.Set(0, 0);
}

King::King(int x, int y, bool color) :Piece(x, y, color), Name("King"), IsMove(false)
{

}

int King::Black()
{
	return this->TotalBlack;
}

int King::White()
{
	return this->TotalWhite;
}

bool King::DidMove()
{
	return this->IsMove;
}

bool King::IsLegalMove(int x2, int y2, bool ptr, bool opt)
{
	int x = 0, y = 0;
	x = Loc.getX() - x2;
	y = Loc.getY() - y2;

	if (this->IsMove == false)
	{
		if (!ptr)
		{
			if (Loc.getY() == y2 && ((Loc.getX() + 2) == x2 || (Loc.getX() - 2) == x2))
				return true;
		}
	}

	if (Loc.getY() == y2)
	{
		if (Loc.getX() == x2 - 1 || Loc.getX() == x2 + 1)
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
	}
	else if (Loc.getX() == x2)
	{

		if (Loc.getY() == y2 - 1 || Loc.getY() == y2 + 1)
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

	}
	else if (x == y)
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
	else if (x == -y)
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
	
	return false;
	
}

void King::move(int c, int r)
{
	this->Loc.Set(c, r);
	if (this->IsMove == false)
		this->IsMove = true;
}

bool King::getColor()
{
	return this->color;
}


void King::Draw()
{
	int b = (getmaxy() - 110) / 8;
	int X = Loc.getX();
	int Y = Loc.getY();

	if (color == 0)
	{
		readimagefile("KB.jpg", 15 + b * X, 15 + b * Y, 70 + b * X, 70 + b * Y);
	}
	if (color == 1)
	{
		readimagefile("KW.jpg", 15 + b * X, 15 + b * Y, 70 + b * X, 70 + b * Y);
	}
}

string King::GetName()
{
	return this->Name;
}

King::~King()
{
	if (color)
		this->TotalWhite = 0;
	else
		this->TotalBlack = 0;
	cout << "king terminated" << endl;
}
