#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
	No. 16236 Using BFS

	1. BFS
	2. Find the nearest space with small fish
	3. Count the number the shark has eaten fishes -> Level Up

*/

class Ocean {

	class Coordinate {
		int row;
		int col;
	};
	class Shark {
		int size;
		int count;
		Coordinate cord;
	public:
		void updateCoordinate(int row, int col) {
			row = row;
			col = col;
		}
		Coordinate getCoordinate() {
			return cord;
		}
		int getSize() {
			return size;
		}
		void increaseCount() {
			++count;
		}
		void growShark() {
			if (count == size) {
				++size;
				count = 0;
			}
		}
	};

	// Ocean with N x N spaces
	int n;
	// Ocean Graph
	vector<vector<int>> graph;
	// Adjacent Information for the Current Shark's Position
	vector<vector<int>> adj;
	// Shark
	Shark shark;
	
public:
	Ocean(int n);
	void eatFish(int row, int col);
	void BFS();
};

Ocean::Ocean(int n) {
	n = n;
	int input;
	bool isShark = false;
	// Initialize adj
	adj.resize(n, vector<int>(n));
	// Initialize graph
	graph.resize(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> input;
			graph.at(i).at(j) = input;
			if (isShark)
				continue;
			if (input == 9) {
				shark.updateCoordinate(i, j);
				isShark = true;
			}
		}
	}
}

void Ocean::eatFish(int row, int col) {
	graph.at(row).at(col) = 9;
	shark.increaseCount();
	shark.growShark();
}

void Ocean::BFS() {
	Coordinate start;
	int size;
	queue<Coordinate> queue;
	// Until a Loop Escape
	do {
		// get the current shark's coordinate + size
		start = shark.getCoordinate();
		size = shark.getSize();
		// push the adjacent spaces (except the spaces with bigger fishes)
		// if there are some edible fishes, eat one of it, and reset the loop
		while (1) {
			
		}
	} while (!queue.empty());
}

int main() {
	cout << "Test" << endl;
	return 0;
}