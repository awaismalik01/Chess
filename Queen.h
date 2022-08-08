#pragma once
#include "Piece.h"
class Queen :
	public Piece
{
protected:
	Position P;
	string Name;
public:
	Queen();
	Queen(int, int, bool);
	int Black() override;
	int White() override;
	bool IsLegalMove(int, int, bool, bool)  override;
	void move(int, int) override;
	void Draw() override;
	bool getColor() override;
	string GetName() override;
	~Queen() override;
};

