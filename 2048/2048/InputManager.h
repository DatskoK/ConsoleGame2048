#pragma once

enum class Input {UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77, ESC = 27};

class InputManager
{
public:
	Input getInput();
};

