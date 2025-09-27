#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> topo;
vector<int> initcost;
vector<int> finalcost;

void topoFunc(int a){
    if(topo.at(a) == 0){
        finalcost.at(a) += initcost.at(a);
        --topo.at(a);
        for(auto &next: graph.at(a)){
            --topo.at(next);
            
            if(finalcost.at(next) < finalcost.at(a))
            finalcost.at(next) = finalcost.at(a);
            topoFunc(next);
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    graph.assign(N+1, vector<int>());
    topo.assign(N+1, 0);
    initcost.assign(N+1, 0);
    finalcost.assign(N+1, 0);
    
    for(int i=1; i<=N; ++i){
        int input;
        cin >> input;
        initcost.at(i) = input;
        cin >> input;
        while(input != -1){
            graph.at(input).push_back(i);
            ++topo.at(i);
            cin >> input;
        }
    }
    
    for(int i=1; i<=N; ++i){
        topoFunc(i);
    }
    
    for(int i=1; i<=N; ++i){
        cout << finalcost.at(i) << "\n";
    }

    return 0;    
}
