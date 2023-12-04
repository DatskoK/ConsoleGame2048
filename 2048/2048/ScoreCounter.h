#pragma once
#include "Displayable.h"
#include <iostream>

class ScoreCounter : public Displayable
{
public:
	ScoreCounter() : _score(0) {};
	~ScoreCounter() {};
	int updateScore(int score);
	int getScore() const { return _score; }
	void display() override;
private:
	int _score;
};

