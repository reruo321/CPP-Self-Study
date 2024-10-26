// Not finished

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<pair<int, int>> graph;
vector<vector<int>> floyd;

int main()
{
    int n, m;
    cin >> n >> m;
    
    graph.assign(n+1, pair<int, int>());
    floyd.assign(n+1, vector<int>(n+1, 0));
    
    for(int i=0; i<m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        graph.at(a).push_back({b, c});
    }

    return 0;
}
