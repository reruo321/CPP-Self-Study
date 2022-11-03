#include <iostream>
#include <vector>
#include <algorithm>

#define EMPTY 0
#define WALL 1
#define VIRUS 2

using namespace std;

// produces all combinations for wall placement, and spreads virus for each case.
void putWallspreadVirus() {

}

int maxSafeZone() {
	int n, m, input;
	int wall = 3, virus = 0, min_virus = 64, wall_count;
	vector<vector<int>> original_factory, factory_final;
	vector<int> wall_vector, virus_vector;

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> input;
			original_factory.at(i).at(j) = input;
			// I'll save the position of an entity in this format: (i * m + j)
			if (input == WALL) {
				wall_vector.push_back(i * m + j);
				++wall;
			}
			else if (input == VIRUS) {
				virus_vector.push_back(i * m + j);
				++virus;
			}

		}

	
	// Try to install three walls
	while (1) {
		wall_count = 0;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {

			}

		if(wall_count < 3)
			break;
	}

}

int main() {
	
}