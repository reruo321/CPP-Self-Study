// Not finished

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> P;

vector<vector<P>> graph;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    graph.assign(m+1, 0);
    
    for(int i=0; i<n; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        
        graph.at(a).push_back(make_pair(b, c));
    }

    return 0;
}
