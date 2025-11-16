#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, h;
vector<vector<int>> bvec_hori;

bool isNotAdjacent(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first != b.first)
		return true;
	if (abs(a.second - b.second) <= 1)
		return false;
	else
		return true;
}

bool isNotAdjacentAddingLines(const vector<pair<int, int>>& vec) {
	switch (vec.size()) {
	case 0:
	case 1:
		return true;
	case 2:
		return isNotAdjacent(vec.at(0), vec.at(1));
	case 3:
		return isNotAdjacent(vec.at(0), vec.at(1))
			&& isNotAdjacent(vec.at(0), vec.at(2))
			&& isNotAdjacent(vec.at(1), vec.at(2));
	default:
		return false;
	}
}

// if a ladder is an answer, return true, otherwise false
bool isAnswerLadder(const vector<vector<int>>& vec) {
	// to be an answer: all vertical starts must be go to finals with the same numbers
	// i: starting line number
	for (int i = 0; i < n; ++i) {
		// cur: current position
		pair<int, int> pair_cur = make_pair(0, i);

		while (pair_cur.first < h) {
			// see left
			if (pair_cur.second > 0)
				if (vec.at(pair_cur.first).at(pair_cur.second - 1) == 1) {
					--pair_cur.second;
					++pair_cur.first;
					continue;
				}
			// see right
			if (pair_cur.second < n - 1) {
				if (vec.at(pair_cur.first).at(pair_cur.second) == 1) {
					++pair_cur.second;
					++pair_cur.first;
					continue;
				}
			}
			// go down
			++pair_cur.first;
		}
		// if start != final, return false
		if (pair_cur.second != i)
			return false;
	}
	return true;
}

void solution() {
	int m1, m2;
	int count_candidate = 0;
	int count_put_line = 0;
	int answer = -1;
	vector<vector<int>> bvec_hori_copy;
	vector<pair<int, int>> vec_candidate;
	vector<bool> bvec_combi;

	/*

	Input format

	M: Horizontal lines been put already
	H: Horizontal lines available for candidates

	N M H
	a1 b1 -> Connected on a1: Horizontal, b1: Vertical
	a2 b2
	.
	.
	.

	*/

	// clear bvec_hori

	bvec_hori.clear();
	bvec_hori.shrink_to_fit();

	// get inputs

	cin >> n >> m >> h;
	bvec_hori.assign(h, vector<int>(n - 1, 0));

	// get M details

	for (int i = 0; i < m; ++i) {
		cin >> m1 >> m2;
		bvec_hori.at(m1 - 1).at(m2 - 1) = 1;

		// disable some spaces to mark lines

		if (m2 - 2 >= 0)
			bvec_hori.at(m1 - 1).at(m2 - 2) = -1;
		if (m2 < n - 1)
			bvec_hori.at(m1 - 1).at(m2) = -1;
	}

	/*
		Function Begins Here

		1. Combination on M candidates from 0 to (n-1) * h - 1
			Start from the number 0, 1, ... X, ... (n-1) * h - 1
		2. If there is a line already, skip previous & next candidates
			Skip bvec_hori.at(x).at(y) = -1 or = 1
		3-a. If there is a line_add_num = X combination that has an answer, return it as a solution
		3-b. If there is no answer in line_add_num = X combination, go back to (2) with line_add_num = X+1.
		4. If there is no combination, return -1
	*/

	// find total line candidates
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < n - 1; ++j) {
			if (bvec_hori.at(i).at(j) == 0) {
				++count_candidate;
				vec_candidate.push_back(make_pair(i, j));
			}
		}
	}

	// make the number of adding lines not over 3
	if (count_candidate > 3)
		count_put_line = 3;
	else
		count_put_line = count_candidate;

	// 1. Start line_add_num = i combination loop
	for (int i = 0; i <= count_put_line; ++i) {
		vector<pair<int, int>> vec_pair_line;
		bool isAnswer = false;

		// Set bool combination
		bvec_combi.assign(count_candidate, false);
		for (int j = 0; j < i; ++j) {
			bvec_combi.at(j) = true;
		}
		sort(bvec_combi.begin(), bvec_combi.end());

		do {
			// Initialize copied vector and bool
			bvec_hori_copy = bvec_hori;
			
			// select combination lines
			for (int j = 0; j < count_candidate; ++j) {
				if (bvec_combi.at(j)) {
					pair<int, int> pair_line = vec_candidate.at(j);
					vec_pair_line.push_back(pair_line);
					bvec_hori_copy.at(pair_line.first).at(pair_line.second) = 1;
				}
			}

			// check if pair_lines are adjacent
			// if no adjacent,
			if (isNotAdjacentAddingLines(vec_pair_line)) {
				// solve the ladder
				isAnswer = isAnswerLadder(bvec_hori_copy);
			}

			// clear copied vector 
			bvec_hori_copy.clear();
			bvec_hori_copy.shrink_to_fit();
			vec_pair_line.clear();
			vec_pair_line.shrink_to_fit();

			// check if the result is an answer
			if (isAnswer) {
				answer = i;
				break;
			}
		} while (next_permutation(bvec_combi.begin(), bvec_combi.end()));

		if (isAnswer)
			break;
	}

	bvec_combi.clear();
	bvec_combi.shrink_to_fit();
	cout << answer << endl;
}


int main() {
	solution();

	return 0;
}