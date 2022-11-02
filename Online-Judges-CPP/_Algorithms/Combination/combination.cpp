#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// The guide is from GeeksforGeeks

void subCombination(vector<vector<int>> &combi_list, vector<int> vec, int n, int r, vector<int> &subvec, int vec_idx, int sub_idx) {

	// if a combination is completed
	if (r == 0) {
		combi_list.push_back(subvec);
		return;
	}
	// if a combination is not completed, but there is no more element to pick
	if (vec_idx >= vec.size()) {
		return;
	}
	subvec[sub_idx] = vec[vec_idx];

	// The case picking vec[vec_idx]
	subCombination(combi_list, vec, n, r - 1, subvec, vec_idx + 1, sub_idx + 1);
	// The case not picking vec[vec_idx] (subvec[sub_idx] will be overlapped by vec[vec_idx + X])
	subCombination(combi_list, vec, n, r, subvec, vec_idx + 1, sub_idx);
}


// Return all combinations
vector<vector<int>> combination(vector<int> vec, int n, int r) {
	vector<vector<int>> combi_list;
	vector<int> subvec(3, 0);

	subCombination(combi_list, vec, n, r, subvec, 0, 0);

	return combi_list;
}

int main() {
	vector<int> vec = { 1, 2, 3, 4, 5 };
	vector<vector<int>> combi_list = combination(vec, 5, 3);
	cout << "(Without STL)" << endl;
	for (auto& col : combi_list) {
		for (auto& n : col)
			cout << n << " ";
		cout << endl;
	}

	cout << endl << "(Using STL - next_permutation)" << endl;
	vector<vector<int>> combiWithSTL_list;
	vector<int> subvec;
	vector<bool> bool_vec(5, false);

	for (int i = 0; i < 3; ++i)
		bool_vec.at(bool_vec.size() - i - 1) = true;

//	sort(bool_vec.begin(), bool_vec.end());

	do {
		for (int i = 0; i < bool_vec.size(); ++i) {
			if (bool_vec[i])
				subvec.push_back(vec.at(i));
		}
		combiWithSTL_list.push_back(subvec);
		subvec.assign(0, 0);
	} while (next_permutation(bool_vec.begin(), bool_vec.end()));

	for (auto& col : combiWithSTL_list) {
		for (auto& n : col)
			cout << n << " ";
		cout << endl;
	}
}