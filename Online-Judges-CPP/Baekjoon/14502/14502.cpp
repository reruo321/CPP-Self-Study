#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define EMPTY 0
#define WALL 1
#define VIRUS 2

using namespace std;

// produces all combinations for wall placement, and spreads virus for each case.
int putWallspreadVirus(vector<vector<int>> &original_factory, const vector<pair<int, int>> & empty_list, queue<pair<int, int>>& virus_orin) {
	// make combinations for wall placement	
	pair<int, int> coord, new_coord;
	int entity = WALL, max = 0, empty_count, virus_count;
	vector<bool> bool_wallcombi(empty_list.size(), true);
	// UP, LEFT, DOWN, RIGHT
	int dr[] = { -1, 0, 1, 0 };
	int dc[] = { 0, -1, 0, 1 };

	for (int i = 0; i < empty_list.size() - 3; ++i)
		bool_wallcombi.at(i) = false;
	
	// combination loop
	do {
		// initialize factory and virus queue
		vector<vector<int>> factory = original_factory;
		queue<pair<int, int>> virus_queue = virus_orin;
		empty_count = 0;
		virus_count = 0;

		for(int i=0; i < bool_wallcombi.size(); ++i)
			// place walls
			if (bool_wallcombi.at(i)) {
				coord = empty_list.at(i);
				factory.at(coord.first).at(coord.second) = WALL;
			}
		// spread virus
		while (!virus_queue.empty()) {
			coord = virus_queue.front();
			virus_queue.pop();
			
			// UP > LEFT > DOWN > RIGHT
			for (int i = 0; i < 4; ++i) {
				// UP DOWN
				if (i % 2 == 0) {
					if (coord.first + dr[i] > 0 && coord.first + dr[i] < factory.size()) {
						new_coord = make_pair(coord.first + dr[i], coord.second);
						entity = factory.at(new_coord.first).at(new_coord.second);
					}
				}
				// LEFT RIGHT
				else {
					if (coord.second + dc[i] > 0 && coord.second + dc[i] < factory.at(0).size()) {
						new_coord = make_pair(coord.first, coord.second + dc[i]);
						entity = factory.at(new_coord.first).at(new_coord.second);
					}
				}
				// spread virus
				if (entity == EMPTY) {
					factory.at(new_coord.first).at(new_coord.second) = VIRUS;
					virus_queue.push(new_coord);
				}
			}
		}
		for (auto& r : factory)
			for (auto& e : r)
				if (e == EMPTY)
					++empty_count;

		if (max < empty_count)
			max = empty_count;
	} while (next_permutation(bool_wallcombi.begin(), bool_wallcombi.end()));
	
	// return the answer
	return max;
}

int maxSafeZone() {
	int n, m, input, wall_count = 0;
	vector<vector<int>> original_factory;
	vector<pair<int, int>> empty_list;
	queue<pair<int, int>> virus_list;

	cin >> n >> m;
	original_factory.assign(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> input;
			original_factory.at(i).at(j) = input;
			if (input == EMPTY)
				empty_list.push_back(make_pair(i, j));
			else if (input == VIRUS)
				virus_list.push(make_pair(i, j));
			else
				++wall_count;
		}
	return putWallspreadVirus(original_factory, empty_list, virus_list);
}

int main() {
	cout << maxSafeZone() << endl;
}