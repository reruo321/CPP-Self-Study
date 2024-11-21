#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<int> parent;
vector<bool> isvisited;

void DFS(int v){
    isvisited.at(v) = true;
    
    for(auto &next: tree.at(v)){
        if(!isvisited.at(next)){
            parent.at(next) = v;
            DFS(next);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    tree.assign(N+1, vector<int>());
    parent.assign(N+1, 1);
    isvisited.assign(N+1, false);
    
    for(int i=0; i<N-1; ++i){
        int a, b;
        cin >> a >> b;
        
        tree.at(a).push_back(b);
        tree.at(b).push_back(a);
    }
    
    DFS(1);
    
    for(int i=2; i<parent.size(); ++i){
        cout << parent.at(i) << "\n";
    }

    return 0;
}
