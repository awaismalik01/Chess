#pragma once
class Position
{
protected:
	int x;
	int y;
public:
	Position();
	void Set(int, int);
	int getX();
	int getY();
	~Position();
};

