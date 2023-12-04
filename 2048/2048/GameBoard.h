#pragma once
#include "Displayable.h"
#include "Block.h"
#include "ScoreCounter.h"
#include <iostream>
#include <iomanip>

class GameBoard : public Displayable
{
public:
	GameBoard(ScoreCounter* scoreCounter);
	void display() override;
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void addBlock();
	bool isGameOver();
	bool isGameWin();
private:
	Block board[4][4];
	ScoreCounter* scoreCounter_;
};

