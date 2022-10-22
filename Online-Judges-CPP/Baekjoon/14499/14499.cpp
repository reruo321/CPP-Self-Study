#include <iostream>
#include <vector>

using namespace std;

enum DIRECTION { EAST = 1, WEST = 2, NORTH = 3, SOUTH = 4 };
enum DICE_DIRECTION { UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3, FRONT = 4, BACK = 5 };

/*
 
	vector<int> dice
	{ UP, DOWN, LEFT, RIGHT, FRONT, BACK }
	[ 0 ,  1  ,  2  ,   3  ,   4  ,   5  ]

*/

bool rotateDice(int direction, vector<int> &dice, int n, int m, int &x, int &y) {
	int temp = dice.at(UP);

	switch(direction) {

	case EAST:
		if (y + 1 > m - 1)
			return false;
		dice.at(UP) = dice.at(LEFT);
		dice.at(LEFT) = dice.at(DOWN);
		dice.at(DOWN) = dice.at(RIGHT);
		dice.at(RIGHT) = temp;
		++y;
		return true;
	case WEST:
		if (y - 1 < 0)
			return false;
		dice.at(UP) = dice.at(RIGHT);
		dice.at(RIGHT) = dice.at(DOWN);
		dice.at(DOWN) = dice.at(LEFT);
		dice.at(LEFT) = temp;
		--y;
		return true;
	case NORTH:
		if (x - 1 < 0)
			return false;
		dice.at(UP) = dice.at(FRONT);
		dice.at(FRONT) = dice.at(DOWN);
		dice.at(DOWN) = dice.at(BACK);
		dice.at(BACK) = temp;
		--x;
		return true;
	case SOUTH:
		if (x + 1 > n - 1)
			return false;
		dice.at(UP) = dice.at(BACK);
		dice.at(BACK) = dice.at(DOWN);
		dice.at(DOWN) = dice.at(FRONT);
		dice.at(FRONT) = temp;
		++x;
		return true;
	}
	return false;
}

void swapNumber(int &down, int &board_cell) {
	if (board_cell == 0)
		board_cell = down;
	else {
		down = board_cell;
		board_cell = 0;
	}
}

void playGame() {

	int n, m, x, y, k, command;
	vector<int> dice(6, 0);
	vector<vector<int>> map;

	cin >> n >> m >> x >> y >> k;
	map.assign(n, vector<int>(m, 0));
	for(int i=0; i<n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> map.at(i).at(j);

	for (int i = 0; i < k; ++i) {
		cin >> command;
		if (rotateDice(command, dice, n, m, x, y)) {
			swapNumber(dice.at(DOWN), map.at(x).at(y));
			cout << dice.at(UP) << endl;
		}
	}

}

int main() {
	playGame();
}