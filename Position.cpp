#include "Position.h"

Position::Position(): x(0), y(0)
{
}

void Position::Set(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Position::getX()
{
	return this->x;
}

int Position::getY()
{
	return this->y;
}

Position::~Position()
{
}
