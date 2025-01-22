// Not finished. Need to be optimized.

#include <iostream>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

vector<int> depth;
vector<vector<int>> tree;
vector<vector<int>> vec_lca;
int N;
int logN;

void DFS(const int &root){
    stack<pair<int, int>> sta;
    sta.push({root, root});
    
    while(!sta.empty()){
        int node = sta.top().first;
        int parent = sta.top().second;
        sta.pop();
        
        vec_lca.at(node).at(0) = parent;
        
        for(int i=1; i<=logN; ++i){
            vec_lca.at(node).at(i) = vec_lca.at(vec_lca.at(node).at(i-1)).at(i-1);
        }
        
        for(auto &next: tree.at(node)){
            if(next != parent){
                depth.at(next) = depth.at(node) + 1;
                sta.push({next, node});
            }
        }        
    }
}

int LCA(int a, int b){
    if(depth.at(a) > depth.at(b)){
        swap(a, b);
    }
    
    for(int i=logN; i>=0; --i){
        if(depth.at(a) <= depth.at(b) - (1 << i)){
            b = vec_lca.at(b).at(i);
        }
    }
    
    if(a == b){
        return a;
    }
    
    for(int i=logN; i>=0; --i){
        if(vec_lca.at(a).at(i) != vec_lca.at(b).at(i)){
            a = vec_lca.at(a).at(i);
            b = vec_lca.at(b).at(i);
        }
    }
    
    return vec_lca.at(a).at(0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    const int root = 1;
    cin >> N;
    
    logN = log2(N);
    
    depth.assign(N+1, 0);
    tree.assign(N+1, vector<int>());
    vec_lca.assign(N+1, vector<int>(logN+1, -1));
    
    for(int i=0; i<N-1; ++i){
        int a, b;
        cin >> a >> b;
        
        tree.at(a).push_back(b);
        tree.at(b).push_back(a);
    }
    
    DFS(root);
    
    int M;
    cin >> M;
    for(int i=0; i<M; ++i){
        int a, b;
        cin >> a >> b;
        
        cout << LCA(a, b) << endl;
    }
    
    return 0;
}
