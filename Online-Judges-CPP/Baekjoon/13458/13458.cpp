#include <iostream>
#include <queue>

using namespace std;

long long howManyDirectorsNeed() {
	
	int n, input, b, c;
	long long total_director = 0;
	queue<int> space;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> input;
		space.push(input);
	}
	cin >> b >> c;

	while(!space.empty()) {
		int& front = space.front();
		front -= b;
		++total_director;

		if (front > 0) {
			if (front % c != 0)
				++total_director;

			total_director += (front / c);
		}

		space.pop();
	}

	return total_director;
}

int main() {
	cout << howManyDirectorsNeed() << endl;
}