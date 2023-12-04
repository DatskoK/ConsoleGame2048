#pragma once
#include "InputManager.h"
#include "GameBoard.h"
#include "ScoreCounter.h"
#include "Displayable.h"
#include <vector>
#include <iostream>
#include <conio.h>

using namespace std;

class Game2048
{
public:
	Game2048();
	void run();
private:
	void display();
	InputManager inputManager;
	ScoreCounter scoreCounter;
	GameBoard gameBoard;
	vector<Displayable*> displayable;
};

