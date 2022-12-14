#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#define CCTV_TYPE_1 0
#define CCTV_TYPE_2 1
#define CCTV_TYPE_3 2
#define CCTV_TYPE_4 3
#define CCTV_TYPE_5 4

vector<vector<int>> vector_zone;
int n, m;
int count_min_not_safe = 64;

struct CCTV {
	int row;
	int col;
	int type;
	CCTV(int r, int c, int t) : row(r), col(c), type(t - 1) {}
};

void dfs(vector<vector<int>> &vector_zone, stack<CCTV>& stack_cctv_list, int direction) {
	// if stack is empty, count not-safe-zones and end the function
	if (stack_cctv_list.empty()) {
		int count_not_safe = 0;
		
		for (auto& row : vector_zone)
			for (auto& e : row)
				if (e == 0)
					++count_not_safe;
		if (count_min_not_safe > count_not_safe)
			count_min_not_safe = count_not_safe;
		return;
	}

	// copy vector_zone and stack_cctv_list
	vector<vector<int>> vector_copied_zone = vector_zone;
	stack<CCTV> stack_copied_cctv_list = stack_cctv_list;

	// give it the specific direction.
	/*
	Type 1 -	One direction (total 4)
	Type 2 -	Side (total 2)
	Type 3 -	90 degree (total 4)
	Type 4 -	Three directions (total 4)
	Type 5 -	All four directions (total 1)
	*/
	
	// 1. do not select the current direction
	// do not edit the current vector
	// pass the current stack, and give another direction

	// 2. select the current direction
	// pop the top CCTV from the stack
	CCTV cctv = stack_copied_cctv_list.top();
	stack_copied_cctv_list.pop();
	// check the current vector
	// pass the 
}

void countNotSafeZone() {

	stack<CCTV> stack_cctv_list;
	int input;

	// take inputs
	cin >> n >> m;
	vector_zone.assign(n, vector<int>(m, 0));
	for(int i=0; i<n; ++n)
		for (int j = 0; j < m; ++m) {
			cin >> input;
			vector_zone.at(i).at(j) = input;
			// if there is cctv, add it to CCTV stack
			if (input > 0 && input < 6)
				stack_cctv_list.push(CCTV(i, j, input));
		}

	// DFS
	
}

int main() {

	countNotSafeZone();

	return 0;
}