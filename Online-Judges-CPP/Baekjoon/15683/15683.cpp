#include <iostream>
#include <vector>

using namespace std;

struct CCTV {
	int row;
	int col;
	int type;
	CCTV(int r, int c, int t) : row(r), col(c), type(t) {}
};

vector<vector<int>> vector_zone(8, vector<int>(8, 0));
vector<vector<int>> vector_copied_zone;
vector<CCTV> vector_cctv_list;

// UP, RIGHT, DOWN, LEFT
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int count_min_not_safe_zone = 64;
int n, m;

void checkZone(int row, int col, int direction) {
	while (1) {
		row += dr[direction % 4];
		col += dc[direction % 4];

		// out of bound
		if (row < 0 || col < 0 || row >= n || col >= m)
			return;
		// find the space
		int& space = vector_copied_zone.at(row).at(col);

		// wall
		if (space == 6)
			return;
		
		// check space to safe zone
		if (space == 0)
			space = 7;
	}
}

void rotateCCTV(int index_cctv) {

	// if all CCTVs are rotated
	if (vector_cctv_list.size() <= index_cctv) {
		// count the not safe zone
		int count_not_safe_zone = 0;
//		cout << endl;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
//				cout << vector_copied_zone.at(i).at(j) << " ";

				if (vector_copied_zone.at(i).at(j) == 0)
					++count_not_safe_zone;
			}
//			cout << endl;
		}

		if (count_min_not_safe_zone > count_not_safe_zone)
			count_min_not_safe_zone = count_not_safe_zone;

		return;
	}

	// rotate CCTV four times
	for (int i = 0; i < 4; ++i) {
		// save the current state of cctv-rotating zone
		vector<vector<int>> vector_current_zone = vector_copied_zone;
		
		// get the cctv
		CCTV& cctv = vector_cctv_list.at(index_cctv);

		// identify the type of cctv
		switch (cctv.type) {
			// check copied zone
		case 1:
			checkZone(cctv.row, cctv.col, i);
			break;
		case 2:
			checkZone(cctv.row, cctv.col, i);
			checkZone(cctv.row, cctv.col, i + 2);
			break;
		case 3:
			checkZone(cctv.row, cctv.col, i);
			checkZone(cctv.row, cctv.col, i + 1);
			break;
		case 4:
			checkZone(cctv.row, cctv.col, i);
			checkZone(cctv.row, cctv.col, i + 1);
			checkZone(cctv.row, cctv.col, i + 2);
			break;
		case 5:
			checkZone(cctv.row, cctv.col, i);
			checkZone(cctv.row, cctv.col, i + 1);
			checkZone(cctv.row, cctv.col, i + 2);
			checkZone(cctv.row, cctv.col, i + 3);
			break;
		}
		// rotate the next CCTV
		rotateCCTV(index_cctv + 1);

		// roll back the current zone state and see the next direction case
		vector_copied_zone = vector_current_zone;
	}
}

void countNotSafeZone() {
	int input;

	// get inputs
	cin >> n >> m;
	for(int i=0; i<n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> input;
			vector_zone.at(i).at(j) = input;
			if (input >= 1 && input <= 5)
				vector_cctv_list.push_back(CCTV(i, j, input));
		}
	// initialize zone
	vector_copied_zone = vector_zone;

	// rotate CCTV one by one
	rotateCCTV(0);

	// get the answer
	cout << count_min_not_safe_zone << endl;
}

int main() {
	countNotSafeZone();

	return 0;
}