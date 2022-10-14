#include <iostream>
#include <vector>
#include <deque>

#define EMPTY 0
#define APPLE 1

enum { LEFT, UP, RIGHT, DOWN };

using namespace std;

class Board {
	
	class Coordinate {
	public:
		int row;
		int col;
		Coordinate() : row(0), col(0) {}
		Coordinate(int row, int col) : row(row), col(col) {}
		bool operator==(const Coordinate& c) { return (row == c.row) && (col == c.col ); }
	};

	vector<vector<int>> boardVector;
	int n;
	int time;
	int direction;
	deque<Coordinate> snake;
	bool isFinished;

public:
	
	Board() : time(0), direction(RIGHT), isFinished(false) {
		int apple_num;
		int row, col;

		snake.push_back(Coordinate());

		cin >> n;
		boardVector.assign(n, vector<int>(n, EMPTY));

		cin >> apple_num;
		for (int i = 0; i < apple_num; ++i) {
			cin >> row >> col;
			boardVector.at(row - 1).at(col - 1) = APPLE;
		}
	}
	
	void changeDirection(char rotate) {
		// L: LEFT -> DOWN -> RIGHT -> UP -> LEFT
		// D: LEFT -> UP -> RIGHT -> DOWN -> LEFT
		switch (rotate) {
			case 'L':
				--direction;
				if (direction < LEFT)
					direction = DOWN;
				break;
			case 'D':
				++direction;
				if (direction > DOWN)
					direction = LEFT;
				break;
		}
	}

	bool isThereNoSnakeBody(Coordinate cord) {
		for (auto c : snake) {
			if (cord == c)
				return false;
		}
		return true;
	}

	bool isOkayToMove() {
		Coordinate new_head = snake.front();
		Coordinate old_tail = snake.back();
		int item;

		switch (direction) {
			case LEFT:
				if (new_head.col == 0)
					return false;
				--new_head.col;
				break;
			case UP:
				if (new_head.row == 0)
					return false;
				--new_head.row;
				break;
			case RIGHT:
				if (new_head.col == n - 1)
					return false;
				++new_head.col;
				break;
			case DOWN:
				if (new_head.row == n - 1)
					return false;
				++new_head.row;
				break;
		}

		if (!isThereNoSnakeBody(new_head))
			return false;

		snake.pop_back();

		switch (boardVector.at(new_head.row).at(new_head.col)) {
			case APPLE:
				snake.push_back(old_tail);
				boardVector.at(new_head.row).at(new_head.col) = EMPTY;
			case EMPTY:
				snake.push_front(new_head);
				return true;
			default:
				return false;
		}
	}

	bool proceed(int step) {
		for (int i = 0; i < step; ++i) {
			++time;
			if (!isOkayToMove())
				return false;
		}
		return true;
	}
	
	int dummyGame() {
		int action, next_time, before_time;
		char dir;

		cin >> action;
		for (int i = 0; i < action; ++i) {
			cin >> next_time >> dir;
			before_time = time;

			if (!proceed(next_time - before_time))
				return time;

			changeDirection(dir);
		}

		while (1) {
			++time;
			if (!isOkayToMove())
				return time;
		}
	}
};

int main() {
	Board board = Board();
	cout << board.dummyGame() << endl;

	return 0;
}