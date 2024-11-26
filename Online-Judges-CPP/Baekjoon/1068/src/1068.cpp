#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<bool> isvisited;
static int leaf = 0;
static int erased = 0;

void DFS(int v){

    if(v == erased)
        return;

    isvisited.at(v) = true;
    int child = 0;
    
    for(auto &next: tree.at(v)){
        if(!isvisited.at(next)){
            isvisited.at(next) = true;
            if(next == erased){
                continue;
            }
            ++child;
            DFS(next);
        }
    }
    if(child == 0)
        ++leaf;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    tree.assign(N, vector<int>());
    isvisited.assign(N, false);
    
    int root = 0;
    
    for(int i=0; i<N; ++i){
        int parent;
        cin >> parent;
        
        if(parent < 0){
            root = i;
        }
        else{
            tree.at(parent).push_back(i);
        }
    }
    
    cin >> erased;
    
    DFS(root);
    
    cout << leaf << "\n";
    
    return 0;
}
