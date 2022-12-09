#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Coordinate {
	int row;
	int col;
	Coordinate() : row(0), col(0) {}
	Coordinate(int row, int col) : row(row), col(col) {}
	Coordinate operator+=(Coordinate ref) {
		row += ref.row;
		col += ref.col;
	}
};

Coordinate* coord_up = &Coordinate(-1, 0);
Coordinate* coord_right = &Coordinate(0, 1);
Coordinate* coord_down = &Coordinate(1, 0);
Coordinate* coord_left = &Coordinate(0, -1);

Coordinate* cctv_type_1[4][1] = { {coord_up}, {coord_right}, {coord_down}, {coord_left} };
Coordinate* cctv_type_2[2][2] = { {coord_up, coord_down}, {coord_left, coord_right} };
Coordinate* cctv_type_3[4][2] = { {coord_up, coord_right}, {coord_right, coord_down}, {coord_down, coord_left}, {coord_left, coord_up} };
Coordinate* cctv_type_4[4][3] = { {coord_left, coord_up, coord_right}, {coord_up, coord_right, coord_down}, {coord_right, coord_down, coord_left}, {coord_down, coord_left, coord_up} };
Coordinate* cctv_type_5[1][4] = { {coord_up, coord_left, coord_right, coord_down} };

Coordinate** cctv_type[5] = { *cctv_type_1, *cctv_type_2, *cctv_type_3, *cctv_type_4, *cctv_type_5 };
int cctv_type_len[5] = { 4, 2, 4, 4, 1 };
int cctv_type_col_len[5] = { 1, 2, 2, 3, 4 };

struct CCTV {
	Coordinate coord;
	int type;
	CCTV(Coordinate coord, int type): coord(coord), type(type) {}
};

void checkCCTVZone(vector<vector<int>> &zone, vector<CCTV> &cctv_list, int cctv_no, int direction) {
	int n = zone.size();
	int m = zone.at(0).size();
	int last_cctv = cctv_list.size() - 1;

	// if all cctvs were counted
	if (cctv_no > last_cctv)
		return;

		
	


	
}

void countNotSafeZone() {
	vector<vector<int>> vector_zone;
	vector<vector<int>> vector_copied_zone;
	vector<CCTV> cctv_list;
	int n, m;
	int input, total_cases = 1;
	int count_zero, count_min_zero = 64;

	cin >> n >> m;
	vector_zone.assign(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> input;
			vector_zone.at(i).at(j) = input;
			if (input > 0 && input < 6)
				cctv_list.push_back(CCTV(Coordinate(i, j), input));
		}

	// calculate total cases
	for (int i = 0; i < cctv_list.size(); ++i) {
		int type = cctv_list.at(i).type;
		total_cases *= cctv_type_len[type - 1];
	}

	// look for all cases of each cctv direction
	for (int i = 0; i < total_cases; ++i) {
		vector_copied_zone = vector_zone;
		count_zero = 0;
		
		// check cctv one by one
		for (int j = 0; j < cctv_list.size(); ++j) {
			checkCCTVZone(vector_copied_zone, cctv_list, 0);
		}
		
		for (auto& row : vector_copied_zone)
			for (auto& space : row)
				if (space == 0)
					++count_zero;

		if (count_min_zero > count_zero)
			count_min_zero = count_zero;
	}
}


int main() {
	return 0;
}