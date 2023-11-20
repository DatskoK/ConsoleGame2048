#pragma once
#include "Displayable.h"
#include <iostream>

class ScoreCounter : public Displayable
{
public:
	ScoreCounter();
	~ScoreCounter();
	void updateScore(int points);
	int getScore();
	void display() override;
private:
	int score;
};

