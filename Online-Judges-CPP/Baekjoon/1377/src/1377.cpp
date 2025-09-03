#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<pair<int, int>> vec;
    vec.reserve(N);
    
    for(int i=0; i<N; ++i){
        int input;
        cin >> input;
        vec.push_back(make_pair(i, input));
    }
    
    sort(vec.begin(), vec.end(), [](const pair<int, int> &a, const pair<int, int> &b){
        if(a.second != b.second)
            return a.second < b.second;
        return a.first < b.first;
    });
    
    int mindiff = 0;
    
    for(int i=0; i<N; ++i){
        mindiff = min(mindiff, i - vec.at(i).first);
    }
    
    cout << -mindiff + 1 << endl;

    return 0;
}
