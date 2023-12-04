#include "GameBoard.h"

using namespace std;

GameBoard::GameBoard(ScoreCounter* scoreCounter) : scoreCounter_(scoreCounter)
{
	for (int i = 0; i < scaling; i++) {
		for (int j = 0; j < scaling; j++) {
			board[i][j] = Block();
		}
	}
	addBlock();
	addBlock();
}

void GameBoard::display()
{
	int i, j;
	for (i = 0; i < scaling; i++) {
		cout << "\t\t";
		for (int n = 0; n < scaling; n++) {
			cout << "------";
		}
		cout << "-";
		cout << "\n\t\t";
		for (j = 0; j < scaling; j++) {
			if (board[i][j].isEmpty())
				cout << "| " << setw(4) << setfill(' ') << " ";
			else
				cout << "| " << setw(4) << setfill(' ') << board[i][j].getValue();
		}
		cout << "|" << endl;
	}
	cout << "\t\t";
	for (int n = 0; n < scaling; n++) {
		cout << "------";
	}
	cout << "-";
	cout << "\n";
}

void GameBoard::moveUp()
{
	int i, j, li, ri;
	for (j = 0; j < scaling; j++)
	{
		li = 0, ri = j;
		for (i = 1; i < scaling; i++)
		{
			if (board[i][j].getValue() != 0)
			{
				if (board[i - 1][j].isEmpty() || board[i - 1][j].getValue() == board[i][j].getValue())
				{
					if (board[li][ri].getValue() == board[i][j].getValue())
					{
						board[li][ri].merge();
						board[i][j].clear();
						scoreCounter_->updateScore(board[li][ri].getValue());
					}
					else
					{
						if (board[li][ri].isEmpty())
						{
							board[li][ri] = board[i][j];
							board[i][j].clear();
						}
						else
						{
							board[++li][ri] = board[i][j];
							board[i][j].clear();
						}
					}
				}
				else li++;
			}
		}
	}
	addBlock();
}

void GameBoard::moveDown()
{
	int i, j, li, ri;
	for (j = 0; j < scaling; j++)
	{
		li = scaling-1, ri = j;
		for (i = scaling-2; i >= 0; i--)
		{
			if (board[i][j].getValue() != 0)
			{
				if (board[i + 1][j].isEmpty() || board[i + 1][j].getValue() == board[i][j].getValue())
				{
					if (board[li][ri].getValue() == board[i][j].getValue())
					{
						board[li][ri].merge();
						board[i][j].clear();
						scoreCounter_->updateScore(board[li][ri].getValue());
					}
					else
					{
						if (board[li][ri].isEmpty())
						{
							board[li][ri] = board[i][j];
							board[i][j].clear();
						}
						else
						{
							board[--li][ri] = board[i][j];
							board[i][j].clear();
						}
					}
				}
				else li--;
			}
		}
	}
	addBlock();
}

void GameBoard::moveLeft()
{
	int i, j, li, ri;
	for (i = 0; i < scaling; i++)
	{
		li = i, ri = 0;
		for (j = 1; j < scaling; j++)
		{
			if (board[i][j].getValue() != 0)
			{
				if (board[i][j - 1].isEmpty() || board[i][j - 1].getValue() == board[i][j].getValue())
				{
					if (board[li][ri].getValue() == board[i][j].getValue())
					{
						board[li][ri].merge();
						board[i][j].clear();
						scoreCounter_->updateScore(board[li][ri].getValue());
					}
					else
					{
						if (board[li][ri].isEmpty())
						{
							board[li][ri] = board[i][j];
							board[i][j].clear();
						}
						else
						{
							board[li][++ri] = board[i][j];
							board[i][j].clear();
						}
					}
				}
				else ri++;
			}
		}
	}
	addBlock();
}

void GameBoard::moveRight()
{
	int i, j, li, ri;
	for (i = 0; i < scaling; i++)
	{
		li = i, ri = scaling-1;
		for (j = scaling-2; j >= 0; j--)
		{
			if (board[i][j].getValue() != 0)
			{
				if (board[i][j + 1].isEmpty() || board[i][j + 1].getValue() == board[i][j].getValue())
				{
					if (board[li][ri].getValue() == board[i][j].getValue())
					{
						board[li][ri].merge();
						board[i][j].clear();
						scoreCounter_->updateScore(board[li][ri].getValue());
					}
					else
					{
						if (board[li][ri].isEmpty())
						{
							board[li][ri] = board[i][j];
							board[i][j].clear();
						}
						else
						{
							board[li][--ri] = board[i][j];
							board[i][j].clear();
						}
					}
				}
				else ri--;
			}
		}
	}
	addBlock();
}

void GameBoard::addBlock()
{
	bool check = false;
	for (int i = 0; i < scaling; i++)
	{
		for (int j = 0; j < scaling; j++)
		{
			if (board[i][j].isEmpty())
			{
				check = true;
			}
		}
	}
	if (check)
	{
		int row, col;
		do {
			row = rand() % scaling;
			col = rand() % scaling;
		} while (!board[row][col].isEmpty());

		board[row][col] = Block(rand() % 2 == 0 ? 2 : 4);
	}
}

bool GameBoard::isGameOver()
{
	for (int i = 0; i < scaling; i++)
	{
		for (int j = 0; j < scaling; j++)
		{
			if (board[i][j].isEmpty()) 
			{
				return false;
			}
		}
	}
	for (int i = 0; i < scaling; i++)
	{
		for (int j = 0; j < scaling; j++)
		{
			if (i > 0 && board[i][j].getValue() == board[i-1][j].getValue())
			{
				return false;
			}
			if (i < scaling-1 && board[i][j].getValue() == board[i + 1][j].getValue())
			{
				return false;
			}
			if (j > 0 && board[i][j].getValue() == board[i][j - 1].getValue())
			{
				return false;
			}
			if (j < scaling-1 && board[i][j].getValue() == board[i][j + 1].getValue())
			{
				return false;
			}
		}
	}
	return true;
}

bool GameBoard::isGameWin()
{
	for (int i = 0; i < scaling; i++)
	{
		for (int j = 0; j < scaling; j++)
		{
			if (board[i][j].getValue() == 2048)
			{
				return true;
			}
		}
	}
	return false;
}
