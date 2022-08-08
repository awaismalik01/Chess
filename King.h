#pragma once
#include "Piece.h"
class King :
	public Piece
{
protected:
	Position P;
	bool IsMove;
	string Name;

public:
	King();
	King(int, int, bool);
	int Black() override;
	int White() override;
	bool DidMove();
	bool IsLegalMove(int, int, bool, bool) override;
	void move(int, int) override;
	bool getColor() override;
	void Draw() override;
	string GetName() override;
	~King() override;
};

