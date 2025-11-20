#include <iostream>
#include <vector>

using namespace std;

vector<bool> tri;

bool isRoad(vector<int> line, const int &len) {
	tri.assign(line.size(), false);
	int n = line.size();

	for (int i = 0; i < n-1; ++i) {
		// find the diff between i and i+1
		int diff = line.at(i) - line.at(i + 1);
		switch(diff) {
		case 0:
			continue;
			// go down	
		case 1:
			if (i + len >= n)
				return false;
			for (int k = 1; k <= len; ++k) {
				if (tri.at(i + k))
					return false;
				if (line.at(i + 1) != line.at(i + k))
					return false;
			}
			for (int k = 1; k <= len; ++k)
				tri.at(i + k) = true;
			i += len - 1;
			break;
			// go up
		case -1:
			if (i - len + 1 < 0)
				return false;
			for (int k = 0; k < len; ++k) {
				if (tri.at(i - k))
					return false;
				if (line.at(i) != line.at(i - k))
					return false;
			}
			for (int k = 0; k < len; ++k)
				tri.at(i - k) = true;
			break;
		default:
			return false;
		}
	}
	return true;
}

void howManyRoads() {
	vector<vector<int>> map;
	vector<int> line;
	int n, len;
	int c_road = 0;
	bool isContinue = false;

	// input
	cin >> n >> len;
	map.assign(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> map.at(i).at(j);

	line.assign(n, 0);
	
	// row
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			line.at(j) = map.at(i).at(j);

		if (isRoad(line, len))
			++c_road;
	}

	// col
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			line.at(j) = map.at(j).at(i);

		if (isRoad(line, len))
			++c_road;
	}

	cout << c_road << endl;
}

int main() {

	howManyRoads();

	return 0;
}