#include <iostream>
#include <vector>

using namespace std;

int sixMax(int six_max[6]) {

	int max = six_max[0] + six_max[1] + six_max[2] + six_max[3] + six_max[4] + six_max[5];
	// Sum of two number must be 2 <= sum <= 2000 because of the input conditions
	int minus_min = 2022;

	// [ 0 | 1 | 2 ]
	// [ 3 | 4 | 5 ]

	// Exclude five cases that do not make a tetris block:
	// - {0, 4}, - {1, 3}, - {1, 4}, - {1, 5}, - {2, 4}

	for (int i = 0; i < 6; ++i) {
		for (int j = i + 1; j < 6; ++j) {
			if (i == 0 && j == 4)
				continue;
			if (i == 1 && j == 3)
				continue;
			if (i == 1 && j == 4)
				continue;
			if (i == 1 && j == 5)
				continue;
			if (i == 2 && j == 4)
				continue;

			if (minus_min > six_max[i] + six_max[j])
				minus_min = six_max[i] + six_max[j];
		}
	}

	return (max - minus_min);
}

int tetrisMax() {
	vector<vector<int>> board;
	int n, m;
	int max = 0, six_max;
	int six_num[6] = {0, };

	cin >> n >> m;
	board.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> board.at(i).at(j);

	// find the maximum from 1 x 4 blocks
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m - 3; ++j) {
			six_max = board.at(i).at(j) + board.at(i).at(j + 1)
				+ board.at(i).at(j + 2) + board.at(i).at(j + 3);
			if (max < six_max)
				max = six_max;
		}

	// find the maximum from 2 x 3 blocks
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < m - 2; ++j) {
			six_num[0] = board.at(i).at(j);
			six_num[1] = board.at(i).at(j + 1);
			six_num[2] = board.at(i).at(j + 2);
			six_num[3] = board.at(i + 1).at(j);
			six_num[4] = board.at(i + 1).at(j + 1);
			six_num[5] = board.at(i + 1).at(j + 2);
			six_max = sixMax(six_num);
			if (max < six_max)
				max = six_max;
		}
	}

	// find the maximum from 3 x 2 blocks
	for (int i = 0; i < n - 2; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			six_num[0] = board.at(i).at(j);
			six_num[3] = board.at(i).at(j + 1);
			six_num[1] = board.at(i + 1).at(j);
			six_num[4] = board.at(i + 1).at(j + 1);
			six_num[2] = board.at(i + 2).at(j);
			six_num[5] = board.at(i + 2).at(j + 1);
			six_max = sixMax(six_num);
			if (max < six_max)
				max = six_max;
		}
	}

	// find the maximum from 4 x 1 blocks
	for (int i = 0; i < n - 3; ++i)
		for (int j = 0; j < m; ++j) {
			six_max = board.at(i).at(j) + board.at(i + 1).at(j)
				+ board.at(i + 2).at(j) + board.at(i + 3).at(j);
			if (max < six_max)
				max = six_max;
		}

	return max;
}

int main() {
	cout << tetrisMax() << endl;
}