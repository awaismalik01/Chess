#pragma once
#include "Piece.h"
class Bishap :
	public Piece
{
protected:
	Position P;
	string Name;
public:
	Bishap();
	Bishap(int, int, bool);
	int Black() override;
	int White() override;
	bool IsLegalMove(int, int, bool, bool)  override;
	void move(int, int) override;
	bool getColor() override;
	void Draw() override;
	string GetName() override;
	~Bishap() override;
};

