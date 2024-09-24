// Not finished

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> P;

vector<vector<P>> graph;
priority_queue<P, vector<P>, greater<P>> que;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    graph.assign(m+1, vector<P>());
    
    for(int i=0; i<n; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        
        graph.at(a).push_back(make_pair(b, c));
    }
    
    que.push(make_pair(0, 1));

    return 0;
}
