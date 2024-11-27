#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

static vector<set<int>> vec;
static vector<bool> isvisited;

void DFS(int n){
    if(!isvisited.at(n)){
        isvisited.at(n) = true;
        cout << n << " ";
        
        for(auto &s: vec.at(n)){
            DFS(s);
        }
    }
}

void BFS(int n){
    queue<int> que;
    que.push(n);
    
    while(!que.empty()){
        int f = que.front();
        que.pop();
        if(!isvisited.at(f)){
            isvisited.at(f) = true;
            cout << f << " ";
            for(auto &s: vec.at(f)){
                que.push(s);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M, V;
    cin >> N >> M >> V;
    vec.assign(N+1, set<int>());
    
    for(int i=0; i<M; ++i){
        int a, b;
        cin >> a >> b;
        vec.at(a).insert(b);
        vec.at(b).insert(a);
    }
    
    isvisited.assign(N+1, false);
    DFS(V);
    cout << "\n";
    
    isvisited.assign(N+1, false);
    BFS(V);

    return 0;
}
