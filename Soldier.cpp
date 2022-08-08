#include "Soldier.h"

Soldier::Soldier()
{
	Loc.Set(0, 0);
	IsMove = false;
}

Soldier::Soldier(int x, int y, bool color):Piece(x, y, color), IsMove(false), Name("Soldier")
{
	
}

int Soldier::Black()
{
	return this->TotalBlack;
}

int Soldier::White()
{
	return this->TotalWhite;
}

bool Soldier::PawnPromotion()
{
	if (this->color == false)
	{
		if (Loc.getY() == 7)
		{
			cout << "BLACK IS PROMOTED" << endl;
			return true;
		}
	}
	else
	{
		if (Loc.getY() == 0)
		{
			cout << "White IS PROMOTED" << endl;
			return true;
		}
	}
	return false;
}

bool Soldier::DidMove()
{
	return IsMove;
}

void Soldier::Unmove()
{
	this->IsMove = false;
}

bool Soldier::IsLegalMove(int x2, int y2, bool ptr, bool opt)
{
	if (this->color == true)
	{
		if (ptr == true && (Loc.getX() == x2 - 1 || Loc.getX() == x2 + 1) && this->Loc.getY() == y2 + 1 && this->color != opt)
			return true;
		else if (this->IsMove == false)
		{
			if ((this->Loc.getY() == y2 + 2 || this->Loc.getY() == y2 + 1) && Loc.getX() == x2 && ptr == false)
				return true;
			else
				return false;
		}
		else
		{
			if (this->Loc.getY() == y2 + 1 && Loc.getX() == x2 && ptr == false)
				return true;
			else
				return false;
		}
	}
	else
	{
		if (ptr == true && (Loc.getX() == x2 - 1 || Loc.getX() == x2 + 1) && this->Loc.getY() == y2 - 1 && this->color != opt)
			return true;
		else if (this->IsMove == false)
		{
			if ((this->Loc.getY() + 2 == y2 || this->Loc.getY() + 1 == y2) && Loc.getX() == x2 && ptr == false)
				return true;
			else
				return false;
		}
		else
		{
			if (this->Loc.getY() + 1 == y2 && Loc.getX() == x2 && ptr == false)
				return true;
			else
				return false;
		}
	}
	
}

bool Soldier::getColor()
{
	return this->color;
}

void Soldier::move(int c, int r)
{
	this->Loc.Set(c, r);
	if (this->IsMove == false)
		this->IsMove = true;
}
void Soldier::Draw()
{
	int b = (getmaxy() - 110) / 8;
	int X = Loc.getX();
	int Y = Loc.getY();

	if (color == 0)
	{
		readimagefile("SB.jpg", 15 + b * X, 15 + b * Y, 70 + b * X, 70 + b * Y);
	}
	if (color == 1)
	{
		readimagefile("SW.jpg", 15 + b * X, 15 + b * Y, 70 + b * X, 70 + b * Y);
	}
}

string Soldier::GetName()
{
	return this->Name;
}

Soldier::~Soldier()
{
	if (color)
		this->TotalWhite--;
	else
		this->TotalBlack--;
	cout << "Soilder terminated" << endl;
}
