#pragma once
#include "Piece.h"
class Soldier :
	public Piece
{
protected:
	Position P;
	bool IsMove;
	string Name;

public:
	Soldier();
	Soldier(int, int, bool);
	int Black() override;
	int White() override;
	bool PawnPromotion();
	bool DidMove();
	void Unmove();
	bool IsLegalMove(int, int, bool, bool)  override;
	bool getColor() override;
	void move(int, int) override;
	void Draw() override;
	string GetName() override;
	~Soldier() override;
};

