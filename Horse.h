#pragma once
#include "Piece.h"
class Horse :
	public Piece
{
protected:
	Position P;
	string Name;
public:
	Horse();
	Horse(int, int, bool);
	int Black() override;
	int White() override;
	bool IsLegalMove(int, int, bool, bool) override;
	void move(int, int) override;
	bool getColor() override;
	void Draw() override;
	string GetName() override;
	~Horse() override;
};

