#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> depth;
vector<vector<int>> graph;
vector<vector<int>> pvec;
const int root = 1;
int logN;
int N;

void DFS(int node, int parent){
    pvec.at(node).at(0) = parent;
    for(int k=1; k<=logN; ++k){
        pvec.at(node).at(k) = pvec.at(pvec.at(node).at(k-1)).at(k-1);
    }
    
    for(auto &next: graph.at(node)){
        if(next != parent){
            depth.at(next) = depth.at(node) + 1;
            DFS(next, node);
        }
    }
}

int LCA(int a, int b){
    if(depth.at(a) > depth.at(b)){
        swap(a, b);
    }
    
    for(int i=logN; i>=0; --i){
        if(depth.at(a) <= depth.at(b) - pow(2, i)){
            b = pvec.at(b).at(i);
        }
    }
    
    if(a == b)
        return a;
    
    for(int i=logN; i>=0; --i){
        if(pvec.at(a).at(i) != pvec.at(b).at(i)){
            a = pvec.at(a).at(i);
            b = pvec.at(b).at(i);
        }
    }
    return pvec.at(b).at(0);
}

int main()
{  
    cin >> N;

    logN = log2(N);

    graph.assign(N+1, vector<int>());
    depth.assign(N+1, 0);
    pvec.assign(N+1, vector<int>(logN+1, -1));

    for(int i=0; i<N-1; ++i){
        int a, b;
        cin >> a >> b;
        graph.at(a).push_back(b);
        graph.at(b).push_back(a);
    }
    
    DFS(1, 1);

    int M;
    cin >> M;
    
    for(int i=0; i<M; ++i){
        int a, b;
        cin >> a >> b;
        cout << LCA(a, b) << endl;
    }
   
    return 0;
}
