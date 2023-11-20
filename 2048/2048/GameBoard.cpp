#include "GameBoard.h"

GameBoard::GameBoard(ScoreCounter &scoreCounter_) : scoreCounter_(scoreCounter_)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			board[i][j] = Block();
		}
		addBlock();
		addBlock();
	}
}

void GameBoard::display()
{
	std::cout << "GameBoard\n";
}

void GameBoard::moveUp()
{
}

void GameBoard::moveDown()
{
}

void GameBoard::moveLeft()
{
}

void GameBoard::moveRight()
{
}

void GameBoard::addBlock()
{
}

bool GameBoard::isGameOver()
{
	return false;
}

void GameBoard::merger()
{
}
