#pragma once

class Block {
public:
	Block() : _value(0) {};
	explicit Block(int val) : _value(val) {};
	int getValue() const { return _value; }
	void merge();
private:
	int _value;
};
