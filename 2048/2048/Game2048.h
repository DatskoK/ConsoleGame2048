#pragma once
#include "GameBoard.h"
#include "ScoreCounter.h"
#include "Displayable.h"
#include <vector>
#include <iostream>
#include <conio.h>
#include "Messages.h"

using namespace std;

enum class Input { UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77, ESC = 27 };

class Game2048
{
public:
	Game2048();
	void run();
private:
	void display();
	Input getInput();
	ScoreCounter scoreCounter;
	GameBoard gameBoard;
	Messages messages;
	vector<Displayable*> displayable;
};

