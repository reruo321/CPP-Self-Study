// Not finished. Wrong solution.

#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

typedef pair<int, int> P;

vector<vector<P>> graph;
vector<int> dijk;
vector<bool> isvisited;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int V, E;
    cin >> V >> E;
    
    int K;
    cin >> K;

    graph.assign(V+1, vector<P>());
    dijk.assign(V+1, numeric_limits<int>::max());
    dijk.at(K) = 0;
    isvisited.assign(V+1, false);
    
    for(int i=0; i<E; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        
        graph.at(u).push_back(make_pair(v, w));
    }
    
    queue<int> que;
    que.push(K);
    
    while(!que.empty()){
        int v = que.front();
        que.pop();
        
        if(!isvisited.at(v)){
            isvisited.at(v) = true;
            int &cur = dijk.at(v);
            
            for(auto &np: graph.at(v)){
                int &next = np.first;
                int &dist = np.second;
                
                dijk.at(next) = min(dijk.at(next), cur + dist);
                if(!isvisited.at(next)){
                    que.push(next);
                }
            }
        }
    }
    
    for(int i=1; i<=V; ++i){
        int &result = dijk.at(i);
        
        if(result == numeric_limits<int>::max())
            cout << "INF\n";
        else
            cout << result << "\n";
    }

    return 0;
}
