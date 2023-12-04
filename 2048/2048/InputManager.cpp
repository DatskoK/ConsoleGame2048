#include "InputManager.h"
#include <conio.h>

Input InputManager::getInput()
{
	int ch = _getch();
	if (ch == 0xE0 || ch == 0)
	{
		return static_cast<Input>(ch);
	}
}
