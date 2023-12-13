#include "Messages.h"
#include <iostream>

void Messages::gameWin()
{
	std::cout << "\n\n\t\t\tGAME WIN!!\n\n\n";
}

void Messages::gameOver()
{
	std::cout << "\n\n\t\t\tGAME OVER!!\n\n\n";
}

void Messages::exit()
{
	std::cout << "\n\t\tPress Esc anytime to quit the game";
	std::cout << "\n\n";
}

void Messages::start()
{
	std::cout << "\n\n\n\n\t\t\t2048 GAME\n\n\n\t\tPress any key to continue";
}
