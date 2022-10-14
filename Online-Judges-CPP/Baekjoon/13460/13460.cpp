#include <iostream>
#include <vector>
#include <queue>
#include <list>

#define TIME_LIMIT 10

using namespace std;

enum CELL_TYPE {
	EMPTY, WALL, RED, BLUE, GOAL
};

enum MOVE_TYPE {
	BLOCKED = 0, PASS, REACH_GOAL
};

class Board {

	class Coordinate {
	public:
		int row;
		int col;

		Coordinate() : row(0), col(-1) {}
		Coordinate(int row, int col) : row(row), col(col) {}
		bool operator== (const Coordinate& c1) {
			return (row == c1.row && col == c1.col);
		}
	};

	class MarblesInfo {
	public:
		Coordinate redMarble;
		Coordinate blueMarble;
		int time;

		MarblesInfo(Coordinate red, Coordinate blue, int time) : redMarble(red), blueMarble(blue), time(time){}
		MarblesInfo(int red_row, int red_col, int blue_row, int blue_col, int time):
			redMarble(red_row, red_col), blueMarble(blue_row, blue_col), time(time) {}
	};

	vector<vector<int>> cellVector;
	queue<MarblesInfo> infoQueue;
	priority_queue<int, vector<int>, greater<int>> answer_list;
	int n, m;

public:
	Board() {
		string space;
		Coordinate red, blue;

		cin >> n >> m;

		cellVector.assign(n, vector<int>(m, EMPTY));

		for (int i = 0; i < n; ++i) {
			cin >> space;

			// Assign each cell

			for (int j = 0; j < m; ++j) {
				switch (space.at(j)) {
					case '#': cellVector.at(i).at(j) = WALL;
						break;
					case 'R': red = Coordinate(i, j);
						break;
					case 'B': blue = Coordinate(i, j);
						break;
					case 'O': cellVector.at(i).at(j) = GOAL;
						break;
//					case '.': cellVector.at(i).at(j).celltype = EMPTY;
					default:
						break;
				}
			}
		}

		infoQueue.push(MarblesInfo(red, blue, 0));

	}

	int isOkayToMove(Coordinate to_move) {

		if (to_move.row < 0 || to_move.row > n - 1)
			return BLOCKED;
		if (to_move.col < 0 || to_move.col > m - 1)
			return BLOCKED;

		int celltype = cellVector.at(to_move.row).at(to_move.col);
		switch (celltype) {
		case EMPTY:
			return PASS;
		case GOAL:
			return REACH_GOAL;
		default:
			return BLOCKED;
		}
	}

	void putMarbleIntoVector(Coordinate marble, int marble_color) {
		if(marble.row >= 0 && marble.col >= 0)
			cellVector.at(marble.row).at(marble.col) = marble_color;
	}

	void removeMarbleFromVector(Coordinate marble) {
		if (marble.row >= 0 && marble.col >= 0)
			cellVector.at(marble.row).at(marble.col) = EMPTY;
	}

	Coordinate move(Coordinate marble, int marble_color, int row, int col) {
		int move_type;
		int final_row = marble.row;
		int final_col = marble.col;

		while ((move_type = isOkayToMove(Coordinate(final_row + row, final_col + col))) == PASS) {
			final_row += row;
			final_col += col;
		}

		// return (-1, 0) if there's a goal reach
		if (move_type == REACH_GOAL) {
			return Coordinate(-1, 0);
		}

		return Coordinate(final_row, final_col);
	}

	void moveFirst(Coordinate red, Coordinate blue, int first_marble_color, int row, int col, int time) {

		Coordinate red_moved, blue_moved;

		if (first_marble_color == RED) {
			red_moved = move(red, RED, row, col);
			putMarbleIntoVector(red_moved, RED);
			blue_moved = move(blue, BLUE, row, col);
			removeMarbleFromVector(red_moved);
		}
		else {
			blue_moved = move(blue, BLUE, row, col);
			putMarbleIntoVector(blue_moved, BLUE);
			red_moved = move(red, RED, row, col);
			removeMarbleFromVector(blue_moved);
		}

		// if there's a move
		if (!(red == red_moved && blue == blue_moved)) {
			// if blue went to the goal
			if (blue_moved.row < 0)
				return;
			// if only red went to the goal
			if (red_moved.row < 0) {
				answer_list.push(++time);
				return;
			}
			// move the result to the new queue
			else
				infoQueue.push(MarblesInfo(red_moved, blue_moved, ++time));
		}
	}

	void moveMarbles(MarblesInfo info) {
		if (info.time >= TIME_LIMIT)
			return;

		Coordinate red = info.redMarble;
		Coordinate blue = info.blueMarble;

		Coordinate red_moved, blue_moved;

		// LEFT

		if (red.row == blue.row && red.col < blue.col)
			moveFirst(red, blue, RED, 0, -1, info.time);
		else
			moveFirst(red, blue, BLUE, 0, -1, info.time);

		// RIGHT

		if (red.row == blue.row && red.col > blue.col)
			moveFirst(red, blue, RED, 0, 1, info.time);
		else
			moveFirst(red, blue, BLUE, 0, 1, info.time);

		// UP

		if (red.col == blue.col && red.row < blue.row)
			moveFirst(red, blue, RED, -1, 0, info.time);
		else
			moveFirst(red, blue, BLUE, -1, 0, info.time);

		// DOWN

		if (red.col == blue.col && red.row > blue.row)
			moveFirst(red, blue, RED, 1, 0, info.time);
		else
			moveFirst(red, blue, BLUE, 1, 0, info.time);
	}

	int BFS() {
		MarblesInfo info = infoQueue.front();
		while (!infoQueue.empty()) {
			info = infoQueue.front();
			infoQueue.pop();
			moveMarbles(info);
		}
		if (answer_list.empty())
			return -1;
		return answer_list.top();
	}
};

int main() {
	Board board = Board();
	cout << board.BFS();

	return 0;
}