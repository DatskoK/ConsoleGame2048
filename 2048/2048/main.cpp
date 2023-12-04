#include <iostream>
#include <conio.h>
#include "Displayable.h"
#include "ScoreCounter.h"
#include "GameBoard.h"
#include "InputManager.h"
#include"Game2048.h"
using namespace std;

int main()
{
    Game2048 game;
    game.run();
    return 0;
}