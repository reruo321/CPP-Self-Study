#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void calcMaxMin() {
	vector<int> num;
	int arith[4] = { 0, };
	int n, result;
	int max = 1 - INT_MAX, min = INT_MAX - 1;
	int combi_acc = 0;

	// take inputs
	cin >> n;
	num.assign(n, 0);
	for (int i = 0; i < n; ++i)
		cin >> num.at(i);
	for (int i = 0; i < 4; ++i)
		cin >> arith[i];

	// prepare combinations for +, -, *, /
	vector<int> combi_arith(n - 1);
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < arith[i]; ++j) {
			combi_arith.at(j + combi_acc) = i;
		}
		combi_acc += arith[i];
	}
	sort(combi_arith.begin(), combi_arith.end());

	// calculate every case
	do {
		result = num[0];
		for (int i = 0; i < n - 1; ++i) {
			switch (combi_arith[i]) {
			case 0:
				result += num[i + 1];
				break;
			case 1:
				result -= num[i + 1];
				break;
			case 2:
				result *= num[i + 1];
				break;
			case 3:
				result /= num[i + 1];
				break;
			}
		}
		if (max < result)
			max = result;
		if (min > result)
			min = result;
	} while (next_permutation(combi_arith.begin(), combi_arith.end()));

	cout << max << endl << min << endl;
}

int main() {

	calcMaxMin();

	return 0;
}