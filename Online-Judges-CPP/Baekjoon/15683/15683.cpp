#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define CCTV_TYPE_1 1
#define CCTV_TYPE_2 2
#define CCTV_TYPE_3 3
#define CCTV_TYPE_4 4
#define CCTV_TYPE_5 5

struct Coordinate {
	int row;
	int col;
	Coordinate() : row(0), col(0) {}
	Coordinate(int row, int col) : row(row), col(col) {}
};

int n, m;
vector<vector<int>> vector_zone;

int cctv_type_len[5] = { 4, 2, 4, 4, 1 };

struct CCTV {
	Coordinate coord;
	int type;
	CCTV(Coordinate coord, int type): coord(coord), type(type) {}
};

void checkUp(vector<vector<int>>& zone, int row, int col) {
	while (1) {
		--row;
		if (row < 0)
			return;

		int& current_space = zone.at(row).at(col);

		// if there is a wall, stop
		if (current_space == 6)
			return;
		
		// check the empty space to 7
		if (current_space == 0)
			current_space = 7;
		}
}

void checkDown(vector<vector<int>>& zone, int row, int col) {
	while (1) {
		++row;
		if (row >= zone.size())
			return;

		int& current_space = zone.at(row).at(col);

		// if there is a wall, stop
		if (current_space == 6)
			return;

		// check the empty space to 7
		if (current_space == 0)
			current_space = 7;
	}
}

void checkLeft(vector<vector<int>>& zone, int row, int col) {
	while (1) {
		--col;
		if (col < 0)
			return;

		int& current_space = zone.at(row).at(col);

		// if there is a wall, stop
		if (current_space == 6)
			return;

		// check the empty space to 7
		if (current_space == 0)
			current_space = 7;
	}
}

void checkRight(vector<vector<int>>& zone, int row, int col) {
	while (1) {
		++col;
		if (col >= zone.at(0).size())
			return;

		int& current_space = zone.at(row).at(col);

		// if there is a wall, stop
		if (current_space == 6)
			return;

		// check the empty space to 7
		if (current_space == 0)
			current_space = 7;
	}
}

void checkCCTV_type_1(vector<vector<int>> &zone, const int &row, const int &col, int direction) {
	
	switch (direction) {

	case 0:
		checkUp(zone, row, col);
		break;
	case 1:
		checkRight(zone, row, col);
		break;
	case 2:
		checkDown(zone, row, col);
		break;
	case 3:
		checkLeft(zone, row, col);
		break;
	}

}

void checkCCTV_type_2(vector<vector<int>>& zone, const int& row, const int& col, int direction) {

	switch (direction) {

	case 0:
		checkUp(zone, row, col);
		checkDown(zone, row, col);
		break;
	case 1:
		checkLeft(zone, row, col);
		checkRight(zone, row, col);
		break;
	}

}

void checkCCTV_type_3(vector<vector<int>>& zone, const int& row, const int& col, int direction) {

	switch (direction) {

	case 0:
		checkUp(zone, row, col);
		checkRight(zone, row, col);
		break;
	case 1:
		checkRight(zone, row, col);
		checkDown(zone, row, col);
		break;
	case 2:
		checkDown(zone, row, col);
		checkLeft(zone, row, col);
		break;
	case 3:
		checkLeft(zone, row, col);
		checkUp(zone, row, col);
		break;
	}

}

void checkCCTV_type_4(vector<vector<int>>& zone, const int& row, const int& col, int direction) {

	switch (direction) {

	case 0:
		checkLeft(zone, row, col);
		checkUp(zone, row, col);
		checkRight(zone, row, col);
		break;
	case 1:
		checkUp(zone, row, col);
		checkRight(zone, row, col);
		checkDown(zone, row, col);
		break;
	case 2:
		checkRight(zone, row, col);
		checkDown(zone, row, col);
		checkLeft(zone, row, col);
		break;
	case 3:
		checkDown(zone, row, col);
		checkLeft(zone, row, col);
		checkUp(zone, row, col);
		break;
	}

}

void checkCCTV_type_5(vector<vector<int>>& zone, const int& row, const int& col, int direction) {

	checkUp(zone, row, col);
	checkDown(zone, row, col);
	checkLeft(zone, row, col);
	checkRight(zone, row, col);

}

int checkCCTVZone(vector<vector<int>> zone, vector<CCTV> &cctv_list, int cctv_no, int direction, int count_min_zero) {
	int n = zone.size();
	int m = zone.at(0).size();
	int last_cctv = cctv_list.size() - 1;

	CCTV& current_cctv = cctv_list.at(cctv_no);
	int type = cctv_list.at(cctv_no).type;

	// The case that the current direction is NOT selected
	// Do not edit the current zone, and pass it to next turn
	for (int i = direction + 1; i < cctv_type_len[type - 1]; ++i) {
		checkCCTVZone(zone, cctv_list, cctv_no, i, count_min_zero);
	}

	// The case that the current direction is selected
	// Edit the current zone, and go to the next cctv
	vector<vector<int>> copied_zone = zone;
	switch (type) {
	case CCTV_TYPE_1:
		checkCCTV_type_1(copied_zone, current_cctv.coord.row, current_cctv.coord.col, direction);
		break;
	case CCTV_TYPE_2:
		checkCCTV_type_2(copied_zone, current_cctv.coord.row, current_cctv.coord.col, direction);
		break;
	case CCTV_TYPE_3:
		checkCCTV_type_3(copied_zone, current_cctv.coord.row, current_cctv.coord.col, direction);
		break;
	case CCTV_TYPE_4:
		checkCCTV_type_4(copied_zone, current_cctv.coord.row, current_cctv.coord.col, direction);
		break;
	case CCTV_TYPE_5:
		checkCCTV_type_5(copied_zone, current_cctv.coord.row, current_cctv.coord.col, direction);
		break;
	}

	int count_zero = 0;

	// if all cctvs were counted, end the function
	if (cctv_no == last_cctv) {
		for(auto &row: zone)
			for (auto& space : row) {
				if (space == 0)
					++count_zero;
			}
		if (count_min_zero > count_zero)
			count_min_zero = count_zero;
		return count_min_zero;
	}

	checkCCTVZone(copied_zone, cctv_list, ++cctv_no, 0, count_min_zero);
	return count_min_zero;
}

void countNotSafeZone() {
	vector<CCTV> cctv_list;
	int input, total_cases = 1;
	int count_zero, count_min_zero = 64;

	// take inputs
	cin >> n >> m;
	vector_zone.assign(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> input;
			vector_zone.at(i).at(j) = input;
			if (input > 0 && input < 6)
				cctv_list.push_back(CCTV(Coordinate(i, j), input));
		}

	count_min_zero = checkCCTVZone(vector_zone, cctv_list, 0, 0, count_min_zero);
	cout << count_min_zero;
}


int main() {

	countNotSafeZone();

	return 0;
}