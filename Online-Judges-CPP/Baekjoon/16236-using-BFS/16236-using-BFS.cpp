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

class Coordinate {
	int row;
	int col;

public:
	Coordinate() : row(0), col(0){}
	Coordinate(int row, int col): row(row), col(col){}
	int getRow() { return row; }
	int getCol() { return col; }
};

class Ocean {
	class Shark {
		int size;
		int count;
		Coordinate cord;
	public:
		Shark() : size(2), count(0){}
		void updateCoordinate(int row, int col) {
			cord = Coordinate(row, col);
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
	// Visit Information
	vector<vector<bool>> visit;
	// Shark
	Shark shark;
	
public:
	Ocean();
	bool enqueue(int row, int col, queue<Coordinate>& queue, int s_size);
	void eatFish(int row, int col);
	bool addAdj(Coordinate front, queue<Coordinate>& queue);
	int BFS();
};

Ocean::Ocean() {
	int input;

	cin >> n;
	// Initialize adj
	adj.resize(n, vector<int>(0));
	// Initialize graph
	graph.resize(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> input;
			graph.at(i).at(j) = input;
			if (input == 9) {
				shark.updateCoordinate(i, j);
			}
		}
	}
}

bool Ocean::enqueue(int row, int col, queue<Coordinate> &queue, int s_size) {
	if (visit.at(row).at(col))
		return false;
	int f_size = graph.at(row).at(col);
	if (f_size <= s_size) {
		queue.push(Coordinate(row, col));
		visit.at(row).at(col) = true;
		if (f_size > 0 && f_size < s_size) {
			eatFish(row, col);
			return true;
		}
	}
	return false;
}

void Ocean::eatFish(int row, int col) {
	graph.at(shark.getCoordinate().getRow()).at(shark.getCoordinate().getCol()) = 0;
	graph.at(row).at(col) = 9;
	shark.updateCoordinate(row, col);
	shark.increaseCount();
	shark.growShark();
}

// If the shark eats a fish, returns true
bool Ocean::addAdj(Coordinate front, queue<Coordinate> &queue) {
	//	1. Get the front of the queue as a parameter
	int row = front.getRow();
	int col = front.getCol();
	int s_size = shark.getSize();

	/*
		2. Adds adjacent spaces to go
			-> If there's an edible fish, eat it and immediately ends the loop
	*/

	// Go Up
	if (row > 0) {
		if (enqueue(row - 1, col, queue, s_size))
			return true;
	}
	// Go Left
	if (col > 0) {
		if (enqueue(row, col - 1, queue, s_size))
			return true;
	}
	// Go Right
	if (col < n - 1) {
		if (enqueue(row, col + 1, queue, s_size))
			return true;
	}
	// Go Down
	if (row < n - 1) {
		if (enqueue(row + 1, col, queue, s_size))
			return true;
	}

	return false;
}

int Ocean::BFS() {
	Coordinate start;
	Coordinate front;
	int size;
	queue<Coordinate> queue;
	bool ateFish;
	int time;
	int total_time = 0;

	// Until a Loop Escape
	do {
		ateFish = false;
		// reset time of each travel
		time = 0;
		// mark all spaces not visited
		visit.resize(n, vector<bool>(n, false));
		// get the current shark's coordinate + size
		start = shark.getCoordinate();
		size = shark.getSize();
		visit.at(start.getRow()).at(start.getCol()) = true;
		queue.push(start);
		// push the adjacent spaces (except the spaces with bigger fishes)
		// if there are some edible fishes, eat one of it, and reset the loop
		while (!ateFish && !queue.empty()) {
			// Updates adj
			// Loop until the shark eats a fish OR a travel ends
			front = queue.front();
			queue.pop();
			ateFish = addAdj(front, queue);
			++time;
		}
		if (ateFish)
			total_time += time;
	} while (!queue.empty());
	return total_time;
}

int main() {
	Ocean ocean = Ocean();
	cout << "Total Time: " << ocean.BFS() << endl;
	return 0;
}