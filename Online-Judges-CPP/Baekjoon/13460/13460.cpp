#include <iostream>
#include <vector>

using namespace std;

enum CELL_TYPE {
	EMPTY, WALL, RED, BLUE, GOAL
};

class Board {

	class Cell {
	public:
		int celltype;

		Cell() : celltype(EMPTY) {};
	};

	vector<vector<Cell>> cellVector;
	int n, m;


	Board() {
		cin >> n >> m;

		string space;

		cellVector.assign(n, vector<Cell>(m));

		for (int i = 0; i < n; ++i) {
			cin >> space;
			
			// Assign each cell

			for (int j = 0; j < m; ++j) {
				switch (space.at(j)) {
					case '#': cellVector.at(i).at(j).celltype = WALL;
						break;
					case 'R': cellVector.at(i).at(j).celltype = RED;
						break;
					case 'B': cellVector.at(i).at(j).celltype = BLUE;
						break;
					case 'O': cellVector.at(i).at(j).celltype = GOAL;
						break;
//					case '.': cellVector.at(i).at(j).celltype = EMPTY;
					default:
						break;
				}
			}
		}

	}

};


int main() {

	return 0;
}