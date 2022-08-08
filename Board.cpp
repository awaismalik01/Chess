#include "Board.h"

Board::Board():Played(false), UNDO(true)
{
	this->b = (getmaxy() - 110) / 8;
	for (int r = 2; r <= 5; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			B[r][c] = nullptr;
		}
	}

	for (int i = 0; i < 8; i++)
	{
		B[1][i] = new Soldier(i, 1, 0);			//0 is black.
		B[6][i] = new Soldier(i, 6, 1);			//1 is white.
	}
	
	B[0][0] = new Elephant(0, 0, 0);
	B[0][7] = new Elephant(7, 0, 0);
	B[7][0] = new Elephant(0, 7, 1);
	B[7][7] = new Elephant(7, 7, 1);

	B[0][1] = new Horse(1, 0, 0);
	B[0][6] = new Horse(6, 0, 0);
	B[7][1] = new Horse(1, 7, 1);
	B[7][6] = new Horse(6, 7, 1);

	B[0][2] = new Bishap(2, 0, 0);
	B[0][5] = new Bishap(5, 0, 0);
	B[7][2] = new Bishap(2, 7, 1);
	B[7][5] = new Bishap(5, 7, 1);

	B[0][4] = new King(4, 0, 0);
	B[7][4] = new King(4, 7, 1);

	B[0][3] = new Queen(3, 0, 0);
	B[7][3] = new Queen(3, 7, 1);
}

void Board::move(int Sr, int Sc, int Dr, int Dc)
{
	cout << "Sorce Co-ordinates" << endl;
	cout << Sr << " " << Sc << endl;
	cout << "Destination Co-ordinates" << endl;
	cout << Dr << " " << Dc << endl;
	bool ptr = 0;
	bool opt = 0;

	if (B[Dr][Dc] != nullptr)
	{
		ptr = 1;
		opt = B[Dr][Dc]->getColor();
	}
	else
		ptr = 0;
	bool path = true;
	if (B[Sr][Sc] != nullptr)
	{
		if (B[Sr][Sc]->GetName() == "Elephant" || B[Sr][Sc]->GetName() == "Bishap" || B[Sr][Sc]->GetName() == "Queen" || B[Sr][Sc]->GetName() == "King")
		{
			if (PathClear(Sc, Sr, Dc, Dr))
				path = true;
			else
				path = false;
		}
	}

	bool castling = false;

	if (B[Sr][Sc] != nullptr)
	{
		if (B[Sr][Sc]->GetName() == "King" && B[Sr][Sc]->DidMove() == false)
		{
			if (B[Dr][Dc + 1] != nullptr)
			{
				if (B[Dr][Dc + 1]->GetName() == "Elephant")
				{
					if (B[Dr][Dc + 1]->DidMove() == false)
					{
						if (PathClear(Sc, Sr, Dc, Dr))
						{
							path = true;
							castling = true;
						}
						else
						{
							path = false;
							castling = false;
						}
					}
					else
					{
						path = false;
						castling = false;
					}
				}
			}

			if (B[Dr][Dc - 2] != nullptr)
			{
				if (B[Dr][Dc - 2]->GetName() == "Elephant")
				{
					if (B[Dr][Dc - 2]->DidMove() == false)
					{
						if (PathClear(Sc, Sr, Dc, Dr))
						{
							path = true;
							castling = true;
						}
						else
						{
							path = false;
							castling = false;
						}
					}
					else
					{
						path = false;
						castling = false;
					}
				}
			}
		}
	}

	

	if ((Sc != Dc || Sr != Dr) && B[Sr][Sc] != nullptr && B[Sr][Sc]->IsLegalMove(Dc, Dr, ptr, opt) && path)
	{
		old.Set(Sc, Sr);					//previous turn saved.
		now.Set(Dc, Dr);
		UNDO = false;
		if ((Sc + Sr) % 2 == 0)
		{
			setfillstyle(1, 4);
		}
		else
		{
			setfillstyle(1, 9);
		}
		bar(Sc * b, Sr * b, (Sc + 1) * b, (Sr + 1) * b);

		line(Sc * b, Sr * b, Sc * b, (Sr + 1) * b);
		line(Sc * b, Sr * b, (Sc + 1) * b, Sr * b);
		line(Sc * b, (Sr + 1) * b, (Sc + 1) * b, (Sr + 1) * b);
		line((Sc + 1) * b, Sr * b, (Sc + 1) * b, (Sr + 1) * b);

		B[Sr][Sc]->move(Dc, Dr);		//(x, y)
		if (B[Dr][Dc] != nullptr)
		{
			B[Dr][Dc]->~Piece();
		}
		B[Dr][Dc] = nullptr;
		
		B[Dr][Dc] = B[Sr][Sc];
		B[Sr][Sc] = nullptr;
		B[Dr][Dc]->Draw();
		this->Played = true;

		if (B[Dr][Dc] != nullptr)
		{
			if (B[Dr][Dc]->GetName() == "Soldier")
			{
				int x = 0, y = 0;
				if (B[Dr][Dc]->PawnPromotion())
				{

					if (B[Dr][Dc]->getColor() == true)
					{

						readimagefile("HW.jpg", 0 * b, 8 * b, 2 * b, 9 * b + 15);
						readimagefile("EW.jpg", 2 * b, 8 * b, 4 * b, 9 * b + 15);
						readimagefile("BW.jpg", 4 * b, 8 * b, 6 * b, 9 * b + 15);
						readimagefile("QW.jpg", 6 * b, 8 * b, 8 * b, 9 * b + 15);

						while (1)
						{
							getmouseclick(WM_LBUTTONDOWN, x, y);
							if (y != -1 && x != -1)
							{
								x /= b;
								y /= b;
								if ((x == 0 || x == 1) && y == 8)
								{
									B[Dr][Dc]->~Piece();
									B[Dr][Dc] = new Horse(Dc, Dr, 1);
									cout << "Horse" << endl;
								}

								if ((x == 2 || x == 3) && y == 8)
								{
									B[Dr][Dc]->~Piece();
									B[Dr][Dc] = new Elephant(Dc, Dr, 1);
									cout << "Elephant" << endl;
								}

								if ((x == 4 || x == 5) && y == 8)
								{
									B[Dr][Dc]->~Piece();
									B[Dr][Dc] = new Bishap(Dc, Dr, 1);
									cout << "Bishap" << endl;
								}

								if ((x == 6 || x == 7) && y == 8)
								{
									B[Dr][Dc]->~Piece();
									B[Dr][Dc] = new Queen(Dc, Dr, 1);
									cout << "Queen" << endl;
								}
								break;
							}
						}
						cout << B[Dr][Dc]->White() << endl;
						B[Dr][Dc]->IncWhite();
						cout << B[Dr][Dc]->White() << endl;
						B[Dr][Dc]->Draw();

						readimagefile("Undo.jpg", 7 * b, 8 * b, 8 * b, 9 * b + 15);
					}
					else
					{
						readimagefile("HB.jpg", 0 * b, 8 * b, 2 * b, 9 * b + 15);
						readimagefile("EB.jpg", 2 * b, 8 * b, 4 * b, 9 * b + 15);
						readimagefile("BB.jpg", 4 * b, 8 * b, 6 * b, 9 * b + 15);
						readimagefile("QB.jpg", 6 * b, 8 * b, 8 * b, 9 * b + 15);

						while (1)
						{
							getmouseclick(WM_LBUTTONDOWN, x, y);
							if (y != -1 && x != -1)
							{
								x /= b;
								y /= b;
								if ((x == 0 || x == 1) && y == 8)
								{
									B[Dr][Dc]->~Piece();
									B[Dr][Dc] = new Horse(Dc, Dr, 0);
									cout << "Horse" << endl;
								}

								if ((x == 2 || x == 3) && y == 8)
								{
									B[Dr][Dc]->~Piece();
									B[Dr][Dc] = new Elephant(Dc, Dr, 0);
									cout << "Elephant" << endl;
								}

								if ((x == 4 || x == 5) && y == 8)
								{
									B[Dr][Dc]->~Piece();
									B[Dr][Dc] = new Bishap(Dc, Dr, 0);
									cout << "Bishap" << endl;
								}

								if ((x == 6 || x == 7) && y == 8)
								{
									B[Dr][Dc]->~Piece();
									B[Dr][Dc] = new Queen(Dc, Dr, 0);
									cout << "Queen" << endl;
								}
								break;
							}
						}

						cout << B[Dr][Dc]->Black() << endl;
						B[Dr][Dc]->IncBlack();
						cout << B[Dr][Dc]->Black() << endl;
						B[Dr][Dc]->Draw();
						readimagefile("Undo.jpg", 7 * b, 8 * b, 8 * b, 9 * b + 15);
					}
				}
			}
		}

		if (castling)
		{
			if (Dc == 6)
			{
				cout << "Right" << endl;
				if (B[Dr][Dc + 1] != nullptr)
				{

					if ((Dc + Dr + 1) % 2 == 0)
					{
						setfillstyle(1, 4);
					}
					else
					{
						setfillstyle(1, 9);
					}
					bar((Dc + 1) * b, Dr * b, (Dc + 2) * b, (Dr + 1) * b);

					line((Dc + 1) * b, Dr * b, (Dc + 1) * b, (Dr + 1) * b);
					line((Dc + 1) * b, Dr * b, (Dc + 2) * b, Dr * b);
					line((Dc + 1) * b, (Dr + 1) * b, (Dc + 2) * b, (Dr + 1) * b);
					line((Dc + 2) * b, Dr * b, (Dc + 2) * b, (Dr + 1) * b);

					B[Dr][Dc + 1]->move(Dc - 1, Dr);
					B[Dr][Dc - 1] = B[Dr][Dc + 1];
					B[Dr][Dc + 1] = nullptr;
					B[Dr][Dc - 1]->Draw();
				}
			}
			if (Dc == 2)
			{
				cout << "Left" << endl;
				if (B[Dr][Dc - 2] != nullptr)
				{

					if ((Dc + Dr - 2) % 2 == 0)
					{
						setfillstyle(1, 4);
					}
					else
					{
						setfillstyle(1, 9);
					}
					bar((Dc - 2) * b, Dr * b, (Dc - 1) * b, (Dr + 1) * b);

					line((Dc - 2) * b, Dr * b, (Dc - 2) * b, (Dr + 1) * b);
					line((Dc - 2) * b, Dr * b, (Dc - 1) * b, Dr * b);
					line((Dc - 2) * b, (Dr + 1) * b, (Dc - 1) * b, (Dr + 1) * b);
					line((Dc - 1) * b, Dr * b, (Dc - 1) * b, (Dr + 1) * b);

					B[Dr][Dc - 2]->move(Dc + 1, Dr);
					B[Dr][Dc + 1] = B[Dr][Dc - 2];
					B[Dr][Dc - 2] = nullptr;
					B[Dr][Dc + 1]->Draw();
				}
			}
		}
		
	}
	else
	{
		if ((Sc + Sr) % 2 == 0)
		{
			setfillstyle(1, 4);
		}
		else
		{
			setfillstyle(1, 9);
		}
		bar(Sc * b, Sr * b, (Sc + 1) * b, (Sr + 1) * b);
		line(Sc * b, Sr * b, Sc * b, (Sr + 1) * b);
		line(Sc * b, Sr * b, (Sc + 1) * b, Sr * b);
		line(Sc * b, (Sr + 1) * b, (Sc + 1) * b, (Sr + 1) * b);
		line((Sc + 1) * b, Sr * b, (Sc + 1) * b, (Sr + 1) * b);
		B[Sr][Sc]->Draw();
		this->Played = false;
		cout << "Illegal Move....." << endl;
	}
}

bool Board::DidMove()
{
	return this->Played;
}

void Board::Undo()
{
	int Sc = 0, Sr = 0;
	Sc = now.getX();
	Sr = now.getY();

	if ((Sc + Sr) % 2 == 0)
	{
		setfillstyle(1, 4);
	}
	else
	{
		setfillstyle(1, 9);
	}
	
	bar(Sc * b, Sr * b, (Sc + 1) * b, (Sr + 1) * b);

	line(Sc * b, Sr * b, Sc * b, (Sr + 1) * b);
	line(Sc * b, Sr * b, (Sc + 1) * b, Sr * b);
	line(Sc * b, (Sr + 1) * b, (Sc + 1) * b, (Sr + 1) * b);
	line((Sc + 1) * b, Sr * b, (Sc + 1) * b, (Sr + 1) * b);

	B[Sr][Sc]->move(old.getX(), old.getY());
	B[old.getY()][old.getX()] = B[Sr][Sc];
	B[Sr][Sc] = nullptr;
	B[old.getY()][old.getX()]->Draw();
	if (B[old.getY()][old.getX()]->GetName() == "Soldier")
	{
		if (old.getY() == 6 && B[old.getY()][old.getX()]->getColor() == true)
		{
			B[old.getY()][old.getX()]->Unmove();
		}
		if (old.getY() == 1 && B[old.getY()][old.getX()]->getColor() == false)
		{
			B[old.getY()][old.getX()]->Unmove();
		}
	}
	UNDO = true;
}

bool Board::DidUndo()
{
	return this->UNDO;
}

bool Board::PathClear(int x1, int y1, int x2, int y2)
{
	if (y1 == y2)
	{
		if (x1 < x2)
		{
			for (int i = x1 + 1; i < x2; i++)
			{
				if (B[y1][i] != nullptr)
					return false;
			}
		}
		else if (x1 > x2)
		{
			for (int i = x1 - 1; i > x2; i--)
			{
				if (B[y1][i] != nullptr)
					return false;
			}
		}
		else
			return false;
	}
	else if (x1 == x2)
	{
		if (y1 < y2)
		{
			for (int i = y1 + 1; i < y2; i++)
			{
				if (B[i][x1] != nullptr)
					return false;
			}
		}
		else if (y1 > y2)
		{
			for (int i = y1 - 1; i > y2; i--)
			{
				if (B[i][x1] != nullptr)
					return false;
			}
		}
		else
			return false;
	}
	else if (x1 < x2 && y1 < y2)
	{
		for (int i = x1 + 1, j = y1 + 1; i < x2 && j < y2; i++, j++)
		{
			if (B[j][i] != nullptr)
				return false;
		}
	}
	else if (x1 > x2 && y1 > y2)
	{
		for (int i = x1 - 1, j = y1 - 1; i > x2 && j > y2; i--, j--)
		{
			if (B[j][i] != nullptr)
				return false;
		}
	}
	else if (x1 < x2 && y1 > y2)
	{
		for (int i = x1 + 1, j = y1 - 1; i < x2 && j > y2; i++, j--)
		{
			if (B[j][i] != nullptr)
				return false;
		}
	}
	else if (x1 > x2 && y1 < y2)
	{
		for (int i = x1 - 1, j = y1 + 1; i > x2 && j < y2; i--, j++)
		{
			if (B[j][i] != nullptr)
				return false;
		}
	}
	return true;
}

bool Board::DecideTurn(int Sr, int Sc, bool turn)
{
	if (B[Sr][Sc]->getColor() == turn)
		return true;
	else
		return false;
}

bool Board::CorrectSpot(int Sr, int Sc)
{
	if ((Sr <= 7 && Sc <= 7 )&& B[Sr][Sc] != nullptr)
		return true;
	else
		return false;
}

void Board::HighLightSource(int j, int i)
{
	setfillstyle(1, 1);
	bar(i * b, j * b, (i + 1) * b, (j + 1) * b);
	line(i * b, j * b, i * b, (j + 1) * b);
	line(i * b, j * b, (i + 1) * b, j * b);
	line(i * b, (j + 1) * b, (i + 1) * b, (j + 1) * b);
	line((i + 1) * b, j * b, (i + 1) * b, (j + 1) * b);
	B[j][i]->Draw();

}

void Board::HighLightDestination(int j, int i)
{
	if (B[j][i] == nullptr)
	{
		setfillstyle(1, 6);
		bar(i * b, j * b, (i + 1) * b, (j + 1) * b);
		line(i * b, j * b, i * b, (j + 1) * b);
		line(i * b, j * b, (i + 1) * b, j * b);
		line(i * b, (j + 1) * b, (i + 1) * b, (j + 1) * b);
		line((i + 1) * b, j * b, (i + 1) * b, (j + 1) * b);
	}
	else
	{
		setfillstyle(1, 4);
		bar(i * b, j * b, (i + 1) * b, (j + 1) * b);
		line(i * b, j * b, i * b, (j + 1) * b);
		line(i * b, j * b, (i + 1) * b, j * b);
		line(i * b, (j + 1) * b, (i + 1) * b, (j + 1) * b);
		line((i + 1) * b, j * b, (i + 1) * b, (j + 1) * b);
		B[j][i]->Draw();
	}

	
}

int Board::GetBlack()
{
	for (int i = 0; i < 8 * 8; i++)
	{
		if (B[i / 8][i % 8] != nullptr)
		{
			return B[i / 8][i % 8]->Black();
		}
	}
	
}

int Board::GetWhite()
{
	for (int i = 0; i < 8 * 8; i++)
	{
		if (B[i / 8][i % 8] != nullptr)
		{
			return B[i / 8][i % 8]->White();
		}
	}
}

void Board::Draw()
{
	
	for (int j = 0; j < 8; j++)		//Coloring
	{
		for (int i = 0; i < 8; i++)
		{
			if ((i + j) % 2 == 0)
			{
				setfillstyle(1, 4);
			}
			else
			{
				setfillstyle(1, 9);
			}
			bar(i * b, j * b, (i + 1) * b, (j + 1) * b);
		}
	}

	for (int j = 0; j < 8; j++)		//border
	{
		for (int i = 0; i < 8; i++)
		{
			line(i * b, j * b, i * b, (j + 1) * b);
			line(i * b, j * b, (i + 1) * b, j * b);
			line(i * b, (j + 1) * b, (i + 1) * b, (j + 1) * b);
			line((i + 1) * b, j * b, (i + 1) * b, (j + 1) * b);
		}
	}

	for (int i = 0; i < 8; i++)
	{
		B[0][i]->Draw();					//row 8
		B[1][i]->Draw();					//row 7
		B[6][i]->Draw();					//row 2
		B[7][i]->Draw();					//row 1
	}	
}

Board::~Board()
{
}
