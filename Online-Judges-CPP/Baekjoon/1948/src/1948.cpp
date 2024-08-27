// Not Finished

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> P;

vector<vector<P>> graph;
vector<int> rcount;
vector<int> topo;

vector<int> roads;

int f_source, f_dest;

void topoFunc(int v){
    if(topo.at(v) == 0){
        --topo.at(v);
        for(auto &np: graph){
            int &next = np.first;
            int &ri = np.second;
            
            bool ismaximum = topoFunc()
        }
    }
}

int main(){
    
    int n, m;
    cin >> n >> m;
    
    graph.assign(n+1, vector<P>());
    maxroads.assign(n+1, 0);
    topo.assign(n+1, 0);
    
    roads.assign(m, 0);
    
    for(int i=0; i<m; ++i){
        int source, dest, d;
        cin >> source >> dest >> d;
        graph.at(source).push_back(make_pair(dest, i));
        
        roads.at(i) = d;
    }
    
    cin >> f_source >> f_dest;
    topoFunc(f_source);
    
    
    return 0;
}
