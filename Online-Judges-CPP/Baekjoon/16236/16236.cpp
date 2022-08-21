#include <iostream>
#include <vector>

using namespace std;
stack<pair<int, int>> coordiStack;

class BabyShark {
	int size;
	int x;
	int y;

public:
	BabyShark(): size(2), x(0), y(0) {}

	void setCoordinate(const int x, const int y) {
		this->x = x;
		this->y = y;
	}
	void makeBigger() {
		++size;
	}
	int getSize() {
		return size;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
};

void updateTime(int x, int y, int time, vector<vector<int>>& timeVector) {
	// if the time at (x,y) is not updated or faster route is found, update.
	if (timeVector.at(x).at(y) < 0 || timeVector.at(x).at(y) > time)
		timeVector.at(x).at(y) = time;
}

// calculates reach time for all routes
vector<vector<int>> calReachTime(BabyShark &shark, vector<vector<int>>& pool, vector<vector<int>>& timeVector, int n, int time = 1) {
	int x = shark.getX();
	int y = shark.getY();
	int size = shark.getSize();
	// go up
	if (y > 0 && size >= pool.at(x).at(y - 1)) {
		updateTime(x, y - 1, time, timeVector);
		calReachTime(shark, pool, timeVector, n, time + 1);
	}
	// go left
	if (x > 0 && size >= pool.at(x - 1).at(y)) {
		updateTime(x - 1, y, time, timeVector);
		calReachTime(shark, pool, timeVector, n, time + 1);
	}
	// go right
	if (x < n - 1 && size >= pool.at(x + 1).at(y)) {
		updateTime(x + 1, y, time, timeVector);
		calReachTime(shark, pool, timeVector, n, time + 1);
	}
	// go down
	if (y < n - 1 && size >= pool.at(x).at(y + 1)) {
		updateTime(x, y + 1, time, timeVector);
		calReachTime(shark, pool, timeVector, n, time + 1);
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

	// gets pool info
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j){
			cin >> k;
			if (k == 9)
				shark.setCoordinate(i, j);
			else
				pool.at(i).at(j) = k;
		}
	timeVector.at(shark.getX()).at(shark.getY()) = 0;

	while (1) {
		int eatCount = 0;
		int ftime = 0, fx, fy;
		// calculates timeVector to know time for reaching every coordinate
		calReachTime(shark, pool, timeVector, n);
		
		for(int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				// finds edible fishes
				if (pool.at(i).at(j) > 0 && shark.getSize() > pool.at(i).at(j)) {
					// finds the minimum time to eat fish
					if (ftime == 0 || ftime > timeVector.at(i).at(j)) {
						ftime = timeVector.at(i).at(j);
						fx = i;
						fy = j;
					}
				}
			}
		// if there is an edible fish, move the shark and eat it
		if (ftime > 0) {
			shark.setCoordinate(fx, fy);
			sum += ftime;
			pool.at(fx).at(fy) = 0;
			// if shark's size == the number of fish the shark has eaten, make him bigger
			if (shark.getSize() == ++eatCount)
				shark.makeBigger();
		}
		// if there is no edible fish, ends the program
		else {
			cout << sum;
			return 0;
		}
	}
}