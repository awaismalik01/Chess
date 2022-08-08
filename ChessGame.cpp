#include "ChessGame.h"

ChessGame::ChessGame() :turn(1)
{
}

void ChessGame::StartGame()
{
	ChessBoard.Draw();
	int b = (getmaxy() - 110) / 8;
	int Sr = 0;
	int Sc = 0;
	int Dr = 0;
	int Dc = 0;
	readimagefile("Undo.jpg", 7 * b, 8 * b, 8 * b, 9 * b + 15);

	readimagefile("W.jpg", 0, 8 * b, 7 * b, 9 * b + 15);
	line(0, 8 * b, 8 * b, 8 * b);
	line(0, 9 * b + 15, 8 * b, 9 * b + 15);

	line(0, 8 * b, 0 * b, 9 * b + 15);
	line(8 * b, 8 * b, 8 * b, 9 * b + 15);

	while (1)
	{
		
		
		getmouseclick(WM_LBUTTONDOWN, Sc, Sr);
		if (Sr != -1 && Sc != -1)
		{

			Sr /= b;
			Sc /= b;
			cout << Sr << " "<<Sc << endl;
			if (ChessBoard.CorrectSpot(Sr, Sc))
			{
				if (ChessBoard.DecideTurn(Sr, Sc, this->turn))
				{
					ChessBoard.HighLightSource(Sr, Sc);
					while (1)
					{
						getmouseclick(WM_LBUTTONDOWN, Dc, Dr);
						if (Dr != -1 && Dc != -1)
						{
							Dc /= b;
							Dr /= b;
							if (Sr <= 7 && Sc <= 7 && Dr <= 7 && Dc <= 7)
							{
								ChessBoard.move(Sr, Sc, Dr, Dc);
								if (ChessBoard.DidMove())
								{
									if (this->turn)
										this->turn = false;
									else
										this->turn = true;
								}

								if (this->turn)
								{
									readimagefile("W.jpg", 0, 8 * b, 7 * b, 9 * b + 15);
								}
								else
								{
									readimagefile("B.jpg", 0, 8 * b, 7 * b, 9 * b + 15);
								}

								line(0, 8 * b, 8 * b, 8 * b);
								line(0, 9 * b + 15, 8 * b, 9 * b + 15);

								line(0, 8 * b, 0 * b, 9 * b + 15);
								line(8 * b, 8 * b, 8 * b, 9 * b + 15);


							}
							else
							{
								cout << "Invalid Co-ordinates" << endl;
							}
							break;
						}
					}
				}
				else
				{
					if (this->turn)
						cout << "It's White Turn" << endl;
					else
						cout << "It's Black Turn" << endl;
				}

			}
			else if (Sc == 7 && Sr == 8 && ChessBoard.DidUndo() == false)
			{
				ChessBoard.Undo();
				if (this->turn)
				{
					this->turn = false;
					readimagefile("B.jpg", 0, 8 * b, 7 * b, 9 * b + 15);
				}
				else
				{
					this->turn = true;
					readimagefile("W.jpg", 0, 8 * b, 7 * b, 9 * b + 15);
				}
				cout << "Undo" << endl;
			}
			else
				cout << "NOt allowed" << endl;
			
		}
		if (ChessBoard.GetBlack() == 0)
		{
			cout << "White Wins" << endl;
			cleardevice();
			readimagefile("WWins.jpg", 1 * b, 2 * b, 7 * b, 6 * b);
			break;
		}
		if (ChessBoard.GetWhite() == 0)
		{
			cout << "Black Wins" << endl;
			cleardevice();
			readimagefile("BWins.jpg", 1 * b, 2 * b, 7 * b, 6 * b);
			break;
		}

	}
	while (!kbhit());
}

ChessGame::~ChessGame()
{
}
