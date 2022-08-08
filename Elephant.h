#pragma once
#include "Piece.h"
class Elephant :
	public Piece
{
protected:
	Position P;
	bool IsMove;
	string Name;
public:
	Elephant();
	Elephant(int, int, bool);
	int Black() override;
	int White() override;
	bool DidMove();
	bool IsLegalMove(int, int, bool, bool) override;
	bool getColor() override;
	void move(int, int) override;
	void Draw() override;
	string GetName() override;
	~Elephant() override;
};

