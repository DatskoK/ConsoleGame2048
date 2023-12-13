#include "Game2048.h"

Game2048::Game2048() : gameBoard(&scoreCounter)
{
	displayable.push_back(&scoreCounter);
	displayable.push_back(&gameBoard);
}

void Game2048::run()
{
    messages.start();
    int ch = _getch();
    system("cls");

    display();

    Input input;
    while (true) {
        input = getInput();
        system("cls");
        switch (input) {
            case Input::UP: gameBoard.moveUp(); break;
            case Input::DOWN: gameBoard.moveDown(); break;
            case Input::LEFT: gameBoard.moveLeft(); break;
            case Input::RIGHT: gameBoard.moveRight(); break;
            case Input::ESC: return;
            default: break;
        }

        display();

        if (gameBoard.isGameWin())
        {
            messages.gameWin();
            return;
        }

        if (gameBoard.isGameOver()) {
            messages.gameOver();
            return;
        }
    }
}

void Game2048::display()
{
    messages.exit();
	for (Displayable* displayable_ : displayable) {
		displayable_->display();
}
}

Input Game2048::getInput()
{
    int ch = _getch();
    if (ch == 0xE0 || ch == 0)
    {
        return static_cast<Input>(ch);
    }
}
