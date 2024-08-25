#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> topo;

void topoFunc(int a){
    if(topo.at(a) == 0){
        cout << a << " ";
        --topo.at(a);
        for(auto &next: graph.at(a)){
            --topo.at(next);
            topoFunc(next);
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    graph.assign(N+1, vector<int>());
    topo.assign(N+1, 0);
    
    for(int i=0; i<M; ++i){
        int inp1, inp2;
        cin >> inp1 >> inp2;
        graph.at(inp1).push_back(inp2);
        ++topo.at(inp2);
    }
    
    for(int i=1; i<=N; ++i){
        topoFunc(i);
    }

    return 0;
}
