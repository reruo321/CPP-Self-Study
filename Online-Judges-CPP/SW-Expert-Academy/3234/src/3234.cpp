#include <iostream>
#include <algorithm>

using namespace std;

int N;
int answer;
int v_input[10];

void putWeight(int level, int sum) {

	if (level == N) {
		++answer;
		return;
	}

	int &w = v_input[level];

	putWeight(level + 1, sum + w);
	if (sum >= w)
		putWeight(level + 1, sum - w);

}

void choo() {
	do {
		putWeight(0, 0);
	} while (next_permutation(v_input, v_input+N));
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int T;
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case) {
		scanf("%d", &N);
		answer = 0;

		for (int i = 0; i < N; ++i) {
			scanf("%d", &v_input[i]);
		}

		sort(v_input, v_input+N);
		choo();

		printf("#%d %d\n", test_case, answer);
	}

	return 0;
}
