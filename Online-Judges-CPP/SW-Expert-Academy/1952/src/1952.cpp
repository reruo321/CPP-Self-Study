#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T;
int min_price;
vector<int> price_list(3, 0);
vector<int> v_plan(12+1, 0);

void backTracking(int month, int sum) {
    if (month > 12) {
        min_price = min(min_price, sum);
        return;
    }
 
    backTracking(month + 1, sum + (v_plan.at(month) * price_list.at(0)));
    backTracking(month + 1, sum + price_list.at(1));
    backTracking(month + 3, sum + price_list.at(2));
}

int main() {
    
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        for (int i = 0; i < price_list.size(); ++i)
            cin >> price_list.at(i);
        cin >> min_price;

        for (int i = 1; i < v_plan.size(); ++i)
            cin >> v_plan.at(i);

        backTracking(1, 0);
        cout << "#" << t << " " << min_price << endl;
    }

    return 0;
}
