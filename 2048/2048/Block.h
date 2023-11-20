#pragma once

class Block {
public:
	Block();
	Block(int val);
	~Block();
	void move();
	bool isEmpty();
private:
	int value;
	int size;
};
