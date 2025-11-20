#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void minStatDiff() {
	vector<vector<int>> stat_vec;
	vector<int> one_vec, two_vec;
	vector<bool> bool_combi, pair_bool_combi;
	int n, zero, diff, min_stat_diff = 40000;
	int team_one, team_two, a, b;
	cin >> n;

	// the shape of the vector will be stairs
	stat_vec.assign(n, vector<int>(0, 0));

	for (int i=0; i<n; ++i)
		stat_vec.at(i).assign(i, 0);

	// add Sij and Sji combi to possible (i,j)
	// Example 1: Put S34 + S43 to (4,3)
	// Example 2: Put S04 + S40 to (4,0)
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> zero;
			if (i == j)
				continue;
			else if (i < j)
				stat_vec.at(j).at(i) += zero;
			else
				stat_vec.at(i).at(j) += zero;
		}
	}

	// make combination
	bool_combi.assign(n, false);
	for (int i = 0; i < n / 2; ++i)
		bool_combi.at(i) = true;
	sort(bool_combi.begin(), bool_combi.end());

	// make a pair combination
	pair_bool_combi.assign(n / 2, false);
	pair_bool_combi.at(0) = true;
	pair_bool_combi.at(1) = true;

	// divide team by combination
	do {
		// initialize
		one_vec.assign(0, 0);
		two_vec.assign(0, 0);
		sort(pair_bool_combi.begin(), pair_bool_combi.end());

		team_one = team_two = 0;

		// divide people into two teams
		for (int i = 0; i < bool_combi.size(); ++i) {
			if (bool_combi.at(i))
				one_vec.push_back(i);
			else
				two_vec.push_back(i);
		}

		// calculate the stat sum of each team
		do {
			// first team
			a = b = -1;
			for (int i = 0; i < pair_bool_combi.size(); ++i) {
				if (pair_bool_combi.at(i)) {
					if (a < 0)
						a = one_vec.at(i);
					else {
						b = one_vec.at(i);
						break;
					}
				}
			}
			if (a < b) {
				int temp = a;
				a = b;
				b = temp;
			}
			// add the stat of pair combination
			team_one += stat_vec.at(a).at(b);

			// second team
			a = b = -1;
			for (int i = 0; i < pair_bool_combi.size(); ++i) {
				if (pair_bool_combi.at(i)) {
					if (a < 0)
						a = two_vec.at(i);
					else {
						b = two_vec.at(i);
						break;
					}
				}
			}
			if (a < b) {
				int temp = a;
				a = b;
				b = temp;
			}
			// add the stat of pair combination
			team_two += stat_vec.at(a).at(b);
		} while (next_permutation(pair_bool_combi.begin(), pair_bool_combi.end()));
		// check the stat difference between two teams
		diff = abs(team_one - team_two);
		if (min_stat_diff > diff)
			min_stat_diff = diff;

	} while (next_permutation(bool_combi.begin(), bool_combi.end()));

	cout << min_stat_diff << endl;

}

int main() {

	minStatDiff();

	return 0;
}