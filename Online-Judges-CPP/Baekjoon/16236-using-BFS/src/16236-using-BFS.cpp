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
	Coordinate() : row(0), col(0) {}
	Coordinate(int row, int col) : row(row), col(col) {}
	int getRow() { return row; }
	int getCol() { return col; }
};

struct cand_functor {
	bool operator() (pair<int, Coordinate> &a, pair<int, Coordinate> &b) {
		if (a.first == b.first) {
			if (a.second.getRow() == b.second.getRow())
				return a.second.getCol() > b.second.getCol();
			else
				return a.second.getRow() > b.second.getRow();
		}
		else
			return a.first > b.first;
	}
};

class Ocean {
	class Cell {
	public:
		int fish_size;
		int time_to_reach;
		bool visited;
	};
	
	class Shark {
	public:
		Coordinate cord;
		int size;
		int eat_count;

		Shark() : size(2), eat_count(0) {
			cord = Coordinate(0, 0);
		}
		Shark(int row, int col) : size(2), eat_count(0) {
			cord = Coordinate(row, col);
		}
		void updateStatus(int row, int col) {
			cord = Coordinate(row, col);
			if (++eat_count == size) {
				++size;
				eat_count = 0;
			}
		}
	};

	vector<vector<Cell>> graph2D;
	Shark shark;
	int n;

public:
	Ocean() {
		int input;

		cin >> n;
		graph2D.resize(n, vector<Cell>(n));
		for(int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				cin >> input;
				if (input == 9) {
					shark = Shark(i, j);
					graph2D.at(i).at(j).fish_size = 0;
				}
				else {
					graph2D.at(i).at(j).fish_size = input;
				}
			}
	}
	void manageEating(int row, int col) {
		graph2D.at(row).at(col).fish_size = 0;
		shark.updateStatus(row, col);
	}
	bool updateCellsInfo(queue<Coordinate>& queue, int row, int col, int time) {
		Cell &cell = graph2D.at(row).at(col);

		// If it is a visited cell, skip
		if (cell.visited)
			return false;
		// If passing the cell is okay,
		if (cell.fish_size <= shark.size) {
			// If the shark can eat the fish inside the cell
			if (cell.fish_size > 0 && cell.fish_size < shark.size) {
				return true;
			}
			// Otherwise,
			queue.push(Coordinate(row, col));
			cell.time_to_reach = time;
			cell.visited = true;
		}
		// A fish is not eaten
		return false;
	}
	void calculateRoute(Coordinate front, queue<Coordinate> &queue, priority_queue<pair<int, Coordinate>, vector<pair<int, Coordinate>>, cand_functor>& candidate) {

		int row = front.getRow();
		int col = front.getCol();
		int time = graph2D.at(row).at(col).time_to_reach;

		// Go Up
		if (row > 0)
			if (updateCellsInfo(queue, row - 1, col, time + 1)) // If a fish is eaten in the cell
				candidate.push(make_pair(time + 1, Coordinate(row - 1, col)));
		// Go Left
		if (col > 0)
			if (updateCellsInfo(queue, row, col - 1, time + 1))
				candidate.push(make_pair(time + 1, Coordinate(row, col - 1)));
		// Go Right
		if (col < n - 1)
			if (updateCellsInfo(queue, row, col + 1, time + 1))
				candidate.push(make_pair(time + 1, Coordinate(row, col + 1)));
		// Go Down
		if (row < n - 1)
			if (updateCellsInfo(queue, row + 1, col, time + 1))
				candidate.push(make_pair(time + 1, Coordinate(row + 1, col)));
	}
	int BFS() {
		// <Coordinate, time> Candidate cells for eating a fish
		priority_queue<pair<int, Coordinate>, vector<pair<int, Coordinate>>, cand_functor> candidate;
		queue<Coordinate> queue;
		Coordinate front;
		int total_time = 0;

		// Calculate BFS until there's no fish to eat
		do {
			// Reset time-to-reach AND visited
			for (auto& row : graph2D)
				for (auto& col : row) {
					col.time_to_reach = 0;
					col.visited = false;
				}

			// reset candidate cells
			candidate = {};

			// reset calc

			// Mark shark's cell as visited
			graph2D.at(shark.cord.getRow()).at(shark.cord.getCol()).visited = true;

			// Enqueue the coordinate of the shark
			queue.push(shark.cord);

			// If a fish is eaten OR there is no way to go, escape this loop
			do {
				front = queue.front();
				queue.pop();
				calculateRoute(front, queue, candidate);
			} while (!queue.empty());

			// Compare candidate cells to eat - cand_functor will automatically sort them
			if (!candidate.empty()) {
				front = candidate.top().second;
				manageEating(front.getRow(), front.getCol());
				queue.push(shark.cord);
				total_time += candidate.top().first;
			}

			// If there's no edible fish, queue will be empty
		} while (!queue.empty());

		// End the calculation AND return the result
		return total_time;
	}
};

int main() {
	
	Ocean ocean = Ocean();
	cout << ocean.BFS() << endl;

	return 0;
}