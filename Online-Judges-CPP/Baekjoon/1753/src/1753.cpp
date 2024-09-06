#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

typedef pair<int, int> P;

vector<vector<P>> graph;
vector<bool> isvisited;
vector<int> dijk;

auto comp = [](const P &a, const P &b){
    if(a.second != b.second)
        return a.second > b.second;
    return a.first > b.first;
};

priority_queue<P, vector<P>, decltype(comp)> que(comp);

int main(){
    
    int V, E;
    cin >> V >> E;
    
    int K;
    cin >> K;
    
    graph.assign(V+1, vector<P>());
    isvisited.assign(V+1, false);
    dijk.assign(V+1, numeric_limits<int>::max());
    
    for(int i=0; i<E; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        
        graph.at(u).push_back(make_pair(v, w));
    }
    
    dijk.at(K) = 0;
    que.push(make_pair(K, dijk.at(K)));
    
    while(!que.empty()){
        int v = que.top().first;
        
        if(!isvisited.at(v)){
            isvisited.at(v) = true;
            for(auto &np: graph.at(v)){
                int &next = np.first;
                int &dist = np.second;
                
                if(dijk.at(next) > dijk.at(v) + dist){
                    dijk.at(next) = dijk.at(v) + dist;
                    que.push(make_pair(next, dijk.at(next)));
                }
            }
        }
        que.pop();
    }
    
    for(int i=1; i<=V; ++i){
        if(dijk.at(i) == numeric_limits<int>::max())
            cout << "INF\n";
        else
            cout << dijk.at(i) << "\n";
    }
    
    return 0;
}
