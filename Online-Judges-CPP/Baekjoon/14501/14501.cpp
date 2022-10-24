#include <iostream>
#include <vector>

using namespace std;

struct TaskPay {
	int t;
	int p;
	TaskPay(): t(0), p(0) {}
};

int maxSalary() {
	int day[17] = {0, };
	int day_paid, pay;
	int n;
	int max = 0;

	cin >> n;
	vector<TaskPay> task_table(n + 1);

	for (int i = 1; i <= n; ++i)
		cin >> task_table.at(i).t >> task_table.at(i).p;

	// Read table in order, find the maximum total salary of each day
	for (int i = 1; i <= n; ++i) {
		if ((day_paid = i + task_table.at(i).t) <= n + 1) {
			pay = day[i] + task_table.at(i).p;
			for(int j = day_paid; j <= n + 1; ++j)
			if (day[j] < pay)
				day[j] = pay;
		}
	}

	for (int i = 1; i <= n + 1; ++i) {
		if (max < day[i])
			max = day[i];
	}

	return max;
}

int main() {
	cout << maxSalary() << endl;
}