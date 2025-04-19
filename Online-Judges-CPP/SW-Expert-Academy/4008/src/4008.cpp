#include <iostream>
#include <limits>

using namespace std;

int T;
int N;

int ops[4] = { 0 };
int num[12] = { 0 };
int ops_used[4] = { 0 };

int ans_max, ans_min;

int getOpResult(int a, int op, int idx) {
	int b = num[idx + 1];
	switch (op) {
		case 0:
			return a + b;
		case 1:
			return a - b;
		case 2:
			return a * b;
		case 3:
			return a / b;
		default:
			return a;
	}
}

void iterateOps(int idx, int result) {
	if (idx == N - 1) {
		ans_max = max(ans_max, result);
		ans_min = min(ans_min, result);
		return;
	}

	for (int i = 0; i < 4; ++i) {
		if (ops_used[i] >= ops[i])
			continue;
		
		++ops_used[i];
		iterateOps(idx + 1, getOpResult(result, i, idx));
		--ops_used[i];
	}
}

int main() {

	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> N;
		ans_max = numeric_limits<int>::min();
		ans_min = numeric_limits<int>::max();

		for (int i = 0; i < 4; ++i) {
			cin >> ops[i];
		}

		for (int i = 0; i < N; ++i) {
			cin >> num[i];
		}

		iterateOps(0, num[0]);

		cout << "#" << t << " " << ans_max - ans_min << endl;
	}

	return 0;
}
