#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define EMPTY 0
#define WALL 1
#define VIRUS 2

using namespace std;

struct Coordinate {
	int r;
	int c;
	Coordinate(): r(0), c(0) {}
	Coordinate(int r, int c) : r(r), c(c) {}
};

int maxEmptySpace() {
	vector<vector<int>> factory, copied_factory;
	queue<Coordinate> virus_list, copied_virus_list;
	vector<Coordinate> combi_coord;
	vector<bool> combi_bool;

	int n, m, input;
	int max = 0, count_empty;

	cin >> n >> m;
	
	// UP LEFT DOWN RIGHT
	int dr[] = { -1, 0, 1, 0 };
	int dc[] = { 0, -1, 0 , 1 };

	factory.assign(n, vector<int>(m));

	// take input
	for(int i=0; i<n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> input;
			factory.at(i).at(j) = input;
			switch (input) {
			case EMPTY:
				combi_coord.push_back(Coordinate(i, j));
				break;
			case WALL:
				break;
			case VIRUS:
				virus_list.push(Coordinate(i, j));
				break;
			}
		}

	// ready wall combination
	combi_bool.assign(combi_coord.size(), false);
	for (int i = 0; i < 3; ++i)
		combi_bool.at(i) = true;
	sort(combi_bool.begin(), combi_bool.end());

	do {
		// initialize
		copied_factory = factory;
		copied_virus_list = virus_list;
		count_empty = 0;

		// select three empty spaces to place wall
		for(int i=0; i<combi_bool.size(); ++i)
			if (combi_bool.at(i)) {
				Coordinate new_wall = combi_coord.at(i);
				copied_factory.at(new_wall.r).at(new_wall.c) = WALL;
			}
		
		// spread virus
		while (!copied_virus_list.empty()) {
			Coordinate virus = copied_virus_list.front();
			copied_virus_list.pop();

			// Go UP, LEFT, DOWN, RIGHT
			for (int i = 0; i < 4; ++i) {
				Coordinate new_virus = virus;
				new_virus.r += dr[i];
				new_virus.c += dc[i];

				if (new_virus.r >= 0 && new_virus.c >= 0 && new_virus.r < n && new_virus.c < m) {
					if (copied_factory.at(new_virus.r).at(new_virus.c) == EMPTY) {
						copied_factory.at(new_virus.r).at(new_virus.c) = VIRUS;
						copied_virus_list.push(new_virus);
					}
				}
			}
		}

		// find the number of empty spaces
		for (auto& r : copied_factory)
			for (auto& e : r)
				if (e == EMPTY)
					++count_empty;

		if (max < count_empty)
			max = count_empty;

	} while (next_permutation(combi_bool.begin(), combi_bool.end()));

	return max;
}


int main() {
	cout << maxEmptySpace() << endl;
}