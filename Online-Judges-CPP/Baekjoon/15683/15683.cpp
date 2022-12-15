#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#define SAFE_ZONE 7

vector<vector<int>> vector_zone;
int n, m;
int count_min_not_safe = 64;

struct CCTV {
	int row;
	int col;
	int type;
	CCTV(int r, int c, int t) : row(r), col(c), type(t) {}
};

void checkUp(vector<vector<int>>& vector_zone, int row, int col) {
	// loop
	while (1) {
		--row;
		// until out of bound
		if (row < 0)
			return;

		int& space = vector_zone.at(row).at(col);

		// until there is a wall
		if (space == 6)
			return;

		// if the space is empty
		if (space == 0)
			space = SAFE_ZONE;
	}
}

void checkDown(vector<vector<int>>& vector_zone, int row, int col) {
	// loop
	while (1) {
		++row;
		// until out of bound
		if (row >= n)
			return;

		int& space = vector_zone.at(row).at(col);

		// until there is a wall
		if (space == 6)
			return;

		// if the space is empty
		if (space == 0)
			space = SAFE_ZONE;
	}
}

void checkLeft(vector<vector<int>>& vector_zone, int row, int col) {
	// loop
	while (1) {
		--col;
		// until out of bound
		if (col < 0)
			return;

		int& space = vector_zone.at(row).at(col);

		// until there is a wall
		if (space == 6)
			return;

		// if the space is empty
		if (space == 0)
			space = SAFE_ZONE;
	}
}

void checkRight(vector<vector<int>>& vector_zone, int row, int col) {
	// loop
	while (1) {
		++col;
		// until out of bound
		if (col >= m)
			return;

		int& space = vector_zone.at(row).at(col);

		// until there is a wall
		if (space == 6)
			return;

		// if the space is empty
		if (space == 0)
			space = SAFE_ZONE;
	}
}

void dfs(vector<vector<int>> &vector_zone, stack<CCTV> &stack_cctv_list, int direction) {

	// if stack is empty, count not-safe-zones and end the function
	if (stack_cctv_list.empty()) {
		int count_not_safe = 0;

		cout << endl;

		for (auto& row : vector_zone) {
			for (auto& e : row) {
				cout << e << " ";
					if (e == 0)
						++count_not_safe;
			}
			cout << endl;
		}

		if (count_min_not_safe > count_not_safe)
			count_min_not_safe = count_not_safe;
		return;
	}

	// copy vector_zone and stack_cctv_list
	vector<vector<int>> vector_copied_zone = vector_zone;
	stack<CCTV> stack_copied_cctv_list = stack_cctv_list;

	// top CCTV
	CCTV cctv = stack_copied_cctv_list.top();

	// give it the specific direction.
	/*
	Type 1 -	One direction (total 4)
	Type 2 -	Side (total 2)
	Type 3 -	90 degree (total 4)
	Type 4 -	Three directions (total 4)
	Type 5 -	All four directions (total 1)
	*/
	
	// 1. do not select the current direction
	// do not edit the current vector
	// pass the current stack, and give another direction
	int num_dir = 0;
	switch (cctv.type) {
		// 4
	case 1:
	case 3:
	case 4:
		num_dir = 4;
		break;

		// 2
	case 2:
		num_dir = 2;
		break;

		// 1
	case 5:
		num_dir = 1;
		break;
	}

	for(int i=direction+1; i<num_dir; ++i)
	dfs(vector_copied_zone, stack_copied_cctv_list, num_dir);

	// 2. select the current direction
	// pop the top CCTV from the stack
	stack_copied_cctv_list.pop();
	
	// edit the current vector with the CCTV
	switch (cctv.type) {
	// CCTV Type 1
	case 1:
		switch (direction) {
		case 0:
			checkUp(vector_copied_zone, cctv.row, cctv.col);
			break;
		case 1:
			checkRight(vector_copied_zone, cctv.row, cctv.col);
			break;
		case 2:
			checkDown(vector_copied_zone, cctv.row, cctv.col);
			break;
		case 3:
			checkLeft(vector_copied_zone, cctv.row, cctv.col);
			break;
		}
		break;

	// CCTV Type 2
	case 2:
		switch (direction) {
		case 0:
			checkUp(vector_copied_zone, cctv.row, cctv.col);
			checkDown(vector_copied_zone, cctv.row, cctv.col);
			break;
		case 1:
			checkLeft(vector_copied_zone, cctv.row, cctv.col);
			checkRight(vector_copied_zone, cctv.row, cctv.col);
			break;
		}
		break;

	// CCTV Type 3
	case 3:
		switch (direction) {
		case 0:
			checkUp(vector_copied_zone, cctv.row, cctv.col);
			checkRight(vector_copied_zone, cctv.row, cctv.col);
			break;
		case 1:
			checkRight(vector_copied_zone, cctv.row, cctv.col);
			checkDown(vector_copied_zone, cctv.row, cctv.col);
			break;
		case 2:
			checkDown(vector_copied_zone, cctv.row, cctv.col);
			checkLeft(vector_copied_zone, cctv.row, cctv.col);
			break;
		case 3:
			checkUp(vector_copied_zone, cctv.row, cctv.col);
			checkLeft(vector_copied_zone, cctv.row, cctv.col);
			break;
		}
		break;

	// CCTV Type 4
	case 4:
		switch (direction) {
		case 0:
			checkLeft(vector_copied_zone, cctv.row, cctv.col);
			checkUp(vector_copied_zone, cctv.row, cctv.col);
			checkRight(vector_copied_zone, cctv.row, cctv.col);
			break;
		case 1:
			checkUp(vector_copied_zone, cctv.row, cctv.col);
			checkRight(vector_copied_zone, cctv.row, cctv.col);
			checkDown(vector_copied_zone, cctv.row, cctv.col);
			break;
		case 2:
			checkRight(vector_copied_zone, cctv.row, cctv.col);
			checkDown(vector_copied_zone, cctv.row, cctv.col);
			checkLeft(vector_copied_zone, cctv.row, cctv.col);
			break;
		case 3:
			checkUp(vector_copied_zone, cctv.row, cctv.col);
			checkLeft(vector_copied_zone, cctv.row, cctv.col);
			checkDown(vector_copied_zone, cctv.row, cctv.col);
			break;
		}
		break;

	// CCTV Type 5
	case 5:
		checkUp(vector_copied_zone, cctv.row, cctv.col);
		checkLeft(vector_copied_zone, cctv.row, cctv.col);
		checkRight(vector_copied_zone, cctv.row, cctv.col);
		checkDown(vector_copied_zone, cctv.row, cctv.col);
		break;
	}

	// next dfs
	dfs(vector_copied_zone, stack_copied_cctv_list, 0);
}

void countNotSafeZone() {

	stack<CCTV> stack_cctv_list;
	int input;

	// take inputs
	cin >> n >> m;

	vector_zone.assign(n, vector<int>(m, 0));
	for(int i=0; i<n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> input;
			vector_zone.at(i).at(j) = input;
			// if there is cctv, add it to CCTV stack
			if (input > 0 && input < 6)
				stack_cctv_list.push(CCTV(i, j, input));
		}

	// DFS
	dfs(vector_zone, stack_cctv_list, 0);
	
}

int main() {

	countNotSafeZone();
	cout << count_min_not_safe << endl;

	return 0;
}