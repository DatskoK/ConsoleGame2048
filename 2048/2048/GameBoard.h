#pragma once
#include "Displayable.h"
#include "Block.h"
#include "ScoreCounter.h"
#include <iostream>

class GameBoard : public Displayable
{
public:
	GameBoard(ScoreCounter &scoreCounter_);
	void display() override;
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void addBlock();
	bool isGameOver();
private:
	void merger();
	Block board[4][4];
	ScoreCounter &scoreCounter_;
};

