#include "ScoreCounter.h"

int ScoreCounter::updateScore(int score)
{
	return _score += score;
}

void ScoreCounter::display()
{
	std::cout << "\t\tScoreBoard " << _score << "\n\n";
}

