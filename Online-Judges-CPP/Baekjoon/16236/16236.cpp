#include <iostream>
#include <vector>

using namespace std;


class BabyShark {
	int size;
	int row;
	int col;

public:
	BabyShark(): size(2), row(0), col(0) {}

	void setCoordinate(const int row, const int col) {
		this->row = row;
		this->col = col;
	}
	void makeBigger() {
		++size;
	}
	int getSize() {
		return size;
	}
	int getRow() {
		return row;
	}
	int getCol() {
		return col;
	}
};

bool updateTime(int row, int col, int time, vector<vector<int>>& timeVector) {
	// if the time at the position is not updated or faster route is found, update.
	if (timeVector.at(row).at(col) < 0 || timeVector.at(row).at(col) > time) {
		timeVector.at(row).at(col) = time;
		return true;
	}
	return false;
}

// calculates reach time for all routes
void calReachTime(int row, int col, int size, vector<vector<int>>& pool, vector<vector<int>>& timeVector, int n, int time = 1) {
	// if the route for the specific position is not faster than the previous one,
	// do not calculate near routes again, or an infinite loop will cause the error...
	
	// go up
	if (row > 0 && size >= pool.at(row-1).at(col)) {
		if(updateTime(row-1, col, time, timeVector))
			calReachTime(row-1, col, size, pool, timeVector, n, time + 1);
	}
	// go left
	if (col > 0 && size >= pool.at(row).at(col-1)) {
		if(updateTime(row, col-1, time, timeVector))
			calReachTime(row, col-1, size, pool, timeVector, n, time + 1);
	}
	// go right
	if (col < n - 1 && size >= pool.at(row).at(col+1)) {
		if(updateTime(row, col+1, time, timeVector))
			calReachTime(row, col+1, size, pool, timeVector, n, time + 1);
	}
	// go down
	if (row < n - 1 && size >= pool.at(row+1).at(col)) {
		if(updateTime(row+1, col, time, timeVector))
			calReachTime(row+1, col, size, pool, timeVector, n, time + 1);
	}
}

int main() {
	int n;
	int k;

	cin >> n;
	vector<vector<int>> pool(n, vector<int>(n, 0));
	vector<vector<int>> timeVector(n, vector<int>(n, -1));
	BabyShark shark;
	int sum = 0;
	int eatCount = 0;

	// gets pool info
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j){
			cin >> k;
			if (k == 9)
				shark.setCoordinate(i, j);
			else
				pool.at(i).at(j) = k;
		}

	while (1) {
		int ftime = 0, frow, fcol;
		
		timeVector.at(shark.getRow()).at(shark.getCol()) = 0;

		// calculates timeVector to know time for reaching every coordinate
		calReachTime(shark.getRow(), shark.getCol(), shark.getSize(), pool, timeVector, n);
		
		for(int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				// finds edible fishes
				if (pool.at(i).at(j) > 0 && shark.getSize() > pool.at(i).at(j)) {
					// finds the minimum time to eat fish
					if (ftime == 0 || ftime > timeVector.at(i).at(j)) {
						ftime = timeVector.at(i).at(j);
						frow = i;
						fcol = j;
						cout << "Fish location - row: " << frow << ", col: " << fcol << endl;
						cout << "Reach Time - " << ftime << endl;
					}
				}
			}
		// if there is an edible fish, move the shark and eat it
		if (ftime > 0) {
			shark.setCoordinate(frow, fcol);
			sum += ftime;
			pool.at(frow).at(fcol) = 0;
			// if shark's size == the number of fish the shark has eaten, make him bigger
			if (shark.getSize() == ++eatCount) {
				shark.makeBigger();
				eatCount = 0;
			}
		}
		// if there is no edible fish, ends the program
		else {
			cout << sum;
			return 0;
		}
	}
}