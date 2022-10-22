#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
int n, m;

int sixMax() {

}

int tetrisMax() {
	int max = 0;
	int six_num[6];
	int six_max, minus_min;

	cin >> n >> m;
	board.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> board.at(i).at(j);

	for (int i = 0; i < n - 1; ++i) {
		// find the maximum from 3 x 2 blocks
		for (int j = 0; j < 6; ++j) {

		}

	}

}

int main() {
	
}