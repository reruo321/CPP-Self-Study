#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

auto comp = [](const int &a, const int &b){ return a > b; };

int main()
{
    vector<int> vec = {3, 4, 1, 5, 2};
    sort(vec.begin(), vec.end(), comp);
    
    for(auto &v: vec){
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
