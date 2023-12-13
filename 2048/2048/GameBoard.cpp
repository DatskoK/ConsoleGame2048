#include "GameBoard.h"

using namespace std;

GameBoard::GameBoard(ScoreCounter* scoreCounter) : scoreCounter_(scoreCounter)
{
	for (int i = 0; i < scaling; i++) {
		for (int j = 0; j < scaling; j++) {
			board[i][j] = nullptr;
		}
	}
	addBlock();
	addBlock();
}

void GameBoard::display()
{
		int i, j;
		for (i = 0; i < scaling; i++) {
			cout << "\t\t";
			for (int n = 0; n < scaling; n++) {
				cout << "------";
			}
			cout << "-";
			cout << "\n\t\t";
			for (j = 0; j < scaling; j++) {
				if (board[i][j] == nullptr)
					cout << "| " << setw(4) << setfill('-') << " ";
				else
					cout << "| " << setw(4) << setfill(' ') << (*board[i][j]).getValue();
			}
			cout << "|" << endl;
		}
		cout << "\t\t";
		for (int n = 0; n < scaling; n++) {
			cout << "------";
		}
		cout << "-";
		cout << "\n";
}

void GameBoard::moveUp() {
	bool canMoveUp = false;
	for (int j = 0; j < scaling; j++) {
		int k = 0;
		for (int i = 0; i < scaling; i++) {
			if (board[i][j] != nullptr) {
				while (k > 0 && board[k - 1][j]->getValue() == board[i][j]->getValue()) {
					delete board[k - 1][j];
					board[k - 1][j] = nullptr;
					board[i][j]->merge();
					k--;
					canMoveUp = true;
				} if (k != i) {
					board[k][j] = board[i][j];
					board[i][j] = nullptr;
					canMoveUp = true;
				} k++;
			}
		}
	}
	if (canMoveUp) {
		addBlock();
	}
}

void GameBoard::moveDown() {
	bool canMoveDown = false;
	for (int j = 0; j < scaling; j++) {
		int k = scaling - 1;
		for (int i = scaling - 1; i >= 0; i--) {
			if (board[i][j] != nullptr) {
				while (k < scaling - 1 && board[k + 1][j]->getValue() == board[i][j]->getValue()) {
					delete board[k + 1][j];
					board[k + 1][j] = nullptr;
					board[i][j]->merge();
					k++;
					canMoveDown = true;
				} if (k != i) {
					board[k][j] = board[i][j];
					board[i][j] = nullptr;
					canMoveDown = true;
				} k--;
			}
		}
	}
	if (canMoveDown) {
		addBlock();
	}
}

void GameBoard::moveLeft() {
	bool canMoveLeft = false;
	for (int i = 0; i < scaling; i++) {
		int k = 0;
		for (int j = 0; j < scaling; j++) {
			if (board[i][j] != nullptr) {
				while (k > 0 && board[i][k - 1]->getValue() == board[i][j]->getValue()) {
					delete board[i][k - 1];
					board[i][k - 1] = nullptr;
					board[i][j]->merge();
					k--;
					canMoveLeft = true;
				} if (k != j) {
					board[i][k] = board[i][j];
					board[i][j] = nullptr;
					canMoveLeft = true;
				} k++;
			}
		}
	}
	if (canMoveLeft) {
		addBlock();
	}
}

void GameBoard::moveRight() {
	bool canMoveRight = false;
	for (int i = 0; i < scaling; i++) {
		int k = scaling - 1;
		for (int j = scaling - 1; j >= 0; j--) {
			if (board[i][j] != nullptr) {
				while (k < scaling - 1 && board[i][k + 1]->getValue() == board[i][j]->getValue()) {
					delete board[i][k + 1];
					board[i][k + 1] = nullptr;
					board[i][j]->merge();
					k++;
					canMoveRight = true;
				} if (k != j) {
					board[i][k] = board[i][j];
					board[i][j] = nullptr;
					canMoveRight = true;
				} k--;
			}
		}
	}
	if (canMoveRight) {
		addBlock();
	}
}

void GameBoard::addBlock() {
	int i, j;
	do {
		i = rand() % scaling;
		j = rand() % scaling;
	} while (board[i][j] != nullptr);
	board[i][j] = new Block(rand() % 2 == 0 ? 2 : 4);
}

bool GameBoard::isGameOver()
{
	bool canMove = false;
	for (int i = 0; i < scaling; i++) {
		for (int j = 0; j < scaling - 1; j++) {
			if (board[i][j] == nullptr || board[i][j + 1] == nullptr || board[i][j]->getValue() == board[i][j + 1]->getValue()) {
				canMove = true;
				break;
			}
		}
		if (canMove) {
			break;
		}
	}
	if (!canMove) {
		for (int j = 0; j < scaling; j++) {
			for (int i = 0; i < scaling - 1; i++) {
				if (board[i][j] == nullptr || board[i + 1][j] == nullptr || board[i][j]->getValue() == board[i + 1][j]->getValue()) {
					canMove = true;
					break;
				}
			}
			if (canMove) {
				break;
			}
		}
	}
	return !canMove;
}

bool GameBoard::isGameWin()
{
	int winValue = 2048;
	for (int i = 0; i < scaling; i++) {
		for (int j = 0; j < scaling; j++) {
			if (board[i][j] != nullptr && board[i][j]->getValue() >= winValue) {
				return true;
			}
		}
	}
	return false;
}
