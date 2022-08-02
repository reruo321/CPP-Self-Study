#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Point {
	int x;
	int y;
};

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
	
	int getSize() {
		return size;
	}
};

int main() {
	int n;
	int k;
	int time = 0;

	cin >> n;
	vector<vector<int>> pool(n, vector<int>(n, 0));
	stack<pair<int, int>> coordiStack;
	BabyShark shark;

	// gets pool info
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j){
			cin >> k;
			if (k == 9)
				shark.setCoordinate(i, j);
			else
				pool.at(i).at(j) = k;
		}

	// finds edible fishes
	while (1) {
		for(int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				// saves the coordinates of edible fishes
				if (shark.getSize() > pool.at(i).at(j))
					coordiStack.push(make_pair(i, j));
			}

		// if there is no edible fish, ends the program
		if (coordiStack.empty()) {
			cout << time;
			return 0;
		}


	}
}