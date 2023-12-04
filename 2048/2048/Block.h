#pragma once

class Block {
public:
	Block() : _value(0) {};
	explicit Block(int val) : _value(val) {};
	int getValue() const { return _value; }
	bool isEmpty() const { return _value == 0; }
	void merge();
	void clear();
private:
	int _value;
};
