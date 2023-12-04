#include "Game2048.h"

Game2048::Game2048() : gameBoard(&scoreCounter)
{
	displayable.push_back(&scoreCounter);
	displayable.push_back(&gameBoard);
}

void Game2048::run()
{
    cout << "\n\n\n\n\t\t\t2048 GAME\n\n\n\t\tPress any key to continue";
    int ch = _getch();
    system("cls");

    display();

    Input input;
    while (true) {
        input = inputManager.getInput();
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

        if (gameBoard.isGameOver()) {
            cout << "\n\n\t\t\tGAME OVER!!\n\n\n";
            return;
        }
    }
}

void Game2048::display()
{
    cout << "\n\t\tPress Esc anytime to quit the game";
    cout << "\n\n";

	for (Displayable* displayable_ : displayable) {
		displayable_->display();
}
}
