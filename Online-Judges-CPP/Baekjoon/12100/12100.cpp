#include <iostream>
#include <vector>
#include <queue>
#include <deque>

enum{ FRONT, BACK };


using namespace std;

class Board {

	class GameCase {
	public:
		vector<vector<int>> game_case;
		int time;
		GameCase(vector<vector<int>> game, int time) : time(time) {
			game_case = game;
		}
	};

	vector<vector<int>> gameboard;
	queue<GameCase> cases_queue;
	priority_queue<int> maxval_queue;
	int n;

public:
	Board() {
		cin >> n;
		gameboard.assign(n, vector<int>(n, 0));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> gameboard.at(i).at(j);
			}
		}
	}
	void printGame(GameCase gamecase) {
		cout << "----- " << gamecase.time << " th try" << endl;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << gamecase.game_case.at(i).at(j) << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	int findMaxValue(vector<vector<int>> game) {
		int max = 0;
		for(int i=0; i<n; ++i)
			for (int j = 0; j < n; ++j) {
				if (max < game.at(i).at(j))
					max = game.at(i).at(j);
			}
		return max;
	}

	void moveAndConquer(vector<int> &smallvec) {

		bool is_upper_combined = false;
		
		for (int i = 0; i < n; ++i) {
			AGAIN:
			if(smallvec.at(i) == 0)
			for (int j = i+1; j < n; ++j) {
				if (smallvec.at(j) != 0) {
					smallvec.erase(smallvec.begin() + i);
					smallvec.push_back(0);
					goto AGAIN;
				}
			}
		}

		for (int i = 1; i < n; ++i) {
			COMBINE_AGAIN:
			if (!is_upper_combined && smallvec.at(i - 1) == smallvec.at(i)) {
				smallvec.at(i - 1) *= 2;
				smallvec.erase(smallvec.begin() + i);
				smallvec.push_back(0);
				is_upper_combined = true;
				goto COMBINE_AGAIN;
			}
			else
				is_upper_combined = false;
		}
	}

	void moveUP(GameCase game) {

		vector<vector<int>> new_game = game.game_case;
		vector<int> smallvec;
		// col
		for (int j = 0; j < n; ++j) {
			smallvec.assign(n, 0);
			// row
			for (int i = 0; i < n; ++i){
				smallvec.at(i) = game.game_case.at(i).at(j);
				}
			moveAndConquer(smallvec);
			for(int i=0; i < n; ++i){
				new_game.at(i).at(j) = smallvec.at(i);
			}
		}
		smallvec.clear();
		smallvec.shrink_to_fit();

		cases_queue.push(GameCase(new_game, ++game.time));
	}

	void moveDOWN(GameCase game) {

		vector<vector<int>> new_game = game.game_case;
		vector<int> smallvec;
		// col
		for (int j = 0; j < n; ++j) {
			smallvec.assign(n, 0);
			// row
			for (int i = 0; i < n; ++i) {
				smallvec.at(i) = game.game_case.at(n-1-i).at(j);
			}
			moveAndConquer(smallvec);
			for (int i = 0; i < n; ++i) {
				new_game.at(n-1-i).at(j) = smallvec.at(i);
			}
		}
		smallvec.clear();
		smallvec.shrink_to_fit();

		cases_queue.push(GameCase(new_game, ++game.time));
	}

	void moveLEFT(GameCase game) {

		vector<vector<int>> new_game = game.game_case;
		vector<int> smallvec;
		// row
		for (int i = 0; i < n; ++i) {
			smallvec.assign(n, 0);
			// col
			for (int j = 0; j < n; ++j) {
				smallvec.at(j) = game.game_case.at(i).at(j);
			}
			moveAndConquer(smallvec);
			for (int j = 0; j < n; ++j) {
				new_game.at(i).at(j) = smallvec.at(j);
			}
		}
		smallvec.clear();
		smallvec.shrink_to_fit();

		cases_queue.push(GameCase(new_game, ++game.time));
	}

	void moveRIGHT(GameCase game) {

		vector<vector<int>> new_game = game.game_case;
		vector<int> smallvec;
		// row
		for (int i = 0; i < n; ++i) {
			smallvec.assign(n, 0);
			// col
			for (int j = 0; j < n; ++j) {
				smallvec.at(j) = game.game_case.at(i).at(n-1-j);
			}
			moveAndConquer(smallvec);
			for (int j = 0; j < n; ++j) {
				new_game.at(i).at(n-1-j) = smallvec.at(j);
			}
		}
		smallvec.clear();
		smallvec.shrink_to_fit();

		cases_queue.push(GameCase(new_game, ++game.time));
	}

	int playGame() {
		int max = 0;
		GameCase front = GameCase(gameboard, 0);
		// initialize
		cases_queue.push(front);

		while (!cases_queue.empty()) {
			front = cases_queue.front();
			if (front.time == 5) {
				maxval_queue.push(findMaxValue(cases_queue.front().game_case));
			}
			else {
				moveUP(front);
				moveDOWN(front);
				moveLEFT(front);
				moveRIGHT(front);
			}
			cases_queue.pop();
		}

		return maxval_queue.top();
	}
};



int main() {
	Board board = Board();
	cout << board.playGame() << endl;
}