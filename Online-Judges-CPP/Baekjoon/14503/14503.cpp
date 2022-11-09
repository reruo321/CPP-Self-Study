#include <iostream>
#include <vector>

using namespace std;

enum DIR{ UP = 0, RIGHT, DOWN, LEFT };

struct Coord {
	int r, c;
	Coord(): r(0), c(0) {}
	Coord(int r, int c): r(r), c(c) {}
};

struct Robot {
	int r, c, d;

	void rotate_left() {
		d = (d + 3) % 4;
	}
	Coord check_front() {
		switch (d) {
		case UP:
			return Coord(r - 1, c);
		case RIGHT:
			return Coord(r, c + 1);
		case DOWN:
			return Coord(r + 1, c);
		case LEFT:
			return Coord(r, c - 1);
		}
	}
	Coord check_back() {
		switch (d) {
		case UP:
			return Coord(r + 1, c);
		case RIGHT:
			return Coord(r, c - 1);
		case DOWN:
			return Coord(r - 1, c);
		case LEFT:
			return Coord(r, c + 1);
		}
	}
};

int robotCleaner() {
	Robot robot;
	vector<vector<int>> room;
	Coord chk;
	int n, m, d;
	int clean = 0;

	// take inputs
	cin >> n >> m >> robot.r >> robot.c >> robot.d;

	room.assign(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> room.at(i).at(j);

FIRST:
	// 1-1 clean the current space
	int &current_space = room.at(robot.r).at(robot.c);
	if (current_space == 0) {
		current_space = -1;
		++clean;
	}

SECOND:
	// 2-1, 2-2 check left
	for (int i = 0; i < 4; ++i) {
		robot.rotate_left();
		chk = robot.check_front();
		// if valid space
		if(chk.r >= 0 && chk.r < n && chk.c >= 0 && chk.c < m)
			// if there is space
			if (room.at(chk.r).at(chk.c) == 0) {
				robot.r = chk.r;
				robot.c = chk.c;
				goto FIRST;
			}
	}

	// 2-3 go back
	chk = robot.check_back();
	if (chk.r >= 0 && chk.r < n && chk.c >= 0 && chk.c < m)
		if (room.at(chk.r).at(chk.c) != 1) {
			robot.r = chk.r;
			robot.c = chk.c;
			goto SECOND;
		}

	return clean;

}

int main() {
	cout << robotCleaner() << endl;

	return 0;
}