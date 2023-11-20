#include "ScoreCounter.h"

ScoreCounter::ScoreCounter()
{
	score = 0;
}

ScoreCounter::~ScoreCounter()
{
}

void ScoreCounter::updateScore(int points)
{
	score += points;
}

int ScoreCounter::getScore()
{
	return score;
}

void ScoreCounter::display()
{
	std::cout << "ScoreBoard\n";
}

